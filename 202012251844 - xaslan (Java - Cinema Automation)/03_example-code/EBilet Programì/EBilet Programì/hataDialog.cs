using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace EBilet_Programı
{
    public partial class hataDialog : Form
    {
        public hataDialog()
        {
            InitializeComponent();
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void hataDialog_KeyDown(object sender, KeyEventArgs e)
        {
            //formun keydown evendti ile hangi tuşa basıldığını aşağıdaki gibi yakalarız... enter F2 kaydet yapıyor lar
            //burada tek dikkat edeceğin şey, bu komutun çalışması için
            // formun keypreview özelliğinin true olması gerekir yokksa bunu yakalayabazsın..
            if (e.KeyCode == Keys.Escape)
                this.Close();
        }
    }
}
