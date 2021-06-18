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
    public partial class Form_Odeme : Form
    {
        int Id = 0;
        public Form_Odeme()
        {
            InitializeComponent();
        }
        public Form_Odeme(int Odeme_Id)
        {
            InitializeComponent();
            Id = Odeme_Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Ogrenciler = new List<string>();
        string tablo = "odeme";
        private void Form_Odeme_Load(object sender, EventArgs e)
        {
            islemler.CBDoldur(cb_Ogrenci, "ogrenci", new int[] { 3, 4 });
            Ogrenciler = islemler.Donustur(islemler.Kayitlar("ogrenci"), 0);

            for (int i = 2020; i < 2050; i++)
                cb_Yıl.Items.Add(i.ToString());
            cb_Yıl.SelectedIndex = 0;

            if (Id != 0)
            {
                this.Text += " Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;

                ArrayList veriler = islemler.Getir(tablo, Id);

                islemler.CBSec(cb_Ogrenci, Ogrenciler, Convert.ToInt32(veriler[1]));

                cb_Yıl.Text = veriler[2].ToString();
                txt_Ucret.Text = veriler[3].ToString();

            }
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            int OgrenciId = Convert.ToInt32(Ogrenciler[cb_Ogrenci.SelectedIndex]);

            ArrayList kayit = new ArrayList()
            {
                new ArrayList(){"ogrenci_Id",OgrenciId},
                new ArrayList(){"yil",Convert.ToInt32(cb_Yıl.Text)},
                new ArrayList(){"ucret",Convert.ToInt32(txt_Ucret.Text)},
            };

            if (Id != 0)
            {
                islemler.Guncelle(this, tablo, kayit, Id); return;
            }
            islemler.Ekle(this, tablo, kayit);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            islemler.Sil(this, tablo, Id);
        }
    }
}
