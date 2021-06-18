namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    //emanettekiKitaplar tablosunda olacak olan kolonların belirlenmesi ve bağlantılı tabloların sanal olarak belirlenmesi
    [Table("emanettekiKitaplar")]
    public partial class emanettekiKitaplar
    {
        public int id { get; set; }

        public int? kitapID { get; set; }

        public int? ogrenciID { get; set; }

        public DateTime? emanetAlimTarihi { get; set; }

        public DateTime? teslimTarihi { get; set; }

        public virtual kitaplar kitaplar { get; set; }

        public virtual ogrenciler ogrenciler { get; set; }
    }
}
