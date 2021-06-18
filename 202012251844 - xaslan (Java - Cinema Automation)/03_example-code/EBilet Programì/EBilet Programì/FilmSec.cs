using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace EBilet_Programı
{
    public partial class FilmSec : Form
    {

        public FilmSec()
        {          
            InitializeComponent();
            
        }

        FilmKoltukSec flmkoltuksec = new FilmKoltukSec();
        public bool _Onay = false;
        public string _FilmAdi = "";

        private void btnCikis_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void FormFilmSec_Load(object sender, EventArgs e)
        {
            FilmSecIsimKaydirma.Enabled = true;
        }

        private void AnaFormIsimKaydirma_Tick(object sender, EventArgs e)
        {
            label1.Text = label1.Text.Substring(1) + label1.Text.Substring(0,1);
        }

        private void btn127Saat_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("127 Saat Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                _Onay = true;
                _FilmAdi = "127 Saat";
                flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                flmkoltuksec.grpBoxMenu.Enabled = false;
                this.Close();

                
            }
        }

        private void btnFetih1453_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("Fetih 1453 Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                
                _FilmAdi = "Fetih 1453 ";
                 _Onay = true;
                 flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                 flmkoltuksec.grpBoxMenu.Enabled = false;
            this.Close();
            }
           
        }

        private void btnHijacked_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("Hi Jacked Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                _FilmAdi = "Hi Jacked ";
                _Onay = true;
                flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                flmkoltuksec.grpBoxMenu.Enabled = false;
                this.Close();
                
            }
        }

        private void btnJohnnyEng_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("Johnny English Reborn Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                _FilmAdi = "Johnny English Reborn";
                _Onay = true;
                flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                flmkoltuksec.grpBoxMenu.Enabled = false;
                this.Close();
            }
        }

        private void btnKillSwitch_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("Kill Switch Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                _FilmAdi = "Kill Switch";
                _Onay = true;
                flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                flmkoltuksec.grpBoxMenu.Enabled = false;
                this.Close();  
            }
        }

        private void btnSherlock_Click(object sender, EventArgs e)
        {
            DialogResult cevap;
            cevap = MessageBox.Show("Sherlock Holmes A Game Of Shadows Filmine Bilet Almak İstiyor musunuz?", "Uyarı", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                _FilmAdi = "Sherlock Holmes A Game Of Shadows";
                _Onay = true;
                flmkoltuksec.grpBoxKoltuklar.Enabled = true;
                flmkoltuksec.grpBoxMenu.Enabled = false;
                this.Close(); 
            }
        }
    }
}