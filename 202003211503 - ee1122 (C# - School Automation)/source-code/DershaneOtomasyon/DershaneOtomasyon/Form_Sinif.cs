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
    public partial class Form_Sinif : Form
    {
        int Id = 0;
        public Form_Sinif()
        {
            InitializeComponent();
        }
        public Form_Sinif(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "sinif";
        private void Form_Sinif_Load(object sender, EventArgs e)
        {
            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                txt_Ad.Text = veriler[1].ToString();
                txt_Blok.Text = veriler[2].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ad",txt_Ad.Text},
                new ArrayList(){"blok",txt_Blok.Text}
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
