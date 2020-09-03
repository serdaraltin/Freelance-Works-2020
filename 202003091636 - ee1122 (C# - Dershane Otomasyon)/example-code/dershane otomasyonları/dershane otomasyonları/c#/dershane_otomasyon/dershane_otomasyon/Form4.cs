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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }
        OleDbConnection baglan = new OleDbConnection("Provider=Microsoft.ace.OleDb.12.0;Data Source=dershane.accdb");
        OleDbCommand kmt = new OleDbCommand();
        DataTable tablo = new DataTable();
        OleDbDataAdapter adtr = new OleDbDataAdapter();
        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 FRM2 = new Form2();
            FRM2.Show();
            this.Hide();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            TextBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
            TextBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
            TextBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();
            TextBox4.Text = dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString();
            TextBox5.Text = dataGridView1.Rows[e.RowIndex].Cells[5].Value.ToString();
           
           
        }
        public void listele()
        {
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            tablo.Clear();
            adtr = new OleDbDataAdapter(" Select * from personel ", baglan);
            adtr.Fill(tablo);
            dataGridView1.DataSource = tablo;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (baglan.State == ConnectionState.Open)
            {

                baglan.Close();
            }
            baglan.Open();



            kmt = new OleDbCommand("INSERT INTO personel(adi,soyadi,tel,pers_maas,brans) VALUES('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "')", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("Kayıt Başarılı");
            listele();
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void button3_Click(object sender, EventArgs e)
        {

            baglan.Open();
            kmt = new OleDbCommand("Delete from personel WHERE adi = '" + TextBox1.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            kmt.Dispose();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("UPDATE personel SET adi='" + TextBox1.Text + "',soyadi='" + TextBox2.Text + "',tel='" + TextBox3.Text + "',pers_maas='" + TextBox4.Text + "',brans='"+TextBox5.Text+"'", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            baglan.Open();
            if (textBox6.Text.Trim() != "")
            {
                adtr.SelectCommand.CommandText = " Select * From personel" +
                     " where(adi='" + textBox6.Text + "' )";
                tablo.Clear();
                adtr.Fill(tablo);
                baglan.Close();
            }
        }
    }
}
