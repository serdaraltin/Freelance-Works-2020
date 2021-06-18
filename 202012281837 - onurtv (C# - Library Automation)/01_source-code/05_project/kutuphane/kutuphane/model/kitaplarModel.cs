using System;
namespace kutuphane.model
{
    //kitaba ait özelliklerin modeli
   public class kitaplarModel
    {
        public int id { get; set; }
        public string barkodNo { get; set; }
        public string kitapAdi { get; set; }
        public DateTime kitapBasimYili { get; set; }
        public Int16 kitapCiltNo { get; set; }
        public string yazarAdi { get; set; }
        public string yayinevi { get; set; }
        public string emanetDurumu { get; set; }

    }
}
