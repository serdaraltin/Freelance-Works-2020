using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Syncfusion.Pdf;
using Syncfusion.Pdf.Grid;

namespace DershaneOtomasyon
{
    public partial class Form_DersIslem : Form
    {
        public Form_DersIslem()
        {
            InitializeComponent();
        }
        Class_Islemler islemler = new Class_Islemler();
        string tablo = "ders";
        int Id = 0;
        public void Listele()
        {
            dg_veriler.DataSource = islemler.Kayitlar(tablo).Tables[0];
        }
        private void Form_DersIslem_Load(object sender, EventArgs e)
        {
            Listele();
        }

        private void dg_Ogrenci_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

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
            Form_Ders form = new Form_Ders();
            form.ShowDialog();
        }

        private void btn_Guncelle_Click(object sender, EventArgs e)
        {
            Form_Ders form = new Form_Ders(Id);
            form.ShowDialog();
        }

        private void btn_excelAktar_Click(object sender, EventArgs e)
        {
            islemler.RaporOlustur(tablo);

        }

        private void btn_excelAktar_Click_1(object sender, EventArgs e)
        {
            islemler.RaporOlustur(tablo);
        }
    }
}
