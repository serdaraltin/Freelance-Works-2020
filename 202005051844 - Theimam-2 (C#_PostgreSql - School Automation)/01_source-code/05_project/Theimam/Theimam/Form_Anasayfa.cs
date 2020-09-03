using System;

using System.Drawing;

using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Anasayfa : Form
    {
        public Form_Anasayfa()
        {
            InitializeComponent();
        }
        Class_Islemler islemler = new Class_Islemler();
        private void Form_Anasayfa_Load(object sender, EventArgs e)
        {
            if(islemler.BaglantiTest())
            {
                stLb_Durum.Text = "Bağlantı Durumu : Başarılı";
                stLb_Durum.ForeColor = Color.Green;
            }
            else
            {
                stLb_Durum.Text = "Bağlantı Durumu : Sorun Var";
                stLb_Durum.ForeColor = Color.Red;
            }
        }

        private void kontrolToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form_VeritabaniBaglanti veritabani = new Form_VeritabaniBaglanti();
            veritabani.ShowDialog();
        }

        private void yenidenBaşlatToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }

        private void kapatToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void hakkındaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Hakkinda hakkinda = new Hakkinda();
            hakkinda.ShowDialog();
        }

        private void btn_OgrenciIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("ogrenci");
            form.ShowDialog();
        }

        private void btn_VeliIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("veli");
            form.ShowDialog();
        }

        private void btn_PersonelIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("personel");
            form.ShowDialog();

        }

        private void btn_OdemeIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("yonetim");
            form.ShowDialog();

        }

        private void btn_SinifIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("sinif");
            form.ShowDialog();
        }

        private void btn_DersIsl_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("ders");
            form.ShowDialog();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("giris");
            form.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("yonetim_tur");
            form.ShowDialog();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("kullanici");
            form.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("bolum");
            form.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("ogretmen");
            form.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("egitmen_alan");
            form.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("personel_alan");
            form.ShowDialog();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("nobet");
            form.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form = new Form_Islem("aile_birligi");
            form.ShowDialog();
        }
    }
}
