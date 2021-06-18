namespace entities.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class initialDb : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.cezalar",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        ogrenciId = c.Int(),
                        kitapId = c.Int(),
                        cezaTutari = c.Decimal(precision: 18, scale: 2),
                        gecikmeGunSayisi = c.Int(),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.kitaplar", t => t.kitapId)
                .ForeignKey("dbo.ogrenciler", t => t.ogrenciId)
                .Index(t => t.ogrenciId)
                .Index(t => t.kitapId);
            
            CreateTable(
                "dbo.kitaplar",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        barkodNo = c.String(maxLength: 50, unicode: false),
                        kitapAdi = c.String(maxLength: 50, unicode: false),
                        YazarID = c.Int(),
                        kitapBasimYili = c.DateTime(),
                        kitapCiltNo = c.Short(),
                        yayinEviID = c.Int(),
                        durum = c.Boolean(),
                        emanetDurumu = c.Boolean(),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.yayinEvi", t => t.yayinEviID)
                .ForeignKey("dbo.yazarlar", t => t.YazarID)
                .Index(t => t.YazarID)
                .Index(t => t.yayinEviID);
            
            CreateTable(
                "dbo.emanettekiKitaplar",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        kitapID = c.Int(),
                        ogrenciID = c.Int(),
                        emanetAlimTarihi = c.DateTime(),
                        teslimTarihi = c.DateTime(),
                    })
                .PrimaryKey(t => t.id)
                .ForeignKey("dbo.ogrenciler", t => t.ogrenciID)
                .ForeignKey("dbo.kitaplar", t => t.kitapID)
                .Index(t => t.kitapID)
                .Index(t => t.ogrenciID);
            
            CreateTable(
                "dbo.ogrenciler",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        adSoyad = c.String(maxLength: 50, unicode: false),
                        ogrenciNo = c.String(maxLength: 20, unicode: false),
                        Tc = c.String(maxLength: 11, unicode: false),
                        Adres = c.String(maxLength: 150, unicode: false),
                        Telefon = c.String(maxLength: 12, unicode: false),
                        durum = c.Boolean(),
                    })
                .PrimaryKey(t => t.id);
            
            CreateTable(
                "dbo.yayinEvi",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        yayinEviAdi = c.String(maxLength: 50, unicode: false),
                        durum = c.Boolean(),
                    })
                .PrimaryKey(t => t.id);
            
            CreateTable(
                "dbo.yazarlar",
                c => new
                    {
                        id = c.Int(nullable: false, identity: true),
                        Tc = c.String(maxLength: 11, unicode: false),
                        yazarAdSoyad = c.String(maxLength: 50, unicode: false),
                        durum = c.Boolean(),
                    })
                .PrimaryKey(t => t.id);
            
            CreateTable(
                "dbo.sysdiagrams",
                c => new
                    {
                        diagram_id = c.Int(nullable: false, identity: true),
                        name = c.String(nullable: false, maxLength: 128, unicode: false),
                        principal_id = c.Int(nullable: false),
                        version = c.Int(),
                        definition = c.Binary(),
                    })
                .PrimaryKey(t => t.diagram_id);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.kitaplar", "YazarID", "dbo.yazarlar");
            DropForeignKey("dbo.kitaplar", "yayinEviID", "dbo.yayinEvi");
            DropForeignKey("dbo.emanettekiKitaplar", "kitapID", "dbo.kitaplar");
            DropForeignKey("dbo.emanettekiKitaplar", "ogrenciID", "dbo.ogrenciler");
            DropForeignKey("dbo.cezalar", "ogrenciId", "dbo.ogrenciler");
            DropForeignKey("dbo.cezalar", "kitapId", "dbo.kitaplar");
            DropIndex("dbo.emanettekiKitaplar", new[] { "ogrenciID" });
            DropIndex("dbo.emanettekiKitaplar", new[] { "kitapID" });
            DropIndex("dbo.kitaplar", new[] { "yayinEviID" });
            DropIndex("dbo.kitaplar", new[] { "YazarID" });
            DropIndex("dbo.cezalar", new[] { "kitapId" });
            DropIndex("dbo.cezalar", new[] { "ogrenciId" });
            DropTable("dbo.sysdiagrams");
            DropTable("dbo.yazarlar");
            DropTable("dbo.yayinEvi");
            DropTable("dbo.ogrenciler");
            DropTable("dbo.emanettekiKitaplar");
            DropTable("dbo.kitaplar");
            DropTable("dbo.cezalar");
        }
    }
}
