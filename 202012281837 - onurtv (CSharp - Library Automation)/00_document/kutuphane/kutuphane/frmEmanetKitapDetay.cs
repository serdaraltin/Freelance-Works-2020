using Bll.Abstract;
using Bll.concrete;
using Dal.concrete;
using entities.Concrete;
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
    public partial class frmEmanetKitapDetay : Form
    {
        public frmEmanetKitapDetay()
        {
            InitializeComponent();
        }
        IEmanettekiKitaplarBll _emanetKitaplar = new EmanettekiKitaplarBll(new EmanettekiKitaplarDal());
        private void frmEmanetKitapDetay_Load(object sender, EventArgs e)
        {
            try
            {
                int emanetId = Convert.ToInt32(Tag);
                emanettekiKitaplar emanetKitap = _emanetKitaplar.getOneById(emanetId);
                if (emanetKitap != null)
                {
                    TimeSpan tarihFarki = (DateTime)emanetKitap.teslimTarihi - DateTime.Now;
                    int toplamGunFarki = (int)tarihFarki.TotalDays;
                    /*
                     * Teslim edilen gün, son teslim süresi tarihinden çıkartılıp gecikme süresi bulunur.
                     * Toplam gecikme süresi 1 lira ile çarpılıp, toplam gecikme cezası bulunur.
                     * Eğer gecikme varsa ceza veritabanına kişi adına kayıt edilir.
                     */
                    if (toplamGunFarki < 0)
                    {
                        txtGecikmeSuresi.Text = (-1 * toplamGunFarki).ToString();
                        lblGecikmeCezasi.Text = ((-1 * toplamGunFarki) * 1).ToString();
                    }
                    else
                    {
                        txtGecikmeSuresi.Text = "0";
                        lblGecikmeCezasi.Text = "0";
                    }
                    dtAlimTarih.Value = (DateTime)emanetKitap.emanetAlimTarihi;
                    dtTeslimTarih.Value = (DateTime)emanetKitap.teslimTarihi;
                    txtAdi.Text = emanetKitap.kitaplar.kitapAdi;
                    txtBarkod.Text = emanetKitap.kitaplar.barkodNo;
                    txtCiltNo.Text = emanetKitap.kitaplar.kitapCiltNo.ToString();
                    txtYayinEvi.Text = emanetKitap.kitaplar.yayinEvi.yayinEviAdi;
                    txtYazar.Text = emanetKitap.kitaplar.yazarlar.yazarAdSoyad;
                    btnTeslim.Tag = emanetKitap.id;
                }

            }
            catch 
            {

                MessageBox.Show("Listeleme Sırasında Bir Hata Meydana Geldi", "Hata");
            }
        }

        private void btnTeslim_Click(object sender, EventArgs e)
        {
            try
            {
                if (btnTeslim.Tag != null)
                {
                    /*
                     * Öğrencinin emanet aldığı kitaba tıklanınca emanet id bu forma taşınır
                     * ve bu id ile emanetler tablosundan böyle bir kayıt var mı diye sorgulanır.
                     * Eğer böyle bir kayıt var ise gecikme süresi hesaplanır ve ceza miktarı form üzerinde görüntülenir
                   
                     */
                    IKitaplarBll _Kitaplar = new KitaplarBll(new KitaplarDal());
                    ICezalarBll _ceza = new CezalarBll(new CezalarDal());
                    int emanetId = Convert.ToInt32(btnTeslim.Tag);
                    kitaplar kitap = _Kitaplar.getOneByDepositId(emanetId);
                    if (kitap != null)
                    {
                        kitap.emanetDurumu = false;
                        _Kitaplar.Update(kitap);
                        /*
                         * Eğer ceza değeri 0'dan büyük ise, yani cezalı duruma düşmüşse, öğrenci için bu ceza tutarı kayıt edilir
                         * ve en sonunda kitabın kütüphaneye iadesi yapılır.
                         */
                        if (lblGecikmeCezasi.Text!="0")
                        {
                            cezalar ceza = new cezalar
                            {
                                cezaTutari = Convert.ToInt32(lblGecikmeCezasi.Text),
                                gecikmeGunSayisi = Convert.ToInt32(txtGecikmeSuresi.Text),
                                kitapId = kitap.id,
                                ogrenciId = kitap.emanettekiKitaplar.FirstOrDefault(x => x.id == emanetId).ogrenciID,

                            };
                            _ceza.Add(ceza);
                            
                        }

                    }
                    MessageBox.Show("Kitap Başarıyla Teslim Edildi");
                }
            }
            catch
            {

                MessageBox.Show("Bilinmeyen Bir Hata Meydana Geldi");
            }
        }
    }
}
