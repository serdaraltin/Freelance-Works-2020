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
      Left            =   1320
      TabIndex        =   0
      Top             =   840
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()

Dim metin As String
Dim metinters As String

metin = InputBox("Islemek uzere bir metin giriniz" + vbCrLf + "icerisinde sessiz harfler bulunmali")

For adim = Len(metin) To 1 Step -1
    Dim harf As String
    harf = Mid(metin, adim, 1)
    metinters = metinters & harf
Next

MsgBox metinters

Dim sessizmetin As String

For k = 1 To Len(metin) Step 1

      If Mid(metin, k, 1) <> "a" Then
          If Mid(metin, k, 1) <> "e" Then
            If Mid(metin, k, 1) <> "ý" Then
                If Mid(metin, k, 1) <> "i" Then
                    If Mid(metin, k, 1) <> "o" Then
                        If Mid(metin, k, 1) <> "ö" Then
                            If Mid(metin, k, 1) <> "u" Then
                                If Mid(metin, k, 1) <> "ü" Then
                                    sessizmetin = sessizmetin + Mid(metin, k, 1)
                                End If
                            End If
                        End If
                    End If
                End If
            End If
          End If
      End If
      
Next


MsgBox sessizmetin

Dim sessizmetinuzunluk As Integer

sessizmetinuzunluk = Len(sessizmetin)

MsgBox sessizmetinuzunluk


End Sub
