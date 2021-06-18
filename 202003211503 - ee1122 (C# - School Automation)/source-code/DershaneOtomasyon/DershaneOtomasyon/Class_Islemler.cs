
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Collections;
using System;
using System.Linq;
using System.Windows.Forms;
using Syncfusion.Pdf;
using Syncfusion.Pdf.Grid;

namespace DershaneOtomasyon
{
    class Class_Islemler
    {
        SqlConnection baglanti = new SqlConnection("Data Source=" + Ayarlar.Default.Sunucu + ";Initial Catalog=" + Ayarlar.Default.Veritabani + ";Integrated Security=True");

        //BAĞLANTI TEST
        public bool BaglantiTest()
        {
            try
            {
                baglanti.Open();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }

        //ANA İŞLEMLER
        public bool Kontrol(string tablo, int Id) //GETİR
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Getir", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Tablo", tablo);
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();
                if (oku.Read())
                {
                    baglanti.Close();
                    return true;
                }
                baglanti.Close();
                return false;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool Ekle(string tablo, ArrayList veriler) //EKLE
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand(tablo + "_Ekle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                foreach (ArrayList Kolon in veriler)
                    komut.Parameters.AddWithValue("@" + Kolon[0], Kolon[1]);
                komut.ExecuteNonQuery();
                komut.Dispose();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool Guncelle(string tablo, ArrayList veriler) //GUNCELLE
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand(tablo + "_Guncelle", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                foreach (ArrayList Kolon in veriler)
                    komut.Parameters.AddWithValue("@" + Kolon[0], Kolon[1]);
                komut.ExecuteNonQuery();
                komut.Dispose();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public bool Sil(string tablo, int Id) //SİL
        {
            if (!(Kontrol(tablo, Id)))
                return false;
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Sil", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Tablo", tablo);
                komut.Parameters.AddWithValue("@Id", Id);
                komut.ExecuteNonQuery();
                komut.Dispose();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        public ArrayList Getir(string tablo, int Id) //GETİR
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Getir", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Tablo", tablo);
                komut.Parameters.AddWithValue("@Id", Id);
                SqlDataReader oku = komut.ExecuteReader();
                ArrayList veriler = new ArrayList();
                if (oku.Read())
                {
                    for (int i = 0; true; i++)
                    {
                        try { veriler.Add(oku[i]); }
                        catch { break; }
                    }
                }

                komut.Dispose();
                baglanti.Close();
                return veriler;
            }
            catch
            {
                baglanti.Close();
                return null;
            }

        }
        public string[] Getir(string tablo, string sorulan) //GETİR ÖZEL
        {
            try
            {
                DataSet veriler = Kayitlar(tablo);
                ArrayList liste = Donustur(veriler);
                foreach (string[] items in liste)
                    foreach (string veri in items)
                        if (veri == sorulan)
                            return items;
                return null;
            }
            catch { return null; }
        }
        public DataSet Kayitlar(string tablo) //KAYITLAR
        {
            try
            {
                baglanti.Open();
                SqlCommand komut = new SqlCommand("Kayitlar", baglanti);
                komut.CommandType = CommandType.StoredProcedure;
                komut.Parameters.AddWithValue("@Tablo", tablo);
                SqlDataAdapter da = new SqlDataAdapter(komut);
                DataSet ds = new DataSet();
                da.Fill(ds);
                komut.Dispose();
                baglanti.Close();
                return ds;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public ArrayList Donustur(DataSet veri) //DÖNÜŞTÜR
        {
            try
            {
                ArrayList veriler = new ArrayList();
                foreach (DataRow satir in veri.Tables[0].Rows)
                {
                    string[] parcalanmis = string.Join(",", satir.ItemArray).Split(',').ToArray();
                    veriler.Add(parcalanmis);
                }
                return veriler;
            }
            catch { return null; }
        }
        public List<string> Donustur(DataSet veri, int kolon) //DÖNÜŞTÜR ÖZEL
        {
            try
            {
                List<string> veriler = new List<string>();
                foreach (DataRow satir in veri.Tables[0].Rows)
                {
                    string[] parcalanmis = string.Join(",", satir.ItemArray).Split(',').ToArray();
                    veriler.Add(parcalanmis[kolon]);
                }
                return veriler;
            }
            catch { return null; }
        }
        public void Ekle(Form form, string tablo, ArrayList veriler)
        {
            if (Ekle(tablo, veriler))
                MesajKutu("basarili", tablo + " ekleme");
            else
                MesajKutu("hata", tablo + " ekleme");
            Temizle(form);
        }
        public void Guncelle(Form form, string tablo, ArrayList veriler, int Id)
        {
            veriler.Add(new ArrayList() { "Id", Id });
            if (Guncelle(tablo, veriler))
                MesajKutu("basarili", tablo + " güncelleme");
            else
                MesajKutu("hata", tablo + " güncelleme");
            return;
        }
        public void Sil(Form form, string tablo, int Id)
        {
            if (SoruKutu(tablo + "'i silmek"))
            {
                if (Sil(tablo, Id))
                {
                    MesajKutu("basarili", "silme");
                    form.Close();
                }
                else
                    MesajKutu("hata", "silme");
            }
        }
        public void MesajKutu(string tur, string islem)
        {
            switch (tur)
            {
                case "basarili":
                    MessageBox.Show(islem.ToUpper() + " işlemi başarılı.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    break;
                case "doldur":
                    MessageBox.Show(islem.ToUpper() + " işlemi için gerekli alanları doldurunuz.", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    break;
                case "hata":
                    MessageBox.Show(islem.ToUpper() + " işlemi başarısız !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    break;
            }
        }
        public bool SoruKutu(string soru)
        {
            DialogResult cevap = MessageBox.Show(soru.ToUpper() + " istediğinize emin misiniz?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
                return true;
            else
                return false;
        }
        public void CBSec(ComboBox box, List<string> veriler, int Id)
        {
            for (int i = 0; i < veriler.Count; i++)
                if (Id == Convert.ToInt32(veriler[i]))
                    box.SelectedIndex = i;
        }
        public void CBDoldur(ComboBox box, string tablo, int kolon)
        {
            try
            {
                ArrayList siniflar = Donustur(Kayitlar(tablo));
                foreach (string[] item in siniflar)
                    box.Items.Add(item[kolon]);
                box.SelectedIndex = 0;
            }
            catch
            {
                MesajKutu("hata", tablo + " kaydı listeleme");
            }
        }
        public void CBDoldur(ComboBox box, string tablo, int[] kolonlar)
        {
            try
            {
                ArrayList siniflar = Donustur(Kayitlar(tablo));
                foreach (string[] item in siniflar)
                {
                    string veri = "";
                    for (int i = 0; i < kolonlar.Length; i++)
                    {
                        veri += item[kolonlar[i]] + " ";
                    }
                    box.Items.Add(veri);
                }

                box.SelectedIndex = 0;
            }
            catch
            {
                MesajKutu("hata", tablo + " kaydı listeleme");
            }
        }
        public void Temizle(Form form)
        {
            foreach (Control item in form.Controls)
            {
                if (item is TextBox)
                    ((TextBox)item).Clear();
                if (item is MaskedTextBox)
                    ((MaskedTextBox)item).Clear();
                if (item is ComboBox)
                    ((ComboBox)item).SelectedIndex = 0;
                if (item is DateTimePicker)
                    ((DateTimePicker)item).ResetText();
            }
        }
        public void RaporOlustur(string tablo)
        {
            try
            {
                SaveFileDialog kaydet = new SaveFileDialog();
                kaydet.Title = "Rapor Oluştur";
                kaydet.Filter = "Pdf|*.pdf";
                kaydet.FileName = "rapor.pdf";
                string kayitYol = "";
                if (kaydet.ShowDialog() == DialogResult.OK)
                    kayitYol = kaydet.FileName;
                else
                    return;
                PdfDocument dokuman = new PdfDocument();
                PdfPage sayfa = dokuman.Pages.Add();
                PdfGrid alan = new PdfGrid();
                alan.DataSource = Kayitlar(tablo);
                PdfGridStyle stil = new PdfGridStyle();
                stil.CellPadding = new PdfPaddings(5, 5, 5, 5);
                alan.Style = stil;
                alan.Draw(sayfa, new System.Drawing.PointF(10, 10));
                dokuman.Save(kayitYol);
                dokuman.Close();
                MesajKutu("basarili", "pdf oluşturma");
            }
            catch
            {
                MesajKutu("hata", "pdf oluşturma");
            }
        }

    }
}
