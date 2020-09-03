Imports System.Data

Imports System.Data.OleDb
Public Class Form8
    Public table As New DataTable
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "DELETE FROM personel WHERE soyadi = '" + TextBox1.Text & "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()
        MsgBox("Silme İşlemi Başarılı!!")
        personel()

    End Sub
    Public Sub personel()

        table.Clear()

        Dim adtr As New OleDbDataAdapter(" Select * from personel ", Form2.bag)

        adtr.Fill(table)

        DataGridView1.DataSource = table

    End Sub
    Private Sub Form8_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        personel()

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = ((((((((((((("UPDATE personel SET gorevi='" + TextBox1.Text & "' , adi='") + TextBox2.Text & "',soyadi='") + TextBox3.Text & "', sinifi='") + TextBox4.Text & "',cinsiyeti='") + TextBox5.Text & "',bölümü='") + TextBox6.Text & "',dali ='") + TextBox7.Text & "',ev_adresi='") + TextBox8.Text & "',posta_kodu='") + TextBox9.Text & "',semt='") + TextBox10.Text & "', sehir='") + TextBox11.Text & "',telefon='") + TextBox12.Text & "',maas='") + TextBox14.Text & "',cep_telefon='") + TextBox13.Text & "' where soyadi='" & TextBox1.Text & "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.kmt.Dispose()

        Form2.bag.Close()
        personel()

    End Sub

    Private Sub LinkLabel1_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Form2.Show()
        Me.Hide()

    End Sub
End Class