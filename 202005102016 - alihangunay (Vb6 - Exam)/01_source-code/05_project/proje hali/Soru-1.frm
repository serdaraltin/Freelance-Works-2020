VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim fareninXkordinati As Integer 'farenin X kordinatinin tutulacagi tamsayi(integer) degisken
Dim fareninYkordinati As Integer 'farenin Y kordinatinin tutulacagi tamsayi(integer) degisken

'Form uzerinde fare ile týklanýp ardýndan kaldýrýlýrken çalýþan fonksiyon
Private Sub Form_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    'Forma farenin 2. butonu ile týklanmýþ ise
    If Button = 2 Then
        'formun yuksekligini tutan degisken
        yukseklik = Me.Height
        'formun genisligini tutan degisken
        genislik = Me.Width
        'rastgele uretilen ve formun genisligiyle sinirli tamsayi degisken
        uretilenXkordinati = Int((genislik * Rnd) + 1)
        'rastgele uretilen ve formun yuksekligiyle sinirli tamsayi degisken
        uretilenYkordinati = Int((yukseklik * Rnd) + 1)
        'form uzerinde cember cizimi, rastgele uretilen degerlerin gosterdigi kordinatlarda ciziliyor , 35 buyuklugunde
        Circle (uretilenXkordinati - 1, uretilenYkordinati - 1), 35
        'form uzerinde cember cizimi, farenin kordinatlarinda ciziliyor, 35 buyuklugunde
        Circle (fareninXkordinati - 1, fareninYkordinati - 1), 35
        'form uzerinde cizgi cizimi, baslangici rastgele uretilen kordinalar ve bitisi farenin kordinatlari
        Line (uretilenXkordinati, uretilenYkordinati)-(fareninXkordinati, fareninYkordinati)
    End If
End Sub
 
'form uzerinde farenin hareket ettirilmesi durumunda calisan fonksiyon
Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    'fonksiyon kendi icerisinde o anki farenin X ve Y kordinatlarini veriyor
    'buna gore daha onceden tanimlanmis tamsayi degiskenlere ilgili kordinatlar ataniyor
    fareninYkordinati = Y
    fareninXkordinati = X
End Sub
