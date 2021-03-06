USE [komurardiye]
GO
/****** Object:  Table [dbo].[tbl_musteri]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_musteri](
	[MusteriID] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nvarchar](50) NULL,
	[Soyad] [nvarchar](50) NULL,
	[Telefon] [nvarchar](50) NULL,
	[Eposta] [nvarchar](50) NULL,
	[Il] [nvarchar](50) NULL,
	[Ilce] [nvarchar](50) NULL,
	[Adres] [nvarchar](250) NULL,
 CONSTRAINT [PK_tbl_musteri] PRIMARY KEY CLUSTERED 
(
	[MusteriID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_marka]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_marka](
	[MarkaID] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nvarchar](50) NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_marka] PRIMARY KEY CLUSTERED 
(
	[MarkaID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_kategori]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_kategori](
	[KategoriID] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nvarchar](50) NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_kategori] PRIMARY KEY CLUSTERED 
(
	[KategoriID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_firma]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_firma](
	[FirmaID] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nvarchar](50) NULL,
	[Adres] [text] NULL,
	[Telefon] [nvarchar](50) NULL,
	[Eposta] [nvarchar](50) NULL,
 CONSTRAINT [PK_tbl_firma] PRIMARY KEY CLUSTERED 
(
	[FirmaID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_yonetici]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_yonetici](
	[YoneticiID] [int] IDENTITY(1,1) NOT NULL,
	[KullaniciAd] [nvarchar](50) NULL,
	[Parola] [nvarchar](50) NULL,
 CONSTRAINT [PK_tbl_yonetici] PRIMARY KEY CLUSTERED 
(
	[YoneticiID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_urun]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_urun](
	[UrunID] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nvarchar](250) NULL,
	[KategoriID] [int] NULL,
	[MarkaID] [int] NULL,
	[Miktar] [float] NULL,
	[Olcu] [nvarchar](50) NULL,
	[Fiyat] [float] NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_urun] PRIMARY KEY CLUSTERED 
(
	[UrunID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_toptanci]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_toptanci](
	[ToptanciID] [int] IDENTITY(1,1) NOT NULL,
	[FirmaID] [int] NULL,
	[Ad] [nvarchar](50) NULL,
	[Soyad] [nvarchar](50) NULL,
	[Telefon] [nvarchar](50) NULL,
	[Eposta] [nvarchar](50) NULL,
	[Il] [nvarchar](50) NULL,
	[Ilce] [nvarchar](50) NULL,
	[Adres] [nvarchar](250) NULL,
 CONSTRAINT [PK_tbl_toptanci] PRIMARY KEY CLUSTERED 
(
	[ToptanciID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_stok]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_stok](
	[StokID] [int] IDENTITY(1,1) NOT NULL,
	[UrunID] [int] NULL,
	[Adet] [int] NULL,
	[Tarih] [datetime] NULL,
 CONSTRAINT [PK_tbl_stok] PRIMARY KEY CLUSTERED 
(
	[StokID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_siparis]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_siparis](
	[SiparisID] [int] IDENTITY(1,1) NOT NULL,
	[MusteriID] [int] NULL,
	[UrunID] [int] NULL,
	[Adet] [int] NULL,
	[Tutar] [float] NULL,
	[Tarih] [datetime] NULL,
 CONSTRAINT [PK_tbl_siparis] PRIMARY KEY CLUSTERED 
(
	[SiparisID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tbl_fatura]    Script Date: 03/22/2020 18:01:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_fatura](
	[FaturaID] [int] IDENTITY(1,1) NOT NULL,
	[SiparisID] [int] NULL,
	[FaturaNo] [nvarchar](50) NULL,
	[Tutar] [float] NULL,
	[OdemeYontem] [nvarchar](50) NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_fatura] PRIMARY KEY CLUSTERED 
(
	[FaturaID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  ForeignKey [FK_tbl_fatura_tbl_siparis]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_fatura]  WITH CHECK ADD  CONSTRAINT [FK_tbl_fatura_tbl_siparis] FOREIGN KEY([SiparisID])
REFERENCES [dbo].[tbl_siparis] ([SiparisID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_fatura] CHECK CONSTRAINT [FK_tbl_fatura_tbl_siparis]
GO
/****** Object:  ForeignKey [FK_tbl_siparis_tbl_musteri]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_siparis]  WITH CHECK ADD  CONSTRAINT [FK_tbl_siparis_tbl_musteri] FOREIGN KEY([MusteriID])
REFERENCES [dbo].[tbl_musteri] ([MusteriID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_siparis] CHECK CONSTRAINT [FK_tbl_siparis_tbl_musteri]
GO
/****** Object:  ForeignKey [FK_tbl_siparis_tbl_urun]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_siparis]  WITH CHECK ADD  CONSTRAINT [FK_tbl_siparis_tbl_urun] FOREIGN KEY([UrunID])
REFERENCES [dbo].[tbl_urun] ([UrunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_siparis] CHECK CONSTRAINT [FK_tbl_siparis_tbl_urun]
GO
/****** Object:  ForeignKey [FK_tbl_stok_tbl_urun]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_stok]  WITH CHECK ADD  CONSTRAINT [FK_tbl_stok_tbl_urun] FOREIGN KEY([UrunID])
REFERENCES [dbo].[tbl_urun] ([UrunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_stok] CHECK CONSTRAINT [FK_tbl_stok_tbl_urun]
GO
/****** Object:  ForeignKey [FK_tbl_toptanci_tbl_firma]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_toptanci]  WITH CHECK ADD  CONSTRAINT [FK_tbl_toptanci_tbl_firma] FOREIGN KEY([FirmaID])
REFERENCES [dbo].[tbl_firma] ([FirmaID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_toptanci] CHECK CONSTRAINT [FK_tbl_toptanci_tbl_firma]
GO
/****** Object:  ForeignKey [FK_tbl_urun_tbl_kategori]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_urun]  WITH CHECK ADD  CONSTRAINT [FK_tbl_urun_tbl_kategori] FOREIGN KEY([KategoriID])
REFERENCES [dbo].[tbl_kategori] ([KategoriID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_urun] CHECK CONSTRAINT [FK_tbl_urun_tbl_kategori]
GO
/****** Object:  ForeignKey [FK_tbl_urun_tbl_marka]    Script Date: 03/22/2020 18:01:30 ******/
ALTER TABLE [dbo].[tbl_urun]  WITH CHECK ADD  CONSTRAINT [FK_tbl_urun_tbl_marka] FOREIGN KEY([MarkaID])
REFERENCES [dbo].[tbl_marka] ([MarkaID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_urun] CHECK CONSTRAINT [FK_tbl_urun_tbl_marka]
GO
