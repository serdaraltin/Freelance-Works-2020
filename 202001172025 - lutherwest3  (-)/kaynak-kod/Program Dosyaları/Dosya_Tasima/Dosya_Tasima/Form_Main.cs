using System;
using System.IO;
using System.Windows.Forms;

namespace Dosya_Tasima
{
    public partial class Form_Main : Form
    {
        public Form_Main()
        {
            InitializeComponent();
        }

        private void btnDosyaSec_Click(object sender, EventArgs e)
        {
            OpenFileDialog dosyaSec = new OpenFileDialog();
            //OpenFileDialog sınıfından dosyaSec isminde yeni bir nesne oluşturma.
            dosyaSec.Filter = "Mp3 Dosyaları|*.mp3|Wav Dosyaları|*.wav";
            //Dosya filtrelemesi yapma. (Açıklama|isim.uzantı, "*" tüm isim uzayını kapsar)
            dosyaSec.Title = "Ses Dosyası Seçiniz";
            //Oluşturulacak olan pencere başlığının belirlenmesi.
            dosyaSec.FileName = "ses.mp3";
            //Oluşturulacak olan pencere içerisinde örnek dosya ismi belirlenmesi. (ses.mp3 referanstır.)
            dosyaSec.Multiselect = false;
            //Çoklu dosya seçiminin engellenmesi.
           
            if(dosyaSec.ShowDialog() == DialogResult.OK)
            //Dosya seçim penceresinde seçim yapılması işleminin kontrolü. (OK -> seçim yapıldı.)
            {
                txtDosya.Text = dosyaSec.FileName;
                //Seçilen dosyanın konum bilgisi txtDosya nesnesinin metin bölümüne atanması.
            }
        }

        private void btnKonumSec_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog konumSec = new FolderBrowserDialog();
            //FolderBrowserDialog sınıfından konumSec isminde yeni bir nesne üretilmesi.
            konumSec.RootFolder = Environment.SpecialFolder.Desktop;
            //Kök dizini olarak daha önceden belirlenmiş seçeneklerden masaüstü seçilmesi.
            
            if(konumSec.ShowDialog() == DialogResult.OK)
            //Konum seçim penceresinde seöim yapıması işleminin kontrolü. (OK -> seçim yapıldı.)
            {
                txtKonum.Text = konumSec.SelectedPath;
                //Seçilen konum bilgisi txtKonum nesnesinin metin bölümüne atanması.
            }
        }

        private void btnDosyayiTasi_Click(object sender, EventArgs e)
        {
            if(txtDosya.Text == "" || txtKonum.Text == "")
            //txtDosya ve txtKonum nesnelerinden herhangi birinin içerinin boş olması kontrolü.
            {
                MessageBox.Show("Gerekli alanladı doldurunuz.", "UYARI", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                //Uyarı amaçlı mesaj kutusu oluşturma.
                return;
                //Methodun sonlandırılması.
            }
            if(File.Exists(txtDosya.Text) == false)
            {
                MessageBox.Show("Dosya bulunamadı !!!", "HATA", MessageBoxButtons.OK, MessageBoxIcon.Error);
                //Hata amaçlı mesaj kutusu oluşturma.
                return;
                //Methodun sonlandırılması.
            }
            string dosya_adi = txtDosya.Text.Substring(txtDosya.Text.LastIndexOf(@"\")+1);
            //Dosya bilgisinden dosya adı bilgisinin ayıklanması ve bir değişkene atanması.
            try
            {
                File.Move(txtDosya.Text, txtKonum.Text + @"\" + dosya_adi);
                //Dosya taşınma işlemi. (1. parametre dosya konumu, 2. parametre taşınacak konum+dosya adı)
                MessageBox.Show(dosya_adi + " adlı dosya " + txtKonum.Text + " konumuna başarıyla taşındı", "BİLGİ", MessageBoxButtons.OK, MessageBoxIcon.Information);
                //Bilgi amaçlı mesaj kutusu oluşturma.
            }
            catch (Exception hata)
            {
                MessageBox.Show("Dosya taşınamadı!!!\n"+hata.Message.ToString(), "HATA", MessageBoxButtons.OK, MessageBoxIcon.Error);
                //Hata amaçlı mesaj kutusu oluşturma.
            }

        }
    }
}
