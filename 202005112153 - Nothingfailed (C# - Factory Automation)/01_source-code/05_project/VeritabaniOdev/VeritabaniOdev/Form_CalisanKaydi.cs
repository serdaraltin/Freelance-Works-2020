using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace VeritabaniOdev
{
    public partial class Form_CalisanKaydi : Form
    {
        public Form_CalisanKaydi()
        {
            InitializeComponent();
        }
        OleDbConnection baglanti = new OleDbConnection(@"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\odev\veritabani.mdb");
        private void btnEkle_Click(object sender, EventArgs e)
        {
            try
            {
                baglanti.Open();
                OleDbCommand komut = new OleDbCommand("Insert Into tbl_calisan (CalisanAd,CalisanSoyad) Values('" + txtCalisanAdi.Text + "','"+txtCalisanSoyadi.Text+"')", baglanti);
                komut.ExecuteNonQuery();
                baglanti.Close();
                MessageBox.Show("Çalışan eklendi");
            }
            catch (Exception hata)
            {
                MessageBox.Show(hata.Message.ToString());
            }
        }
    }
}
