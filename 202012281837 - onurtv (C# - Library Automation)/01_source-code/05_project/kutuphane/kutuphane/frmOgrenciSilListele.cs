using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;

using kutuphane.model;
using System;
using System.Collections.Generic;

using System.Linq;

using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmOgrenciSilListele : Form
    {
        public frmOgrenciSilListele()
        {
            InitializeComponent();
        }
        IOgrencilerBll _ogrenciler = new OgrencilerBll(new OgrencilerDal());
        void listele()
        {
            try
            {
                List<OgrenciModel> ogrenciler = new List<OgrenciModel>();
                //öğrencilerin listelenmesi işlemi
                foreach (var item in _ogrenciler.getAll())
                {
                    OgrenciModel model = new OgrenciModel();
                    model.ogrenciNo = item.ogrenciNo;
                    model.id = item.id;
                    model.Adres = item.Adres;
                    model.AdSoyad = item.adSoyad;
                    model.Tc = item.Tc;
                    model.Telefon = item.Telefon;
                    ogrenciler.Add(model);

                }
                dGridMusteler.DataSource = ogrenciler.ToList();
            }
            catch 
            {
                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }

        }
        private void frmMusteriSilListele_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void dGridMusteler_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            try
            {
                //çift tıklanan verinin id'si alınıp veritabanından aranır, eğer bu veri bulursa silme işlemi yapılır
                int id = Convert.ToInt32(dGridMusteler.CurrentRow.Cells["id"].Value);
                DialogResult dialog = MessageBox.Show("Silmek İstediğinize Emin misiniz ?", "Uyarı", MessageBoxButtons.YesNo);
                if (DialogResult.Yes == dialog)
                {
                    ogrenciler ogrenci = _ogrenciler.getOneById(id);
                    if (ogrenci != null)
                    {



                        ogrenci.durum = false;
                        _ogrenciler.Update(ogrenci);

                        MessageBox.Show("Müşteri Silindi", "Başarılı");
                        listele();

                    }
                }
            }
            catch
            {

                MessageBox.Show("Bir Hata Meydana Geldi", "Hata");

            }
        }
    }
}
