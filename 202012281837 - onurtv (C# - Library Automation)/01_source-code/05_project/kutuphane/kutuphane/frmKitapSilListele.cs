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
    public partial class frmKitapSilListele : Form
    {
        public frmKitapSilListele()
        {
            InitializeComponent();
        }
        IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());
        void listele()
        {
            try
            {
                //kitapların listelenmesi işlemi
                List<kitaplarModel> kitaplar = new List<kitaplarModel>();

                foreach (var item in _kitaplar.getAll())
                {
                    kitaplarModel model = new kitaplarModel();
                    model.id = item.id;
                    model.kitapAdi = item.kitapAdi;
                    model.kitapBasimYili = (DateTime)item.kitapBasimYili;
                    model.kitapCiltNo = (Int16)item.kitapCiltNo;
                    model.yazarAdi = item.yazarlar.yazarAdSoyad;
                    model.yayinevi = item.yayinEvi.yayinEviAdi;
                    model.barkodNo = item.barkodNo;
                    model.emanetDurumu = item.emanetDurumu == true ? "Emanette" : "Müsait";
                    kitaplar.Add(model);

                }
                dGridKitapListeleSil.DataSource = kitaplar.ToList();
            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
          
        }
        private void frmKitapSilListele_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void dGridKitapListeleSil_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            try
            {
                //tablodan seçilen kaydın silinmesi işlemi
                int id = Convert.ToInt32(dGridKitapListeleSil.CurrentRow.Cells["id"].Value);
                DialogResult dialog = MessageBox.Show("Silmek İstediğinize Emin misiniz ?", "Uyarı", MessageBoxButtons.YesNo);
                if (DialogResult.Yes == dialog)
                {
                    kitaplar kitap = _kitaplar.getOneById(id);
                    if (kitap != null)
                    {
                        kitap.durum = false;
                        _kitaplar.Update(kitap);

                        MessageBox.Show("kitap Silindi", "Başarılı");
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
