namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("yazarlar")]
    public partial class yazarlar
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public yazarlar()
        {
            kitaplar = new HashSet<kitaplar>();
        }

        public int id { get; set; }

        [StringLength(11)]
        public string Tc { get; set; }

        [StringLength(50)]
        public string yazarAdSoyad { get; set; }

        public bool? durum { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<kitaplar> kitaplar { get; set; }
    }
}
