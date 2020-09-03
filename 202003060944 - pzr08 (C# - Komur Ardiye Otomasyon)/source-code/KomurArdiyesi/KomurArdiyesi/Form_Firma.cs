using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Firma : Form
    {
        int FirmaId = 0;
        public Form_Firma()
        {
            InitializeComponent();
        }
        public Form_Firma(int Firma_Id)
        {
            InitializeComponent();
            FirmaId = Firma_Id;
        }

        Class_VeritabaniIslemleri Veritabani = new Class_VeritabaniIslemleri();
    
        private void btn_ekle_Click(object sender, EventArgs e)
        {
            
            if (Veritabani.FirmaKontrol(txt_FirmaAd.Text))
            {
                MessageBox.Show("Firma zaten kayıtlı!", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (FirmaId != 0)
            {
                if (Veritabani.FirmaGuncelle(FirmaId,txt_FirmaAd.Text, txt_Mail.Text))
                {
                    MessageBox.Show("Firma güncelleme işlemi başarılı", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
            }
            if (Veritabani.FirmaEkle(txt_FirmaAd.Text, txt_Mail.Text))
            {
                MessageBox.Show("Firma Ekleme işlemi başarılı","Bilgi",MessageBoxButtons.OK,MessageBoxIcon.Information);
                txt_FirmaAd.Clear();
                txt_Mail.Clear();
            }
            return;
        }

        private void Form_Firma_Load(object sender, EventArgs e)
        {
            if(FirmaId != 0)
            {
                txt_FirmaAd.Text = Veritabani.FirmaBilgi(FirmaId)[0];
                txt_Mail.Text = Veritabani.FirmaBilgi(FirmaId)[1];
                btn_ekle.Text = "Güncelle";
                this.Text += "Güncelle";
                btn_Sil.Visible = true;
            }
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Firmayı silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (Veritabani.FirmaSil(FirmaId))
            {
                MessageBox.Show("Firma silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                }            
                this.Close();
            }
            else
                MessageBox.Show("Firma silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
