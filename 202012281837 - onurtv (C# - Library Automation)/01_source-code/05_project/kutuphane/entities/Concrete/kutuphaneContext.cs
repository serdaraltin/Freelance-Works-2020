namespace entities.Concrete
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    
    public partial class kutuphaneContext : DbContext
    {
        public kutuphaneContext()
            : base("name=kutuphaneContext")
        {
        }

        public virtual DbSet<cezalar> cezalar { get; set; }
        public virtual DbSet<emanettekiKitaplar> emanettekiKitaplar { get; set; }
        public virtual DbSet<kitaplar> kitaplar { get; set; }
        public virtual DbSet<ogrenciler> ogrenciler { get; set; }
        public virtual DbSet<sysdiagrams> sysdiagrams { get; set; }
        public virtual DbSet<yayinEvi> yayinEvi { get; set; }
        public virtual DbSet<yazarlar> yazarlar { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<kitaplar>()
                .HasMany(e => e.cezalar)
                .WithOptional(e => e.kitaplar)
                .HasForeignKey(e => e.kitapId);

            modelBuilder.Entity<kitaplar>()
                .HasMany(e => e.emanettekiKitaplar)
                .WithOptional(e => e.kitaplar)
                .HasForeignKey(e => e.kitapID);

            modelBuilder.Entity<ogrenciler>()
                .HasMany(e => e.cezalar)
                .WithOptional(e => e.ogrenciler)
                .HasForeignKey(e => e.ogrenciId);

            modelBuilder.Entity<ogrenciler>()
                .HasMany(e => e.emanettekiKitaplar)
                .WithOptional(e => e.ogrenciler)
                .HasForeignKey(e => e.ogrenciID);

            modelBuilder.Entity<yazarlar>()
                .HasMany(e => e.kitaplar)
                .WithOptional(e => e.yazarlar)
                .HasForeignKey(e => e.YazarID);
        }
    }
}
