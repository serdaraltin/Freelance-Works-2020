using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;
using System;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmYayinEviEkle : Form
    {
        public frmYayinEviEkle()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                IYayinEviBll _yayinEvi = new YayinEviBll(new YayinEviDal());
                yayinEvi yayinEvi = new yayinEvi();
                yayinEvi.durum = true;
                yayinEvi.yayinEviAdi = txtAd.Text;
                _yayinEvi.Add(yayinEvi);

                MessageBox.Show("Yayinevi Başarıyla Kayıt Edildi", "Başarılı");

                
            }
            catch
            {

                MessageBox.Show("Bir Hata Meydana Geldi", "Hata");
            }
        }
    }
}
