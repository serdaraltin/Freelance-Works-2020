Public Class frmMain
    Dim bm As Bitmap
    Dim g_bm As Graphics

    Dim scale_bm As Integer = 4

    Dim bDrawing As Boolean = False

    Dim mouse_lastPos As Point

    Dim b_mouseExited As Boolean = False

    Dim drawingArea As Rectangle

    Private Sub frmMain_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Init()
    End Sub

    Private Sub Init()
        bm = New Bitmap(256, 256)
        g_bm = Graphics.FromImage(bm)

        g_bm.Clear(Color.Black)

        ResizeCanvas()

        pbCanvas.Invalidate()
    End Sub

    Private Sub pbCanvas_MouseDown(sender As Object, e As MouseEventArgs) Handles pbCanvas.MouseDown
        If drawingArea.Contains(e.Location) Then
            mouse_lastPos = New Point(e.X \ scale_bm, e.Y \ scale_bm)

            bDrawing = True

            bm.SetPixel(e.X \ scale_bm, e.Y \ scale_bm, Color.White)

            pbCanvas.Invalidate()
        End If
    End Sub

    Private Sub pbCanvas_MouseMove(sender As Object, e As MouseEventArgs) Handles pbCanvas.MouseMove
        If drawingArea.Contains(e.Location) Then
            If b_mouseExited = True Then
                mouse_lastPos = New Point(e.X \ scale_bm, e.Y \ scale_bm)
                bDrawing = Not bDrawing
                b_mouseExited = False
            End If
            If bDrawing Then
                g_bm.DrawLine(Pens.White, mouse_lastPos, New Point(e.X \ scale_bm, e.Y \ scale_bm))
            End If

            mouse_lastPos = New Point(e.X \ scale_bm, e.Y \ scale_bm)

            pbCanvas.Invalidate()
        Else
            bDrawing = False
            b_mouseExited = True
        End If
    End Sub

    Private Sub pbCanvas_MouseUp(sender As Object, e As MouseEventArgs) Handles pbCanvas.MouseUp
        bDrawing = False
        b_mouseExited = False
    End Sub

    Private Sub pbCanvas_Paint(sender As Object, e As PaintEventArgs) Handles pbCanvas.Paint
        e.Graphics.InterpolationMode = Drawing2D.InterpolationMode.NearestNeighbor
        e.Graphics.PixelOffsetMode = Drawing2D.PixelOffsetMode.Half

        e.Graphics.DrawImage(bm, 0, 0, bm.Width * scale_bm, bm.Height * scale_bm)

        e.Graphics.FillRectangle(Brushes.White, mouse_lastPos.X * scale_bm, mouse_lastPos.Y * scale_bm, scale_bm, scale_bm)
    End Sub

    Private Sub ResizeCanvas()
        pbCanvas.ClientSize = New Size(bm.Width * scale_bm, bm.Height * scale_bm)
        drawingArea = pnlCanvas.ClientRectangle
    End Sub

    Private Sub frmMain_Resize(sender As Object, e As EventArgs) Handles Me.Resize
        If bm IsNot Nothing Then ResizeCanvas()
    End Sub
End Class
