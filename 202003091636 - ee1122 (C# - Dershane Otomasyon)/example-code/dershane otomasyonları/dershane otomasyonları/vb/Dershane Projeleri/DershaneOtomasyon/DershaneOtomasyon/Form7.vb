Public Class Form7
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = ((((((((((((("INSERT INTO personel(gorevi,adi,soyadi,sinifi,cinsiyeti,bölümü,dali,ev_adresi,posta_kodu,semt,sehir,telefon,cep_telefon,maas) VALUES ('" + ComboBox1.Text & "','") + TextBox2.Text & "','") + TextBox3.Text & "','") + TextBox4.Text & "','") + TextBox5.Text & "','") + TextBox6.Text & "','") + TextBox7.Text & "','") + TextBox8.Text & "','") + TextBox9.Text & "','") + TextBox10.Text & "','") + TextBox11.Text & "','") + TextBox12.Text & "','") + TextBox13.Text & "','") + TextBox14.Text & "')"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()

        Form2.kmt.Dispose()
        MsgBox("Kayıt İşlemi Başarılı")
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
        If Not ComboBox1.Text = "Öğretmen" Then
            TextBox4.Enabled = False
            TextBox5.Enabled = False
            TextBox6.Enabled = False
        Else
            TextBox4.Enabled = True

            TextBox5.Enabled = True

            TextBox6.Enabled = True

        End If

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form2.Show()
        Me.Hide()
    End Sub
End Class