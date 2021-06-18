
using System;
using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;
using System.Linq;
using System.Windows.Forms;
namespace kutuphane
{
    public partial class frmKitapEkle : Form
    {
        public frmKitapEkle()
        {
            InitializeComponent();
        }
        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
     
        private void btnKayit_Click(object sender, EventArgs e)
        {
            try
            {
                IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());
                kitaplar kiradaMi = _kitaplar.getOneBarcodeId(txtBarkod.Text);
                if (kiradaMi==null)
                {

                    kitaplar kitaplar = new kitaplar();
                    kitaplar.durum = true;
                    kitaplar.kitapAdi = txtAdi.Text;
                    kitaplar.barkodNo = txtBarkod.Text;
                    kitaplar.YazarID = Convert.ToInt32(cmbYazar.SelectedValue);
                    kitaplar.yayinEviID = Convert.ToInt32(cmbYayinEvi.SelectedValue);


                    kitaplar.kitapCiltNo = Convert.ToInt16(txtCiltNo.Text);
                    kitaplar.kitapBasimYili = dtBasimYili.Value;
                    _kitaplar.Add(kitaplar);
                    MessageBox.Show("Kitap Başarıyla Kayıt Edildi", "Başarılı");
                    txtAdi.Text = "";
                    txtBarkod.Text = "";
                    txtCiltNo.Text = "";
                }else
                    MessageBox.Show("Barkod Numarası Zaten Kullanımda", "Hata");

                //girilen tüm veriler veritabanında kitap tablosunun alanlarına eşitlenip veritabanına kayıt edilir.



            }
            catch
            {
                MessageBox.Show("Bir Hata Meydana Geldi", "Hata");
            }
          
              
           
                
        }
        private void frmKitapEkle_Load(object sender, EventArgs e)
        {
            IYayinEviBll yayinEvi = new YayinEviBll(new YayinEviDal());
            IYazarlarBll yazar = new YazarlarBll(new YazarlarDal());
            cmbYayinEvi.DataSource = yayinEvi.getAll();
            cmbYayinEvi.ValueMember = "id";
            cmbYayinEvi.DisplayMember = "yayinEviAdi";
            cmbYazar.DataSource = yazar.getAll();
            cmbYazar.ValueMember = "id";
            cmbYazar.DisplayMember = "yazarAdSoyad";
        }
    }
}
