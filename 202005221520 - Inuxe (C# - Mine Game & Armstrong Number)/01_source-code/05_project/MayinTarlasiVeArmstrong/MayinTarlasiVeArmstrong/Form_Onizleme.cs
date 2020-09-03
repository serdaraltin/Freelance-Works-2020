using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MayinTarlasiVeArmstrong
{
    public partial class Form_Onizleme : Form
    {
        public Form_Onizleme()
        {
            InitializeComponent();
        }

        private void Form_Onizleme_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                e.Cancel = true;
                Hide();
            }
        }
    }
}
