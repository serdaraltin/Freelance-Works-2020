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
    public partial class Form_Ders : Form
    {
        int Id = 0;
        public Form_Ders()
        {
            InitializeComponent();
        }
        public Form_Ders(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "ders";
        private void Form_Ders_Load(object sender, EventArgs e)
        {
            islemler.CBDoldur(cb_Personel, "personel", new int[] { 2, 3 });
            Liste = islemler.Donustur(islemler.Kayitlar("personel"), 0);

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);
                islemler.CBSec(cb_Personel, Liste, Convert.ToInt32(veriler[1]));
                txt_Ad.Text = veriler[2].ToString();
            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int PersonelId = Convert.ToInt32(Liste[cb_Personel.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"personel_Id",PersonelId},
                new ArrayList(){"ad",txt_Ad.Text},
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
