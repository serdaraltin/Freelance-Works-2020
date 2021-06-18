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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        SqlConnection con = new SqlConnection("Data Source=DESKTOP-TMORB4D;Initial Catalog=Okul;Integrated Security=True");
        string soz1, soz2, soz3, soz4, soz5;
        int sayac = 1, id;

        private void timer1_Tick(object sender, EventArgs e)
        {
            label3.Visible = true;
            if (sayac == 1)
            {
                progressBar1.Value = 20;
                label3.Text = soz1;
                sayac++;
            }
            else if (sayac == 2)
            {
                progressBar1.Value = 40;
                label3.Text = soz2;
                sayac++;
            }
            else if (sayac == 3)
            {
                progressBar1.Value = 60;
                label3.Text = soz3;
                sayac++;
            }
            else if (sayac == 4)
            {
                progressBar1.Value = 80;
                label3.Text = soz4;
                sayac++;
            }
            else if (sayac == 5)
            {
                progressBar1.Value = 100;
                label3.Text = soz5;
                sayac = 0;
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = con;
                cmd.CommandText = "update dinleme set dinleme_sayisi += 1 where id = @s_id";
                cmd.Parameters.AddWithValue("@s_id", id);
                cmd.ExecuteNonQuery();
                cmd.Dispose();
                timer1.Stop();
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            label3.Visible = false;
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            progressBar1.Value = 0;
            if (textBox1.Text != "")
            {
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = con;
                cmd.CommandText = "select soz1, soz2, soz3, soz4, soz5, id from sarki where sarki_ismi = @s_ad";
                cmd.Parameters.AddWithValue("@s_ad", textBox1.Text);
                SqlDataReader dr = cmd.ExecuteReader();
                while (dr.Read())
                {
                    soz1 = dr[0].ToString();
                    soz2 = dr[1].ToString();
                    soz3 = dr[2].ToString();
                    soz4 = dr[3].ToString();
                    soz5 = dr[4].ToString();
                    id = Convert.ToInt16(dr[5]);
                }
                dr.Close();
                timer1.Interval = 1000;
                timer1.Start();
            }
            else
            {
                MessageBox.Show("Lütfen Şarkı Adını Boş Bırakmayın!", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
