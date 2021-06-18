Public Class Form3
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = (((((((((("INSERT INTO ogr(numarasi,adi,soyadi,sinifi,cinsiyeti,bölümü,dali,ev_adresi,posta_kodu,semt,sehir) VALUES ('" + TextBox1.Text & "','") + TextBox2.Text & "','") + TextBox3.Text & "','") + TextBox4.Text & "','") + TextBox5.Text & "','") + TextBox6.Text & "','") + TextBox7.Text & "','") + TextBox8.Text & "','") + TextBox9.Text & "','") + TextBox10.Text & "','") + TextBox11.Text & "')"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()

        Form2.kmt.Dispose()
        MsgBox("Kayıt İşlemi Başarılı")

    End Sub

    Private Sub Form3_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form2.Show()
        Me.Hide()

    End Sub
End Class