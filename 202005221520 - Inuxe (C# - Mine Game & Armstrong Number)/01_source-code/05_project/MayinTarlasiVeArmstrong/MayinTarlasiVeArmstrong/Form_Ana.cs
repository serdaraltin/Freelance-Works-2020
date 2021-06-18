using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MayinTarlasiVeArmstrong
{
    public partial class Form_Ana : Form
    {
        public Form_Ana()
        {
            InitializeComponent();
        }
        Form_Onizleme onizleme = new Form_Onizleme();
        int sayac = 0;
        public int[] BombaOlustur(int adet)
        {
            int[] bombalar = new int[adet];
            Random rst = new Random();
            for (int i = 0; i < adet; i++)
            {

                int rastgele = rst.Next(0, 24);
                for (int j = 0; j < adet; j++)
                {
                    if (bombalar[j] == rastgele)
                    {
                        while (bombalar[j] == rastgele)
                        {
                            rastgele = rst.Next(0, 24);
                        }

                    }
                }

                bombalar[i] = rastgele;
            }
            return bombalar;
        }
        private bool BombaYerlestir(int[] bombalar, int i)
        {
            foreach (int bomba in bombalar)
            {
                if (bomba == i)
                    return true;
            }
            return false;
        }

        private int KomsuHesapla(int name)
        {
            int adet = 0;

            int[] komsular = { name - 5, name + 5, name + 1, name - 1, name - 6, name - 4, name + 6, name + 4 };

            foreach (int komsu in komsular)
            {
                try { 
                    Button button = (Button)(onizleme.Controls.Find("button" + (komsu).ToString(), true)[0]);
                    if (button.BackColor == Color.Red)
                        adet++;
                }
                catch { }
            }
            
            return adet;
        }
        public void ButonOlustur(int bomba)
        {
            onizleme.pnTarla.Controls.Clear();
            pnTarla.Controls.Clear();
            int[] bombalar = BombaOlustur(bomba);

            int x = 10, y = 12;
            int name = 0;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    Button btn = new Button();
                    Button btn2 = new Button();
                    onizleme.pnTarla.Controls.Add(btn);
                    pnTarla.Controls.Add(btn2);

                    btn.Name = "button" + name.ToString();
                    btn.Size = new Size(35, 35);
                    btn.Location = new Point(x, y);
                    btn.BackColor = Color.Green;
                    if (BombaYerlestir(bombalar, name))
                        btn.BackColor = Color.Red;

                    btn2.Name = "button" + name.ToString();
                    btn2.Size = new Size(35, 35);
                    btn2.Location = new Point(x, y);
                    btn2.BackColor = Color.Gray;
                    btn2.Click += new EventHandler(this.Btn2_Click);
                   // btn2.Text = name.ToString();


                    x += 41;
                    if (j == 4)
                        x = 10;
                    name++;
                }
                y += 41;
            }
        
            for (int i = 0; i <=24; i++)
            {
                Button button = (Button)(onizleme.Controls.Find("button" + i.ToString(), true)[0]);
                button.Text = KomsuHesapla(i).ToString();
            }

        }

        private void Btn2_Click(object sender, EventArgs e)
        {
            String name = ((Button)sender).Name;
            Button button = (Button)(onizleme.Controls.Find(name, true)[0]);
            ((Button)sender).Text = button.Text;
            ((Button)sender).BackColor = Color.Green;
            if (button.BackColor == Color.Red)
            {
                ((Button)sender).BackColor = Color.Red;
                OyunBitir();
            }
            sayac = Convert.ToInt32(ndSure.Value);
        }

        private void OyunBaslat()
        {
            if (tmSayac.Enabled)
            {
                DialogResult soru = MessageBox.Show("Yeni oyun başlatmak istediğinizden emin misiniz?", "Soru", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                if(soru == DialogResult.No)
                {
                    return;
                }
            }
            ButonOlustur(Convert.ToInt32(ndMayinSayisi.Value));

            onizleme.Show();
            ndSure.Enabled = false;
            pnTarla.Enabled = true;
            ndMayinSayisi.Enabled = false;
            tmSayac.Enabled = true;

            sayac = Convert.ToInt32(ndSure.Value);
         
        }
        private void OyunBitir()
        {
            tmSayac.Enabled = false;
            ndMayinSayisi.Enabled = true;
            ndSure.Enabled = true;
            pnTarla.Enabled = false;
            MessageBox.Show("Oyun Bitti", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            sayac = 0;
            lbKalanSure.Text = "Kalan Süre = __";
        }

        private bool ArmstrongHesapla(int sayi)
        {
            int basamak = 1;
            int gecici = sayi;
            do
            {
                gecici = gecici / 10;
                basamak++;
            }
            while (gecici >= 10);

            int toplam = 0;
            for (int i = sayi; i > 0; i = i / 10)
            {
                toplam = toplam + (int)Math.Pow(i % 10, basamak);
            }

            if (sayi == toplam)
                return true;
            else
                return false;
        }
        private void btnBul_Click(object sender, EventArgs e)
        {
            if (txtAltSinir.Text == "" || txtUstSinir.Text == "")
            {
                MessageBox.Show("Gerekli alanları doldurunuz!", "Uyarı", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            lstSayilar.Items.Clear();
            int altSinir = Convert.ToInt32(txtAltSinir.Text);
            int ustSinir = Convert.ToInt32(txtUstSinir.Text);

            for (int i = altSinir; i < ustSinir; i++)
            {
                if (ArmstrongHesapla(i))
                {
                    lstSayilar.Items.Add(i.ToString());
                }
            }
        }

        private void txtAltSinir_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void txtUstSinir_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ButonOlustur(Convert.ToInt32(ndMayinSayisi.Value));
        }

        private void btnBasla_Click(object sender, EventArgs e)
        {
            OyunBaslat();
        }

        private void tmSayac_Tick(object sender, EventArgs e)
        {

            if(sayac == 0)
            {
                OyunBitir();
            }
            sayac--;
            lbKalanSure.Text = "Kalan Süre = " + sayac.ToString();
        }
    }
}
