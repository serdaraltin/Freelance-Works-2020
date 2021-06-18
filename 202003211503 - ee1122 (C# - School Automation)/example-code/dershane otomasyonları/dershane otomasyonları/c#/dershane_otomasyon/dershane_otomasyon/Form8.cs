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
    public partial class Form8 : Form
    {
        public Form8()
        {
            InitializeComponent();
        }
        OleDbConnection baglan = new OleDbConnection("Provider=Microsoft.ace.OleDb.12.0;Data Source=dershane.accdb");
        OleDbCommand kmt = new OleDbCommand();
        DataTable tablo = new DataTable();
        OleDbDataAdapter adtr = new OleDbDataAdapter();
        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                TextBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();
                TextBox2.Text = dataGridView1.Rows[e.RowIndex].Cells[2].Value.ToString();
                TextBox3.Text = dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString();
                TextBox4.Text = dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString();
                TextBox5.Text = dataGridView1.Rows[e.RowIndex].Cells[5].Value.ToString();
                textBox6.Text = dataGridView1.Rows[e.RowIndex].Cells[6].Value.ToString();
            }
            catch (Exception)
            {

                throw;
            }
          

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 FRM2 = new Form2();
            FRM2.Show();
            this.Hide();
        }
        public void listele()
        {
            TextBox1.Text = "";
            TextBox2.Text = "";
            TextBox3.Text = "";
            TextBox4.Text = "";
            TextBox5.Text = "";
            textBox6.Text = "";
            tablo.Clear();
            adtr = new OleDbDataAdapter(" Select * from gider ", baglan);
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



            kmt = new OleDbCommand("INSERT INTO gider(pers_maas,derslik,kira,fatura,muhasebe,sigorta) VALUES('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "','" + textBox6.Text + "')", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("Kayıt Başarılı");
            listele();
        }

        private void Form8_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void button3_Click(object sender, EventArgs e)
        {

            baglan.Open();
            kmt = new OleDbCommand("Delete from gider WHERE derslik = '" +TextBox2.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            kmt.Dispose();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();
        }

        private void button4_Click(object sender, EventArgs e)
        {

            baglan.Open();
            kmt = new OleDbCommand("UPDATE gider SET pers_maas='" + TextBox1.Text + "',derslik='" + TextBox2.Text + "',kira='" + TextBox3.Text + "',fatura='" + TextBox4.Text + "',muhasebe='" + TextBox5.Text + "',sigorta='" + textBox6.Text + "'", baglan);
            kmt.ExecuteNonQuery();
            baglan.Close();
            MessageBox.Show("İşleminiz başarılı");
            listele();


           // kmt = new OleDbCommand("INSERT INTO gider(pers_maas,derslik,kira,fatura,muhasebe,sigorta) VALUES('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "')", baglan);
            
        }

        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (baglan.State == ConnectionState.Closed)
            {
                baglan.Open();
            }


            adtr.SelectCommand.CommandText = " Select * From gider" +
                 " where(pers_maas='" + textBox7.Text + "' )";
            tablo.Clear();
            adtr.Fill(tablo);
            baglan.Close();
        }
    }
}
