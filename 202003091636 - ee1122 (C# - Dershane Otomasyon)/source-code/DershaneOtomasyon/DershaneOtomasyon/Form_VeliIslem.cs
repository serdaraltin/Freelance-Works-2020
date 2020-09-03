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
    public partial class Form_VeliIslem : Form
    {
        public Form_VeliIslem()
        {
            InitializeComponent();
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "veli";
        int Id = 0;
        public void Listele()
        {
            dg_veriler.DataSource = islemler.Kayitlar(tablo).Tables[0];
        }
        private void Form_VeliIslem_Load(object sender, EventArgs e)
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
                Form_Veli form = new Form_Veli(Id);
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
            Form_Veli form = new Form_Veli();
            form.ShowDialog();
        }

        private void btn_Guncelle_Click(object sender, EventArgs e)
        {
            Form_Veli form = new Form_Veli(Id);
            form.ShowDialog();
        }

        private void btn_excelAktar_Click(object sender, EventArgs e)
        {
            islemler.RaporOlustur(tablo);
        }
    }
}
