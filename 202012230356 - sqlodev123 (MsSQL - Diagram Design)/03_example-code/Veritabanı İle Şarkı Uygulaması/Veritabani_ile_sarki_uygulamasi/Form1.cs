using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace Veritabani_ile_sarki_uygulamasi
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SqlConnection con = new SqlConnection("Data Source=DESKTOP-TMORB4D;Initial Catalog=Okul;Integrated Security=True");
        string soz1, soz2, soz3, soz4, soz5;
        int sayac = 1;

        private void button2_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "insert into sarki(sarki_ismi, sarki_suresi, sarki_turu, sarkici, soz1, soz2, soz3, soz4, soz5) values(@sarki_ismi, @sarki_suresi, @sarki_turu, @sarkici, @soz1, @soz2, @soz3, @soz4, @soz5)";
            cmd.Parameters.AddWithValue("@sarki_ismi", textBox1.Text);
            cmd.Parameters.AddWithValue("@sarki_suresi", textBox2.Text);
            cmd.Parameters.AddWithValue("@sarki_turu", comboBox1.Text);
            cmd.Parameters.AddWithValue("@sarkici", textBox3.Text);
            cmd.Parameters.AddWithValue("@soz1", soz1);
            cmd.Parameters.AddWithValue("@soz2", soz2);
            cmd.Parameters.AddWithValue("@soz3", soz3);
            cmd.Parameters.AddWithValue("@soz4", soz4);
            cmd.Parameters.AddWithValue("@soz5", soz5);
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            listele();
            MessageBox.Show("Başarıyla Kaydedildi!", "Başarılı", MessageBoxButtons.OK, MessageBoxIcon.Information);
            sayac = 1;
            button1.Text = "1. Sözü Kaydet";
            button1.Enabled = true;
            button2.Enabled = false;
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            comboBox1.Items.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "delete from sarki where id = @secili_id";
            cmd.Parameters.AddWithValue("@secili_id", dataGridView1.CurrentRow.Cells[0].Value);
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            listele();
            MessageBox.Show("Başarıyla Silindi!", "Başarılı", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "update sarki set sarki_ismi=@sarki_ismi, sarki_suresi=@sarki_suresi, sarki_turu=@sarki_turu, sarkici=@sarkici where id = @secili_id";
            cmd.Parameters.AddWithValue("@sarki_ismi", textBox1.Text);
            cmd.Parameters.AddWithValue("@sarki_suresi", textBox2.Text);
            cmd.Parameters.AddWithValue("@sarki_turu", comboBox1.Text);
            cmd.Parameters.AddWithValue("@sarkici", textBox3.Text);
            cmd.Parameters.AddWithValue("@secili_id", dataGridView1.CurrentRow.Cells[0].Value);
            cmd.ExecuteNonQuery();
            cmd.Dispose();
            listele();
            MessageBox.Show("Başarıyla Güncellendi!", "Başarılı", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form2 frm2 = new Form2();
            frm2.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form3 frm3 = new Form3();
            frm3.ShowDialog();
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            textBox1.Text = dataGridView1.CurrentRow.Cells[1].Value.ToString();
            textBox2.Text = dataGridView1.CurrentRow.Cells[2].Value.ToString();
            comboBox1.Text = dataGridView1.CurrentRow.Cells[3].Value.ToString();
            textBox3.Text = dataGridView1.CurrentRow.Cells[4].Value.ToString();
        }     

        void listele()
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "select * from sarki";
            SqlDataAdapter adaptor = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            adaptor.Fill(ds, "sarki");
            dataGridView1.DataSource = ds.Tables["sarki"];
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox4.Text != "")
            {
                if (sayac == 1)
                {
                    soz1 = textBox4.Text;
                    button1.Text = "2. Sözü Kaydet";
                    sayac++;
                    textBox4.Clear();
                }
                else if (sayac == 2)
                {
                    soz2 = textBox4.Text;
                    button1.Text = "3. Sözü Kaydet";
                    sayac++;
                    textBox4.Clear();
                }
                else if (sayac == 3)
                {
                    soz3 = textBox4.Text;
                    button1.Text = "4. Sözü Kaydet";
                    sayac++;
                    textBox4.Clear();
                }
                else if (sayac == 4)
                {
                    soz4 = textBox4.Text;
                    button1.Text = "5. Sözü Kaydet";
                    sayac++;
                    textBox4.Clear();
                }
                else if (sayac == 5)
                {
                    soz5 = textBox4.Text;
                    button1.Enabled = false;
                    button2.Enabled = true;
                    textBox4.Clear();
                }
            }
            else
            {
                MessageBox.Show("Lütfen Şarkı Sözünü Boş Bırakmayın!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            button2.Enabled = false;
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            listele();
        }
    }
}
