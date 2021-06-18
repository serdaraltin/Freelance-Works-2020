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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        SqlConnection con = new SqlConnection("Data Source=DESKTOP-TMORB4D;Initial Catalog=Okul;Integrated Security=True");

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

        private void Form3_Load(object sender, EventArgs e)
        {
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            listele();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "select * from sarki order by sarki_ismi asc";
            SqlDataAdapter adaptor = new SqlDataAdapter(cmd);
            DataSet ds = new DataSet();
            adaptor.Fill(ds, "sarki");
            dataGridView1.DataSource = ds.Tables["sarki"];
        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "exec sarkici_sarkilari @isim";
            cmd.Parameters.AddWithValue("@isim", textBox1.Text);
            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                listBox1.Items.Add(dr[0]);
            }
            dr.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = "select sarki.sarki_ismi from dinleme inner join sarki on dinleme.id = sarki.id where dinleme_sayisi = (select max(dinleme_sayisi) from dinleme)";
            string adi = cmd.ExecuteScalar().ToString();
            MessageBox.Show("En Çok Dinlenen Şarkı: " + adi);
        }
    }
}
