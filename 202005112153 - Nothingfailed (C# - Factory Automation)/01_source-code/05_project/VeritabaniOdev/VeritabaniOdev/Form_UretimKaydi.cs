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
    public partial class Form_UretimKaydi : Form
    {
        public Form_UretimKaydi()
        {
            InitializeComponent();
        }
  
        OleDbConnection baglanti = new OleDbConnection(@"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\odev\veritabani.mdb");

        int UrunID = 0, CalisanID = 0, MakineID = 0;
        private void btnYeniUrunEkle_Click(object sender, EventArgs e)
        {
            Form_UrunKaydi urunKaydi = new Form_UrunKaydi();
            urunKaydi.ShowDialog();
        }

        private void btnYeniCalisanEkle_Click(object sender, EventArgs e)
        {
            Form_CalisanKaydi calisanKaydi = new Form_CalisanKaydi();
            calisanKaydi.ShowDialog();
        }

        private void btnYeniMakineEkle_Click(object sender, EventArgs e)
        {
            Form_MakineKaydi makineKaydi = new Form_MakineKaydi();
            makineKaydi.ShowDialog();
        }

        private void Listele()
        {
            baglanti.Open();
            OleDbCommand komut = new OleDbCommand("Select * From tbl_urun", baglanti);
            OleDbDataAdapter adaptor = new OleDbDataAdapter(komut);
            DataTable urun = new DataTable();
            adaptor.Fill(urun);
            dgUrun.DataSource = urun;

            OleDbCommand komut2 = new OleDbCommand("Select * From tbl_calisan", baglanti);
            OleDbDataAdapter adaptor2 = new OleDbDataAdapter(komut2);
            DataTable calisan = new DataTable();
            adaptor2.Fill(calisan);
            dgCalisan.DataSource = calisan;

            OleDbCommand komut3 = new OleDbCommand("Select * From tbl_makine", baglanti);
            OleDbDataAdapter adaptor3 = new OleDbDataAdapter(komut3);
            DataTable makine = new DataTable();
            adaptor3.Fill(makine);
            dgMakine.DataSource = makine;

            OleDbCommand komut4 = new OleDbCommand("Select * From tbl_uretim", baglanti);
            OleDbDataAdapter adaptor4 = new OleDbDataAdapter(komut4);
            DataTable uretim = new DataTable();
            adaptor4.Fill(uretim);
            dgUretimKaydi.DataSource = uretim;

            baglanti.Close();
        }
        private void Form_UretimKaydi_Load(object sender, EventArgs e)
        {
            Listele();
        }
        private void btnYeniUretimEkle_Click(object sender, EventArgs e)
        {
            try
            {
                baglanti.Open();
                OleDbCommand komut = new OleDbCommand("Insert Into tbl_uretim (UrunID,CalisanID,MakineID,UretimAdet,UretimTarih) Values("+UrunID+","+CalisanID+","+MakineID+","+Convert.ToInt32(ndUretimAdet.Value)+",'"+dtUretimTarih.Value.ToShortDateString()+"')", baglanti);
                komut.ExecuteNonQuery();
                baglanti.Close();
                MessageBox.Show("Üretim kaydı eklendi");
                Listele();
            }
            catch (Exception hata)
            {
                MessageBox.Show(hata.Message.ToString());
            }
        }

        private void dgUrun_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                UrunID = Convert.ToInt32(dgUrun.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dgUretimKaydi_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                int urunId = Convert.ToInt32(dgUretimKaydi.Rows[e.RowIndex].Cells[1].Value);
                int calisanId = Convert.ToInt32(dgUretimKaydi.Rows[e.RowIndex].Cells[2].Value);
                int makineId = Convert.ToInt32(dgUretimKaydi.Rows[e.RowIndex].Cells[3].Value);

                baglanti.Open();
                OleDbCommand komut = new OleDbCommand("Select * From tbl_urun where Id=" + urunId, baglanti);
                OleDbDataReader oku = komut.ExecuteReader();
                if (oku.Read()) 
                    txtUrunAd.Text = oku["UrunAd"].ToString();
                oku.Close();
          

           
                OleDbCommand komut2 = new OleDbCommand("Select * From tbl_calisan where Id=" + calisanId, baglanti);
                OleDbDataReader oku2 = komut2.ExecuteReader();
                if (oku2.Read())
                {
                    txtCalisanAdi.Text = oku2["CalisanAd"].ToString();
                    txtCalisanSoyadi.Text = oku2["CalisanSoyad"].ToString();
                }
                oku2.Close();
        

                OleDbCommand komut3 = new OleDbCommand("Select * From tbl_makine where Id=" + makineId, baglanti);
                OleDbDataReader oku3 = komut3.ExecuteReader();
                if (oku3.Read())
                    txtMakineAd.Text = oku3["MakineAd"].ToString();
                oku3.Close();
                baglanti.Close();

                txtUretimAdet.Text = dgUretimKaydi.Rows[e.RowIndex].Cells[4].Value.ToString();
                txtUretimTarih.Text = dgUretimKaydi.Rows[e.RowIndex].Cells[5].Value.ToString();
               
            }
            catch { }
        }

        private void dgCalisan_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                CalisanID = Convert.ToInt32(dgCalisan.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dgMakine_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                MakineID = Convert.ToInt32(dgMakine.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        

    }
}
