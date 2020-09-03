using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_AnaPencere : Form
    {
        int YoneticiId = 0;
        public Form_AnaPencere()
        {
            InitializeComponent();
        }
        public Form_AnaPencere(int Yoneciti_Id)
        {
            InitializeComponent();
            YoneticiId = Yoneciti_Id;
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();
        int SiparisId = 0, UrunId = 0, MusteriId=0,OdemeId=0;
        private void yenidenBaşlatToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }
        private void kapatToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void parolaDeğiştirToolStripMenuItem_Click(object sender, EventArgs e)
        {

            Form_YoneticiEkle yon = new Form_YoneticiEkle(YoneticiId);
            yon.ShowDialog();
        }
        private void yöneticiEkleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form_YoneticiEkle yon = new Form_YoneticiEkle();
            yon.ShowDialog();
        }

        private void Listele_Siparisler()
        {
            dg_Siparisler.DataSource = veritabani.Siparisler().Tables[0];
        }
        private void Listele_Urunler()
        {
            dg_Urunler.DataSource = veritabani.Urunler().Tables[0];
        }
        private void Listele_Odemeler()
        {
            dg_Odemeler.DataSource = veritabani.Odemeler().Tables[0];
        }
        private void Listele_Musteriler()
        {
            dg_Musteriler.DataSource = veritabani.Musteriler().Tables[0];
        }
        private void Form_AnaPencere_Load(object sender, EventArgs e)
        {
            stLb_KullaniciAd.Text = veritabani.YoneticiBilgi(YoneticiId)[0];
            Listele_Siparisler();
            Listele_Urunler();
            Listele_Odemeler();
            Listele_Musteriler();
            
        }

        private void dg_Siparisler_DoubleClick(object sender, EventArgs e)
        {
            Form_Siparis siparis = new Form_Siparis(true,SiparisId);
            siparis.ShowDialog();
        }

        private void dg_Musteriler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                MusteriId = Convert.ToInt32(dg_Musteriler.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dg_Urunler_DoubleClick(object sender, EventArgs e)
        {
            Form_Urun urun = new Form_Urun(UrunId);
            urun.ShowDialog();
        }

        private void dg_Odemeler_DoubleClick(object sender, EventArgs e)
        {
            Form_Odeme odeme = new Form_Odeme(true,OdemeId);
            odeme.ShowDialog();
        }

        private void dg_Musteriler_DoubleClick(object sender, EventArgs e)
        {
            Form_Musteri musteri = new Form_Musteri(MusteriId);
            musteri.ShowDialog();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            stLb_Saat.Text = DateTime.Now.ToLongTimeString();
        }

        private void btn_UrunEkle_Click(object sender, EventArgs e)
        {
            Form_Urun urun = new Form_Urun();
            urun.ShowDialog();
        }

        private void btn_SiparisEkle_Click(object sender, EventArgs e)
        {
            if (MusteriId != 0)
            {
                Form_Siparis siparis = new Form_Siparis(MusteriId);
                siparis.ShowDialog();
            }
            else
            {
                MessageBox.Show("Müşteri seçin !", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void btn_OdemeEkle_Click(object sender, EventArgs e)
        {
            if (MusteriId != 0)
            {
                Form_Odeme pdeme = new Form_Odeme(MusteriId);
                pdeme.ShowDialog();
            }
            else
            {
                MessageBox.Show("Müşteri seçin !", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        private void btn_MusteriEkle_Click(object sender, EventArgs e)
        {
            Form_Musteri musteri = new Form_Musteri();
            musteri.ShowDialog();
        }

        private void btn_FirmaEkle_Click(object sender, EventArgs e)
        {
            Form_Firma firma = new Form_Firma();
            firma.ShowDialog();
        }

        private void btn_ToptanciEkle_Click(object sender, EventArgs e)
        {
            Form_Toptanci toptanci = new Form_Toptanci();
            toptanci.ShowDialog();
        }

        private void btn_Toptancilar_Click(object sender, EventArgs e)
        {
            Form_Toptancilar toptancilar = new Form_Toptancilar();
            toptancilar.ShowDialog();
        }

        private void btn_Firmalar_Click(object sender, EventArgs e)
        {
            Form_Firmalar firmalar = new Form_Firmalar();
            firmalar.ShowDialog();
        }

        private void hakkındaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form_Hakkinda hakkinda = new Form_Hakkinda();
            hakkinda.ShowDialog();
        }

        private void Form_AnaPencere_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void dg_Siparisler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                SiparisId = Convert.ToInt32(dg_Siparisler.Rows[e.RowIndex].Cells[0].Value);

            }
            catch { }
        }
        private void dg_Urunler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                UrunId = Convert.ToInt32(dg_Urunler.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }
        private void dg_Odemeler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                OdemeId = Convert.ToInt32(dg_Odemeler.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }
    }
}
