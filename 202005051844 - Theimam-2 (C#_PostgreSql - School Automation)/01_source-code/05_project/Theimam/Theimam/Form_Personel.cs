using System;
using System.Collections;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Personel : Form
    {
        int Id = 0;
        public Form_Personel()
        {
            InitializeComponent();
        }
        public Form_Personel(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "personel";
        private void Form_Ogrenci_Load(object sender, EventArgs e)
        {
            ArrayList alanlar = islemler.Donustur(islemler.Kayitlar("personel_alan"));
            foreach (string[] item in alanlar)
                cb_Alan.Items.Add(item[1]);

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
                cb_Alan.Text = islemler.Getir("personel_alan", Convert.ToInt32(veriler[7]))[1].ToString();

            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {

            int alan_id = Convert.ToInt32(islemler.Getir("personel_alan", cb_Alan.Text)[0]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"telno",txt_Telefon.Text},
                new ArrayList(){"eposta",txt_Eposta.Text},
                new ArrayList(){"adres",txt_Adres.Text},
                new ArrayList(){"personel_alan_id",alan_id}
            };
            if (Id != 0)
            {
                kayit.Add(new ArrayList() { "personel_id", Id });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu(tablo + " güncelleme");
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

            islemler.Sil("ogrenci", Id);
        }
    }
}
