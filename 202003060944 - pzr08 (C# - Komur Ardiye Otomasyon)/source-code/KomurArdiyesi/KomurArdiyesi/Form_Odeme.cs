using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Odeme : Form
    {
        int MusteriId = 0, OdemeId = 0;
        public Form_Odeme()
        {
            InitializeComponent();
        }
        public Form_Odeme(int Musteri_Id)
        {
            InitializeComponent();
            MusteriId = Musteri_Id;
        }
        public Form_Odeme(bool Guncelle, int Odeme_Id)
        {
            InitializeComponent();
            
            OdemeId = Odeme_Id;
        }

        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();

        private void btn_Isle_Click(object sender, EventArgs e)
        {
            bool kontrol = true;
            foreach (Control item in this.Controls)
            {
                if (item is TextBox && ((TextBox)item).Text == "")
                    kontrol = false;
                if (item is MaskedTextBox && ((MaskedTextBox)item).Text == "")
                    kontrol = false;
            }
            if (cb_OdemeYontem.Text == "")
                kontrol = false;
            if (!kontrol)
            {
                MessageBox.Show("Lütfen gerekli alanları doldurunuz !!!", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (OdemeId != 0)
                if (veritabani.OdemeGuncelle(OdemeId, MusteriId, float.Parse(txt_Tutar.Text),
        (DateTime)dt_SiparisTarih.Value, (DateTime)dt_OdemeTarih.Value, txt_FaturaNo.Text,
        cb_OdemeYontem.Text, (DateTime)dt_GirisTarih.Value, (DateTime)dt_CikisTarih.Value))
                {
                    MessageBox.Show("Ödeme güncellendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
                else
                {
                    MessageBox.Show("Ödeme güncellenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            if (veritabani.OdemeEkle(MusteriId, float.Parse(txt_Tutar.Text),
        (DateTime)dt_SiparisTarih.Value, (DateTime)dt_OdemeTarih.Value, txt_FaturaNo.Text,
        cb_OdemeYontem.Text, (DateTime)dt_GirisTarih.Value, (DateTime)dt_CikisTarih.Value))
                MessageBox.Show("Ödeme işlendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show("Ödeme işlenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void txt_Tutar_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != 44)
                e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Ödemeyi silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (veritabani.OdemeSil(OdemeId))
            {
                MessageBox.Show("Ödeme silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                    if (item is MaskedTextBox)
                        ((MaskedTextBox)item).Clear();
                }
                cb_OdemeYontem.SelectedIndex = 0;
                this.Close();
            }
            else
                MessageBox.Show("Ödeme silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void Form_Odeme_Load(object sender, EventArgs e)
        {
            if(MusteriId == 0)
                MusteriId = Convert.ToInt32(veritabani.OdemeBilgi(OdemeId)[0]);

            txt_Musteri.Text = veritabani.MusteriBilgi(MusteriId)[1] + " " + veritabani.MusteriBilgi(MusteriId)[2];
            if (OdemeId != 0)
            {
                this.Text = "Ödeme Güncelle";
                btn_Sil.Visible = true;
                btn_Isle.Text = "Güncelle";

                string[] veriler = veritabani.OdemeBilgi(OdemeId);
                txt_Tutar.Text = veriler[1].Substring(0, veriler[1].IndexOf(",") + 3);
                dt_SiparisTarih.Text = veriler[2];
                dt_OdemeTarih.Text = veriler[3];
                txt_FaturaNo.Text = veriler[4];
                cb_OdemeYontem.Text = veriler[5];
                dt_GirisTarih.Text = veriler[6];
                dt_CikisTarih.Text = veriler[7];
            }


        }
    }
}
