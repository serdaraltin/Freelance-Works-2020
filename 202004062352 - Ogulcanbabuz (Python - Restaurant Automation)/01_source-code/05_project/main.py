from tkinter import *
import tkinter.font as tkFont

veriler=[]

for i in range(16):
	veriler.append(["","",""])

def Dosya_Oku():
	dosya = open("veri.txt","r")
	for satir in dosya:
		try:
			veri = satir.split(',')
			Rezarvasyon_Yap(veri[0], veri[1], veri[2])
		except:
			pass

def Dosya_Yaz():
	dosya = open("veri.txt","w")
	for veri in veriler:
		if veri[1] != "":
			dosya.write(veri[0]+","+veri[1]+","+veri[2]+"\n")
	dosya.close()

def Rezarvasyon_Yap(masa,isim,telefon):


	masa = int(masa)
	veriler[masa] = [str(masa),isim,telefon]
	Dosya_Yaz()
	if(masa == 1):
		btn_1.configure(bg="red")
	elif(masa == 2):
		btn_2.configure(bg="red")
	elif(masa == 3):
		btn_3.configure(bg="red")
	elif(masa == 4):
		btn_4.configure(bg="red")
	elif(masa == 5):
		btn_5.configure(bg="red")
	elif(masa == 6):
		btn_6.configure(bg="red")
	elif(masa == 7):
		btn_7.configure(bg="red")
	elif(masa == 8):
		btn_8.configure(bg="red")
	elif(masa == 9):
		btn_9.configure(bg="red")
	elif(masa == 10):
		btn_10.configure(bg="red")
	elif(masa == 11):
		btn_11.configure(bg="red")
	elif(masa == 12):
		btn_12.configure(bg="red")
	elif(masa == 13):
		btn_13.configure(bg="red")
	elif(masa == 14):
		btn_14.configure(bg="red")
	elif(masa == 15):
		btn_15.configure(bg="red")

def Rezarvasyon_Sil():
	lbl_Bilgi = Label(frm_Ust, text="Rezarvasyon Silindi", justify = LEFT,bg="red",fg="white")
	lbl_Bilgi.pack(side=LEFT,padx=15)
	lbl_Bilgi.after(2000,lbl_Bilgi.destroy)

	imasa = int(lbl_Masa['text'].split(':')[1])
	veriler[imasa] = ["","",""]
	btn_color = "#2b9200"

	txt_Isim.delete(1.0,END)
	txt_Telefon.delete(1.0,END)
	if(imasa == 1):
		btn_1.configure(bg=btn_color)
	elif(imasa == 2):
		btn_2.configure(bg=btn_color)
	elif(imasa == 3):
		btn_3.configure(bg=btn_color)
	elif(imasa == 4):
		btn_4.configure(bg=btn_color)
	elif(imasa == 5):
		btn_5.configure(bg=btn_color)
	elif(imasa == 6):
		btn_6.configure(bg=btn_color)
	elif(imasa == 7):
		btn_7.configure(bg=btn_color)
	elif(imasa == 8):
		btn_8.configure(bg=btn_color)
	elif(imasa == 9):
		btn_9.configure(bg=btn_color)
	elif(imasa == 10):
		btn_10.configure(bg=btn_color)
	elif(imasa == 11):
		btn_11.configure(bg=btn_color)
	elif(imasa == 12):
		btn_12.configure(bg=btn_color)
	elif(imasa == 13):
		btn_13.configure(bg=btn_color)
	elif(imasa == 14):
		btn_14.configure(bg=btn_color)
	elif(imasa == 15):
		btn_15.configure(bg=btn_color)
	Dosya_Yaz()

def Masa_Sec(masa):
	lbl_Masa.configure(text ="Masa:"+str(masa))
	txt_Isim.delete(1.0,END)
	txt_Telefon.delete(1.0,END)
	if veriler[int(masa)][1] != "":		
		txt_Isim.insert(INSERT,veriler[int(masa)][1])
		txt_Telefon.insert(INSERT,veriler[int(masa)][2])


		
def Rezarvasyon_Ekle():
	if lbl_Masa['text'] != "Masa:[Seçilmemiş]":
		Rezarvasyon_Yap(lbl_Masa['text'].split(':')[1],txt_Isim.get("1.0","end-1c") ,txt_Telefon.get("1.0","end-1c"))
		lbl_Bilgi = Label(frm_Ust, text="Eklendi", justify = LEFT,bg="#2b9200",fg="white")
		lbl_Bilgi.pack(side=LEFT,padx=15)
		
		lbl_Bilgi.after(2000,lbl_Bilgi.destroy)

#pencere özellikleri
pencere = Tk()
pencere.geometry("1138x595")
pencere.resizable(False,False)
pencere.title("Restoran Rezarvasyon Otomasyonu")

#Üst Kısım
frm_Ust = Frame(pencere)

#Başlık
lbl_Baslik = Label(frm_Ust, text="Restoran Otomasyon Sistemi",bg = "#0089c5", fg="white", font=("Arial","22"),width=71,height=1)
lbl_Baslik.pack(pady=7)
#Masa
lbl_Masa = Label(frm_Ust, text="Masa:[Seçilmemiş]", justify = LEFT)
lbl_Masa.pack(side=LEFT)
#Müşteri İsim
lbl_Isim = Label(frm_Ust, text="Müşteri Isim:", justify = LEFT)
lbl_Isim.pack(side=LEFT,padx=15)
txt_Isim = Text(frm_Ust,height=1,width=20)
txt_Isim.pack(side=LEFT)
#Müşteri Telefon
lbl_Telefon = Label(frm_Ust, text="Müşteri Telefon:", justify = LEFT)
lbl_Telefon.pack(side=LEFT,padx=15)
txt_Telefon = Text(frm_Ust,height=1,width=20)
txt_Telefon.pack(side=LEFT)
#Rezarvasyon Kaydet/Güncelle
btn_Ekle = Button(frm_Ust, text="Rezarvasyon Ekle/Güncelle",bg="white", command = Rezarvasyon_Ekle)
btn_Ekle.pack(side=LEFT,padx=20)
#Rezarvasyon Sil
btn_Sil = Button(frm_Ust, text="Rezarvasyonu Sil",bg="white",command = Rezarvasyon_Sil)
btn_Sil.pack(side=LEFT,padx=20)


#Alt Kısım
frm_Alt = Frame(pencere,relief=SUNKEN,bd=3)
#buton özellikleri
btn_width = 10
btn_height = 4
btn_color = "#2b9200"
btn_padx = 10
btn_pady = 10

#btn_1
btn_1 = Button(frm_Alt, text="1",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(1))
btn_1.grid(row=1, padx =btn_padx,pady=btn_pady)
#btn_2
btn_2 = Button(frm_Alt, text="2",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(2))
btn_2.grid(row=2,  padx =btn_padx,pady=btn_pady)
#btn_3
btn_3 = Button(frm_Alt, text="3",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(3))
btn_3.grid(row=3, padx =btn_padx,pady=btn_pady)
#btn_4
btn_4 = Button(frm_Alt, text="3",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(4))
btn_4.grid(row=1, column=1, padx =btn_padx,pady=btn_pady)
#btn_5
btn_5 = Button(frm_Alt, text="4",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(5))
btn_5.grid(row=2, column=1, padx =btn_padx,pady=btn_pady)
#btn_6
btn_6 = Button(frm_Alt, text="6",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(6))
btn_6.grid(row=3, column=1,  padx =btn_padx,pady=btn_pady)
#btn_7
btn_7 = Button(frm_Alt, text="7",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(7))
btn_7.grid(row=1, column=2, padx =btn_padx,pady=btn_pady)
#btn_8
btn_8 = Button(frm_Alt, text="8",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(8))
btn_8.grid(row=2, column=2, padx =btn_padx,pady=btn_pady)
#btn_9
btn_9 = Button(frm_Alt, text="9",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(9))
btn_9.grid(row=3, column=2,  padx =btn_padx,pady=btn_pady)
#btn_10
btn_10 = Button(frm_Alt, text="10",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(10))
btn_10.grid(row=1, column=3, padx =btn_padx,pady=btn_pady)
#btn_11
btn_11 = Button(frm_Alt, text="11",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(11))
btn_11.grid(row=2, column=3, padx =btn_padx,pady=btn_pady)
#btn_12
btn_12 = Button(frm_Alt, text="12",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(12))
btn_12.grid(row=3, column=3,  padx =btn_padx,pady=btn_pady)
#btn_13
btn_13 = Button(frm_Alt, text="13",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(13))
btn_13.grid(row=1, column=4, padx =btn_padx,pady=btn_pady)
#btn_14
btn_14 = Button(frm_Alt, text="14",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(14))
btn_14.grid(row=2, column=4, padx =btn_padx,pady=btn_pady)
#btn_15
btn_15 = Button(frm_Alt, text="15",bg=btn_color,width=btn_width,height=btn_height, command= lambda: Masa_Sec(15))
btn_15.grid(row=3, column=4,  padx =btn_padx,pady=btn_pady)


#frameler
frm_Ust.pack()
frm_Alt.pack(fill=BOTH,expand=1, padx=10,pady=10)

Dosya_Oku()
pencere.mainloop()

	
