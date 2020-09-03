using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;
namespace dershane_otomasyon
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }
        OleDbConnection baglan = new OleDbConnection("Provider=Microsoft.ace.OleDb.12.0;Data Source=dershane.accdb");
        OleDbCommand kmt = new OleDbCommand();
        DataTable tablo = new DataTable();
        OleDbDataAdapter adtr = new OleDbDataAdapter();
        OleDbDataReader dr;
        public void listele()
        {
            TextBox1.Text = "";
            comboBox1.Text = "";
            comboBox2.Text = "";
          
            tablo.Clear();
            adtr = new OleDbDataAdapter(" Select * from siniflar ", baglan);
            adtr.Fill(tablo);
            dataGridView1.DataSource = tablo;


        }
        public void cek()
        {

            baglan.Open();
            OleDbCommand cmd = new OleDbCommand("select * from ogrenci",baglan);
            kmt = new OleDbCommand("select * from personel",baglan);
            dr = kmt.ExecuteReader();
            OleDbDataReader drr = cmd.ExecuteReader();
            while (dr.Read())
            {
                comboBox1.Items.Add(dr[0]);
            }
            while (drr.Read())
            {
                comboBox2.Items.Add(drr[0]);
            }
            baglan.Close();

        }
        private void Form5_Load(object sender, EventArgs e)
        {
            cek();
            listele();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (baglan.State == ConnectionState.Open)
            {

                baglan.Close();
            }
            baglan.Open();



            kmt = new OleDbCommand("INSERT INTO siniflar(sinif_adi,pers_id,ogr_id) VALUES('" + TextBox1.Text + "','" + comboBox1.Text + "','" + comboBox2.Text + "')", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("Kayıt Başarılı");
            listele();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("Delete from siniflar WHERE sinif_adi = '" + TextBox1.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            kmt.Dispose();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("UPDATE siniflar SET sinif_adi='" + TextBox1.Text + "',pers_id='" + comboBox1.Text + "',ogr_id='" + comboBox2.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {

            try
            {
                TextBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
                comboBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
                comboBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();

            }
            catch (Exception)
            {


            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 FRM2 = new Form2();
            FRM2.Show();
            this.Hide();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            baglan.Open();
            if (textBox6.Text.Trim() != "")
            {
                adtr.SelectCommand.CommandText = " Select * From siniflar" +
                     " where(sinif_adi='" + textBox6.Text + "' )";
                tablo.Clear();
                adtr.Fill(tablo);
                baglan.Close();
            }
        }
    }
}
