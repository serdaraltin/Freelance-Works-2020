using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Giris : Form
    {
        public Form_Giris()
        {
            InitializeComponent();
        }

        Class_VeritabaniIslemleri Veritabani = new Class_VeritabaniIslemleri();
        private void btn_Giris_Click(object sender, EventArgs e)
        {
            
            if (Veritabani.YoneticiKontrol(txt_KullaniciAd.Text, txt_Parola.Text))
            {
                int YoneticiId = Convert.ToInt32(Veritabani.YoneticiBilgiGetAd(txt_KullaniciAd.Text)[0]);
                Form_AnaPencere anapencere = new Form_AnaPencere(YoneticiId);
                anapencere.Show();
                MessageBox.Show("Hoşgeldiniz", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Hide();
            }
            else
            {
                MessageBox.Show("Kullanıcı Adı veya Parola hatalı !!!", "HATA", MessageBoxButtons.OK, MessageBoxIcon.Error);

            }
        }

        private void Form_Giris_Load(object sender, EventArgs e)
        {

            if (!Veritabani.BaglantiTest() || (Ayarlar.Default.Sunucu == "" || Ayarlar.Default.Veritabani == ""))
            {
                MessageBox.Show("Veritabanı bağlantısı başarısız!!!\nVeritabanı bilgilerini güncelleyiniz.", "HATA", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Form_VeritabaniBaglanti baglanti = new Form_VeritabaniBaglanti();
                baglanti.ShowDialog();
                //this.Hide();
            }
            if(!Veritabani.YoneticiVarlikKontrol())
            {
                MessageBox.Show("Yönetici bulunamadı\nYeni Yönetici ekleyiniz", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                Form_YoneticiEkle yonetici = new Form_YoneticiEkle();
                yonetici.ShowDialog();
            }
        }
    }
}
