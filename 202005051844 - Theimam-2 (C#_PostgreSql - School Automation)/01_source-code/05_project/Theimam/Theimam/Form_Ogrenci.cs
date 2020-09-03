using System;
using System.Collections;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Ogrenci : Form
    {
        int Id = 0;
        public Form_Ogrenci()
        {
            InitializeComponent();
        }
        public Form_Ogrenci(int _Id)
        {
            InitializeComponent();
            Id =_Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "ogrenci";
        private void Form_Ogrenci_Load(object sender, EventArgs e)
        {
            ArrayList siniflar = islemler.Donustur(islemler.Kayitlar("sinif"));
            foreach (string[] item in siniflar)
                cb_Sinif.Items.Add(item[1]);
            ArrayList bolumler = islemler.Donustur(islemler.Kayitlar("bolum"));
            foreach (string[] item in bolumler)
                cb_Bolum.Items.Add(item[1]);
            cb_Sinif.SelectedIndex = 0;
            cb_Bolum.SelectedIndex = 0;


            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);

                cb_Sinif.Text = veriler[7].ToString();
                cb_Bolum.Text = veriler[8].ToString();
                txt_TcNo.Text = veriler[0].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[1].ToString();
                txt_Soyad.Text = veriler[2].ToString();
                txt_Telefon.Text = veriler[3].ToString();
                txt_Eposta.Text = veriler[4].ToString();
                txt_Adres.Text = veriler[5].ToString();

            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {

            int sinif_Id = Convert.ToInt32(islemler.Getir("sinif", cb_Sinif.Text)[0]);
            int bolum_Id = Convert.ToInt32(islemler.Getir("bolum", cb_Bolum.Text)[0]);

            ArrayList kayit = new ArrayList()
            {
                
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"telno",txt_Telefon.Text},
                new ArrayList(){"eposta",txt_Eposta.Text},
                new ArrayList(){"adres",txt_Adres.Text},
                new ArrayList(){"bolum_id",bolum_Id},
                new ArrayList(){"sinif_id",sinif_Id}

            };

            if(Id != 0)
            {
                kayit.Add(new ArrayList() { "ogrenci_id", Id });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu( "öğrenci güncelleme");
                else
                    islemler.MesajKutu(2, "öğrenci güncelleme");
                return;
            }
            if (islemler.Ekle(tablo, kayit))
                islemler.MesajKutu(tablo+" ekleme");
            else
                islemler.MesajKutu(2, tablo + " ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(tablo, Id);
        }
    }
}
