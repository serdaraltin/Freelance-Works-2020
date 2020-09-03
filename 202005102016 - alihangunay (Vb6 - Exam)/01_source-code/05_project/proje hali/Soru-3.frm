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
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   480
      TabIndex        =   0
      Top             =   720
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
MsgBox "    ALTIN   " + parcala(doviz(False))
MsgBox "    DOVÝZ   " + parcala(doviz(True))
End Sub

Function parcala(parcalanacakmetin As String) As String
Dim islemsonucu As String

Dim adim1() As String
adim1() = Split(parcalanacakmetin, "/")

For i = 0 To UBound(adim1)
    Dim adim2() As String
    adim2() = Split(adim1(i), "*")
    Dim adim3() As String
    adim3() = Split(adim2(1), "-")
    islemsonucu = islemsonucu & vbCrLf & adim2(0) & "=" & adim3(0) & "/" & adim3(1)
Next

parcala = islemsonucu
End Function


'Hocanin kodu
Function doviz(yatirimkodu As Boolean) As String
Dim veri As String
If yatirimkodu Then
veri = "Dolar*5-6/TL*1-2/Euro*6-7"
Else
veri = "Gram*80-90/Yarim*500-600/Tam*1000-1200"
End If
doviz = veri
End Function

