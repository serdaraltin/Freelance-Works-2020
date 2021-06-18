using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


//ANASAYFA FORM
namespace kutuphane
{
    public partial class frmAnaSayfa : Form
    {
        public frmAnaSayfa()
        {
            InitializeComponent();
        }

        //menü > kitap ekle 
        private void müşteriEkeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kitap ekle penceresinin gösterilmesi
            var frmKitapEkle = new frmKitapEkle();
            frmKitapEkle.Show();

        }

        private void kitapSilToolStripMenuItem_Click(object sender, EventArgs e)
        {
            
        }
        //menü > kitap güncelle
        private void kitapGüncelleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kitap Güncelle penceresinin gösterilmesi
            var frmKitapGuncelle = new frmKitapGuncelle();
            frmKitapGuncelle.Show();
        }

        //menü > müşteri ekle 
        private void müşteriEkleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Müşteri Ekle penceresinin gösterilmesi
            var frmMusteriEkle = new frmOgrenciEkle();
            frmMusteriEkle.Show();
        }

        //menü > müşteri sil 
        private void müşteriSilToolStripMenuItem_Click(object sender, EventArgs e){
            //Müşteri Sil Listele penceresinin gösterilmesi
            var frmMusteriSilListele = new frmOgrenciSilListele();
            frmMusteriSilListele.Show();
        }
        //menü > kitap listele
        private void kitapListeleSilToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kitap Sil Listele penceresinin gösterilmesi
            var frmKitapSilListele = new frmKitapSilListele();
            frmKitapSilListele.Show();
        }

          //menü > müşteri güncelle 
        private void müşteriGüncelleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Müşteri Güncelle penceresinin gösterilmesi
            var frmMusteriGuncelle = new frmOgrenciGuncelle();
            frmMusteriGuncelle.Show();
        }
          //menü > yayinevi ekle
        private void yayıneviEkleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //YayınEvi Ekle penceresinin gösterilmesi
            var frmYayinEviEkle = new frmYayinEviEkle();
            frmYayinEviEkle.Show();
        }
          //menü > yazar ekle
        private void yazareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Yazar Ekle penceresinin gösterilmesi
            var frmYazarEkle = new frmYazarEkle();
            frmYazarEkle.Show();
        }

          //menü > kitap kirala
        private void kitapKiralaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kitap Kirala penceresinin gösterilmesi
            var frmKitapKirala = new frmKitapKirala();
            frmKitapKirala.Show();
        }
          //menü > kiradaki kitaplar 
        private void kiradakiKitaplarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kiradaki Kitaplar penceresinin gösterilmesi
            var frmKiradakiKitaplar = new frmKiradakiKitaplar();
            frmKiradakiKitaplar.Show();
        }

        private void fmrAnaSayfa_Load(object sender, EventArgs e)
        {

        }
          //menü > kitap listesi
        private void kitapListesiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Kitap Listesi penceresinin gösterilmesi
            frmKitapListesi liste = new frmKitapListesi();
            liste.Show();
        }
          //menü > öğrenci listesi
        private void öğrenciListesiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Öğrenci Listesi penceresinin gösterilmesi
            frmOgrenciListesi liste = new frmOgrenciListesi();
            liste.Show();
        }
    }
}
