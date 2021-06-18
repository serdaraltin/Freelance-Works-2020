namespace entities.Concrete
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("cezalar")]
    public partial class cezalar
    {
        public int id { get; set; }

        public int? ogrenciId { get; set; }

        public int? kitapId { get; set; }

        public decimal? cezaTutari { get; set; }

        public int? gecikmeGunSayisi { get; set; }

        public virtual kitaplar kitaplar { get; set; }

        public virtual ogrenciler ogrenciler { get; set; }
    }
}
