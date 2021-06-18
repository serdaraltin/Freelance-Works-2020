using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Bolum_ : Form
    {
        int Id = 0;
        public Form_Bolum_()
        {
            InitializeComponent();
        }
        public Form_Bolum_(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "bolum";
        private void Form_Ders_Load(object sender, EventArgs e)
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
                new ArrayList(){"ad",txt_Ad.Text},
            };

            if (Id != 0)
            {
                islemler.Guncelle(this, tablo, kayit, Id); return;
            }
            islemler.Ekle(this, tablo, kayit);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            if (Id == 0)
                islemler.MesajKutu(1, "seçim yapınız");
            if (islemler.Sil(tablo, Id))
                islemler.MesajKutu("silme");
            else
                islemler.MesajKutu(2, "silme");
        }
    }
}
