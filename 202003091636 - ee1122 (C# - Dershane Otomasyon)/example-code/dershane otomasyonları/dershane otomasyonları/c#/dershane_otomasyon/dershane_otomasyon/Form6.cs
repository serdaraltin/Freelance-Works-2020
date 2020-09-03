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
    public partial class Form6 : Form
    {
        public Form6()
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
            comboBox3.Text = "";
            comboBox1.Text = "";
            comboBox2.Text = "";

            tablo.Clear();
            adtr = new OleDbDataAdapter(" Select * from gruplar ", baglan);
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



            kmt = new OleDbCommand("INSERT INTO gruplar(gruplar,kurs_saati,ogr_durum) VALUES('" + comboBox3.Text + "','" + comboBox1.Text + "','" + comboBox2.Text + "')", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("Kayıt Başarılı");
            listele();
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("Delete from gruplar WHERE gruplar = '" + comboBox3.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            kmt.Dispose();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            baglan.Open();
            kmt = new OleDbCommand("UPDATE gruplar SET gruplar='" + comboBox3.Text + "',kurs_saati='" + comboBox1.Text + "',ogr_durum='" + comboBox2.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.Show();
            this.Hide();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
               comboBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
                comboBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
                comboBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();

            }
            catch (Exception)
            {


            }
        }

        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            baglan.Open();
            if (textBox6.Text.Trim() != "")
            {
                adtr.SelectCommand.CommandText = " Select * From gruplar" +
                     " where(gruplar='" + textBox6.Text + "' )";
                tablo.Clear();
                adtr.Fill(tablo);
                baglan.Close();
            }
        }
    }
}
