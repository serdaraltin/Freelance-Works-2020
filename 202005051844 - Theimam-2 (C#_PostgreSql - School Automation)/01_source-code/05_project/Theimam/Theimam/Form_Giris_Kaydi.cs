using System;
using System.Collections;
using System.Collections.Generic;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Giris_Kaydi : Form
    {
        int Id = 0;
        public Form_Giris_Kaydi()
        {
            InitializeComponent();
        }
        public Form_Giris_Kaydi(int _Id)
        {
            InitializeComponent();
            Id = _Id;
        }
        Class_Islemler islemler = new Class_Islemler();
        List<string> Liste = new List<string>();
        string tablo = "giris";
        private void Form_Ders_Load(object sender, EventArgs e)
        {
            if (Id != 0)
            {

                ArrayList veriler = islemler.Getir(tablo, Id);
                txt_Tarih.Text = veriler[1].ToString();
                txt_Tarih.Text = veriler[2].ToString();
            }
        }

       
    }
}
