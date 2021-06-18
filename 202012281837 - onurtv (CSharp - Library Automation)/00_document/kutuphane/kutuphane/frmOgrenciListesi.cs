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
    public partial class frmOgrenciListesi : Form
    {
        public frmOgrenciListesi()
        {
            InitializeComponent();
        }

        private void frmOgrenciListesi_Load(object sender, EventArgs e)
        {
            try
            {
                IOgrencilerBll _ogrenciler = new OgrencilerBll(new OgrencilerDal());

                List<OgrenciModel> ogrenciler = new List<OgrenciModel>();

                foreach (var item in _ogrenciler.getAll())
                {
                    OgrenciModel model = new OgrenciModel();
                    model.ogrenciNo = item.ogrenciNo;
                    model.id = item.id;
                    model.Adres = item.Adres;
                    model.AdSoyad = item.adSoyad;
                    model.Tc = item.Tc;
                    model.Telefon = item.Telefon;
                    model.cezaMiktari = (decimal)item.cezalar.Sum(x => x.cezaTutari);
                    ogrenciler.Add(model);

                }
                dGridMusteler.DataSource = ogrenciler.ToList();
            }
            catch
            {
                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi","Hata");
            }
            
        }

        private void dGridMusteler_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            int ogrenciId = Convert.ToInt32(dGridMusteler.CurrentRow.Cells["id"].Value);
            frmOgrenciEmanetGecmisiListe emanetler = new frmOgrenciEmanetGecmisiListe();
            emanetler.Tag = ogrenciId;
            emanetler.Show();
;        }
    }
}
