using System;
using System.Collections;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Giris : Form
    {
        public Form_Giris()
        {
            InitializeComponent();
        }
        Class_Islemler islemler = new Class_Islemler();

        private void button1_Click(object sender, EventArgs e)
        {
            if (!islemler.BaglantiTest())
            {
                Form_VeritabaniBaglanti veritabani = new Form_VeritabaniBaglanti();
                veritabani.Show();
                this.Hide();
            }
            if(txt_KullaniciAdi.Text == "" || txt_Parola.Text == "")
            {
                islemler.MesajKutu(1, "giriş");
                return;
            }
            if (islemler.Yonetici_Kontrol(txt_KullaniciAdi.Text, txt_Parola.Text) == 0)
            {
                islemler.MesajKutu(2, "giriş");
                return;
            }
            if (islemler.Yonetici_Kontrol(txt_KullaniciAdi.Text, txt_Parola.Text) != 0)
            {
               
                int kullanici_id = islemler.Yonetici_Kontrol(txt_KullaniciAdi.Text, txt_Parola.Text);
               
                ArrayList kayit = new ArrayList
                {
                    new ArrayList{"kullanici_id",kullanici_id},
                    new ArrayList{"tarih",DateTime.Now.ToString()}
                };
                islemler.Ekle("giris", kayit);
                Form anasayfa = new Form_Anasayfa();
                anasayfa.Show();
                this.Hide();
            }
        }
    }
}
