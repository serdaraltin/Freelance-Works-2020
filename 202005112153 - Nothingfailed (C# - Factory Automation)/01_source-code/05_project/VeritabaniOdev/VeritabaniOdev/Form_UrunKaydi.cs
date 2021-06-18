using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;

namespace VeritabaniOdev
{
    public partial class Form_UrunKaydi : Form
    {
        public Form_UrunKaydi()
        {
            InitializeComponent();
        }
        OleDbConnection baglanti = new OleDbConnection(@"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\odev\veritabani.mdb");
        private void btnEkle_Click(object sender, EventArgs e)
        {
            try
            {
                baglanti.Open();
                OleDbCommand komut = new OleDbCommand("Insert Into tbl_urun (UrunAd) Values('" + txtUrunAd.Text + "')", baglanti);
                komut.ExecuteNonQuery();
                baglanti.Close();
                MessageBox.Show("Ürün eklendi");
            }
            catch(Exception hata)
            {
                MessageBox.Show(hata.Message.ToString());
            }
        }

    }
}
