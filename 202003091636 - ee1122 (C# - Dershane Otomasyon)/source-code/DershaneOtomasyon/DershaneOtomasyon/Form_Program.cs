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
    public partial class Form_Program : Form
    {
        int Id = 0;
        public Form_Program()
        {
            InitializeComponent();
        }
        public Form_Program(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Dersler = new List<string>();
        List<string> Siniflar = new List<string>();
        string tablo = "program";
        private void Form_Program_Load(object sender, EventArgs e)
        {
            cb_Gun.SelectedIndex = 0;
            islemler.CBDoldur(cb_Ders, "ders", 2);
            islemler.CBDoldur(cb_Sinif, "sinif", 1);

            Dersler = islemler.Donustur(islemler.Kayitlar("ders"), 0);
            Siniflar = islemler.Donustur(islemler.Kayitlar("sinif"), 0);

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                islemler.CBSec(cb_Ders, Dersler, Convert.ToInt32(veriler[1]));
                islemler.CBSec(cb_Sinif, Dersler, Convert.ToInt32(veriler[2]));

                cb_Gun.Text = veriler[3].ToString();
                txt_Baslangic.Text = veriler[4].ToString();
                txt_Bitis.Text = veriler[5].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int DersId = Convert.ToInt32(Dersler[cb_Ders.SelectedIndex]);
            int SinifId = Convert.ToInt32(Siniflar[cb_Sinif.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ders_Id",DersId},
                new ArrayList(){"sinif_Id",SinifId},
                new ArrayList(){"gun",cb_Gun.Text},
                new ArrayList(){"baslangic",txt_Baslangic.Text},
                new ArrayList(){"bitis",txt_Bitis.Text},
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
