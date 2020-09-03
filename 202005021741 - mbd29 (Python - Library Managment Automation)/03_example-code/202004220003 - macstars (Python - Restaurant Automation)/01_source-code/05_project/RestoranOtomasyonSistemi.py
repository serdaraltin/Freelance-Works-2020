from tkinter import *

data=[]
for i in range(16):
	data.append(["","",""])
def Ayir(masa,isim,telefon):
	masa = int(masa)
	data[masa] = [str(masa),isim,telefon]
	WriteFile()
	if(masa == 1):
		dugme1.configure(bg="red")
	elif(masa == 2):
		dugme2.configure(bg="red")
	elif(masa == 3):
		dugme3.configure(bg="red")
	elif(masa == 4):
		dugme4.configure(bg="red")
	elif(masa == 5):
		dugme5.configure(bg="red")
	elif(masa == 6):
		dugme6.configure(bg="red")
	elif(masa == 7):
		dugme7.configure(bg="red")
	elif(masa == 8):
		dugme8.configure(bg="red")
	elif(masa == 9):
		dugme9.configure(bg="red")
	elif(masa == 10):
		dugme10.configure(bg="red")
	elif(masa == 11):
		dugme11.configure(bg="red")
	elif(masa == 12):
		dugme12.configure(bg="red")
	elif(masa == 13):
		dugme13.configure(bg="red")
	elif(masa == 14):
		dugme14.configure(bg="red")
	elif(masa == 15):
		dugme15.configure(bg="red")
def ReadFile():
	dosya = open("veri.txt","r")
	for satir in dosya:
		try:
			satir = satir.split(',')
			Ayir(satir[0], satir[1], satir[2])
		except:
			pass
def Sil():
	bilgilb = Label(ustkisim, text="Silindi", justify = LEFT,bg="red",fg="white")
	bilgilb.pack(side=LEFT,padx=15)
	bilgilb.after(2000,bilgilb.destroy)
	imasa = int(masalb['text'].split(':')[1])
	data[imasa] = ["","",""]
	isimtxt.delete(1.0,END)
	telefontxt.delete(1.0,END)
	if(imasa == 1):
		dugme1.configure(bg="green")
	if(imasa == 2):
		dugme2.configure(bg="green")
	if(imasa == 3):
		dugme3.configure(bg="green")
	if(imasa == 4):
		dugme4.configure(bg="green")
	if(imasa == 5):
		dugme5.configure(bg="green")
	if(imasa == 6):
		dugme6.configure(bg="green")
	if(imasa == 7):
		dugme7.configure(bg="green")
	if(imasa == 8):
		dugme8.configure(bg="green")
	if(imasa == 9):
		dugme9.configure(bg="green")
	if(imasa == 10):
		dugme10.configure(bg="green")
	if(imasa == 11):
		dugme11.configure(bg="green")
	if(imasa == 12):
		dugme12.configure(bg="green")
	if(imasa == 13):
		dugme13.configure(bg="green")
	if(imasa == 14):
		dugme14.configure(bg="green")
	if(imasa == 15):
		dugme15.configure(bg="green")
	WriteFile()
def Ekle():
	if masalb['text'] != "Masa:[Seçilmemiş]":
		Ayir(masalb['text'].split(':')[1],isimtxt.get("1.0","end-1c") ,telefontxt.get("1.0","end-1c"))
		bilgilb = Label(ustkisim, text="Eklendi", justify = LEFT,bg="green",fg="white")
		bilgilb.pack(side=LEFT,padx=15)
		bilgilb.after(2000,bilgilb.destroy)
def WriteFile():
	dosya = open("veri.txt","w")
	for satir in data:
		if satir[1] != "":
			dosya.write(satir[0]+","+satir[1]+","+satir[2]+"\n")
	dosya.close()
def Sec(masa):
	masalb.configure(text ="Masa:"+str(masa))
	isimtxt.delete(1.0,END)
	telefontxt.delete(1.0,END)
	if data[int(masa)][1] != "":		
		isimtxt.insert(INSERT,data[int(masa)][1])
		telefontxt.insert(INSERT,data[int(masa)][2])	

window = Tk()
window.geometry("1150x600")
window.resizable(False,False)
window.title("Restoran Rezarvasyon Otomasyonu")
ustkisim = Frame(window)
titlelb = Label(ustkisim, text="Restoran Otomasyon Sistemi",bg = "blue", fg="white", font=("Arial","22"),width=75,height=1)
titlelb.pack(pady=7)
masalb = Label(ustkisim, text="Masa:[Seçilmemiş]", justify = LEFT)
masalb.pack(side=LEFT)
isimlb = Label(ustkisim, text="Müşteri Isim:", justify = LEFT)
isimlb.pack(side=LEFT,padx=15)
isimtxt = Text(ustkisim,height=1,width=20)
isimtxt.pack(side=LEFT)
telefonlb = Label(ustkisim, text="Müşteri Telefon:")
telefonlb.pack(side=LEFT,padx=15)
telefontxt = Text(ustkisim,height=1,width=20)
telefontxt.pack(side=LEFT)
eklelb = Button(ustkisim, text="Rezarvasyon Ekle/Güncelle",bg="white", command = Ekle)
eklelb.pack(side=LEFT,padx=20)
silbtn = Button(ustkisim, text="Rezarvasyonu Sil",bg="white",command = Sil)
silbtn.pack(side=LEFT,padx=20)
altkisim = Frame(window,relief=SUNKEN,bd=3)
dugme1 = Button(altkisim, text="1",bg="green",width=10,height=4, command= lambda: Sec(1))
dugme1.grid(row=1, padx =10,pady=10)
dugme2 = Button(altkisim, text="2",bg="green",width=10,height=4, command= lambda: Sec(2))
dugme2.grid(row=2,  padx =10,pady=10)
dugme3 = Button(altkisim, text="3",bg="green",width=10,height=4, command= lambda: Sec(3))
dugme3.grid(row=3, padx =10,pady=10)
dugme4 = Button(altkisim, text="4",bg="green",width=10,height=4, command= lambda: Sec(4))
dugme4.grid(row=1, column=1, padx =10,pady=10)
dugme5 = Button(altkisim, text="5",bg="green",width=10,height=4, command= lambda: Sec(5))
dugme5.grid(row=2, column=1, padx =10,pady=10)
dugme6 = Button(altkisim, text="6",bg="green",width=10,height=4, command= lambda: Sec(6))
dugme6.grid(row=3, column=1,  padx =10,pady=10)
dugme7 = Button(altkisim, text="7",bg="green",width=10,height=4, command= lambda: Sec(7))
dugme7.grid(row=1, column=2, padx =10,pady=10)
dugme8 = Button(altkisim, text="8",bg="green",width=10,height=4, command= lambda: Sec(8))
dugme8.grid(row=2, column=2, padx =10,pady=10)
dugme9 = Button(altkisim, text="9",bg="green",width=10,height=4, command= lambda: Sec(9))
dugme9.grid(row=3, column=2,  padx =10,pady=10)
dugme10 = Button(altkisim, text="10",bg="green",width=10,height=4, command= lambda: Sec(10))
dugme10.grid(row=1, column=3, padx =10,pady=10)
dugme11 = Button(altkisim, text="11",bg="green",width=10,height=4, command= lambda: Sec(11))
dugme11.grid(row=2, column=3, padx =10,pady=10)
dugme12 = Button(altkisim, text="12",bg="green",width=10,height=4, command= lambda: Sec(12))
dugme12.grid(row=3, column=3,  padx =10,pady=10)
dugme13 = Button(altkisim, text="13",bg="green",width=10,height=4, command= lambda: Sec(13))
dugme13.grid(row=1, column=4, padx =10,pady=10)
dugme14 = Button(altkisim, text="14",bg="green",width=10,height=4, command= lambda: Sec(14))
dugme14.grid(row=2, column=4, padx =10,pady=10)
dugme15 = Button(altkisim, text="15",bg="green",width=10,height=4, command= lambda: Sec(15))
dugme15.grid(row=3, column=4,  padx =10,pady=10)
ustkisim.pack()
altkisim.pack(fill=BOTH,expand=1, padx=10,pady=10)
ReadFile()
window.mainloop()

	
