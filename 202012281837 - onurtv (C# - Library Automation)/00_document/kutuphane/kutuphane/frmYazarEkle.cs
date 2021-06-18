using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;
using System;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmYazarEkle : Form
    {
        public frmYazarEkle()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                IYazarlarBll _yayinEvi = new YazarlarBll(new YazarlarDal());
                yazarlar yazar = new yazarlar();
                yazar.durum = true;
                yazar.yazarAdSoyad = txtAd.Text;
                _yayinEvi.Add(yazar);

                MessageBox.Show("Yazar Başarıyla Kayıt Edildi", "Başarılı");

               
            }
            catch
            {

                MessageBox.Show("Bir Hata Meydana Geldi", "Hata");
            }
        }
    }
}
