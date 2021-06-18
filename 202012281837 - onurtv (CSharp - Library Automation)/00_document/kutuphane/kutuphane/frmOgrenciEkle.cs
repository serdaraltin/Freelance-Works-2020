using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;

using System;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmOgrenciEkle : Form
    {
        public frmOgrenciEkle()
        {
            InitializeComponent();
        }

        private void btnEkle_Click(object sender, EventArgs e)
        {
            try
            {
                IOgrencilerBll _ogrenciler = new OgrencilerBll(new OgrencilerDal());

                ogrenciler ogrenci = new ogrenciler();
                ogrenci.ogrenciNo = txtOgrNo.Text;
                ogrenci.durum = true;
                ogrenci.adSoyad = txtAd.Text;
                ogrenci.Tc = txtTC.Text;
                ogrenci.Telefon = txtTelefon.Text;
                ogrenci.Adres = txtAdres.Text;
                _ogrenciler.Add(ogrenci);
                      MessageBox.Show("Öğrenci Başarıyla Kayıt Edildi", "Başarılı");
                txtAd.Text = "";
                txtAdres.Text = "";
                txtOgrNo.Text = "";
                txtTC.Text = "";
                txtTelefon.Text = "";
            }
            catch 
            {
                MessageBox.Show("Bir Hata Meydana Geldi", "Hata");
            }
          
              
           
           
               
        }
    }
}
