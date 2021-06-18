using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmAnaSayfa : Form
    {
        public frmAnaSayfa()
        {
            InitializeComponent();
        }

        private void müşteriEkeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmKitapEkle = new frmKitapEkle();
            frmKitapEkle.Show();

        }

        private void kitapSilToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }

        private void kitapGüncelleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmKitapGuncelle = new frmKitapGuncelle();
            frmKitapGuncelle.Show();
        }

        private void müşteriEkleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmMusteriEkle = new frmOgrenciEkle();
            frmMusteriEkle.Show();
        }

        private void müşteriSilToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmMusteriSilListele = new frmOgrenciSilListele();
            frmMusteriSilListele.Show();
        }

        private void kitapListeleSilToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmKitapSilListele = new frmKitapSilListele();
            frmKitapSilListele.Show();
        }

        private void müşteriGüncelleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmMusteriGuncelle = new frmOgrenciGuncelle();
            frmMusteriGuncelle.Show();
        }

        private void yayıneviEkleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmYayinEviEkle = new frmYayinEviEkle();
            frmYayinEviEkle.Show();
        }

        private void yazareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmYazarEkle = new frmYazarEkle();
            frmYazarEkle.Show();
        }

      

        
        private void kitapKiralaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmKitapKirala = new frmKitapKirala();
            frmKitapKirala.Show();
        }

        private void kiradakiKitaplarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            var frmKiradakiKitaplar = new frmKiradakiKitaplar();
            frmKiradakiKitaplar.Show();
        }

        private void fmrAnaSayfa_Load(object sender, EventArgs e)
        {

        }

        private void kitapListesiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmKitapListesi liste = new frmKitapListesi();
            liste.Show();
        }

        private void öğrenciListesiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmOgrenciListesi liste = new frmOgrenciListesi();
            liste.Show();
        }
    }
}
