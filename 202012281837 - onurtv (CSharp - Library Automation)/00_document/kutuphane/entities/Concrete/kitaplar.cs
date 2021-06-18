namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("kitaplar")]
    public partial class kitaplar
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public kitaplar()
        {
            cezalar = new HashSet<cezalar>();
            emanettekiKitaplar = new HashSet<emanettekiKitaplar>();
        }

        public int id { get; set; }

        [StringLength(50)]
        public string barkodNo { get; set; }

        [StringLength(50)]
        public string kitapAdi { get; set; }

        public int? YazarID { get; set; }

        public DateTime? kitapBasimYili { get; set; }

        public short? kitapCiltNo { get; set; }

        public int? yayinEviID { get; set; }

        public bool? durum { get; set; }

        public bool? emanetDurumu { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<cezalar> cezalar { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<emanettekiKitaplar> emanettekiKitaplar { get; set; }

        public virtual yayinEvi yayinEvi { get; set; }

        public virtual yazarlar yazarlar { get; set; }
    }
}
