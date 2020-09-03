using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Urun : Form
    {
        int UrunId = 0;
        public Form_Urun()
        {
            InitializeComponent();
        }
        public Form_Urun(int Urun_Id)
        {
            InitializeComponent();
            UrunId = Urun_Id;
        }

        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();
        private void txt_Fiyat_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 44)
                e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void txt_Miktar_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void Form_Urun_Load(object sender, EventArgs e)
        {
        
            if (UrunId != 0)
            {
                this.Text += "Ürün Güncelle";
                btn_Ekle.Text = "Güncelle";
                btn_Sil.Visible = true;
                txt_Barkod.ReadOnly = true;

                string[] veriler = veritabani.UrunBilgi(UrunId);
                txt_Barkod.Text = veriler[0];
                txt_UrunAd.Text = veriler[1];
                cb_Birim.Text = veriler[2];
                txt_Miktar.Text = veriler[3];
                txt_Fiyat.Text = veriler[4];
                dt_GirisTarih.Text = veriler[5];
                dt_CikisTarih.Text = veriler[6];
            }

        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
          
            if (UrunId != 0)
            {
                if (veritabani.UrunGuncelle(UrunId,txt_Barkod.Text,
                txt_UrunAd.Text, cb_Birim.Text, Convert.ToInt32(txt_Miktar.Text),
                float.Parse(txt_Fiyat.Text), (DateTime)dt_GirisTarih.Value, (DateTime)dt_CikisTarih.Value))
                {
                    MessageBox.Show("Ürün güncellendi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show("Ürün güncellenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                return;
            }
            if (veritabani.UrunEkle(txt_Barkod.Text,
                txt_UrunAd.Text, cb_Birim.Text,Convert.ToInt32(txt_Miktar.Text),
                float.Parse(txt_Fiyat.Text), (DateTime)dt_GirisTarih.Value, (DateTime)dt_CikisTarih.Value))
            {
                MessageBox.Show("Ürün eklendi.", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Ürün eklenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Ürünü silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (veritabani.UrunSil(UrunId))
            {
                MessageBox.Show("Ürün silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                    if (item is MaskedTextBox)
                        ((MaskedTextBox)item).Clear();
                }
                cb_Birim.SelectedIndex = 0;
                this.Close();
            }
            else
                MessageBox.Show("Ürün silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }
    }
}
