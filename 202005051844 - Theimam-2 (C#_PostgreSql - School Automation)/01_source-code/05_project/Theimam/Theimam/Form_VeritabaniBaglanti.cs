using System;
using System.Windows.Forms;
using Npgsql;

namespace Theimam
{
    public partial class Form_VeritabaniBaglanti : Form
    {
        public Form_VeritabaniBaglanti()
        {
            InitializeComponent();
        }
        private bool Test()
        {
            NpgsqlConnection baglanti = new NpgsqlConnection("Server=" + txtSunucu.Text + "; Port=" + txtPort.Text +
         "; Database=" + txtVeritabani.Text + "; User Id=" + txtKullanici.Text + "; Password=" + txtParola.Text + ";");

            try
            {
                baglanti.Open();
                baglanti.Close();
                return true;
            }
            catch
            {
                baglanti.Close();
                return false;
            }
        }
        private void Form_VeritabaniBaglanti_Load(object sender, EventArgs e)
        {
            txtSunucu.Text = Ayarlar.Default.sunucu;
            txtPort.Text = Ayarlar.Default.port;
            txtKullanici.Text = Ayarlar.Default.kullanici;
            txtParola.Text = Ayarlar.Default.parola;
            txtVeritabani.Text = Ayarlar.Default.veritabani;
        }

        private void btnTest_Click(object sender, EventArgs e)
        {

            foreach (Control item in this.Controls)
            {
                if (item is TextBox && ((TextBox)item).Text == "")
                {
                    MessageBox.Show("Gerekli alanları doldurunuz !", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            if (Test())
            {
                MessageBox.Show("Bağlantı testi başarılı.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            MessageBox.Show("Bağlantı testi başarısız.", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
        private void btnKaydet_Click(object sender, EventArgs e)
        {
            if (!Test())
            {
                MessageBox.Show("Bağlantı testi başarısız.", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            Ayarlar.Default.sunucu = txtSunucu.Text;
            Ayarlar.Default.port = txtPort.Text;
            Ayarlar.Default.kullanici = txtKullanici.Text ;
            Ayarlar.Default.parola = txtParola.Text ;
            Ayarlar.Default.veritabani = txtVeritabani.Text;
            Ayarlar.Default.Save();
            MessageBox.Show("Program yeniden başlatılacak...", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Application.Restart();
        }
    }
}
