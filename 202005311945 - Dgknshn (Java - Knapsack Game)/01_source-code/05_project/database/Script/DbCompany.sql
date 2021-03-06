USE [master]
GO
/****** Object:  Database [DbCompany]    Script Date: 2.06.2020 19:40:36 ******/
CREATE DATABASE [DbCompany]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'DbCompany', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DbCompany.mdf' , SIZE = 5120KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'DbCompany_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\DbCompany_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [DbCompany] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [DbCompany].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [DbCompany] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [DbCompany] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [DbCompany] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [DbCompany] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [DbCompany] SET ARITHABORT OFF 
GO
ALTER DATABASE [DbCompany] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [DbCompany] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [DbCompany] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [DbCompany] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [DbCompany] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [DbCompany] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [DbCompany] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [DbCompany] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [DbCompany] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [DbCompany] SET  DISABLE_BROKER 
GO
ALTER DATABASE [DbCompany] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [DbCompany] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [DbCompany] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [DbCompany] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [DbCompany] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [DbCompany] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [DbCompany] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [DbCompany] SET RECOVERY FULL 
GO
ALTER DATABASE [DbCompany] SET  MULTI_USER 
GO
ALTER DATABASE [DbCompany] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [DbCompany] SET DB_CHAINING OFF 
GO
ALTER DATABASE [DbCompany] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [DbCompany] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [DbCompany] SET DELAYED_DURABILITY = DISABLED 
GO
EXEC sys.sp_db_vardecimal_storage_format N'DbCompany', N'ON'
GO
USE [DbCompany]
GO
/****** Object:  Table [dbo].[tb_Employee_Project]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tb_Employee_Project](
	[counter] [int] IDENTITY(1,1) NOT NULL,
	[Employee_Id] [int] NULL,
	[Project_Id] [int] NULL,
	[StartDate] [date] NULL,
	[FinisDate] [date] NULL,
 CONSTRAINT [PK_tb_Employee_Project] PRIMARY KEY CLUSTERED 
(
	[counter] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[tbl_Customer]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_Customer](
	[customer_Id] [int] IDENTITY(1,1) NOT NULL,
	[Customer_Name] [varbinary](80) NULL,
	[Address] [text] NULL,
	[Phone] [varbinary](15) NULL,
 CONSTRAINT [PK_tbl_Customer] PRIMARY KEY CLUSTERED 
(
	[customer_Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_Department]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_Department](
	[Department_Id] [int] IDENTITY(1,1) NOT NULL,
	[Department_Name] [varbinary](80) NULL,
 CONSTRAINT [PK_tbl_Department] PRIMARY KEY CLUSTERED 
(
	[Department_Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_Department_Project_Control]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_Department_Project_Control](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[Department_Id] [int] NULL,
	[Project_Id] [int] NULL,
	[StartDate] [date] NULL,
	[FinishDate] [date] NULL,
	[info] [text] NULL,
 CONSTRAINT [PK_tbl_Department_Project_Control] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[tbl_Employee]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_Employee](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [varchar](80) NULL,
	[LastName] [varchar](80) NULL,
	[Address] [text] NULL,
	[StartDate] [date] NULL,
	[Salary] [float] NULL,
	[Department_Id] [int] NULL,
 CONSTRAINT [PK_tbl_Employee] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_Project]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_Project](
	[Project_Id] [int] IDENTITY(1,1) NOT NULL,
	[Project_Name] [varbinary](80) NULL,
	[projectType_Id] [int] NULL,
	[finishDate] [date] NULL,
 CONSTRAINT [PK_tbl_Project] PRIMARY KEY CLUSTERED 
(
	[Project_Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[tbl_Project_Sales]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tbl_Project_Sales](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[customer_Id] [int] NULL,
	[Project_Id] [int] NULL,
	[Sel_Date] [date] NULL,
	[TecnicalSupportTime] [date] NULL,
	[TimePeriod] [date] NULL,
	[Price] [float] NULL,
 CONSTRAINT [PK_tbl_Project_Sales] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[tbl_ProjectType]    Script Date: 2.06.2020 19:40:36 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[tbl_ProjectType](
	[type_Id] [int] NOT NULL,
	[Type_Name] [varbinary](80) NULL,
 CONSTRAINT [PK_tbl_ProjectType] PRIMARY KEY CLUSTERED 
(
	[type_Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
ALTER TABLE [dbo].[tb_Employee_Project]  WITH CHECK ADD  CONSTRAINT [FK_tb_Employee_Project_tbl_Employee] FOREIGN KEY([Employee_Id])
REFERENCES [dbo].[tbl_Employee] ([Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tb_Employee_Project] CHECK CONSTRAINT [FK_tb_Employee_Project_tbl_Employee]
GO
ALTER TABLE [dbo].[tb_Employee_Project]  WITH CHECK ADD  CONSTRAINT [FK_tb_Employee_Project_tbl_Project] FOREIGN KEY([Project_Id])
REFERENCES [dbo].[tbl_Project] ([Project_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tb_Employee_Project] CHECK CONSTRAINT [FK_tb_Employee_Project_tbl_Project]
GO
ALTER TABLE [dbo].[tbl_Department_Project_Control]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Department_Project_Control_tbl_Department] FOREIGN KEY([Department_Id])
REFERENCES [dbo].[tbl_Department] ([Department_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Department_Project_Control] CHECK CONSTRAINT [FK_tbl_Department_Project_Control_tbl_Department]
GO
ALTER TABLE [dbo].[tbl_Department_Project_Control]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Department_Project_Control_tbl_Project] FOREIGN KEY([Project_Id])
REFERENCES [dbo].[tbl_Project] ([Project_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Department_Project_Control] CHECK CONSTRAINT [FK_tbl_Department_Project_Control_tbl_Project]
GO
ALTER TABLE [dbo].[tbl_Employee]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Employee_tbl_Department] FOREIGN KEY([Department_Id])
REFERENCES [dbo].[tbl_Department] ([Department_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Employee] CHECK CONSTRAINT [FK_tbl_Employee_tbl_Department]
GO
ALTER TABLE [dbo].[tbl_Project]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Project_tbl_ProjectType] FOREIGN KEY([projectType_Id])
REFERENCES [dbo].[tbl_ProjectType] ([type_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Project] CHECK CONSTRAINT [FK_tbl_Project_tbl_ProjectType]
GO
ALTER TABLE [dbo].[tbl_Project_Sales]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Project_Sales_tbl_Customer] FOREIGN KEY([customer_Id])
REFERENCES [dbo].[tbl_Customer] ([customer_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Project_Sales] CHECK CONSTRAINT [FK_tbl_Project_Sales_tbl_Customer]
GO
ALTER TABLE [dbo].[tbl_Project_Sales]  WITH CHECK ADD  CONSTRAINT [FK_tbl_Project_Sales_tbl_Project] FOREIGN KEY([Project_Id])
REFERENCES [dbo].[tbl_Project] ([Project_Id])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[tbl_Project_Sales] CHECK CONSTRAINT [FK_tbl_Project_Sales_tbl_Project]
GO
USE [master]
GO
ALTER DATABASE [DbCompany] SET  READ_WRITE 
GO
