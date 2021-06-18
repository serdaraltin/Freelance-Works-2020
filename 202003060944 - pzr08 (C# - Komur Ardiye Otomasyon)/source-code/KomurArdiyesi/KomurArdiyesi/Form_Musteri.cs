using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Musteri : Form
    {
        int MusteriId = 0;
        public Form_Musteri()
        {
            InitializeComponent();
        }
        public Form_Musteri(int Id)
        {
            InitializeComponent();
            MusteriId = Id;
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();
        private void Form_Musteri_Load(object sender, EventArgs e)
        {
          
            string[] sehirler = { "Adana", "Adıyaman", "Afyon", "Ağrı", "Amasya", "Ankara", "Antalya", "Artvin", "Aydın", "Balıkesir", "Bilecik", "Bingöl", "Bitlis", "Bolu", "Burdur", "Bursa", "Çanakkale", "Çankırı", "Çorum", "Denizli", "Diyarbakır", "Edirne", "Elazığ", "Erzincan", "Erzurum", "Eskişehir", "Gaziantep", "Giresun", "Gümüşhane", "Hakkari", "Hatay", "Isparta", "İçel(Mersin)", "İstanbul", "İzmir", "Kars", "Kastamonu", "Kayseri", "Kırklareli", "Kırşehir", "Kocaeli", "Konya", "Kütahya", "Malatya", "Manisa", "K.maraş", "Mardin", "Muğla", "Muş", "Nevşehir", "Niğde", "Ordu", "Rize", "Sakarya", "Samsun", "Siirt", "Sinop", "Sivas", "Tekirdağ", "Tokat", "Trabzon", "Tunceli", "Şanlıurfa", "Uşak", "Van", "Yozgat", "Zonguldak", "Aksaray", "Bayburt", "Karaman", "Kırıkkale", "Batman", "Şırnak", "Bartın", "Ardahan", "Iğdır", "Yalova", "Karabük", "Kilis", "Osmaniye", "Düzce" };
            cb_Sehir.DataSource = sehirler;
            cb_Sehir.SelectedIndex = 0;

            if (MusteriId != 0)
            {
                this.Text = "Müşteri Güncelle";
                txt_TcNo.ReadOnly = true;
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                string[] veriler = veritabani.MusteriBilgi(MusteriId);

                txt_TcNo.Text = veriler[0];
                txt_Ad.Text = veriler[1];
                txt_Soyad.Text = veriler[2];
                txt_Telefon.Text = veriler[3];
                txt_Eposta.Text = veriler[4];
                cb_Sehir.Text = veriler[5];
                txt_Ilce.Text = veriler[6];
                txt_Adres.Text = veriler[7];
                txt_Ad.Focus();

            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            if (MusteriId != 0)
            {
                if (veritabani.MusteriGuncelle(MusteriId, txt_TcNo.Text, txt_Ad.Text, txt_Soyad.Text, txt_Telefon.Text, txt_Eposta.Text, cb_Sehir.Text, txt_Ilce.Text, txt_Adres.Text))
                    MessageBox.Show("Müşteri başarıyla güncellendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    MessageBox.Show("Müşteri güncellenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            bool kontrol = true;
            foreach (Control item in this.Controls)
            {
                if (item is TextBox && ((TextBox)item).Text == "")
                    kontrol = false;
                if (item is MaskedTextBox && ((MaskedTextBox)item).Text == "")
                    kontrol = false;
            }
            if (!kontrol)
            {
                MessageBox.Show("Lütfen gerekli alanları doldurunuz !!!", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (veritabani.MusteriEkle(txt_TcNo.Text, txt_Ad.Text, txt_Soyad.Text, txt_Telefon.Text, txt_Eposta.Text, cb_Sehir.Text, txt_Ilce.Text, txt_Adres.Text))
                MessageBox.Show("Müşteri başarıyla eklendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show("Müşteri eklenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Müşteriyi silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (veritabani.MusteriSil(MusteriId))
            {
                MessageBox.Show("Müşteri silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                    if (item is MaskedTextBox)
                        ((MaskedTextBox)item).Clear();
                }
                cb_Sehir.SelectedIndex = 0;
            }
            else
                MessageBox.Show("Müşteri silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }
    }
}
