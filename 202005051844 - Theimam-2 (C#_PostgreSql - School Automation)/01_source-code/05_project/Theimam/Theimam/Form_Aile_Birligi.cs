using System;
using System.Collections;
using System.Collections.Generic;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Aile_Birligi : Form
    {
        int Id = 0;
        public Form_Aile_Birligi()
        {
            InitializeComponent();
        }
        public Form_Aile_Birligi(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "aile_birligi";
        private void Form_Ders_Load(object sender, EventArgs e)
        {
            islemler.CBDoldur(cb_Veli, "veli", new int[] { 1, 2 });
            Liste = islemler.Donustur(islemler.Kayitlar("veli"), 6);

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                islemler.CBSec(cb_Veli, Liste, Convert.ToInt32(veriler[1]));
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int VeliId = Convert.ToInt32(Liste[cb_Veli.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"veli_id",VeliId}
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
