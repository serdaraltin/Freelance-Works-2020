using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kutuphane.model
{
    //öğrenci emanetlerine ait özelliklerin modeli
   public class OgrenciEmanetlerModel
    {
        public int id { get; set; }
        public string barkodNo { get; set; }
        public string kitapAdi { get; set; }
      
        public string yazarAdi { get; set; }
        public string yayinevi { get; set; }
        public string emanetDurumu { get; set; }
        public DateTime emanetAlimTarihi { get; set; }
        public DateTime teslimTarihi { get; set; }
    }
}
