using System;
using System.Collections;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Ogretmen : Form
    {
        int Id = 0;
        public Form_Ogretmen()
        {
            InitializeComponent();
        }
        public Form_Ogretmen(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "ogretmen";
        private void Form_Ogrenci_Load(object sender, EventArgs e)
        {
            ArrayList siniflar = islemler.Donustur(islemler.Kayitlar("bolum"));
            foreach (string[] item in siniflar)
                cb_Bolum.Items.Add(item[1]);
            ArrayList alanlar = islemler.Donustur(islemler.Kayitlar("egitmen_alan"));
            foreach (string[] item in alanlar)
                cb_Alan.Items.Add(item[1]);
            cb_Bolum.SelectedIndex = 0;
            cb_Alan.SelectedIndex = 0;


            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);


                txt_TcNo.Text = veriler[0].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[1].ToString();
                txt_Soyad.Text = veriler[2].ToString();
                txt_Telefon.Text = veriler[3].ToString();
                txt_Eposta.Text = veriler[4].ToString();
                txt_Adres.Text = veriler[5].ToString();
                cb_Bolum.Text = islemler.Getir("bolum", Convert.ToInt32(veriler[7]))[1].ToString();
                cb_Alan.Text = islemler.Getir("egitmen_alan", Convert.ToInt32(veriler[8]))[1].ToString();
            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {

            int bolum_Id = Convert.ToInt32(islemler.Getir("bolum", cb_Bolum.Text)[0]);
            int egitmen_alan_Id = Convert.ToInt32(islemler.Getir("egitmen_alan", cb_Alan.Text)[0]);

            ArrayList kayit = new ArrayList()
            {
                
                new ArrayList(){"tcno",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"telno",txt_Telefon.Text},
                new ArrayList(){"eposta",txt_Eposta.Text},
                new ArrayList(){"adres",txt_Adres.Text},
                new ArrayList(){"bolum_id",bolum_Id},
                new ArrayList(){"egitmen_alan_id", egitmen_alan_Id }

            };

            if(Id != 0)
            {
                kayit.Add(new ArrayList() { "ogretmen_id", Id });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu(tablo+" güncelleme");
                else
                    islemler.MesajKutu(2, tablo+" güncelleme");
                return;
            }
            if (islemler.Ekle(tablo, kayit))
                islemler.MesajKutu(tablo+" ekleme");
            else
                islemler.MesajKutu(2, tablo+" ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(this, tablo, Id);
        }
    }
}
