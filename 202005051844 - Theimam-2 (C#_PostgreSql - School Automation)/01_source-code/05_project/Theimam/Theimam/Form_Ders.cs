using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Ders : Form
    {
        int Id = 0;
        public Form_Ders()
        {
            InitializeComponent();
        }
        public Form_Ders(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "ders";
        private void Form_Ders_Load(object sender, EventArgs e)
        {
            islemler.CBDoldur(cb_Ogretmen, "ogretmen", new int[] { 1, 2 });
            Liste = islemler.Donustur(islemler.Kayitlar("ogretmen"), 6);

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;
               
                ArrayList veriler = islemler.Getir(tablo, Id);

                islemler.CBSec(cb_Ogretmen, Liste, Convert.ToInt32(veriler[2]));
                txt_Ad.Text = veriler[1].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int ogretmen_id = Convert.ToInt32(Liste[cb_Ogretmen.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"ogretmen_id", ogretmen_id},
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
