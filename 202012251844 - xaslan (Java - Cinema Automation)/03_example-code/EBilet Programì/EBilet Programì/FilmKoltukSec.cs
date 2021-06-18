using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace EBilet_Programı
{
    public partial class FilmKoltukSec : Form
    {
        
        public FilmKoltukSec()
        {
            InitializeComponent();

            // TEK TIKLANMA OLAYLARI

            A1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            A10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            B10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            C10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            D10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            E10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            F10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            G10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            H10.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I1.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I2.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I3.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I4.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I5.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I6.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I7.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I8.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I9.MouseClick += new MouseEventHandler(tıklama_MouseClick);
            I10.MouseClick += new MouseEventHandler(tıklama_MouseClick);       
        }    
        public Button tıklananbuton;
        
        
        public int KisiID;
        int boskoltuklar = 90;
        int dolukoltuklar = 0;
        
        void tıklama_MouseClick(object sender, EventArgs e)
        {
            // bu kısımda veritabanı bağlantısı oluşturduk. Koltuklara her tıklandığında koltukların namesi (örn A1,C5 gibi) veritabanına atacak.
            // Bilet iptal işleminde işimize yarıyacaktır. Çünkü tıklanan koltuk namelerini veritabanında tutup iptal işleminde karşılaştırıp ona göre bos-dolu
            // ayarını yaparız.
            SqlConnection con = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True"); // veritabanı yolunu yaz buraya...
            if (con.State == ConnectionState.Closed)
                con.Open();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;

            if (con.State == ConnectionState.Closed) // bağlantı kontrol
            {
                con.Open();
            }
            tıklananbuton = (Button)sender;

            cmd.CommandText = @"insert into TiklananKoltuklar(TiklananKoltuklar) values (@TiklananKoltuklar)";
            cmd.Parameters.AddWithValue("@TiklananKoltuklar", tıklananbuton.Name); // tıklanankoltuk namelerini veritabanına attık.
            cmd.ExecuteNonQuery();
            con.Close();
            tıklananbuton.BackColor = Color.Salmon;
            tıklananbuton.Enabled = false;
            boskoltuklar--;
            dolukoltuklar++;
            LblBosKoltukSayisi.Text = boskoltuklar.ToString();
            LblDoluKoltukSayısı.Text = dolukoltuklar.ToString();
            if (txtSecilenKoltuk.Text == "") // eğer text boş ise ekle
            {
                grpBoxMenu.Enabled = true;
                txtSecilenKoltuk.Text = tıklananbuton.Name.ToString();
            }
            else // boş değil ise araya ; koyarak ekle
            {
                grpBoxMenu.Enabled = true;
                txtSecilenKoltuk.Text += ";" + tıklananbuton.Name.ToString();
            }
            rdbutonTam.Focus();
        }

        //****************************************************************//

        private void SaatGosterici_Tick(object sender, EventArgs e)
        {
            LblSaat.Text = (DateTime.Now.Hour) + ":" + (DateTime.Now.Minute) + ":" + (DateTime.Now.Second).ToString();
        }

        //****************************************************************//

        private void AnaForm_Load(object sender, EventArgs e)
        {
            // bu kısımda yeni veritabanı bağlantısı açtık. Burada dolu koltukları form açılışında dolu olarak göstereceğiz.
            SaatGosterici.Interval = 50;
            txtTarih.Text = DateTime.Today.ToShortDateString();
            SqlConnection con = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True"); // veritabanı yolunu yaz buraya...
            if (con.State == ConnectionState.Closed)
                con.Open();

            SqlCommand cmd= new SqlCommand("select SecilenKoltuk  from EBiletTablosu", con);
            SqlDataReader dr= cmd.ExecuteReader();

            //burada veritabanında seçilmiş olan koltukların listesini getireceğiz,
            //bunları seçilmiş yani satılmış olarak varsayacağız

            while (dr.Read()) // burada verilmiş koltuklar read la sırayla okunur...
            {
                foreach (Control item in this.grpBoxKoltuklar.Controls) // burası, form üzerindeki control olan tüm öğeleri dolaşır bitene kadar.
                {
                    if (item is Button) // burası, dolaşırken buton varsa koşulu,
                    {
                        //takla burada başlayacak işte...
                        string koltuk= dr["SecilenKoltuk"].ToString(); //burad koltuğu getirdik bir  den çok da olsa
                        //ancak ilk önce içinde ; virgül var mı ona bakacaığız..

                        int bul= koltuk.IndexOf(';');  // eğer için de virgül geçiyorsa varsa bize virgülün sırasını
                        //verecek bizim umurumuzda değil, sadece var olduğunu bilelim yeter...

                        if (bul > 0)  //birden çok koltuk seçili ise 0 dan büyük bir değer gelir..
                        {
                            string[] secilenKoltuk = koltuk.Split(';'); // eğer birden çoksa bununla her bir koltuğu ayıracağız..
                            //şimdi sirasıyla koltukları aratacağız...

                            for (int k= 0; k <= secilenKoltuk.Length - 1; k++)
                            {
                                if (item.Name == secilenKoltuk[k]) // burası, buton bulduğunda namesinin, bizim veri tabanından çektiğimiz mi kontrolu
                                {
                                    // eğer namesi bizim vts den çektiğimizse, bu butonun enamblesini false, rengini de salamon yap...
                                    item.Enabled = false;
                                    item.BackColor = Color.Salmon;
                                    dolukoltuklar++;
                                    boskoltuklar--;
                                    LblDoluKoltukSayısı.Text = dolukoltuklar.ToString();
                                    LblBosKoltukSayisi.Text = boskoltuklar.ToString();
                                }
                            }
                        }
                        else // birden fazla koltuk yok, tek ise...
                        {

                            if (item.Name == dr["SecilenKoltuk"].ToString()) // burası, buton bulduğunda namesinin, bizim veri tabanından çektiğimiz mi kontrolu
                            {
                                // eğer namesi bizim vts den çektiğimizse, bu butonun enamblesini false, rengini de salamon yap...
                                item.Enabled = false;
                                item.BackColor = Color.Salmon;
                                dolukoltuklar++;
                                boskoltuklar--;
                                LblDoluKoltukSayısı.Text = dolukoltuklar.ToString();
                                LblBosKoltukSayisi.Text = boskoltuklar.ToString();
                            }                   
                        }           
                    }
                }
            } // tüm veritabanındaki kayıtlar bitene kadar datareader true değer gönderir, o yüzden while sürekli satır bitene
            // kadar devam eder... bitince de datareader bittiğini içeren false değer gönderir ve veritabanında çekim biter...
            Refresh();
        }

        //****************************************************************//

        void temizle()
        {
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True";
            con.Open();
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;
            cmd.CommandText = @"delete TiklananKoltuklar"; //burda tıklanan koltuk namelerini TiklananKoltuk aktardık, bu tabloyuda
            //kökten temizler. Maksat veritabanın içindeki tablo kalabalık olmasın..
            // 
            txtIsim.Clear();
            comboSeans.SelectedIndex = -1;
            txtSecilenFilm.Clear();
            txtSecilenKoltuk.Clear();
            txtSoyisim.Clear();
            cmd.ExecuteNonQuery();
            con.Close();
        }

        //****************************************************************//

        private void AnaFormIsimKaydirma_Tick(object sender, EventArgs e)
        {
            label10.Text = label10.Text.Substring(1) + label10.Text.Substring(0, 1);
        }

        //****************************************************************//
        
        private void btnKayitlariGoster_Click(object sender, EventArgs e)
        {
            AsilAnaForm anafrm = new AsilAnaForm();
            this.Hide();
            anafrm.ShowDialog();
        }

        //****************************************************************//

        private void btnCikis_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //****************************************************************//

        private void btnBiletIptal_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(@"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True"); // veritabanı yolunu yaz buraya...
            if (con.State == ConnectionState.Closed)
                con.Open();

            SqlCommand cmd = new SqlCommand("select TiklananKoltuklar  from TiklananKoltuklar", con);
            SqlDataReader dr = cmd.ExecuteReader();
            ArrayList secilenkoltuklar = new ArrayList();
            DialogResult cevap;
            cevap = MessageBox.Show("Bilet Satın Alma İşlemi İptal Etmek İstediğinizden Emin misiniz ?", "Durum", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (cevap == DialogResult.Yes)
            {
                // bu kısımda tıklanan koltukları bilet iptal edildiğinde tekrardan boş olarak göstermek için kullandık.
                while (dr.Read())
                {
                    foreach (Control item in this.grpBoxKoltuklar.Controls) // burası, grpBoxKoltuklar üzerindeki control olan tüm öğeleri dolaşır bitene kadar.
                    {
                        if (item is Button) // burası, dolaşırken buton varsa koşulu,
                        {
                            string koltuk = dr["TiklananKoltuklar"].ToString(); // veritabanına kaydedilen tıklanan buton namelerini koltuk değişkenine aktardık
                            string[] koltuklar = koltuk.Split(';'); // ; varsa ayırıp diziye aktardık.
                            for (int k = 0; k <= koltuklar.Length - 1; k++) // döngü kuruarak koltuk dizisinin uzunluğunun -1 ine kadar döndürdük
                            {
                                if (koltuklar[k] == item.Name) // koltukların k'ıncı indisinin namesi ile grpboxdaki buton namesi ile eşleşirse....
                                {
                                    item.Enabled = true;
                                    item.BackColor = Color.PaleGreen;
                                    dolukoltuklar--;
                                    boskoltuklar++;
                                    LblDoluKoltukSayısı.Text = dolukoltuklar.ToString();
                                    LblBosKoltukSayisi.Text = boskoltuklar.ToString();
                                }
                            }
                        }
                    }
                }
                MessageBox.Show("Bilet Satın Alma İşlemi İptal Edildi..", "Durum", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                temizle();
                grpBoxKoltuklar.Enabled = false;
                grpBoxKoltuklar.Enabled = false;
                grpBoxMenu.Enabled = false;
                btnFilmSec.Enabled = true;
            }           
            else
            {
                ;
            }
        }

        //****************************************************************//

        private void btnBiletAl_Click(object sender, EventArgs e)
        {
            LblSaat.Text = (DateTime.Now.Hour) + ":" + (DateTime.Now.Minute) + ":" + (DateTime.Now.Second).ToString();
            SqlConnection con = new SqlConnection();
            con.ConnectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True";
            SqlCommand cmd = new SqlCommand();
            cmd.Connection = con;

            if (con.State == ConnectionState.Closed) // bağlantı kontrol
            {
                con.Open();
            }


            if (btnBiletAl.Text == "Bilet Al") // eğer al yazıyorsa normal açılmıştır o yüzden kaytettir burada kaydedilir..
            {
                cmd.CommandText = @"insert into EBiletTablosu (Isim,SoyIsim,SecilenFilm,
                              SecilenKoltuk,FilmSeansSaati,BiletiAldigiGun,BiletiAldigiSaat,SecilenTarife,Fiyat)
                              values (@Isim,@SoyIsim,@SecilenFilm,@SecilenKoltuk,@FilmSeansSaati,@BiletiAldigiGun,@BiletiAldigiSaat,@SecilenTarife,@Fiyat)";

                cmd.Parameters.AddWithValue("@Isim", txtIsim.Text);
                cmd.Parameters.AddWithValue("@SoyIsim", txtSoyisim.Text);
                cmd.Parameters.AddWithValue("@SecilenFilm", txtSecilenFilm.Text);
                cmd.Parameters.AddWithValue("@SecilenKoltuk", txtSecilenKoltuk.Text);
                cmd.Parameters.AddWithValue("@FilmSeansSaati", comboSeans.SelectedItem);
                cmd.Parameters.AddWithValue("@BiletiAldigiGun", txtTarih.Text);
                cmd.Parameters.AddWithValue("@BiletiAldigiSaat", LblSaat.Text);
                string koltuk = txtSecilenKoltuk.ToString();
                string[] koltuklar = koltuk.Split(';');
                int KoltukAdeti = koltuklar.Length;
                int Fiyat = 0;
                if (rdbutonOgrenci.Checked == true)
                {
                    cmd.Parameters.AddWithValue("@SecilenTarife", "Öğrenci");
                    Fiyat = 10;
                }
                else if (rdbutonTam.Checked == true)
                {
                    cmd.Parameters.AddWithValue("@SecilenTarife", "Tam");
                    Fiyat = 12;
                }
                int ToplamBedel = Fiyat * KoltukAdeti;
                cmd.Parameters.AddWithValue("@Fiyat", ToplamBedel);

                cmd.ExecuteNonQuery();
                con.Close();

                MessageBox.Show("Bilet Alınmıştır..", "Durum", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                temizle();
                Refresh();
                btnBiletAl.Enabled = false;
                btnFilmSec.Enabled = true;
                btnBiletIptal.Enabled = false;
                grpBoxMenu.Enabled = false;
                grpBoxKoltuklar.Enabled = false;

            }
            else
            {

                //düzeltme kodları burada
                //düzeltme yapabilmek için KişiID ye ihtiyac var onu da ilk formdan göndereceğim.

                cmd.CommandText = @"update EBiletTablosu SET Isim=@Isim,SoyIsim=@SoyIsim,SecilenFilm=@SecilenFilm,SecilenKoltuk=@SecilenKoltuk,FilmSeansSaati=@FilmSeansSaati,
                                    BiletiAldigiGun=@BiletiAldigiGun,BiletiAldigiSaat=@BiletiAldigiSaat,SecilenTarife=@SecilenTarife,Fiyat=@Fiyat where KisiID=@KisiID";

                cmd.Parameters.AddWithValue("@KisiID", KisiID);
                cmd.Parameters.AddWithValue("@Isim", txtIsim.Text);
                cmd.Parameters.AddWithValue("@SoyIsim", txtSoyisim.Text);
                cmd.Parameters.AddWithValue("@SecilenFilm", txtSecilenFilm.Text);
                cmd.Parameters.AddWithValue("@SecilenKoltuk", txtSecilenKoltuk.Text);
                cmd.Parameters.AddWithValue("@FilmSeansSaati", comboSeans.SelectedItem);
                cmd.Parameters.AddWithValue("@BiletiAldigiGun", txtTarih.Text);
                cmd.Parameters.AddWithValue("@BiletiAldigiSaat", LblSaat.Text);
                string koltuk = txtSecilenKoltuk.ToString();
                string[] koltuklar = koltuk.Split(';');
                int KoltukAdeti = koltuklar.Length;
                int Fiyat = 0;
                if (rdbutonOgrenci.Checked == true)
                {
                    cmd.Parameters.AddWithValue("@SecilenTarife", "Öğrenci");
                    Fiyat = 10;
                }
                else if (rdbutonTam.Checked == true)
                {
                    cmd.Parameters.AddWithValue("@SecilenTarife", "Tam");
                    Fiyat = 12;
                }
                int ToplamBedel = Fiyat * KoltukAdeti;
                cmd.Parameters.AddWithValue("@Fiyat", ToplamBedel);
                cmd.ExecuteNonQuery();
                con.Close();
                MessageBox.Show("Bilet Bilgileri Güncellenmiştir..", "Durum", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
                Refresh();
                btnBiletAl.Enabled = false;
                btnFilmSec.Enabled = true;
                //btnBiletIptal.Enabled = false;
                grpBoxMenu.Enabled = false;
                grpBoxKoltuklar.Enabled = false;
                temizle();
            }
        }

        //**************************************************************//

        private void btnFilmSec_Click(object sender, EventArgs e)
        {
            FilmSec f = new FilmSec();
            f.ShowDialog();

            if (f._Onay == true)
            {
                btnFilmSec.Enabled = false;
                grpBoxKoltuklar.Enabled = true;
                txtSecilenFilm.Text = f._FilmAdi;
                grpBoxMenu.Enabled = false;
            }
        }

        //*************************************************************//

        private void btnHakkinda_Click(object sender, EventArgs e)
        {
            // Programın nasıl kullanıldığına dair bilgiler içeren bir word dosyası açar.
            System.Diagnostics.Process.Start(@"D:\£f£ ß£LG£L£R!M\EBilet Programı\EBilet Programı\EBilet Programı\MY Bilet Programı Kullanımı.docx");
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://www.facebook.com/efe.okcu");
        }
        
    }
}
