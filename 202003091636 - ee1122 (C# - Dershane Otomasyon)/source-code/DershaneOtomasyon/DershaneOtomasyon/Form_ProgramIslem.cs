using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DershaneOtomasyon
{
    public partial class Form_ProgramIslem : Form
    {
        public Form_ProgramIslem()
        {
            InitializeComponent();
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "program";
        int Id = 0;
        public void Listele()
        {
            dg_veriler.DataSource = islemler.Kayitlar(tablo).Tables[0];
        }
        private void Form_ProgramIslem_Load(object sender, EventArgs e)
        {
            Listele();
        }

        private void btn_Sil_Click(object sender, EventArgs e)
        {
            if (Id == 0)
                islemler.MesajKutu("uyari", "seçim yapınız");
            if (islemler.Sil(tablo, Id))
            {
                islemler.MesajKutu("basarili", "silme");
                Listele();
            }
            else
                islemler.MesajKutu("hata", "silme");
        }

        private void dg_veriler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                Id = Convert.ToInt32(dg_veriler.Rows[e.RowIndex].Cells[0].Value);
            }
            catch { }
        }

        private void dg_veriler_DoubleClick(object sender, EventArgs e)
        {
            try
            {
                Form_Program form = new Form_Program(Id);
                form.ShowDialog();
            }
            catch { }
        }

        private void btn_Kapat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btn_Yenile_Click(object sender, EventArgs e)
        {
            Listele();
        }

        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            Form_Program form = new Form_Program();
            form.ShowDialog();
        }

        private void btn_Guncelle_Click(object sender, EventArgs e)
        {
            Form_Program form = new Form_Program(Id);
            form.ShowDialog();
        }

        private void btn_excelAktar_Click(object sender, EventArgs e)
        {
            islemler.RaporOlustur(tablo);
        }
    }
}
