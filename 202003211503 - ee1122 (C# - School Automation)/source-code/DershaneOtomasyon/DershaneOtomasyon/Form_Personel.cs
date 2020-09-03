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
    public partial class Form_Personel : Form
    {
        int Id = 0;
        public Form_Personel()
        {
            InitializeComponent();
        }
        public Form_Personel(int Personel_Id)
        {
            InitializeComponent();
            Id = Personel_Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "personel";
        private void Form_Personel_Load(object sender, EventArgs e)
        {
            cb_Cinsiyet.SelectedIndex = 0;
            cb_Dal.SelectedIndex = 0;
            cb_Bolum.SelectedIndex = 2;

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);

                txt_TcNo.Text = veriler[1].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[2].ToString();
                txt_Soyad.Text = veriler[3].ToString();
                cb_Cinsiyet.Text = veriler[4].ToString();
                txt_Telefon.Text = veriler[5].ToString();
                txt_Adres.Text = veriler[6].ToString();
                cb_Dal.Text = veriler[7].ToString();
                cb_Bolum.Text = veriler[8].ToString();
                txt_Maas.Text = veriler[9].ToString();

            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"cinsiyet",cb_Cinsiyet.Text},
                new ArrayList(){"telefon",txt_Telefon.Text},
                new ArrayList(){"adres",txt_Adres.Text},
                new ArrayList(){"dal",cb_Dal.Text},
                new ArrayList(){"bolum",cb_Bolum.Text},
                new ArrayList(){"maas",Convert.ToInt32(txt_Maas.Text)},
            };

            if (Id != 0)
            {
                kayit.Add(new ArrayList() { "Id", Id });
                if (islemler.Guncelle(tablo, kayit))
                    islemler.MesajKutu("basarili", tablo+" güncelleme");
                else
                    islemler.MesajKutu("hata", tablo+" güncelleme");
                return;
            }
            if (islemler.Ekle(tablo, kayit))
                islemler.MesajKutu("basarili", tablo+" ekleme");
            else
                islemler.MesajKutu("hata", tablo + " ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(this, "personel", Id);
        }
    }
}
