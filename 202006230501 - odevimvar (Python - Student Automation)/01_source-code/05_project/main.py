#-*- coding:utf-8 -*-
import os.path
from os import path

dosyaDersler = "dersler.txt"
dosyaOgrenciler = "ogrenciler.txt"
dosyaNotlar = "notlar.txt"

dersler = [] # bolumNo,sinifNo,dersKodu,dersAdi
ogrenciler = [] # bolumNo,sinifNo,ogrenciNo,ogrenciAdSoyad
notlar = [] # ogrenciNo,dersKodu,not

def DosyaYazDersler():#+
	try:
		dosya = open(dosyaDersler,"w")
		for ders in dersler:
			dosya.write(str(ders[0])+","+str(ders[1])+","+str(ders[2])+","+str(ders[3])+"\n")
		dosya.close()
		DosyaOkuDersler()
		return True
	except:
		return False

def DosyaYazOgrenciler():#+
	try:
		dosya = open(dosyaOgrenciler,"w")
		for ogrenci in ogrenciler:
			dosya.write(str(ogrenci[0])+","+str(ogrenci[1])+","+str(ogrenci[2])+","+str(ogrenci[3])+"\n")
		dosya.close()
		DosyaOkuOgrenciler()
		return True
	except:
		return False

def DosyaYazNotlar():#+
	try:
		dosya = open(dosyaNotlar,"w")
		for vnot in notlar:
			dosya.write(str(vnot[0])+","+str(vnot[1])+","+str(vnot[2])+"\n")
		dosya.close()
		DosyaOkuNotlar()
		return True
	except:
		return False

def DosyaOkuOgrenciler():#+
	if (path.exists(dosyaOgrenciler) == False):
		return
	del ogrenciler[:]
	dosya = open(dosyaOgrenciler,"r")
	for satir in dosya.readlines():
		try:
			satir = satir.split(',')
			ogrenciler.append([satir[0],satir[1],satir[2],satir[3]])
		except:
			pass
	dosya.close()

def DosyaOkuDersler():#+
	if (path.exists(dosyaDersler) == False):
		return
	del dersler[:]
	dosya = open(dosyaDersler,"r")
	for satir in dosya.readlines():
		try:
			satir = satir.split(',')
			dersler.append([satir[0],satir[1],satir[2],satir[3]])
		except:
			pass
	dosya.close()

def DosyaOkuNotlar():#+
	if (path.exists(dosyaNotlar) == False):
		return
	del notlar[:]
	dosya = open(dosyaNotlar,"r")
	for satir in dosya.readlines():
		try:
			satir = satir.split(',')
			notlar.append([satir[0],satir[1],satir[2]])
		except:
			pass
	dosya.close()

def AnaMenu():#+
	print("\n")
	print("1) Bölümleri Listele 2) Öğrenci Ara 3) Çıkış")
	secim = int(raw_input("Seçiminiz: "))
	if(secim == 1):
		BolumMenu()
	elif(secim == 2):
		OgrenciAra()
	elif(secim == 3):
		Cikis()
	else:
		print("Hatalı seçim yaptınız.Tekrar seçiniz!")
	AnaMenu()

def BolumMenu():#+
	print("\n")
	print("1) Yazılım Müh.")
	print("2) Endüstri Müh.")
	print("3) Elektrik Müh.")
	print("4) İnşaat Müh.")
	bolumNo = int(input("İşlem yapmak istediğiniz bölüm numarasını giriniz: "))
	
	if(bolumNo >= 1 or bolumNo <= 4):
		sinifNo = int(input("İşlem yapmak istediğiniz sınıfı giriniz: "))
		if(sinifNo >=1 or sinifNo <= 4):
			DersMenu(bolumNo, sinifNo)
		else:
			print("Hatalı seçim yaptınız.Tekrar seçiniz!")	
	else:
		print("Hatalı seçim yaptınız.Tekrar seçiniz!")
	BolumMenu()

def DersMenu(bolumNo,sinifNo):#+
	print("\n")
	print("1) Öğrencileri Listele 2) Dersleri Listele 3) Not Girişi")
	print("4) Öğrenci Ekle/Sil    5) Ders Ekle/Sil    6) Ana Menu")
	secim = int(raw_input("Seçenek giriniz: "))
	print("\n")
	if(secim == 1):
		OgrencileriListe(bolumNo, sinifNo)
	elif(secim == 2):
		DersleriListele(bolumNo,sinifNo)
	elif(secim == 3):
		NotGirisi(bolumNo, sinifNo)
	elif(secim == 4):
		OgrenciEkleSil(bolumNo)
	elif(secim == 5):
		DersEkleSil(bolumNo)
	elif(secim == 6):
		print("Ana menüye yönlendiriliyorsunuz...")
		AnaMenu()
	else:
		print("Hatalı seçim yaptınız.Tekrar seçiniz!")
	print("Önceki menüye yönlendiriliyorsunuz...")
	DersMenu(bolumNo,sinifNo)

def OgrenciAra():#+
	ogrenciNo = raw_input("Öğrenci No giriniz: ")
	if(OgrenciGetir(ogrenciNo)):
		print("\n"+ogrenciNo+" numaralı öğrenci bilgileri:\n")
		print("Adı Soyadı: "+OgrenciGetir(ogrenciNo)[3])
		print("Sınıf: "+OgrenciGetir(ogrenciNo)[1])
		return

	islem = raw_input(ogrenciNo+" numaralı bir öğrenci bulunamadı. Tekrar denemek iser misini? Evet / Hayır:")
	if(islem == "evet" or islem == "Evet"):
		OgrenciAra()
		return
	elif(islem == "hayır" or islem == "Hayır"):
		return

def OgrencileriListe(bolumNo,sinifNo):#+

	bolumNo = str(bolumNo)
	sinifNo = str(sinifNo)
	i=0
	for ogrenci in ogrenciler:
		if(ogrenci[1] == sinifNo and ogrenci[0] == bolumNo):
			i+=1
			print(ogrenci[2]+" "+ogrenci[3])
	print("\nToplam Öğrenci Sayısı: "+str(i))
	return

def OgrenciEkleSil(bolumNo):#+
	islem = raw_input('Öğrenci kaydetmek için "kaydet", öğrencinin kaydını silmek için ise "sil" yazınız: ')

	if(islem == "kaydet"):
		ogrenciNo = raw_input("Öğrenci No: ")
		if(OgrenciGetir(ogrenciNo)) is not None:
			print("Öğrenci zaten var.")
			return
		adSoyad = raw_input("Öğrenci Adı ve Soyadı: ")
		sinifNo = int(raw_input("Öğrencinin Sınıfı: "))
		if(OgrenciEkle(bolumNo, sinifNo, ogrenciNo, adSoyad)):
			print("Öğrenci "+str(sinifNo)+". sınıfa başarıyla kaydedildi.")
			print("Öğrenciye "+str(sinifNo)+". sınıf dersleri otomatik olarak eklendi.")
			return

	if(islem == "sil"):
		ogrenciNo = raw_input("Silmek istediğiniz öğrencinin numarası: ")
		if(OgrenciGetir(ogrenciNo)) is None:
			print("Öğrenci bulunamadı.")
			return
		secim = raw_input(ogrenciNo+' nolu öğrenci silinecektir. Onaylamak için "onay", iptal etmek için "iptal" yazınız:')
		if(secim == "onay"):
			if(OgrenciSil(ogrenciNo)):
				print(dersKodu+" adlı ders başarıyla silindi.")
			return
		elif(secim == "iptal"):
			print("İşlem iptal edildi.")
			return
	DosyaYazOgrenciler()

def OgrenciEkle(bolumNo,sinifNo,ogrenciNo,adSoyad):#+
	ogrenciler.append([str(bolumNo),str(sinifNo),ogrenciNo,adSoyad])
	return DosyaYazOgrenciler()

def OgrenciSil(ogrenciNo):#+
	if(ogrenciler.remove(OgrenciGetir(ogrenciNo))):
		return DosyaYazOgrenciler()

def OgrenciGetir(ogrenciNo):#+
	for ogrenci in ogrenciler:
		if(ogrenci[2] == ogrenciNo):
			return ogrenci
	return None

def DersleriListele(bolumNo,sinifNo):#+
	bolumNo = str(bolumNo)
	sinifNo = str(sinifNo)
	i=0
	for ders in dersler:
		if(ders[0] == bolumNo and ders[1] == sinifNo):
			print(ders[2]+" "+ders[3])
			i+=1
	print("\nToplam Ders Sayısı: "+str(i))

def DersEkleSil(bolumNo):#+
	islem = raw_input('Ders kaydetmek için "kaydet", ders silmek için ise "sil" yazınız: ')

	if(islem == "kaydet"):
		sinifNo = raw_input("Eklemek istediğiniz ders kaçıncı sınıfa ait: ")
		dersKodu = raw_input("Ders kodunu giriniz: ")
		if(DersGetir(bolumNo, sinifNo, dersKodu)) is not None:
			print("Ders zaten var!")
			return
		dersAdi = raw_input("Ders adını giriniz: ")

		if(DersEkle(bolumNo, sinifNo, dersKodu, dersAdi)):
			print(dersKodu+" kodlu ders başarıyla eklendi.")
			return

	elif(islem == "sil"):
		sinifNo = raw_input("Silmek istediğiniz ders kaçıncı sınıfa ait: ")
		dersKodu = raw_input("Ders kodunu giriniz: ")
		secim = raw_input(dersKodu+' adlı ders silinecektir. Onaylamak için "onay", iptal etmek için "iptal" yazınız:')
	
		if(secim == "onay"):
			if(DersSil(bolumNo, sinifNo,dersKodu)):
				print(dersKodu+" adlı ders başarıyla silindi.")
				return
		elif(secim == "iptal"):
			print("İşlem iptal edildi.")
			return

def DersEkle(bolumNo,sinifNo,dersKodu,dersAdi):#+
	dersler.append([bolumNo,sinifNo,dersKodu,dersAdi])
	return DosyaYazDersler()

def DersSil(bolumNo,sinifNo,dersKodu):#+
	if(dersler.remove(DersGetir(bolumNo, sinifNo, dersKodu))):
		return True
	return False

def DersGetir(bolumNo,sinifNo,dersKodu):#+
	for ders in dersler:
		if(ders[2] == dersKodu):
			return ders

def NotGirisi(bolumNo,sinifNo):#+
	ogrenciNo = raw_input("Öğrenci No: ")
	if(OgrenciGetir(ogrenciNo)) is None:
		print("Öğrenci bulunamadı.")
		return
	ogrenciBilgi = []

	for ogrenci in ogrenciler:
		if(ogrenci[2] == ogrenciNo):
			ogrenciBilgi = ogrenci
			break

	i=0
	for ders in dersler:
		if(ders[0] == str(bolumNo) and ders[1] == str(sinifNo)):
			i+=1
			print(str(i)+") "+ders[2]+" "+ders[3])

	print("Bu öğrenci toplam "+str(len(dersler))+" sayıda ders almaktadır.\n")
	dersNo = int(input("Hangi ders için not girmek istersiniz: "))
	nottur = int(input("1) Vize 2) Final :"))

	if(nottur == 2):
		final = int(input("Final notunu giriniz: "))
		print(ogrenciBilgi[2]+" numaralo "+ogrenciBilgi[3]+" adlı öğrencinin final notunu "+str(final)+" olarak girdiniz.")
		islem = raw_input('Onaylamak için "onay", iptal etmek için "iptal" yazınız: ')
		if(islem == "iptal"):
			print("İşlem iptal edildi.")
			return
		elif(islem == "onay"):
			if(NotGir(dersler[dersNo-1], ogrenciNo, final*0.6)):
				print("Öğrencinin notu başarıyla girildi.")
				return
	elif(nottur == 1):
		vize = int(input("Vize notunu giriniz: "))
		print(ogrenciBilgi[2]+" numaralo "+ogrenciBilgi[3]+" adlı öğrencinin vize notunu "+str(vize)+" olarak girdiniz.")
		islem = raw_input('Onaylamak için "onay", iptal etmek için "iptal" yazınız: ')
		if(islem == "iptal"):
			print("İşlem iptal edildi.")
			return
		elif(islem == "onay"):
			if(NotGir(dersler[dersNo-1], ogrenciNo, vize*0.4)):
				print("Öğrencinin notu başarıyla girildi.")
				return
	DosyaYazNotlar()

def NotGir(ders,ogrenciNo,puan):#+
	notlar.append([ders[2],ogrenciNo,puan])
	return DosyaYazNotlar()

def Cikis():#+
	print("Program kapatılıyor...")
	quit()


DosyaOkuOgrenciler()
DosyaOkuDersler()
DosyaOkuNotlar()

print("Öğrenci Bilgi Sistemi")
AnaMenu()


