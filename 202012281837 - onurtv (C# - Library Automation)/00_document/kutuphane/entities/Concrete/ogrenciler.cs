namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("ogrenciler")]
    public partial class ogrenciler
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public ogrenciler()
        {
            cezalar = new HashSet<cezalar>();
            emanettekiKitaplar = new HashSet<emanettekiKitaplar>();
        }

        public int id { get; set; }

        [StringLength(50)]
        public string adSoyad { get; set; }

        [StringLength(20)]
        public string ogrenciNo { get; set; }

        [StringLength(11)]
        public string Tc { get; set; }

        [StringLength(150)]
        public string Adres { get; set; }

        [StringLength(12)]
        public string Telefon { get; set; }

        public bool? durum { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<cezalar> cezalar { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<emanettekiKitaplar> emanettekiKitaplar { get; set; }
    }
}
