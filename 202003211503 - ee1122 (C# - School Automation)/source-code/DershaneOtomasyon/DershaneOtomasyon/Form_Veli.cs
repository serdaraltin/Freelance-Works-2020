using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DershaneOtomasyon
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
            cb_Cinsiyet.SelectedIndex = 0;
            cb_Yakinlik.SelectedIndex = 0;
            cb_Egitim.SelectedIndex = 2;
            islemler.CBDoldur(cb_Ogrenci, "ogrenci", new int[] { 3, 4 });
            Ogrenciler = islemler.Donustur(islemler.Kayitlar("ogrenci"), 0);


            if (VeliId != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir("veli", VeliId);

                int OgrenciId = Convert.ToInt32(islemler.Getir("ogrenci", Convert.ToInt32(veriler[1]))[0]);

                for (int i = 0; i < Ogrenciler.Count; i++)
                    if (OgrenciId == Convert.ToInt32(Ogrenciler[i]))
                        cb_Ogrenci.SelectedIndex = i;

                txt_TcNo.Text = veriler[2].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[3].ToString();
                txt_Soyad.Text = veriler[4].ToString();
                cb_Cinsiyet.Text = veriler[5].ToString();
                txt_Telefon.Text = veriler[6].ToString();
                txt_Adres.Text = veriler[7].ToString();
                cb_Egitim.Text = veriler[8].ToString();
                txt_Gelir.Text = veriler[9].ToString();

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
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"cinsiyet",cb_Cinsiyet.Text},
                new ArrayList(){"telefon",txt_Telefon.Text},
                new ArrayList(){"ogrenci_Id",OgrenciId},
                new ArrayList(){"yakinlik",cb_Yakinlik.Text},
                new ArrayList(){"gelir",txt_Gelir.Text},
                new ArrayList(){"adres",txt_Adres.Text},
                new ArrayList(){"egitim",cb_Egitim.Text}
            };

            if (VeliId != 0)
            {
                kayit.Add(new ArrayList() { "Id", VeliId });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu("basarili", "veli güncelleme");
                else
                    islemler.MesajKutu("hata", "veli güncelleme");
                return;
            }
            if (islemler.Ekle(tablo, kayit))
                islemler.MesajKutu("basarili", "veli ekleme");
            else
                islemler.MesajKutu("hata", "veli ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
          
            islemler.Sil(this, tablo, VeliId);
        }
    }
}
