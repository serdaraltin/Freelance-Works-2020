using entities.Concrete;
using System;
using System.Collections.Generic;

namespace kutuphane.model
{
    //kitap detayına ait özelliklerin modeli
    public class kitapDetayModel
    {
        public int id { get; set; }
        public string barkodNo { get; set; }
   
        public string KitapAdi { get; set; }
        public string ciltNo { get; set; }

        public DateTime kitapBasimYili { get; set; }

     
        public string OgrenciTc { get; set; }
        public string ogrenciNo { get; set; }
        public string ogrenciAdSoyad { get; set; }
        public DateTime AlisTarihi { get; set; }
        public DateTime teslimTarihi { get; set; }
    }
}
