using System.Collections.Generic;
using System.Data;
using System.Collections;
using System;
using System.Windows.Forms;
using System.Linq;
using Npgsql;

namespace Theimam
{
    class Class_Islemler
    {
         NpgsqlConnection baglanti = new NpgsqlConnection("Server="+Ayarlar.Default.sunucu+"; Port="+Ayarlar.Default.port+
             "; Database="+Ayarlar.Default.veritabani+"; User Id="+Ayarlar.Default.kullanici+"; Password="+Ayarlar.Default.parola+";");

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
        public int Yonetici_Kontrol(string KullaniciAd, string Parola) //YONETICI KONTROL +
        {
            try
            {
                baglanti.Open();
                string sql = "Select *From kullanici Where kullanici_ad='" + KullaniciAd + "' and parola='" + Parola + "'";
                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
                NpgsqlDataReader oku = komut.ExecuteReader();
                if (oku.Read())
                {
                    int kid = Convert.ToInt32(oku[0]);
                    baglanti.Close();
                    return kid;
                }
                baglanti.Close();
                return 0;
            }
            catch
            {
                baglanti.Close();
                return 0;
            }
        }
        //ANA İŞLEMLER
        public bool Kontrol(string tablo, int Id) //KONTROL +
        {
            try
            {
                baglanti.Open();
                string sql = "Select *From " + tablo + " Where " + tablo + "_id=" + Id;
                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
                NpgsqlDataReader oku = komut.ExecuteReader();
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
        public bool Ekle(string tablo, ArrayList veriler) //EKLE +
        {
            try
            {
                baglanti.Open();
                string sql = "Insert Into " + tablo + " (";

                string values = " Values(";

                foreach (ArrayList Kolon in veriler)
                {
                    sql += Kolon[0] + ",";

                    values += "'" + Kolon[1] + "',";
                }
                sql = SondanSil(sql, ",");
                values = SondanSil(values, ",");
                sql += ") " + values + ")";
                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
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
        public string SondanSil(string text, string character)
        {
            if (text.Length < 1) return text;
            return text.Remove(text.ToString().LastIndexOf(character), character.Length);
        }
        public bool Guncelle(string tablo, ArrayList veriler) //GUNCELLE +
        {
            try
            {
                baglanti.Open();
                string sql = "Update " + tablo + " Set ";
                string id="";
                foreach (ArrayList Kolon in veriler)
                {
                    if (Kolon[0].ToString() == tablo + "_id" || Kolon[0].ToString() == "Id")
                    {
                        id = Kolon[1].ToString();
                        continue;
                    }
                        
                    sql += Kolon[0] + "='"+Kolon[1]+"',";              
                }
                sql += " Where " + tablo + "_id=" + id;
                sql = SondanSil(sql, ",");

                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
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
        public bool Sil(string tablo, int Id) //SİL +
        {
            if (!(Kontrol(tablo, Id)))
                return false;
            try
            {
                baglanti.Open();
                string sql = "Delete From " + tablo + " Where " + tablo + "_id=" + Id;
                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
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
        public ArrayList Getir(string tablo, int Id) //GETİR +
        {
            try
            {
                baglanti.Open();
                string sql = "Select *From " + tablo + " Where " + tablo + "_id=" + Id;
                NpgsqlCommand komut = new NpgsqlCommand(sql, baglanti);
                NpgsqlDataReader oku = komut.ExecuteReader();
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
        public string[] Getir(string tablo, string sorulan) //GETİR ÖZEL +
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

        public DataSet Ara(string tablo, string aranan) //GETİR ÖZEL +
        {
            try
            {
                baglanti.Open();
                NpgsqlDataAdapter da = new NpgsqlDataAdapter("Select *From "+tablo+" Where *='"+aranan+"'", baglanti);
                DataSet ds = new DataSet();
                da.Fill(ds);
                baglanti.Close();
                return ds;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }

        public DataSet Kayitlar(string tablo) //KAYITLAR +
        {
            try
            {
                baglanti.Open();
                NpgsqlDataAdapter da = new NpgsqlDataAdapter("Select *From " + tablo, baglanti);
                DataSet ds = new DataSet();
                da.Fill(ds);
                baglanti.Close();
                return ds;
            }
            catch
            {
                baglanti.Close();
                return null;
            }
        }
        public ArrayList Donustur(DataSet veri) //DÖNÜŞTÜR +
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
                MesajKutu(tablo + " ekleme");
            else
                MesajKutu(2, tablo + " ekleme");
            Temizle(form);
        }
        public void Guncelle(Form form, string tablo, ArrayList veriler, int Id)
        {
            veriler.Add(new ArrayList() { "Id", Id });
            if (Guncelle(tablo, veriler))
                MesajKutu(tablo + " güncelleme");
            else
                MesajKutu(2, tablo + " güncelleme");
            return;
        }
        public void Sil(Form form, string tablo, int Id)
        {
            if (SoruKutu(tablo + "'i silmek"))
            {
                if (Sil(tablo, Id))
                {
                    MesajKutu("silme");
                    form.Close();
                }
                else
                    MesajKutu(2, "silme");
            }
        }
        public void MesajKutu(int tur, string islem)
        {
            switch (tur)
            {
                case 1:
                    MessageBox.Show(islem.ToUpper() + " işlemi için gerekli alanları doldurunuz.", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    break;
                case 2:
                    MessageBox.Show(islem.ToUpper() + " işlemi başarısız !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    break;
            }
        }
        public void MesajKutu(string islem)
        {
            MessageBox.Show(islem.ToUpper() + " işlemi başarılı.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
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
                ArrayList veriler = Donustur(Kayitlar(tablo));
                foreach (string[] item in veriler)
                    box.Items.Add(item[kolon]);
                box.SelectedIndex = 0;
            }
            catch
            {
                MesajKutu(2, tablo + " kaydı listeleme");
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
                MesajKutu(2, tablo + " kaydı listeleme");
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
                    if (((ComboBox)item).Items.Count > 0)
                        ((ComboBox)item).SelectedIndex = 0;
                if (item is DateTimePicker)
                    ((DateTimePicker)item).ResetText();
            }
        }

    }
}
