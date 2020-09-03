using System;
using System.Collections;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Yonetim_Tur : Form
    {
        int Id = 0;
        public Form_Yonetim_Tur()
        {
            InitializeComponent();
        }
        public Form_Yonetim_Tur(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "yonetim_tur";
        private void Form_Sinif_Load(object sender, EventArgs e)
        {
            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                txt_Ad.Text = veriler[1].ToString();
                
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ad",txt_Ad.Text}
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
