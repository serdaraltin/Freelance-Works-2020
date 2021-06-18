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
    public partial class frmOgrenciEmanetGecmisiListe : Form
    {
        public frmOgrenciEmanetGecmisiListe()
        {
            InitializeComponent();
        }

        private void frmOgrenciEmanetGecmisiListe_Load(object sender, EventArgs e)
        {
            try
            {
                IEmanettekiKitaplarBll _emanetKitaplar = new EmanettekiKitaplarBll(new EmanettekiKitaplarDal());

                List<OgrenciEmanetlerModel> kitaplar = new List<OgrenciEmanetlerModel>();
                int ogrenciId = Convert.ToInt32(Tag);
                foreach (var item in _emanetKitaplar.getAllByStudentId(ogrenciId))
                {
                    OgrenciEmanetlerModel model = new OgrenciEmanetlerModel();
                    model.id = item.id;
                    model.kitapAdi = item.kitaplar.kitapAdi;

                    model.yazarAdi = item.kitaplar.yazarlar.yazarAdSoyad;
                    model.yayinevi = item.kitaplar.yayinEvi.yayinEviAdi;
                    model.barkodNo = item.kitaplar.barkodNo;
                    //emanetDurumu true ya da false olacağından, bunu metinsel olarak ifade etmek için true ise "teslim edildi" değilde edilmedi şeklinde datagrid hücresine yazarız
                    model.emanetDurumu = item.kitaplar.emanetDurumu == true ? "Teslim Edilmedi" : "Teslim Edildi";
                    model.emanetAlimTarihi = (DateTime)item.emanetAlimTarihi;
                    model.teslimTarihi = (DateTime)item.teslimTarihi;
                    kitaplar.Add(model);

                }
                dGridEmanetListesi.DataSource = kitaplar.ToList();
                for (int i = 0; i < dGridEmanetListesi.Rows.Count; i++)
                {
                    /*
                     * datagrid içerisinde dönülerek her bir verinin gecikme süresi ve teslim durumu kontrol edilir
                     * teslim edilmişse yeşil, gecikmişse kırmızı, 2 gün kalmışsa sarı renk yapılır ilgili satır
                     
                     */
                    DateTime teslimTarih = (DateTime)dGridEmanetListesi.Rows[i].Cells["teslimTarihi"].Value;
                    string teslimDurumu = dGridEmanetListesi.Rows[i].Cells["emanetDurumu"].Value.ToString();
                    TimeSpan tarihFark = teslimTarih - DateTime.Now;
                    int gunFark = (int)tarihFark.TotalDays;
                    if (gunFark < 3 && gunFark > 0 && teslimDurumu=="Teslim Edilmedi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Yellow;
                        dGridEmanetListesi.Rows[i].DefaultCellStyle = renk;
                    }
                    else if (gunFark <= 0 && teslimDurumu == "Teslim Edilmedi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Red;
                        dGridEmanetListesi.Rows[i].DefaultCellStyle = renk;
                    }
                    else if (teslimDurumu == "Teslim Edildi")
                    {
                        DataGridViewCellStyle renk = new DataGridViewCellStyle();
                        renk.BackColor = Color.Green;
                        dGridEmanetListesi.Rows[i].DefaultCellStyle = renk;
                    }
                }
            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
        }

        private void dGridEmanetListesi_CellMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            string emanetDurumu = dGridEmanetListesi.CurrentRow.Cells["emanetDurumu"].Value.ToString();
            if (emanetDurumu=="Teslim Edilmedi")
            {
                int emanetId = Convert.ToInt32(dGridEmanetListesi.CurrentRow.Cells["id"].Value);
                frmEmanetKitapDetay detay = new frmEmanetKitapDetay();
                detay.Tag = emanetId;
                detay.Show();
            }
          
        }
    }
}
