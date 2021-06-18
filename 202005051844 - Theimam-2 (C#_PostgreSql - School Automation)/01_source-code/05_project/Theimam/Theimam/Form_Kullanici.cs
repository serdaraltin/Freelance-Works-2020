using System;
using System.Collections;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Kullanici : Form
    {
        int Id = 0;
        public Form_Kullanici()
        {
            InitializeComponent();
        }
        public Form_Kullanici(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "kullanici";
        private void Form_Sinif_Load(object sender, EventArgs e)
        {
            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                txt_KullaniciAd.Text = veriler[1].ToString();
                txt_Parola.Text = veriler[2].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"kullanici_ad",txt_KullaniciAd.Text},
                new ArrayList(){"parola",txt_Parola.Text}
            };

            if (Id != 0)
            {
                islemler.Guncelle(this, tablo, kayit, Id); return;
            }
            islemler.Ekle(this, tablo, kayit);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(tablo, Id);
        }
    }
}
