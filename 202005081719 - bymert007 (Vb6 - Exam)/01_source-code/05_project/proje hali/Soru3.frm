VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   1455
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   2505
   LinkTopic       =   "Form1"
   ScaleHeight     =   1455
   ScaleWidth      =   2505
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Buton"
      Height          =   375
      Left            =   360
      TabIndex        =   0
      Top             =   480
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Function doviz(yatirimkodu As Boolean) As String
Dim veri As String
If yatirimkodu Then
veri = "Dolar*5-6/TL*1-2/Euro*6-7"
Else
veri = "Gram*80-90/Yarim*500-600/Tam*1000-1200"
End If
doviz = veri
End Function

Function parcala(metin As String) As String
Dim sonuc As String

Dim turler() As String
turler() = Split(metin, "/")

For i = 0 To UBound(turler)
    Dim tur() As String
    tur() = Split(turler(i), "*")
    Dim alisSatis() As String
    alisSatis() = Split(tur(1), "-")
    sonuc = sonuc + vbCrLf + tur(0) + "=" + alisSatis(0) + "/" + alisSatis(1)
Next

parcala = sonuc
End Function

Private Sub Command1_Click()
MsgBox "    ALTIN   " + parcala(doviz(False))
MsgBox "    DOVÝZ   " + parcala(doviz(True))
End Sub
