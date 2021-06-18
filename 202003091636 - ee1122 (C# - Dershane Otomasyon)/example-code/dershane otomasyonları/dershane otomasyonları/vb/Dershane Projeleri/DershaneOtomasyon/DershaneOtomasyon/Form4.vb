Imports System.Data

Imports System.Data.OleDb

Public Class Form4
    Public table As New DataTable




    Public Sub ogrenci()

        table.Clear()

        Dim adtr As New OleDbDataAdapter(" Select * from ogr ", Form2.bag)

        adtr.Fill(table)

        dataGridView1.DataSource = table

    End Sub

    Private Sub Form4_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ogrenci()

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "DELETE FROM ogr WHERE numarasi = '" + textBox1.Text & "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()




        ogrenci()



        MsgBox("Silme işlemi gerçekleştirildi !")
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = (((((((((((("UPDATE ogr SET numarasi='" + TextBox1.Text & "' , adi='") + TextBox2.Text & "',soyadi='") + TextBox3.Text & "', sinifi='") + TextBox4.Text & "',cinsiyeti='") + TextBox5.Text & "',bölümü='") + TextBox6.Text & "',dali ='") + TextBox7.Text & "',ev_adresi='") + TextBox8.Text & "',posta_kodu='") + TextBox9.Text & "',semt='") + TextBox10.Text & "', sehir='") + TextBox11.Text & "',telefon='") + TextBox12.Text & "',cep_telefon='") + TextBox13.Text & "' where numarasi='" & TextBox1.Text & "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.kmt.Dispose()

        Form2.bag.Close()



        ogrenci()



        MsgBox("Güncelleme işlemi gerçekleştirildi !")
    End Sub

    Private Sub Label14_Click(sender As Object, e As EventArgs) Handles Label14.Click
        Form2.Show()
        Me.Hide()

    End Sub

    Private Sub Label15_Click(sender As Object, e As EventArgs) Handles Label15.Click
        Application.Exit()
    End Sub
End Class