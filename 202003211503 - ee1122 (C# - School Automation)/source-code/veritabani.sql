USE [KomurArdiye]
GO
/****** Object:  Table [dbo].[Firma]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Firma](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Ad] [nchar](20) NULL,
	[Mail] [nchar](20) NULL,
 CONSTRAINT [PK_Firma] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Musteri]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Musteri](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[TcNo] [nchar](20) NULL,
	[Ad] [nchar](30) NULL,
	[Soyad] [nchar](30) NULL,
	[Telefon] [nchar](20) NULL,
	[Eposta] [nchar](20) NULL,
	[Sehir] [nchar](20) NULL,
	[Ilce] [nchar](30) NULL,
	[Adres] [nchar](50) NULL,
 CONSTRAINT [PK_Musteri] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Odeme]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Odeme](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Musteri_Id] [int] NULL,
	[Tutar] [float] NULL,
	[SiparisTarih] [datetime] NULL,
	[OdemeTarih] [datetime] NULL,
	[FaturaNo] [varchar](60) NULL,
	[OdemeYontem] [nchar](10) NULL,
	[GirisTarih] [datetime] NULL,
	[CikisTarih] [datetime] NULL,
 CONSTRAINT [PK_Odeme] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[Siparis]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Siparis](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[MusteriId] [int] NULL,
	[SiparisTarih] [datetime] NULL,
	[TeslimatTarih] [datetime] NULL,
	[TeslimatAdres] [nchar](40) NULL,
 CONSTRAINT [PK_Siparis] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Siparis_Detay]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Siparis_Detay](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[SiparisId] [int] NULL,
	[UrunId] [int] NULL,
	[Miktar] [int] NULL,
	[Fiyat] [float] NULL,
 CONSTRAINT [PK_Siparis_Detay] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Toptanci]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Toptanci](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[FirmaId] [int] NULL,
	[Telefon] [nchar](20) NULL,
	[Mail] [nchar](20) NULL,
	[Adres] [nchar](40) NULL,
 CONSTRAINT [PK_Toptanci] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Urun]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Urun](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Barkod] [int] NULL,
	[UrunAd] [nchar](50) NULL,
	[Birim] [int] NULL,
	[Miktar] [int] NULL,
	[Fiyat] [float] NULL,
	[GirisTarih] [datetime] NULL,
	[CikisTarih] [datetime] NULL,
 CONSTRAINT [PK_Urun] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Yonetici]    Script Date: 6.03.2020 10:44:50 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Yonetici](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[KullaniciAd] [nchar](20) NULL,
	[Parola] [nchar](20) NULL,
 CONSTRAINT [PK_Yonetici] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
