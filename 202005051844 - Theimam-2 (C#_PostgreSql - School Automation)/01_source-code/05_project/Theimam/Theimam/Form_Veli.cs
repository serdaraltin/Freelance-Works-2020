using System;
using System.Collections;
using System.Collections.Generic;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Veli : Form
    {
        int VeliId = 0;
        public Form_Veli()
        {
            InitializeComponent();
        }
        public Form_Veli(int Veli_Id)
        {
            InitializeComponent();
            VeliId = Veli_Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Ogrenciler = new List<string>();
        string tablo = "veli";
        private void Form_Veli_Load(object sender, EventArgs e)
        {
           
            islemler.CBDoldur(cb_Ogrenci, "ogrenci", new int[] { 1, 2 });
            Ogrenciler = islemler.Donustur(islemler.Kayitlar("ogrenci"), 6);


            if (VeliId != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir("veli", VeliId);

                int OgrenciId = Convert.ToInt32(islemler.Getir("ogrenci", Convert.ToInt32(veriler[7]))[6]);

                for (int i = 0; i < Ogrenciler.Count; i++)
                    if (OgrenciId == Convert.ToInt32(Ogrenciler[i]))
                        cb_Ogrenci.SelectedIndex = i;

                txt_TcNo.Text = veriler[0].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[1].ToString();
                txt_Soyad.Text = veriler[2].ToString();
                txt_Telefon.Text = veriler[3].ToString();
                txt_Eposta.Text = veriler[4].ToString();
                txt_Adres.Text = veriler[5].ToString();
                

            }
        }

        private void cb_Ogrenci_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int OgrenciId = Convert.ToInt32(Ogrenciler[cb_Ogrenci.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ogrenci_id",OgrenciId},
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"telno",txt_Telefon.Text},
                new ArrayList(){"eposta",txt_Eposta.Text},
                new ArrayList(){"adres",txt_Adres.Text},
            };

            if (VeliId != 0)
            {
                kayit.Add(new ArrayList() { "veli_id", VeliId });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu(tablo+" güncelleme");
                else
                    islemler.MesajKutu(2, tablo + " güncelleme");
                return;
            }
            if (islemler.Ekle(tablo, kayit))
                islemler.MesajKutu(tablo + " ekleme");
            else
                islemler.MesajKutu(2, tablo + " ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(this, tablo, VeliId);
        }
    }
}
