
using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;

using kutuphane.model;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
namespace kutuphane
{
    public partial class frmKiradakiKitaplar : Form
    {
        public frmKiradakiKitaplar()
        {
            InitializeComponent();
        }
        IEmanettekiKitaplarBll _kitaplar = new EmanettekiKitaplarBll(new EmanettekiKitaplarDal());
        private void frmKiradakiKitaplar_Load(object sender, EventArgs e)
        {
            try
            {
               /*
                * Kütüphaneden emanet alınan tüm kitapların listesi alınır.
                * Bu liste alınırken emanetler tablosu birden fazla tablo ile ilişkili olduğundan
                * ve o ilişkili tablolar da geleceğinden dolayı biz sadece ihtiyacımız olan bilgileri almak için
                * içerisinde sadece istediğimiz alanları eklediğimiz yeni bir class oluşturup ve gelen emanetler listesinin
                * ihtiyacımız olan parametrelerini alıp, bu class'a atarız ve bu classı datagrid'te görüntüleriz.
                */
            List<kiradakiKitaplarModel> kitaplar = new List<kiradakiKitaplarModel>();

                foreach (var item in _kitaplar.getAll())
                {
                    kiradakiKitaplarModel kitap = new kiradakiKitaplarModel();
                    kitap.barkodNo = item.kitaplar.barkodNo;
                    kitap.kitapId = item.kitaplar.id;
                    kitap.ogrenciAdSoyad = item.ogrenciler.adSoyad;
                    kitap.kitapAdi = item.kitaplar.kitapAdi;
                    kitap.kitapAlimTarihi = (DateTime)item.emanetAlimTarihi;
                    kitap.kitapTeslimTarihi = (DateTime)item.teslimTarihi;
                    kitap.ogrenciTC = item.ogrenciler.Tc;
                    /* teslim durumu true ya da false döner. Bunu kullanıcının anlayacağı dile çevirmek için true ise teslim edilmedi, false ise teslim edildi olarak
                     kullanıcıya bildiririz.*/
                    kitap.teslimDurumu = item.kitaplar.emanetDurumu == true ? "Teslim Edilmedi" : "Teslim Edildi";
                    kitaplar.Add(kitap);
                }
                dgridKiradakiKitapListesi.DataSource = kitaplar.ToList();
                for (int i = 0; i < dgridKiradakiKitapListesi.Rows.Count; i++)
                {
                    DateTime teslimTarih = (DateTime)dgridKiradakiKitapListesi.Rows[i].Cells["kitapTeslimTarihi"].Value;
                    string teslimDurumu= dgridKiradakiKitapListesi.Rows[i].Cells["teslimDurumu"].Value.ToString();
                    TimeSpan tarihFark = teslimTarih - DateTime.Now;
                    int gunFark = (int)tarihFark.TotalDays;
                    if (gunFark < 3 && gunFark > 0 && teslimDurumu == "Teslim Edilmedi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Yellow;
                        dgridKiradakiKitapListesi.Rows[i].DefaultCellStyle = renk;
                    }
                    else if (gunFark <= 0 && teslimDurumu == "Teslim Edilmedi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Red;
                        dgridKiradakiKitapListesi.Rows[i].DefaultCellStyle = renk;
                    }
                    else if (teslimDurumu == "Teslim Edildi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Green;
                        dgridKiradakiKitapListesi.Rows[i].DefaultCellStyle = renk;
                    }
                }
            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
        }

        private void dgridKiradakiKitapListesi_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {

        }
    }
}
