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
    public partial class frmKitapGuncelle : Form
    {
        public frmKitapGuncelle()
        {
            InitializeComponent();
        }
        IKitaplarBll _kitaplar = new KitaplarBll(new KitaplarDal());
        void listele()
        {
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
            dgridKitapGuncelle.DataSource = kitaplar.ToList();
        }
        private void frmKitapGuncelle_Load(object sender, EventArgs e)
        {
            IYazarlarBll yazarlar = new YazarlarBll(new YazarlarDal());
            IYayinEviBll yayinEvi = new YayinEviBll(new YayinEviDal());
            cmbYazar.DataSource = yazarlar.getAll();
            cmbYazar.DisplayMember = "yazarAdSoyad";
            cmbYazar.ValueMember = "id";
            cmbYayinEvi.DataSource = yayinEvi.getAll();
            cmbYayinEvi.DisplayMember = "yayinEviAdi";
            cmbYayinEvi.ValueMember = "id";
            listele();
        }

        private void dgridKitapGuncelle_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            //dataGrid içindeki güncellenecek veriye çift tıklandığında o verinin tüm satırları textboxlar içerisine yazılır
            btnGuncelle.Tag = dgridKitapGuncelle.CurrentRow.Cells["id"].Value.ToString();
            txtAdi.Text = dgridKitapGuncelle.CurrentRow.Cells["kitapAdi"].Value.ToString();
            txtCiltNo.Text = dgridKitapGuncelle.CurrentRow.Cells["kitapCiltNo"].Value.ToString();
            txtBarkod.Text = dgridKitapGuncelle.CurrentRow.Cells["barkodNo"].Value.ToString();
           
            dtBasimYili.Text = dgridKitapGuncelle.CurrentRow.Cells["kitapBasimYili"].Value.ToString();
            cmbYayinEvi.Text = dgridKitapGuncelle.CurrentRow.Cells["yayinevi"].Value.ToString();
            cmbYazar.Text = dgridKitapGuncelle.CurrentRow.Cells["yazarAdi"].Value.ToString();
        
        }

        private void btnGuncelle_Click(object sender, EventArgs e)
        {
            try
            {
                //Güncellenmiş veriler,güncellenecek olan veri veritabanından çağrılarak tüm değerlerine atanır ve güncelleme yapılır
                int id = Convert.ToInt32(btnGuncelle.Tag);
                kitaplar kitap = _kitaplar.getOneById(id);
                if (kitap != null)
                {
                    kitap.barkodNo = txtBarkod.Text;
                    kitap.kitapAdi = txtAdi.Text;

                    kitap.kitapCiltNo = Convert.ToInt16(txtCiltNo.Text);
                    kitap.yayinEviID = Convert.ToInt32(cmbYayinEvi.SelectedValue);
                    kitap.YazarID = Convert.ToInt32(cmbYazar.SelectedValue);
                    kitap.kitapBasimYili = Convert.ToDateTime(dtBasimYili.Value);

                    _kitaplar.Update(kitap);

                    MessageBox.Show("Kitap Güncellendi", "Başarılı");
                    listele();

                }
            }
            catch 
            {
                MessageBox.Show("Kitap Güncellenirken Bir Hata Meydana Geldi", "Hata");
            }
        }
    }
}
