namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    //yayinEvi tablosunda olacak olan kolonların belirlenmesi ve bağlantılı tabloların sanal olarak belirlenmesi
    [Table("yayinEvi")]
    public partial class yayinEvi
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public yayinEvi()
        {
            kitaplar = new HashSet<kitaplar>();
        }

        public int id { get; set; }

        [StringLength(50)]
        public string yayinEviAdi { get; set; }

        public bool? durum { get; set; }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<kitaplar> kitaplar { get; set; }
    }
}
