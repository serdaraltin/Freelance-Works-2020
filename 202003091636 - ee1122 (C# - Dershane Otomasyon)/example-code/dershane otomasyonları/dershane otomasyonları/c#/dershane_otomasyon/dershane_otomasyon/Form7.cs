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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }
        OleDbConnection baglan = new OleDbConnection("Provider=Microsoft.ace.OleDb.12.0;Data Source=dershane.accdb");
        OleDbCommand kmt = new OleDbCommand();
        DataTable tablo = new DataTable();
        OleDbDataAdapter adtr = new OleDbDataAdapter();
        public void listele()
        {
            TextBox4.Text = DateTime.Now.ToShortDateString();
            tablo.Clear();
            adtr = new OleDbDataAdapter(" Select * from odeme_turu ", baglan);
            adtr.Fill(tablo);
            dataGridView1.DataSource = tablo;
            TextBox1.Text = "";
            comboBox1.Text = "";
            TextBox3.Text = "";
           // TextBox4.Text = "";
            TextBox5.Text = "";
            textBox6.Text = "";
        }
        private void button2_Click(object sender, EventArgs e)
        {

            if (baglan.State == ConnectionState.Open)
            {

                baglan.Close();
            }
            baglan.Open();



            kmt = new OleDbCommand("INSERT INTO odeme_turu(kayitli_ogr,odeme_turu,top_miktar,tarih,odenen,kalan) VALUES('" + TextBox1.Text + "','" + comboBox1.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "','" + textBox6.Text +"')", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("Kayıt Başarılı");
            listele();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            
            baglan.Open();
            kmt = new OleDbCommand("DELETE * FROM odeme_turu WHERE kayitli_ogr = '" +TextBox1.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            kmt.Dispose();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Form7_Load(object sender, EventArgs e)
        {
            TextBox4.Text = DateTime.Now.ToShortDateString();
            listele();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 FRM2 = new Form2();
            FRM2.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("UPDATE odeme_turu SET kayitli_ogr='" + TextBox1.Text + "',odeme_turu='" + comboBox1.Text + "',top_miktar='" + TextBox3.Text + "',tarih='" + TextBox4.Text + "',odenen='" + TextBox5.Text + "',kalan='" + textBox6.Text +"'where kayitli_ogr='" + TextBox1.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();


        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                TextBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
                comboBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
                TextBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();
                TextBox4.Text = dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString();
                TextBox5.Text = dataGridView1.Rows[e.RowIndex].Cells[5].Value.ToString();
                textBox6.Text = dataGridView1.Rows[e.RowIndex].Cells[6].Value.ToString();
            }
            catch (Exception)
            {


            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (baglan.State==ConnectionState.Closed)
            {
                baglan.Open();
            }
           
           
                adtr.SelectCommand.CommandText = " Select * From odeme_turu" +
                     " where(kayitli_ogr='" + textBox2.Text + "' )";
                tablo.Clear();
                adtr.Fill(tablo);
                baglan.Close();
            
        }
    }
}
