using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace B181210010
{
    public partial class Form_Ana : Form
    {
        public Form_Ana()
        {
            InitializeComponent();
        }
        List<Atik> atiklar = new List<Atik>();
        Atik atik = new Atik();

        OrganikKutu organikKutu = new OrganikKutu();
        KagitKutu kagitKutu = new KagitKutu();
        CamKutu camKutu = new CamKutu();
        MetalKutu metalKutu = new MetalKutu();

        int sure, puan;

        public int AtikBul(string tur)
        {
            for (int i = 0; i < atiklar.Count; i++)
            {
                if (atiklar[i].Tur == tur && atiklar[i].Ad == atik.Ad)
                {
                    YeniAtik();
                    return i;
                }

            }
            return -1;
        }

        public void YeniAtik()
        {
            int sec = new Random().Next(0, atiklar.Count);
            atik = atiklar[sec];
            pbAtik.Image = atik.Image;
        }

        public void YeniOyun()
        {
            btnYeniOyun.Enabled = false;
            pbAtik.Image = null;
            sure = 60;
            puan = 0;
            PanelTemizle(pnOrganik, true);
            PanelTemizle(pnKagit, true);
            PanelTemizle(pnCam, true);
            PanelTemizle(pnMetal, true);
            tmSayac.Enabled = true;
            YeniAtik();
        }
        public void PanelTemizle(Panel panel, bool ac)
        {
            foreach (Control control in panel.Controls)
            {
                if (control is Button)
                    ((Button)control).Enabled = ac;
                if (control is ListBox)
                    ((ListBox)control).Items.Clear();
                if (control is ProgressBar)
                    ((ProgressBar)control).Value = 0;
            }
        }
        private void Form_Ana_Load(object sender, EventArgs e)
        {
            atiklar.Add(new Atik("cam", "Cam Şişe", 600));
            atiklar.Add(new Atik("cam", "Bardak", 250));
            atiklar.Add(new Atik("kagit", "Gazete", 250));
            atiklar.Add(new Atik("kagit", "Dergi", 200));
            atiklar.Add(new Atik("organik", "Domates", 150));
            atiklar.Add(new Atik("organik", "Salatalık", 120));
            atiklar.Add(new Atik("metal", "Kola Kutusu", 350));
            atiklar.Add(new Atik("metal", "Salça Kutusu", 550));
        }
        public void OyunBitir()
        {
            tmSayac.Enabled = false;
            btnYeniOyun.Enabled = true;
            pbAtik.Image = null;
            PanelTemizle(pnOrganik, false);
            PanelTemizle(pnKagit, false);
            PanelTemizle(pnCam, false);
            PanelTemizle(pnMetal, false);
        }
        private void tmSayac_Tick(object sender, EventArgs e)
        {
            if (sure <= 0)
            {
                OyunBitir();
                return;
            }
            sure--;
            lbSure.Text = sure.ToString();
            lbPuan.Text = puan.ToString();
        }
        private void btnYeniOyun_Click(object sender, EventArgs e)
        {
            YeniOyun();
        }
        private void btnOrganikAtik_Click(object sender, EventArgs e)
        {
            int index = AtikBul("organik");
            if (index > -1)
            {
                if (organikKutu.Ekle(atiklar[index]))
                {
                    pgOrganik.Value = organikKutu.DolulukOrani;
                    lstOrganik.Items.Add(atiklar[index].Ad + " (" + atiklar[index].Hacim.ToString() + ")");
                }
            }

        }
        private void btnBosaltOrganik_Click(object sender, EventArgs e)
        {
            int doluHacim = organikKutu.DoluHacim;
            if (organikKutu.Bosalt())
            {
                lstOrganik.Items.Clear();
                pgOrganik.Value = organikKutu.DolulukOrani;
                puan += doluHacim + organikKutu.BosaltmaPuani;
                sure += 3;
            }

        }

        private void btnKagit_Click(object sender, EventArgs e)
        {
            int index = AtikBul("kagit");
            if (index > -1)
            {
                if (kagitKutu.Ekle(atiklar[index]))
                {
                    pgKagit.Value = kagitKutu.DolulukOrani;
                    lstKagit.Items.Add(atiklar[index].Ad + " (" + atiklar[index].Hacim.ToString() + ")");
                }
            }
        }

        private void btnCam_Click(object sender, EventArgs e)
        {
            int index = AtikBul("cam");
            if (index > -1)
            {
                if (camKutu.Ekle(atiklar[index]))
                {
                    pgCam.Value = camKutu.DolulukOrani;
                    lstCam.Items.Add(atiklar[index].Ad + " (" + atiklar[index].Hacim.ToString() + ")");
                }
            }
        }

        private void btnMetal_Click(object sender, EventArgs e)
        {
            int index = AtikBul("metal");
            if (index > -1)
            {
                if (metalKutu.Ekle(atiklar[index]))
                {
                    pgMetal.Value = metalKutu.DolulukOrani;
                    lstMetal.Items.Add(atiklar[index].Ad + " (" + atiklar[index].Hacim.ToString() + ")");
                }
            }
        }

        private void btnBosaltCam_Click(object sender, EventArgs e)
        {
            int doluHacim = camKutu.DoluHacim;
            if (camKutu.Bosalt())
            {
                lstCam.Items.Clear();
                pgCam.Value = camKutu.DolulukOrani;
                puan += doluHacim + camKutu.BosaltmaPuani;
                sure += 3;
            }
        }

        private void btnBosaltMetal_Click(object sender, EventArgs e)
        {
            int doluHacim = metalKutu.DoluHacim;
            if (metalKutu.Bosalt())
            {
                lstMetal.Items.Clear();
                pgMetal.Value = metalKutu.DolulukOrani;
                puan += doluHacim + metalKutu.BosaltmaPuani;
                sure += 3;
            }
        }

        private void btnCikis_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btnBosaltKagit_Click(object sender, EventArgs e)
        {
            int doluHacim = kagitKutu.DoluHacim;
            if (kagitKutu.Bosalt())
            {
                lstKagit.Items.Clear();
                pgKagit.Value = kagitKutu.DolulukOrani;
                puan += doluHacim + kagitKutu.BosaltmaPuani;
                sure += 3;
            }
        }


    }
}
