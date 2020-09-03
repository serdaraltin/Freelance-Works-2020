using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace final_oyun
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private string rand;
        private string kul_tahmini;
        private int kul_tah_say;

        private int[] a = new int[10];//yazilimin tahmininin 1. basamagi
        private int[] b = new int[10];
        private int[] c = new int[10];
        private int[] d = new int[10];//yazilimin tahmininin 4. basamagi

        private int[] P = new int[10];//Kullanicinin verdigi pozitif ipuclar
        private int[] N = new int[10];// " negatif ipuclar

        private int P1, N1;//gecici negatif pozitif 

        private int m=0,n;//P[m] icin dongu 


        private void button1_Click(object sender, EventArgs e)
        {
            button1.Text = "Tekrar Oyna!";//baslat tekrar oyna butonu
            comboBox1.SelectedIndex = 0;//kullanici ipucu 
            comboBox2.SelectedIndex = 0;//kullanici ipucu

            button2.Enabled = true;//ipucu ver
            comboBox1.Enabled = true;
            comboBox2.Enabled = true;
            textBox3.Enabled = true;//kullanici tahmini
            button2.BackColor = Color.FromArgb(192, 0, 0);
            button3.BackColor = Color.FromArgb(64, 64, 64);
            textBox5.Text = "";
            textBox6.Text = "";
            textBox3.Text = "";

            kul_tah_say = 0;//kullanici kac kere tahmin denemis
            
            textBox4.Text = ""+kul_tah_say;

            Random rnd = new Random();
            int random = rnd.Next(1, 10);

            rand = "";

            rand += random;

            string rr = "";

            while (true) //rakamlari farkli 4 basamakli rastgele sayi uret
            {
                random = rnd.Next(0, 10);
                rr = random.ToString();

                if (!rand.Contains(rr))
                    rand = rand + rr;

                if (rand.Length == 4)
                    break;
            }

            
           /////yeni oyun icin degerleri basa al
            Array.Clear(a, 0, a.Length);
            Array.Clear(b, 0, b.Length);
            Array.Clear(c, 0, c.Length);
            Array.Clear(d, 0, d.Length);
            Array.Clear(P, 0, P.Length);
            Array.Clear(N, 0, N.Length);

            P1 = 0;
            N1 = 0;
            m = 0;
            n = 0;

            textBox2.Text = "" + (m + 1);
            textBox7.Text = "";

            if (P[m] != 4)//bu if'i basta 1 kere calistirarak yazilimin ilk tahminini uret
            {
                a[m] = 0; b[m] = 0;
                while (a[m] == b[m] || a[m] == c[m] || a[m] == d[m] || b[m] == c[m] || b[m] == d[m] || c[m] == d[m])
                {
                    d[m] = rnd.Next(0, 10);
                    c[m] = rnd.Next(0, 10);
                    b[m] = rnd.Next(0, 10);
                    a[m] = rnd.Next(0, 10);


                }
                for (n = 0; n < m; n++)
                {
                    P1 = 0; N1 = 0;
                    if (a[n] == b[m] || a[n] == c[m] || a[n] == d[m]) { N1 = N1 + 1; } else if (a[n] == a[m]) { P1 = P1 + 1; }
                    if (b[n] == a[m] || b[n] == c[m] || b[n] == d[m]) { N1 = N1 + 1; } else if (b[n] == b[m]) { P1 = P1 + 1; }
                    if (c[n] == b[m] || c[n] == a[m] || c[n] == d[m]) { N1 = N1 + 1; } else if (c[n] == c[m]) { P1 = P1 + 1; }
                    if (d[n] == b[m] || d[n] == c[m] || d[n] == a[m]) { N1 = N1 + 1; } else if (d[n] == d[m]) { P1 = P1 + 1; }
                    if (P1 != P[n] || N1 != N[n])
                    {
                        a[m] = 0; b[m] = 0;
                        while (a[m] == b[m] || a[m] == c[m] || a[m] == d[m] || b[m] == c[m] || b[m] == d[m] || c[m] == d[m])
                        {
                            d[m] = rnd.Next(0, 10);
                            c[m] = rnd.Next(0, 10);
                            b[m] = rnd.Next(0, 10);
                            a[m] = rnd.Next(0, 10);
                        }
                        n = -1;
                    }
                }

            }

            textBox1.Text = "" + a[m] + b[m] + c[m] + d[m];//ilk tahmini kutuda goster
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
            button2.Enabled = false;
            button3.Enabled = false;
            comboBox1.Enabled = false;
            comboBox2.Enabled = false;
            textBox3.Enabled = false;

            
            

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            string Newline = Environment.NewLine;

            MessageBox.Show("1) Başla butonuyla oyuna başla." + Newline+ Newline +
                            "2) Verilen tahminde" + Newline + Newline +
                            "~Basamağı ve değeri doğru sayılar varsa o kadar + ipucu gir." + Newline + Newline +
                            "~Basamağı yanlış ama değeri doğru sayılar varsa o kadar - ipucu gir." + Newline + Newline +
                            "3) İpucuları girince İpucu Tamam!'a tıkla" + Newline + Newline +
                            "4) Oyunun tuttuğu sayıyı bulmak için bir tahmin gir." + Newline + Newline +
                            "5) Hem yeni tahmin almak hem yeni tahmin vermek için Tahmit Et'e tıkla." + Newline + Newline +
                            "6) Sonraki tahmininde benzer şekilde sana verilen ipucudan yararlan."
                            , "Oynanış");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int poz;
            int neg;

            int.TryParse(comboBox1.Text, out poz);
            int.TryParse(comboBox2.Text, out neg);

            


            if (poz - neg <= 4)//kullanici ipuclarinin buyukluklerinin toplamı 4'ten buyuk olamamalı
            {
                button2.Enabled = false;
                button3.Enabled = true;
                button2.BackColor = Color.FromArgb(64, 64, 64);
                button3.BackColor = Color.FromArgb(192, 0, 0);
                comboBox1.Enabled = false;
                comboBox2.Enabled = false;

                int.TryParse(comboBox1.Text, out P[m]);//yeni pozitif ipucu al
                if (P[m] != 4)
                {
                    int.TryParse(comboBox2.Text, out N[m]);//yeni negatif ipucu al
                    N[m] = -1 * N[m];

                }
                else//pozitif ipucu=4 , yazilimin kazanma kosulu
                {

                    comboBox1.Enabled = false;
                    comboBox2.Enabled = false;
                    button2.Enabled = false;
                    button3.Enabled = false;
                    textBox3.Enabled = false;

                    button3.BackColor = Color.FromArgb(64, 64, 64);
                    

                    textBox4.Text = "" + kul_tah_say;
                    MessageBox.Show("Aklından tuttuğun sayı "+ a[m] + b[m] + c[m] + d[m] + "! " + (m+1) + ". tahminde buldum!", "Kaybettin!");

                }

                m++;
            }
            else
                MessageBox.Show("Geçersiz ipucu girdin!", "Hata!");


        }

        private void button3_Click(object sender, EventArgs e)//yazilimin sayisini tahmin et ve ondan yeni tahmin iste
        {
            int i, j;
            bool tekrarvar = false;

            string Newline = Environment.NewLine;

            int pozitifler=0;//yazilimin ipuclari
            int negatifler = 0;

            kul_tahmini = textBox3.Text;//kullanicinin tahminini al

            kul_tahmini = kul_tahmini.Replace(" ", String.Empty);//bosluk kontrolu

            var isNumeric = int.TryParse(kul_tahmini, out n);//sayi kontrolu

            if (kul_tahmini.Distinct().Count() != kul_tahmini.Count()) //icinde tekrar olup olmadiginin kontrolu
            {
                tekrarvar = true;
            }

            if (isNumeric && kul_tahmini.Length == 4 && kul_tahmini[0] != '0' && !tekrarvar)//gecerli tahmin girildiyse
            {

                button3.Enabled = false;
                button2.Enabled = true;
                button3.BackColor = Color.FromArgb(64, 64, 64);
                button2.BackColor = Color.FromArgb(192, 0, 0);
                comboBox2.Enabled = true;
                comboBox1.Enabled = true;

                textBox7.Text = "" + kul_tahmini + Newline + textBox7.Text + Newline; 
                kul_tah_say++;
                textBox4.Text = "" + kul_tah_say;

                for (i = 0; i < 4; i++)//pozitifleri hesapla
                {
                    if (kul_tahmini[i] == rand[i])
                        pozitifler++;

                }

                for (i = 0; i < 4; i++)//negatifleri hesapla
                    for (j = 0; j < 4; j++)
                        if (kul_tahmini[i] == rand[j] && i != j)
                            negatifler--;

                if (pozitifler == 0)
                    textBox5.Text = "0";//kutularda goster
                else
                    textBox5.Text = "+" + pozitifler;

                textBox6.Text = "" + negatifler;


                if (pozitifler == 4)//kullanicinin kazanma kosulu
                {

                    comboBox1.Enabled = false;
                    comboBox2.Enabled = false;
                    button2.Enabled = false;
                    button3.Enabled = false;
                    button2.BackColor = Color.FromArgb(64, 64, 64);
                    button3.BackColor = Color.FromArgb(64, 64, 64);
                    textBox3.Enabled = false;

                    textBox4.Text = ""+kul_tah_say;
                    MessageBox.Show(rand + " doğru sayı! " + kul_tah_say + ". tahminde buldun!", "Kazandın!");

                   
                    
                }

                Random rnd = new Random();

                if (P[m] != 4)//yazilimin yeni tahmin uretmesi
                {             //Mantik:Tum tahminlerin listesi ve bunlara karsilik gelen cikti ile (poz/neg ipuclari) tutarlı olan yeni bir tahmin, olası cozum icin secenek  
                    a[m] = 0; b[m] = 0;
                    while(a[m] == b[m] || a[m] == c[m] || a[m] == d[m] || b[m] == c[m] || b[m] == d[m] || c[m] == d[m])
                        {
                        d[m] = rnd.Next(0, 10);
                        c[m] = rnd.Next(0, 10);
                        b[m] = rnd.Next(0, 10);
                        a[m] = rnd.Next(0, 10);


                        }
                    for (n = 0; n < m; n++)
                    {
                        P1 = 0; N1 = 0;
                        if (a[n] == b[m] || a[n] == c[m] || a[n] == d[m]) { N1 = N1 + 1; } else if (a[n] == a[m]) { P1 = P1 + 1; }
                        if (b[n] == a[m] || b[n] == c[m] || b[n] == d[m]) { N1 = N1 + 1; } else if (b[n] == b[m]) { P1 = P1 + 1; }
                        if (c[n] == b[m] || c[n] == a[m] || c[n] == d[m]) { N1 = N1 + 1; } else if (c[n] == c[m]) { P1 = P1 + 1; }
                        if (d[n] == b[m] || d[n] == c[m] || d[n] == a[m]) { N1 = N1 + 1; } else if (d[n] == d[m]) { P1 = P1 + 1; }
                        if (P1 != P[n] || N1 != N[n])
                        {
                            a[m] = 0; b[m] = 0;
                            while(a[m] == b[m] || a[m] == c[m] || a[m] == d[m] || b[m] == c[m] || b[m] == d[m] || c[m] == d[m])
                            {
                                d[m] = rnd.Next(0, 10);
                                c[m] = rnd.Next(0, 10);
                                b[m] = rnd.Next(0, 10);
                                a[m] = rnd.Next(0, 10);
                            }
                            n = -1;
                        }
                    }

                }

                textBox1.Text = "" + a[m] + b[m] + c[m] + d[m];//yeni tahmini kutuda goster

                textBox2.Text = "" + (m + 1);
            }///////////////dongu
            else
                MessageBox.Show("Lütfen Senin Tahminin kısmına rakamları birbirinden farklı 4 basamaklı bir sayı girin!", "Hata!");
        }
    }
}
