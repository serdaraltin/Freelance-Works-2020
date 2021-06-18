using System;
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
                stLb_Durum.Text = "Bağlantı Durumu : Tamam";
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
            Form_Hakkinda hakkinda = new Form_Hakkinda();
            hakkinda.ShowDialog();
        }

        private void btn_OgrenciIsl_Click(object sender, EventArgs e)
        {
            Form_OgrenciIslem form = new Form_OgrenciIslem();
            form.ShowDialog();
        }

        private void btn_VeliIsl_Click(object sender, EventArgs e)
        {
            Form_VeliIslem form = new Form_VeliIslem();
            form.ShowDialog();
        }

        private void btn_PersonelIsl_Click(object sender, EventArgs e)
        {
            Form_PersonelIslem form = new Form_PersonelIslem();
            form.ShowDialog();

        }

        private void btn_OdemeIsl_Click(object sender, EventArgs e)
        {
            Form_OdemeIslem form = new Form_OdemeIslem();
            form.ShowDialog();

        }

        private void btn_SinifIsl_Click(object sender, EventArgs e)
        {
            Form_SinifIslem form = new Form_SinifIslem();
            form.ShowDialog();

        }

        private void btn_DersIsl_Click(object sender, EventArgs e)
        {
            Form_DersIslem form = new Form_DersIslem();
            form.ShowDialog();

        }
    }
}
