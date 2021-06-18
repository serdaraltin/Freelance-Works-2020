using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Siparisler : Form
    {
        int SiparisId = 0;
        public Form_Siparisler()
        {
            InitializeComponent();
        }
        public Form_Siparisler(int Siparis_Id)
        {
            InitializeComponent();
            SiparisId = Siparis_Id;
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();


        public void Siparis_Listele(int Siparis)
        {
            dg_Siparisler.DataSource = veritabani.Siparis_Detaylar(Siparis).Tables[0];
        }
        public void Urun_Listele()
        {
            lst_Urun.DataSource = veritabani.UrunlerAd();
        }

        private void Form_SiparisDetay_Load(object sender, EventArgs e)
        {
            SiparisId = 3;
            Urun_Listele();
            int MusteriId = 0;
            if (SiparisId != 0)
            {
                MusteriId = Convert.ToInt32(veritabani.SiparisBilgi(SiparisId)[0]); ;
                Siparis_Listele(SiparisId);
                txt_Musteri.Text = veritabani.MusteriBilgi(MusteriId)[1] + " " + veritabani.MusteriBilgi(MusteriId)[2];
                txt_SiparisId.Text = SiparisId.ToString();
                this.Text += " - " + SiparisId.ToString();
            }
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void btn_Temizle_Click(object sender, EventArgs e)
        {
            txt_Miktar.Clear();
            txt_Fiyat.Clear();
            lst_Urun.SelectedIndex = 0;
            txt_Id.Clear();
            btn_Ekle.Text = "Ekle";
            btn_Sil.Enabled = false;
        }

        private void dg_Siparisler_DragEnter(object sender, DragEventArgs e)
        {
           
        }

        private void txt_Id_TextChanged(object sender, EventArgs e)
        {
            if (txt_Id.Text != "")
            {
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Enabled = true;
            }
            else
            {
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Enabled = true;
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int UrunId = Convert.ToInt32(veritabani.UrunBilgi(lst_Urun.SelectedItem.ToString())[0]);
            if (txt_Id.Text != "")
            {
                int Id = Convert.ToInt32(txt_Id.Text);
                if (veritabani.SiparisDetayGuncelle(Id, SiparisId, UrunId, Convert.ToInt32(txt_Miktar.Text), float.Parse(txt_Fiyat.Text)))
                    MessageBox.Show("Güncellendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    MessageBox.Show("Güncellenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                btn_Temizle.PerformClick();
                return;
            }
            if (veritabani.SiparisDetayEkle(SiparisId, UrunId, Convert.ToInt32(txt_Miktar.Text), float.Parse(txt_Fiyat.Text)))
                MessageBox.Show("Eklendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show("Eklenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            btn_Temizle.PerformClick();
            Siparis_Listele(SiparisId);
        }

        private void txt_Miktar_TextChanged(object sender, EventArgs e)
        {
            try
            {
                int UrunId = Convert.ToInt32(veritabani.UrunBilgi(lst_Urun.SelectedItem.ToString())[0]);
                int fiyat = Convert.ToInt32(veritabani.UrunBilgi(lst_Urun.SelectedItem.ToString())[5]);
                int miktar = Convert.ToInt32(txt_Miktar.Text);
                if (Convert.ToInt32(veritabani.UrunBilgi(UrunId)[3]) > miktar)
                    txt_Fiyat.Text = (miktar * fiyat).ToString();
                else if (Convert.ToInt32(veritabani.UrunBilgi(UrunId)[3]) == miktar)
                {
                    txt_Miktar.Text = veritabani.UrunBilgi(UrunId)[3];
                    txt_Fiyat.Text = (miktar * fiyat).ToString();
                }
                else
                {
                    txt_Miktar.Text = veritabani.UrunBilgi(UrunId)[3];
                    MessageBox.Show("Stokta daha fazla ürün yok", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
                
            }
            catch
            {
                MessageBox.Show("Miktar sorunu !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void dg_Siparisler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                txt_Id.Text = dg_Siparisler.Rows[e.RowIndex].Cells[0].Value.ToString();
                int UrunId = Convert.ToInt32(dg_Siparisler.Rows[e.RowIndex].Cells[2].Value.ToString());
               
                int i =0;
                foreach (var ListBoxItem in lst_Urun.Items)
                {
                    if (ListBoxItem.ToString() == veritabani.UrunBilgi(UrunId)[1])
                        lst_Urun.SelectedIndex = i;
                    i++;
                }
                txt_Miktar.Text = dg_Siparisler.Rows[e.RowIndex].Cells[3].Value.ToString();
            }
            catch
            {

            }
        }
    }
}
