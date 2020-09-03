masaSayisi = 10
veriDosyasi = "veri.txt"
veriler=[]

for i in range(masaSayisi):
	veriler.append(["","",""])


def DosyaOku():
	dosya = open(veriDosyasi,"r")
	for satir in dosya:
		try:
			veri = satir.split(',')
			veriler[int(veri[0])] = [veri[0],veri[1],veri[2]]
		except:
			pass
	print("Bilgi : Kayitlar "+veriDosyasi+" dosyasindan okundu.\n")
	dosya.close()


def DosyaYaz():
	dosya = open(veriDosyasi,"w")
	for veri in veriler:
		if(veri[1] != ""):
			dosya.write(veri[0]+","+veri[1]+","+veri[2]+"\n")
	dosya.close()


def MasaKontrol(masaNo):
	if(masaNo < 1 or masaNo > 10):
		return -1
	if(veriler[masaNo][0] != ""):
		return 1
	return 0


def RezervasyonEkle(masaNo,musteriIsim,musteriTelefon):
	try:
		veriler[masaNo] = [str(masaNo),musteriIsim,musteriTelefon]
		DosyaYaz()
		DosyaOku()
		return True
	except:
		return False

def RezervasyonYap():
	print("\n")
	masaNo = input("Masa No : ")
	if(MasaKontrol(masaNo) != 0):
		if(MasaKontrol(masaNo) == -1):
			print("Gecersiz bir masa numarasi girdiniz!")
		elif(MasaKontrol(masaNo) == 1):
			print("Masa dolu!")
		RezervasyonYap()
		return
	musteriIsim = raw_input("Musteri Isim : ")
	musteriTelefon = raw_input("Musteri Telefon : ")
	if(RezervasyonEkle(masaNo, musteriIsim, musteriTelefon)):
		print("Rezervasyon eklendi.")
	else:
		print("Hata : Rezervasyon eklenemiyor!")
	print("\n")


def RezervasyonGuncelle():
	print("\n")
	masaNo = input("Masa No : ")
	if(MasaKontrol(masaNo) == -1):
		print("Gecersiz bir masa numarasi girdiniz!")
		RezervasyonGuncelle()
		return
	if(MasaKontrol(masaNo) != 1):
		print("Masa bos.")
		RezervasyonGuncelle()
		return
	musteriIsim = raw_input("Musteri Isim : ")
	musteriTelefon = raw_input("Musteri Telefon : ")
	veriler[masaNo] = [str(masaNo),musteriIsim,musteriTelefon]
	DosyaYaz()
	DosyaOku()
	print("\n------------------------------------")
	print("Masa No : "+str(masaNo)+"\nMusteri Isim : "+musteriIsim+"\nMusteri Telefon : "+musteriTelefon)
	print("------------------------------------\n")
	print("Rezervasyon guncellendi.\n")
	print("\n")

def RezervasyonAra():
	print("\n")
	musteriIsim = raw_input("Musteri Isim : ")
	bulundu = False
	for veri in veriler:
		if(veri[1] == musteriIsim):
			bulundu = True
			print("\n------------------------------------")
			print("Masa No : "+veri[0]+"\nMusteri Isim : "+veri[1]+"\nMusteri Telefon : "+veri[2])
			print("------------------------------------\n")
			return bulundu
	if(bulundu == False):
		print("Uyari : Aranan kayit bulunamadi.\n")
		return bulundu


def RezervasyonSil():
	print("\n")
	masaNo = input("Masa No : ")
	if(MasaKontrol(masaNo) == -1):
		print("Gecersiz bir masa numarasi girdiniz!")
		RezervasyonSil()
		return
	if(MasaKontrol(masaNo) != 1):
		print("Masa bos.")
		RezervasyonSil()
		return

	veriler[masaNo] = ["","",""]
	DosyaYaz()
	DosyaOku()
	print("Rezervasyon silindi.")
	print("\n")

def RezervasyonListele():
	print("\n")
	print("Masa\tIsim\t\tTelefon")
	print("------------------------------------")
	for veri in veriler:
		if(veri[1] != ""):
			print(veri[0]+'\t'+veri[1]+'\t'+veri[2])
	print("------------------------------------")
	print("\n")

def Menu():
	print(">>> Restoran Rezervasyon Otomasyonu <<<")
	print("1) Rezervasyon Yap")
	print("2) Rezervasyon Guncelle")
	print("3) Rezervasyon Ara")
	print("4) Rezervasyon Sil")
	print("5) Rezervasyon Listele")
	print("0) Cikis")
	secim = raw_input("Seciminiz : ")
	if(secim == "0"):
		print("Cikis yapiliyor...")
		quit()
	elif(secim == "1"):
		RezervasyonYap()
	elif(secim == "2"):
		RezervasyonGuncelle()
	elif(secim == "3"):
		RezervasyonAra()
	elif(secim == "4"):
		RezervasyonSil()
	elif(secim == "5"):
		RezervasyonListele()
	else:
		print("Hata : Yanlis bir secim yaptiniz.")
	Menu()

DosyaOku()
Menu()