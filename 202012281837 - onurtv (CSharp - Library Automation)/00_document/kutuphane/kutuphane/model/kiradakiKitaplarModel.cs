using System;
namespace kutuphane.model
{
    public class kiradakiKitaplarModel
    {
        public int kitapId { get; set; }
        public string barkodNo { get; set; }
        public string kitapAdi { get; set; }
        public string ogrenciTC { get; set; }
        public string ogrenciAdSoyad { get; set; }
        public DateTime kitapAlimTarihi { get; set; }
        public DateTime kitapTeslimTarihi { get; set; }
        public string teslimDurumu { get; set; }


    }
}
