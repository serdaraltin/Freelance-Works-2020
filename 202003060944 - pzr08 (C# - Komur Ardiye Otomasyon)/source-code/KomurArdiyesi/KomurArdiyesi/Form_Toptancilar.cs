using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Toptancilar : Form
    {
        public Form_Toptancilar()
        {
            InitializeComponent();
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();

        int ToptanciId = 0;
        private void Listele()
        {
            dg_Toptancilar.DataSource = veritabani.Toptancilar().Tables[0];
        }
        private void Form_Toptancilar_Load(object sender, EventArgs e)
        {
            Listele();
        }

        private void dg_Toptancilar_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                ToptanciId = Convert.ToInt32(dg_Toptancilar.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dg_Toptancilar_DoubleClick(object sender, EventArgs e)
        {
            Form_Toptanci toptanci = new Form_Toptanci(ToptanciId);
            toptanci.ShowDialog();
        }
    }
}
