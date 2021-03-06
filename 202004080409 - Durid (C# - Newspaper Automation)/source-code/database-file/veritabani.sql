USE [gazete]
GO
/****** Object:  Table [dbo].[tbl_abone]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_abone](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[AboneTur] [varchar](50) NULL,
	[TcNo] [varchar](12) NULL,
	[Ad] [varchar](50) NULL,
	[Soyad] [varchar](50) NULL,
	[Telefon] [varchar](12) NULL,
	[Email] [varchar](50) NULL,
	[Meslek] [varchar](50) NULL,
	[Adres] [text] NULL,
	[AbonelikUcret] [float] NULL,
 CONSTRAINT [PK_tbl_abone] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_aboneUrun]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_aboneUrun](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[AboneId] [int] NULL,
	[UrunId] [int] NULL,
	[BaslangicTarih] [date] NULL,
	[BitisTarih] [date] NULL,
	[Durum] [varchar](10) NULL,
 CONSTRAINT [PK_tbl_abone_urun] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_firma]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_firma](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[FirmaAd] [varchar](50) NULL,
	[Slogan] [varchar](100) NULL,
	[Il] [varchar](50) NULL,
	[Ilce] [varchar](50) NULL,
	[Adres] [text] NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_firma] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_personel]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_personel](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[TcNo] [varchar](12) NULL,
	[Ad] [varchar](50) NULL,
	[Soyad] [varchar](50) NULL,
	[Cinsiyet] [varchar](5) NULL,
	[Telefon] [varchar](12) NULL,
	[Email] [varchar](50) NULL,
	[Bolum] [varchar](50) NULL,
	[Adres] [text] NULL,
	[BaslangicTarih] [date] NULL,
 CONSTRAINT [PK_tbl_personel] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_stok]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_stok](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[UrunId] [int] NULL,
	[Adet] [int] NULL,
	[EklemeTarih] [date] NULL,
 CONSTRAINT [PK_tbl_stok] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[tbl_teslimat]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_teslimat](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[AboneUrunId] [int] NULL,
	[Sayi] [int] NULL,
	[TeslimatTarih] [date] NULL,
	[Aciklama] [text] NULL,
 CONSTRAINT [PK_tbl_teslimat] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[tbl_urun]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_urun](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Tur] [varchar](50) NULL,
	[UrunAd] [varchar](150) NULL,
	[Fiyat] [float] NULL,
 CONSTRAINT [PK_tbl_urun] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_yonetici]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_yonetici](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[KullaniciAd] [varchar](50) NULL,
	[Parola] [varchar](50) NULL,
 CONSTRAINT [PK_tbl_yonetici] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  StoredProcedure [dbo].[Getir]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[Getir]
@Tablo varchar(50),
@Id int

As
Begin
EXEC('Select *From '+ @Tablo+' Where Id='+@Id)
End
GO
/****** Object:  StoredProcedure [dbo].[Kayitlar]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[Kayitlar]
@Tablo varchar(50)
As
Begin
	EXEC('Select * From ' + @Tablo)
End
GO
/****** Object:  StoredProcedure [dbo].[Sil]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[Sil]
@Tablo varchar(50),
@Id int

As
Begin
EXEC('Delete From '+ @Tablo+' Where Id='+@Id)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_abone_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_abone_Ekle]
@AboneTur varchar(50),
@TcNo varchar(12),
@Ad varchar(50),
@Soyad varchar(50),
@Telefon varchar(12),
@Email varchar(50),
@Meslek varchar(50),
@Adres text,
@AbonelikUcret float

As
Begin
Insert Into tbl_abone (AboneTur,TcNo,Ad,Soyad,Telefon,Email,Meslek,Adres,AbonelikUcret) Values(@AboneTur,@TcNo,@Ad,@Soyad,@Telefon,@Email,@Meslek,@Adres,@AbonelikUcret)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_abone_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_abone_Guncelle]
@Id int,
@AboneTur varchar(50),
@TcNo varchar(12),
@Ad varchar(50),
@Soyad varchar(50),
@Telefon varchar(12),
@Email varchar(50),
@Meslek varchar(50),
@Adres text,
@AbonelikUcret float

As
Begin
Update tbl_abone Set AboneTur=@AboneTur,TcNo=@TcNo,Ad=@Ad,Soyad=@Soyad,Telefon=@Telefon,Email=@Email,Meslek=@Meslek,Adres=@Adres,AbonelikUcret=@AbonelikUcret
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_aboneUrun_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_aboneUrun_Ekle]
@AboneId int,
@UrunId int,
@BaslangicTarih date,
@BitisTarih date,
@Durum varchar(50)

As
Begin
Insert Into tbl_aboneUrun (AboneId,UrunId,BaslangicTarih,BitisTarih,Durum) Values(@AboneId,@UrunId,@BaslangicTarih,@BitisTarih,@Durum)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_aboneUrun_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_aboneUrun_Guncelle]
@Id int,
@AboneId int,
@UrunId int,
@BaslangicTarih date,
@BitisTarih date,
@Durum varchar(50)

As
Begin
Update tbl_aboneUrun Set AboneId=@AboneId,UrunId=@UrunId,BaslangicTarih=@BaslangicTarih,BitisTarih=@BitisTarih,Durum=@Durum
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_firma_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_firma_Ekle]
@FirmaAd varchar(50),
@Slogan varchar(100),
@Il varchar(50),
@Ilce varchar(50),
@Adres text,
@Aciklama text

As
Begin
Insert Into tbl_firma (FirmaAd,Slogan,Il,Ilce,Adres,Aciklama) Values(@FirmaAd,@Slogan,@Il,@Ilce,@Adres,@Aciklama)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_firma_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_firma_Guncelle]
@Id int,
@FirmaAd varchar(50),
@Slogan varchar(100),
@Il varchar(50),
@Ilce varchar(50),
@Adres text,
@Aciklama text

As
Begin
Update tbl_firma Set FirmaAd=@FirmaAd,Slogan=@Slogan,Il=@Il,Ilce=@Ilce,Adres=@Adres,Aciklama=@Aciklama
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_personel_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_personel_Ekle]
@TcNo varchar(12),
@Ad varchar(50),
@Soyad varchar(50),
@Cinsiyet varchar(5),
@Telefon varchar(12),
@Email varchar(50),
@Bolum varchar(50),
@Adres text,
@BaslangicTarih date

As
Begin
Insert Into tbl_personel (TcNo,Ad,Soyad,Cinsiyet,Telefon,Email,Bolum,Adres,BaslangicTarih) Values(@TcNo,@Ad,@Soyad,@Cinsiyet,@Telefon,@Email,@Bolum,@Adres,@BaslangicTarih)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_personel_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_personel_Guncelle]
@Id int,
@TcNo varchar(12),
@Ad varchar(50),
@Soyad varchar(50),
@Cinsiyet varchar(5),
@Telefon varchar(12),
@Email varchar(50),
@Bolum varchar(50),
@Adres text,
@BaslangicTarih date

As
Begin
Update tbl_personel Set TcNo=@TcNo,Ad=@Ad,Soyad=@Soyad,Cinsiyet=@Cinsiyet,Telefon=@Telefon,Email=@Email,Bolum=@Bolum,Adres=@Adres,BaslangicTarih=@BaslangicTarih
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_stok_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_stok_Ekle]
@UrunId int,
@Adet int,
@EklemeTarih date

As
Begin
Insert Into tbl_stok (UrunId,Adet,EklemeTarih) Values(@UrunId,@Adet,@EklemeTarih)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_stok_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_stok_Guncelle]
@Id int,
@UrunId int,
@Adet int,
@EklemeTarih date

As
Begin
Update tbl_stok Set UrunId=@UrunId,Adet=@Adet,EklemeTarih=@EklemeTarih
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_teslimat_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_teslimat_Ekle]
@AboneUrunId int,
@Sayi int,
@TeslimatTarih date,
@Aciklama text

As
Begin
Insert Into tbl_teslimat (AboneUrunId,Sayi,TeslimatTarih,Aciklama) Values(@AboneUrunId,@Sayi,@TeslimatTarih,@Aciklama)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_teslimat_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_teslimat_Guncelle]
@Id int,
@AboneUrunId int,
@Sayi int,
@TeslimatTarih date,
@Aciklama text

As
Begin
Update tbl_teslimat Set AboneUrunId=@AboneUrunId,Sayi=@Sayi,TeslimatTarih=@TeslimatTarih,Aciklama=@Aciklama
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_urun_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_urun_Ekle]
@Tur varchar(50),
@UrunAd varchar(150),
@Fiyat float

As
Begin
Insert Into tbl_urun (Tur,UrunAd,Fiyat) Values(@Tur,@UrunAd,@Fiyat)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_urun_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_urun_Guncelle]
@Id int,
@Tur varchar(50),
@UrunAd varchar(150),
@Fiyat float

As
Begin
Update tbl_urun Set Tur=@Tur,UrunAd=@UrunAd,Fiyat=@Fiyat
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_yonetici_Ekle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_yonetici_Ekle]
@KullaniciAd varchar(50),
@Parola varchar(50)

As
Begin
Insert Into tbl_yonetici (KullaniciAd,Parola) Values(@KullaniciAd,@Parola)
End
GO
/****** Object:  StoredProcedure [dbo].[tbl_yonetici_Guncelle]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[tbl_yonetici_Guncelle]
@Id int,
@KullaniciAd varchar(50),
@Parola varchar(50)

As
Begin
Update tbl_yonetici Set KullaniciAd=@KullaniciAd,Parola=@Parola
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[Yonetici_Kontrol]    Script Date: 8.04.2020 01:28:03 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[Yonetici_Kontrol]
@KullaniciAd varchar(50),
@Parola varchar(50)

As
Begin
Select * From tbl_yonetici Where KullaniciAd=@KullaniciAd And Parola=@Parola
End
GO
