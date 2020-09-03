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
    public partial class Form_Ogrenci : Form
    {
        int OgrenciId = 0;
        public Form_Ogrenci()
        {
            InitializeComponent();
        }
        public Form_Ogrenci(int Ogrenci_Id)
        {
            InitializeComponent();
            OgrenciId = Ogrenci_Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        private void Form_Ogrenci_Load(object sender, EventArgs e)
        {
            ArrayList siniflar = islemler.Donustur(islemler.Kayitlar("sinif"));
            foreach (string[] item in siniflar)
                cb_Sinif.Items.Add(item[1]);
            cb_Sinif.SelectedIndex = 0;
            cb_Cinsiyet.SelectedIndex = 0;


            if (OgrenciId != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir("ogrenci", OgrenciId);

                cb_Sinif.Text = veriler[1].ToString();
                txt_TcNo.Text = veriler[2].ToString(); txt_TcNo.ReadOnly = true;
                txt_Ad.Text = veriler[3].ToString();
                txt_Soyad.Text = veriler[4].ToString();
                cb_Cinsiyet.Text = veriler[5].ToString();
                txt_Telefon.Text = veriler[6].ToString();
                txt_Bolum.Text = veriler[7].ToString();
                txt_Dal.Text = veriler[8].ToString();
                txt_Adres.Text = veriler[9].ToString();

            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {

            int sinif_Id = Convert.ToInt32(islemler.Getir("sinif", cb_Sinif.Text)[0]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"sinif_Id",sinif_Id},
                new ArrayList(){"tcNo",txt_TcNo.Text},
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"soyad",txt_Soyad.Text},
                new ArrayList(){"cinsiyet",cb_Cinsiyet.Text},
                new ArrayList(){"telefon",txt_Telefon.Text},
                new ArrayList(){"bolum",txt_Bolum.Text},
                new ArrayList(){"dal",txt_Dal.Text},
                new ArrayList(){"adres",txt_Adres.Text},

            };

            if(OgrenciId != 0)
            {
                kayit.Add(new ArrayList() { "Id", OgrenciId });
                if (islemler.Guncelle("ogrenci", kayit))
                    islemler.MesajKutu("basarili", "öğrenci güncelleme");
                else
                    islemler.MesajKutu("hata", "öğrenci güncelleme");
                return;
            }
            if (islemler.Ekle("ogrenci", kayit))
                islemler.MesajKutu("basarili", "öğrenci ekleme");
            else
                islemler.MesajKutu("hata", "öğrenci ekleme");

            islemler.Temizle(this);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            if(islemler.SoruKutu(islemler.Getir("ogrenci",OgrenciId)[3]+ " "+
                islemler.Getir("ogrenci", OgrenciId)[4]+" adlı öğrenciyi silmek"))
            {
                if(islemler.Sil("ogrenci",OgrenciId))
                {
                    islemler.MesajKutu("basarili","silme");
                    this.Close();
                }
                else
                    islemler.MesajKutu("hata","silme");
            }
        }
    }
}
