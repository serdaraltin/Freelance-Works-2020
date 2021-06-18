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
    public partial class frmOgrenciGuncelle : Form
    {
        public frmOgrenciGuncelle()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void txtTelefon_TextChanged(object sender, EventArgs e)
        {

        }
        IOgrencilerBll _ogrenciler = new OgrencilerBll(new OgrencilerDal());
        void listele()
        {
            List<OgrenciModel> ogrenciler = new List<OgrenciModel>();

            foreach (var item in _ogrenciler.getAll())
            {
                OgrenciModel ogrenci = new OgrenciModel();
                ogrenci.id = item.id;
                ogrenci.Adres = item.Adres;
                ogrenci.AdSoyad = item.adSoyad;
                ogrenci.Tc = item.Tc;
                ogrenci.Telefon = item.Telefon;
                ogrenci.ogrenciNo = item.ogrenciNo;
                ogrenci.cezaMiktari = (decimal)item.cezalar.Sum(x => x.cezaTutari);
                ogrenciler.Add(ogrenci);

            }
            dGridMusteriler.DataSource = ogrenciler.ToList();
        }
        private void frmMusteriGuncelle_Load(object sender, EventArgs e)
        {
            listele();
        }

        private void dGridMusteriler_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            try
            {
                btnEkle.Tag = dGridMusteriler.CurrentRow.Cells["id"].Value.ToString();
                txtAd.Text = dGridMusteriler.CurrentRow.Cells["adSoyad"].Value.ToString();
                txtAdres.Text = dGridMusteriler.CurrentRow.Cells["Adres"].Value.ToString();
                txtTC.Text = dGridMusteriler.CurrentRow.Cells["Tc"].Value.ToString();
                txtOgrNo.Text = dGridMusteriler.CurrentRow.Cells["ogrenciNo"].Value.ToString();
                txtTelefon.Text = dGridMusteriler.CurrentRow.Cells["Telefon"].Value.ToString();
            }
            catch 
            {

            }


        }

        private void btnEkle_Click(object sender, EventArgs e)
        {
            try
            {
                int id = Convert.ToInt32(btnEkle.Tag);
                ogrenciler ogrenci = _ogrenciler.getOneById(id);
                if (ogrenci != null)
                {
                    ogrenci.ogrenciNo = txtOgrNo.Text;
                    ogrenci.Tc = txtTC.Text;
                    ogrenci.Adres = txtAdres.Text;
                    ogrenci.adSoyad = txtAd.Text;
                    ogrenci.Telefon = txtTelefon.Text;
                    ogrenci.Adres = txtAdres.Text;
                    
                    _ogrenciler.Update(ogrenci);
                    MessageBox.Show("Müşteri Güncellendi", "Başarılı");
                    listele();


                }
            }
            catch
            {
                MessageBox.Show("Bir Hata Meydana Geldi ", "Hata");
            }
        }
    }
}
