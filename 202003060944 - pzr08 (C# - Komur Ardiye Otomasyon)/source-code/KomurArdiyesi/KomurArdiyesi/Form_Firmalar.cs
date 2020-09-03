using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace KomurArdiyesi
{
    public partial class Form_Firmalar : Form
    {
        public Form_Firmalar()
        {
            InitializeComponent();
        }
        Class_VeritabaniIslemleri veritabani = new Class_VeritabaniIslemleri();
        int FirmaId = 0;
        private void Listele()
        {
            dg_Firmalar.DataSource = veritabani.Firmalar().Tables[0];
        }
        private void Form_Firmalar_Load(object sender, EventArgs e)
        {
            Listele();
        }

        private void dg_Firmalar_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                FirmaId = Convert.ToInt32(dg_Firmalar.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dg_Firmalar_DoubleClick(object sender, EventArgs e)
        {
            Form_Firma firma = new Form_Firma(FirmaId);
            firma.ShowDialog();
        }
    }
}
