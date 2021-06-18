VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   1125
   ClientLeft      =   1530
   ClientTop       =   1275
   ClientWidth     =   2490
   LinkTopic       =   "Form1"
   ScaleHeight     =   1125
   ScaleWidth      =   2490
   Begin VB.CommandButton Command1 
      Caption         =   "Buton"
      Height          =   375
      Left            =   480
      TabIndex        =   0
      Top             =   360
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
girdiMetni = InputBox("Metin giriniz")
 
For i = Len(girdiMetni) To 1 Step -1
    Var = Mid(girdiMetni, i, 1)
    tersMetin = tersMetin & Var
Next
 
MsgBox tersMetin

For i = 1 To Len(girdiMetni) Step 1

    If Mid(girdiMetni, i, 1) <> "a" And Mid(girdiMetni, i, 1) <> "e" And Mid(girdiMetni, i, 1) <> "ý" And Mid(girdiMetni, i, 1) <> "i" And Mid(girdiMetni, i, 1) <> "o" And Mid(girdiMetni, i, 1) <> "ö" And Mid(girdiMetni, i, 1) <> "u" And Mid(girdiMetni, i, 1) <> "ü" Then
        Var = Mid(girdiMetni, i, 1)
        sessizMetin = sessizMetin & Var
    End If
Next

MsgBox sessizMetin

MsgBox Len(sessizMetin)

End Sub
