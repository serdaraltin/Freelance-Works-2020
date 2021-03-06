USE [Dershane]
GO
/****** Object:  StoredProcedure [dbo].[ders_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[ders_Ekle]
@personel_Id int,
@ad varchar(50)

As
Begin
Insert Into ders (personel_Id,ad) Values(@personel_Id,@ad)
End
GO
/****** Object:  StoredProcedure [dbo].[ders_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[ders_Guncelle]
@Id int,
@personel_Id int,
@ad varchar(50)

As
Begin
Update ders set personel_Id=@personel_Id,ad=@ad
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[Getir]    Script Date: 9.03.2020 15:36:20 ******/
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
/****** Object:  StoredProcedure [dbo].[Kayitlar]    Script Date: 9.03.2020 15:36:20 ******/
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
/****** Object:  StoredProcedure [dbo].[odeme_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[odeme_Ekle]
@ogrenci_Id int,
@yil int,
@ucret int

As
Begin
Insert Into odeme (ogrenci_Id,yil,ucret) Values(@ogrenci_Id,@yil,@ucret)
End
GO
/****** Object:  StoredProcedure [dbo].[odeme_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[odeme_Guncelle]
@Id int,
@ogrenci_Id int,
@yil int,
@ucret int

As
Begin
Update odeme set ogrenci_Id=@ogrenci_Id,yil=@yil,ucret=@ucret
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[ogrenci_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[ogrenci_Ekle]
@sinif_Id int,
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@bolum varchar(20),
@dal varchar(50),
@adres text

As
Begin
Insert Into ogrenci(sinif_Id,tcNo,ad,soyad,cinsiyet,telefon,bolum,dal,adres) Values(@sinif_Id,@tcNo,@ad,@soyad,@cinsiyet,@telefon,@bolum,@dal,@adres)
End
GO
/****** Object:  StoredProcedure [dbo].[ogrenci_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[ogrenci_Guncelle]
@Id int,
@sinif_Id int,
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@bolum varchar(20),
@dal varchar(50),
@adres text

As
Begin
Update ogrenci set sinif_Id=@sinif_Id,tcNo=@tcNo,ad=@ad,soyad=@soyad,cinsiyet=@cinsiyet,telefon=@telefon,bolum=@bolum,dal=@dal,adres=@adres
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[personel_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[personel_Ekle]
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@adres text,
@dal varchar(50),
@bolum varchar(50),
@maas int


As
Begin
Insert Into personel(tcNo,ad,soyad,cinsiyet,telefon,adres,dal,bolum,maas) Values(@tcNo,@ad,@soyad,@cinsiyet,@telefon,@adres,@dal,@bolum,@maas)
End
GO
/****** Object:  StoredProcedure [dbo].[personel_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[personel_Guncelle]
@Id int,
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@adres text,
@dal varchar(50),
@maas int,
@bolum varchar(20)

As
Begin
Update personel set tcNo=@tcNo,ad=@ad,soyad=@soyad,cinsiyet=@cinsiyet,telefon=@telefon,adres=@adres,dal=@dal,bolum=@bolum,maas=@maas
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[program_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[program_Ekle]
@ders_Id int,
@sinif_Id int,
@gun varchar(20),
@baslangic varchar(10),
@bitis varchar(10)
As
Begin
Insert Into program (ders_Id,sinif_Id,gun,baslangic,bitis)
Values (@ders_Id,@sinif_Id,@gun,@baslangic,@bitis)
End
GO
/****** Object:  StoredProcedure [dbo].[program_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[program_Guncelle]
@Id int,
@ders_Id int,
@sinif_Id int,
@gun varchar(20),
@baslangic varchar(10),
@bitis varchar(10)
As
Begin
Update program set ders_Id=@ders_Id,sinif_Id=@sinif_Id,gun=@gun,baslangic=@baslangic,bitis=@bitis
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[Sil]    Script Date: 9.03.2020 15:36:20 ******/
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
/****** Object:  StoredProcedure [dbo].[sinif_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[sinif_Ekle]
@ad varchar(50),
@blok varchar(20)

As
Begin
Insert Into sinif (ad,blok) Values(@ad,@blok)
End
GO
/****** Object:  StoredProcedure [dbo].[sinif_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[sinif_Guncelle]
@Id int,
@ad varchar(50),
@blok varchar(20)

As
Begin
Update sinif set ad=@ad,blok=@blok
Where Id=@Id
End
GO
/****** Object:  StoredProcedure [dbo].[veli_Ekle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[veli_Ekle]
@ogrenci_Id int,
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@adres text,
@egitim varchar(20),
@gelir int,
@yakinlik varchar(20)


As
Begin
Insert Into veli (ogrenci_Id,tcNo,ad,soyad,cinsiyet,telefon,adres,egitim,gelir,yakinlik) Values(@ogrenci_Id,@tcNo,@ad,@soyad,@cinsiyet,@telefon,@adres,@egitim,@gelir,@yakinlik)
End
GO
/****** Object:  StoredProcedure [dbo].[veli_Guncelle]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create Proc [dbo].[veli_Guncelle]
@Id int,
@ogrenci_Id int,
@tcNo varchar(15),
@ad varchar(50),
@soyad varchar(50),
@cinsiyet varchar(10),
@telefon varchar(20),
@adres text,
@egitim varchar(20),
@gelir int,
@yakinlik varchar(20)

As
Begin
Update veli set ogrenci_Id=@ogrenci_Id,tcNo=@tcNo,ad=@ad,soyad=@soyad,cinsiyet=@cinsiyet,telefon=@telefon,adres=@adres,egitim=@egitim,gelir=@gelir,yakinlik=@yakinlik
Where Id=@Id
End
GO
/****** Object:  Table [dbo].[ders]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ders](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[personel_Id] [int] NULL,
	[ad] [varchar](50) NULL,
 CONSTRAINT [PK_ders] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[odeme]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[odeme](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[ogrenci_Id] [int] NULL,
	[yil] [int] NULL,
	[ucret] [float] NULL,
 CONSTRAINT [PK_odeme] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ogrenci]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ogrenci](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[sinif_Id] [int] NULL,
	[tcNo] [varchar](15) NULL,
	[ad] [varchar](50) NULL,
	[soyad] [varchar](50) NULL,
	[cinsiyet] [varchar](10) NULL,
	[telefon] [varchar](20) NULL,
	[bolum] [varchar](20) NULL,
	[dal] [varchar](50) NOT NULL,
	[adres] [text] NULL,
 CONSTRAINT [PK_ogrenci_1] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[personel]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[personel](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[tcNo] [varchar](15) NULL,
	[ad] [varchar](50) NULL,
	[soyad] [varchar](50) NULL,
	[cinsiyet] [varchar](10) NULL,
	[telefon] [varchar](20) NULL,
	[adres] [text] NULL,
	[dal] [varchar](50) NOT NULL,
	[bolum] [varchar](20) NULL,
	[maas] [int] NULL,
 CONSTRAINT [PK_personel] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[program]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[program](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[ders_Id] [int] NULL,
	[sinif_Id] [int] NULL,
	[gun] [varchar](20) NULL,
	[baslangic] [varchar](10) NULL,
	[bitis] [varchar](50) NULL,
 CONSTRAINT [PK_program] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[sinif]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[sinif](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[ad] [varchar](50) NULL,
	[blok] [varchar](20) NULL,
 CONSTRAINT [PK_sinif] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[veli]    Script Date: 9.03.2020 15:36:20 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[veli](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[ogrenci_Id] [int] NULL,
	[tcNo] [varchar](15) NULL,
	[ad] [varchar](50) NULL,
	[soyad] [varchar](50) NULL,
	[cinsiyet] [varchar](10) NULL,
	[telefon] [varchar](20) NULL,
	[adres] [text] NULL,
	[egitim] [varchar](20) NULL,
	[gelir] [int] NULL,
	[yakinlik] [varchar](20) NULL,
 CONSTRAINT [PK_ogrenci] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
ALTER TABLE [dbo].[ders]  WITH CHECK ADD  CONSTRAINT [FK_ders_personel] FOREIGN KEY([personel_Id])
REFERENCES [dbo].[personel] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[ders] CHECK CONSTRAINT [FK_ders_personel]
GO
ALTER TABLE [dbo].[odeme]  WITH CHECK ADD  CONSTRAINT [FK_odeme_ogrenci] FOREIGN KEY([ogrenci_Id])
REFERENCES [dbo].[ogrenci] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[odeme] CHECK CONSTRAINT [FK_odeme_ogrenci]
GO
ALTER TABLE [dbo].[program]  WITH CHECK ADD  CONSTRAINT [FK_program_ders] FOREIGN KEY([ders_Id])
REFERENCES [dbo].[ders] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[program] CHECK CONSTRAINT [FK_program_ders]
GO
ALTER TABLE [dbo].[program]  WITH CHECK ADD  CONSTRAINT [FK_program_sinif] FOREIGN KEY([sinif_Id])
REFERENCES [dbo].[sinif] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[program] CHECK CONSTRAINT [FK_program_sinif]
GO
ALTER TABLE [dbo].[veli]  WITH CHECK ADD  CONSTRAINT [FK_veli_ogrenci] FOREIGN KEY([ogrenci_Id])
REFERENCES [dbo].[ogrenci] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[veli] CHECK CONSTRAINT [FK_veli_ogrenci]
GO
