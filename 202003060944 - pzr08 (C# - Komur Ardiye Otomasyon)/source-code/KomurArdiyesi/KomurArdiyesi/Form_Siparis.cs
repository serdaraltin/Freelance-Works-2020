using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Siparis : Form
    {
        int MusteriId = 0, SiparisId = 0;
        public Form_Siparis()
        {
            InitializeComponent();
        }

        public Form_Siparis(int Musteri_Id)
        {
            InitializeComponent();
            MusteriId = Musteri_Id;
        }
        public Form_Siparis(bool Guncelle, int Siparis_Id)
        {
            InitializeComponent();
            SiparisId = Siparis_Id;
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();

        private void btn_Isle_Click(object sender, EventArgs e)
        {
            if (SiparisId != 0)
            {
                if (veritabani.SiparisGuncelle(SiparisId, MusteriId, (DateTime)dt_SiparisTarih.Value, (DateTime)dt_TeslimatTarih.Value, txt_TeslimatAdres.Text))
                    MessageBox.Show("Sipariş güncellendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                else
                    MessageBox.Show("Sipariş güncellenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (veritabani.SiparisEkle(MusteriId, (DateTime)dt_SiparisTarih.Value, (DateTime)dt_TeslimatTarih.Value, txt_TeslimatAdres.Text))
                MessageBox.Show("Sipariş eklendi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show("Sipariş eklenemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            DialogResult soru = MessageBox.Show("Siparisi silmek istediğinizden emin misiniz ?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (soru == DialogResult.No)
                return;
            if (veritabani.SiparisSil(SiparisId))
            {
                MessageBox.Show("Siparis silindi", "Bilgi", MessageBoxButtons.OK, MessageBoxIcon.Information);
                foreach (Control item in this.Controls)
                {
                    if (item is TextBox)
                        ((TextBox)item).Clear();
                    if (item is MaskedTextBox)
                        ((MaskedTextBox)item).Clear();
                }
                this.Close();
            }
            else
                MessageBox.Show("Müşteri silinemedi !!!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }

        private void btn_SiparisDetay_Click(object sender, EventArgs e)
        {
            Form_Siparisler siparisler = new Form_Siparisler(SiparisId);
            siparisler.ShowDialog();
        }

        private void Form_Siparis_Load(object sender, EventArgs e)
        {
            if(MusteriId == 0)
                MusteriId = Convert.ToInt32(veritabani.SiparisBilgi(SiparisId)[0]);
            txt_Musteri.Text = veritabani.MusteriBilgi(MusteriId)[1] + " " + veritabani.MusteriBilgi(MusteriId)[2];
            if (SiparisId != 0)
            {
                this.Text += "Güncelle";
                btn_Isle.Text = "Güncelle";
                btn_Sil.Visible = true;
                btn_SiparisDetay.Visible = true;
                string[] veriler = veritabani.SiparisBilgi(SiparisId);
                dt_SiparisTarih.Text = veriler[1];
                dt_TeslimatTarih.Text = veriler[2];
                txt_TeslimatAdres.Text = veriler[3];

            }


        }
    }
}
