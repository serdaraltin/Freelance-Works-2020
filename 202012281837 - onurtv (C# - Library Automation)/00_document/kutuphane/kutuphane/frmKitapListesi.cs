using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using kutuphane.model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace kutuphane
{
    public partial class frmKitapListesi : Form
    {
        public frmKitapListesi()
        {
            InitializeComponent();
        }

        private void frmKitapListesi_Load(object sender, EventArgs e)
        {
            try
            {
                IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());

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
                dGridKitapListele.DataSource = kitaplar.ToList();
            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
           
           
        }

        private void dGridKitapListele_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            int kitapId = Convert.ToInt32(dGridKitapListele.CurrentRow.Cells["id"].Value);
            frmKitapDetay detay = new frmKitapDetay();
            detay.Tag = kitapId;
            detay.Show();
        }
    }
}
