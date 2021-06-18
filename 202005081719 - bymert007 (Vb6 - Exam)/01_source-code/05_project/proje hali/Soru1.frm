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
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   4200
      Top             =   2520
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim mouse_X As Integer
Dim mouse_Y As Integer

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    mouse_X = X
    mouse_Y = Y
End Sub

Private Sub Form_MouseUp(Button As Integer, Shift As Integer, X As Single, Y As Single)
    If Button = 2 Then
        Dim rastgele_X As Integer
        rastgele_X = Int((Me.Width * Rnd) + 1)
        Dim rastgele_Y As Integer
        rastgele_Y = Int((Me.Height * Rnd) + 1)
        
        Me.Line (rastgele_X, rastgele_Y)-(mouse_X, mouse_Y), QBColor(0)
       
        Circle (rastgele_X, rastgele_Y), 30, QBColor(0)
        Circle (mouse_X, mouse_Y), 30, QBColor(0)
        
    End If
End Sub
