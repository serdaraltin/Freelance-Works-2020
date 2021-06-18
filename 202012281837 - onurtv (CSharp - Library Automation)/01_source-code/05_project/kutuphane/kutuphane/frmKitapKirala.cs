using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;
using kutuphane.model;
using System;
using System.Collections.Generic;

using System.Data;

using System.Linq;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmKitapKirala : Form
    {
        public frmKitapKirala()
        {
            InitializeComponent();
        }
        IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());
        IOgrencilerBll _ogrenciler = new OgrencilerBll(new OgrencilerDal());
        IEmanettekiKitaplarBll _emanet = new EmanettekiKitaplarBll(new EmanettekiKitaplarDal());
        void KitapListele()
        {
            //kitapların listelenmesi işlemi
            List<kitaplarModel> kitaplar = new List<kitaplarModel>();

            foreach (var item in _kitaplar.getAll())
            {
                kitaplarModel model = new kitaplarModel();
                model.id = item.id;
                model.barkodNo = item.barkodNo;
                model.kitapAdi = item.kitapAdi;
                model.kitapBasimYili = (DateTime)item.kitapBasimYili;
                model.kitapCiltNo = (Int16)item.kitapCiltNo;
                model.yazarAdi = item.yazarlar.yazarAdSoyad;
                model.yayinevi = item.yayinEvi.yayinEviAdi;
                model.emanetDurumu=item.emanetDurumu == true ? "Emanette" : "Müsait";
                kitaplar.Add(model);

            }
            dGridKitaplar.DataSource = kitaplar.ToList();
        }
        void musteriListele()
        {
            try
            {
                //öğrencilerin listelenmesi işlemi
                List<OgrenciModel> musteriler = new List<OgrenciModel>();

                foreach (var item in _ogrenciler.getAll())
                {
                    OgrenciModel model = new OgrenciModel();
                    model.id = item.id;
                    model.Adres = item.Adres;
                    model.AdSoyad = item.adSoyad;
                    model.Tc = item.Tc;
                    model.Telefon = item.Telefon;
                    model.ogrenciNo = item.ogrenciNo;
                    musteriler.Add(model);

                }
                cmbOgrenciler.DataSource = musteriler.ToList();
                cmbOgrenciler.DisplayMember = "AdSoyad";
                cmbOgrenciler.ValueMember = "id";
            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
          
        }
        private void frmKitapKirala_Load(object sender, EventArgs e)
        {
            musteriListele();
            KitapListele();
        }

        private void dGridKitaplar_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            txtKitapAdi.Tag = dGridKitaplar.CurrentRow.Cells["id"].Value;
            txtKitapAdi.Text = dGridKitaplar.CurrentRow.Cells["kitapAdi"].Value.ToString();
         
      
        }

        private void dGridMusteriler_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            /* 
             * datagrid üzerinden istenilen öğrenciye çift tıklandığında bu öğrencinin ad soyad ve id bilgileri
             * txtmusterAd içine adı, tag'ine ise id'si yazdırılır. Kirala butonuna basılınca da 
             * id bilgisi alınıp sorgulama yapılır ve öğrenciye bu kitap emanet verilir
             */
       
        }

        private void txtGunSayisi_TextChanged(object sender, EventArgs e)
        {
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                //kitap kiralama işlemi
                int kitapID = Convert.ToInt32(txtKitapAdi.Tag);
                int musteriId = Convert.ToInt32(cmbOgrenciler.SelectedValue);
                kitaplar kitap = _kitaplar.getOneById(kitapID);
                if (kitap != null)
                {
                    if (kitap.emanetDurumu == false)
                    {
                        emanettekiKitaplar emanet = new emanettekiKitaplar();
                        emanet.kitapID = kitap.id;
                        ogrenciler ogrenci = _ogrenciler.getOneById(musteriId);
                        if (ogrenci != null)
                        {
                            emanet.ogrenciID = ogrenci.id;

                        }
                        emanet.emanetAlimTarihi = DateTime.Now;
                       
                            emanet.teslimTarihi = DateTime.Now.AddDays(Convert.ToInt32(30));
                       

                        _emanet.Add(emanet);


                       
                        kitap.emanetDurumu = true;
                        _kitaplar.Update(kitap);

                        KitapListele();
                        MessageBox.Show("Kitap Başarıyla Kiralandı", "Başarılı");



                    }else
                        MessageBox.Show("Bu Kitap Zaten Kirada", "Hata");

                }
            }
            catch 
            {
                MessageBox.Show("Bir Hata Meydana Geldi");

            }
            
        }
    }
}
