using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Toptanci : Form
    {
        int ToptanciId = 0;
        public Form_Toptanci()
        {
            InitializeComponent();
        }
        public Form_Toptanci(int Toptanci_Id)
        {
            InitializeComponent();
            ToptanciId = Toptanci_Id;
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();

        public void Firma_Listele()
        {

            cb_Firma.DataSource = veritabani.FirmalarAd();
            cb_Firma.SelectedIndex = 0;
        }
        private void Form_Toptanci_Load(object sender, EventArgs e)
        {
            Firma_Listele();
            if(ToptanciId != 0)
            {
                this.Text += "Güncelle";
                btn_Isle.Text = "Güncelle";
                btn_Sil.Visible = true;

                string[] veriler = veritabani.ToptanciBilgi(ToptanciId);

                cb_Firma.Text = veriler[0];
                txt_Telefon.Text = veriler[1];
                txt_Mail.Text = veriler[2];
                txt_Adres.Text = veriler[3];

            }
        }

        private void btn_Isle_Click(object sender, EventArgs e)
        {
            
            int FId = Convert.ToInt32(veritabani.FirmaBilgi(cb_Firma.Text)[0]);


            if(ToptanciId != 0)
            {
                if (veritabani.ToptanciGuncelle(ToptanciId,FId, txt_Telefon.Text, txt_Mail.Text, txt_Adres.Text))
                    MessageBox.Show("Toptantı güncellendi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    MessageBox.Show("Toptancı güncellenemedi !!!", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (veritabani.ToptanciEkle(FId, txt_Telefon.Text, txt_Mail.Text, txt_Adres.Text))
                MessageBox.Show("Toptantı eklendi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show("Toptancı eklenemedi !!!", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Toptancıyı silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (veritabani.ToptanciSil(ToptanciId))
            {
                MessageBox.Show("Toptancı silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                    if (item is MaskedTextBox)
                        ((MaskedTextBox)item).Clear();
                }
                cb_Firma.SelectedIndex = 0;
                this.Close();
            }
            else
                MessageBox.Show("Toptancı silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }
    }

}
