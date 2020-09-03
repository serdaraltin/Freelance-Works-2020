using System;
using System.Collections;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Nobet : Form
    {
        int Id = 0;
        public Form_Nobet()
        {
            InitializeComponent();
        }
        public Form_Nobet(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "nobet";
        private void Form_Ders_Load(object sender, EventArgs e)
        {
            islemler.CBDoldur(cb_Ogrenci, "ogrenci", new int[] { 1, 2 });
            Liste = islemler.Donustur(islemler.Kayitlar("ogrenci"), 6);

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                islemler.CBSec(cb_Ogrenci, Liste, Convert.ToInt32(veriler[1]));
                txt_Tarih.Text = veriler[2].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int OgrenciId = Convert.ToInt32(Liste[cb_Ogrenci.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ogrenci_id",OgrenciId},
                new ArrayList(){"tarih",txt_Tarih.Text},
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
