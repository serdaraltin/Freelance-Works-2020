Public Class Form5
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click




        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "INSERT INTO veli(veli_adi,veli_ogr_no,veli_yakinligi,ev_adresi,is_adresi,p_kodu,c_telefonu,tc_kimlik,egitim_durumu,gelir_duzeyi) VALUES ('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "','" + TextBox6.Text + "','" + TextBox7.Text + "','" + TextBox8.Text + "','" + TextBox9.Text + "','" + TextBox10.Text + "')"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()

        Form2.kmt.Dispose()



        MsgBox("Kayıt işlemi gerçekleştirildi !")

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form2.Show()
        Me.Hide()

    End Sub

    Private Sub Label11_Click(sender As Object, e As EventArgs) Handles Label11.Click
        Application.Exit()
    End Sub
End Class