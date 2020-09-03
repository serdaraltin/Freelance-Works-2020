using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_YoneticiEkle : Form
    {
        int YoneticiId = 0;
        public Form_YoneticiEkle()
        {
            InitializeComponent();
        }
        public Form_YoneticiEkle(int Id)
        {
            InitializeComponent();
            YoneticiId = Id;
        }
        Class_VeritabaniIslemleri Veritabani = new Class_VeritabaniIslemleri();
        private void Form_YoneticiEkle_Load(object sender, EventArgs e)
        {
            if(YoneticiId != 0)
            {
                this.Text = "Yönetici Güncelle";
                txt_KullaniciAd.ReadOnly = true;
                txt_KullaniciAd.Text = Veritabani.YoneticiBilgi(YoneticiId)[0].ToString().Trim();
                txt_Parola.Text = Veritabani.YoneticiBilgi(YoneticiId)[1].ToString().Trim();
                btn_Ekle.Text = "Güncelle";
                txt_Parola.Focus();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            if (!(txt_KullaniciAd.Text != "" && txt_Parola.Text.Length > 6))
            {
                MessageBox.Show("Lütfen gerekli alanları doğru şekilde doldurun.", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if(YoneticiId != 0)
            {
                if (Veritabani.YoneticiGuncelle(YoneticiId, txt_KullaniciAd.Text, txt_Parola.Text))
                    MessageBox.Show("Parola başarıyla güncelleştirildi","Bilgi",MessageBoxButtons.OK,MessageBoxIcon.Information);
                txt_Parola.Clear();
                Application.Restart();
            }
            if (Veritabani.YoneticiEkle(txt_KullaniciAd.Text, txt_Parola.Text))
            {
                MessageBox.Show("Yeni yönetici eklendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                txt_KullaniciAd.Clear();
                txt_Parola.Clear();
                return;
            }
        }
    }
}
