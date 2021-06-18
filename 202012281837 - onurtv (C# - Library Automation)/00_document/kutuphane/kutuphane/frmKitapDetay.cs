using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;

using kutuphane.model;
using System;
using System.Collections.Generic;

using System.Linq;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmKitapDetay : Form
    {
        public frmKitapDetay()
        {
            InitializeComponent();
        }
        IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());
        IEmanettekiKitaplarBll _emanet = new EmanettekiKitaplarBll(new EmanettekiKitaplarDal());
        List<kitapDetayModel> detaylar = new List<kitapDetayModel>();
        private void frmSatisDetay_Load(object sender, EventArgs e)
        {
            try
            {
                /*Kitap listesinden bir kitaba tıkladığımızda o kitabın id'sini bu formun Tag property'sine atarız ve formun görüntülenmesini sağlarız
                 Eğer veritabanında böyle bir kitap varsa kitabn bilgilerini form üzerindeki textbox gibi araçların içine yazdırırız
                 Ödevde bu kitabın emanet geçmişisinin de istenildiği için, varsa emanet geçmişini de datagrid içine yazdırırız
                 */
                int kitapId = Convert.ToInt32(Tag);
                var kitap = _kitaplar.getOneById(kitapId);
                txtAdi.Text = kitap.kitapAdi;
                txtBarkod.Text = kitap.barkodNo;
                txtCiltNo.Text = kitap.kitapCiltNo.ToString();
                txtYayinEvi.Text = kitap.yayinEvi.yayinEviAdi;
                txtYazar.Text = kitap.yazarlar.yazarAdSoyad;
                dtBasimYili.Value = (DateTime)kitap.kitapBasimYili;
                foreach (var item in _emanet.getAllByBookId(kitap.id))
                {
                    kitapDetayModel detay = new kitapDetayModel
                    {

                        KitapAdi = item.kitaplar.kitapAdi,
                        id = item.id,

                        ogrenciAdSoyad = item.ogrenciler.adSoyad,
                        OgrenciTc = item.ogrenciler.Tc,
                        ogrenciNo = item.ogrenciler.ogrenciNo,
                        AlisTarihi = (DateTime)item.emanetAlimTarihi,
                        teslimTarihi = (DateTime)item.teslimTarihi,
                        barkodNo = item.kitaplar.barkodNo,
                    };

                    detaylar.Add(detay);



                }

                dGridDetay.DataSource = detaylar.ToList();
                //ciltNo ve basım yılı listede görüntülenmesine gerek olmadığı için bu iki alanı gizliyoruz
                dGridDetay.Columns["ciltNo"].Visible = false;
                dGridDetay.Columns["kitapBasimYili"].Visible = false;
            }
            catch 
            {
                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
              
            }
        }
    }
}
