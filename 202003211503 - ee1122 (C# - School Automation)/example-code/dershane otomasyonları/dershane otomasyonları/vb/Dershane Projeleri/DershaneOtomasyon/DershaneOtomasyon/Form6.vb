Imports System.Data

Imports System.Data.OleDb
Public Class Form6
    Public table As New DataTable
    Public Sub velibilgileri()

        table.Clear()

        Dim adtr As New OleDbDataAdapter(" Select * from veli ", Form2.bag)

        adtr.Fill(table)

        DataGridView1.DataSource = table

    End Sub
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "DELETE FROM veli WHERE tc_kimlik = '" + TextBox11.Text + "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()

        Form2.kmt.Dispose()

        MsgBox("Silme işlemi gerçekleştirildi !")
        velibilgileri()


    End Sub

    Private Sub Form6_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        velibilgileri()

    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "UPDATE veli SET veli_adi='" + TextBox1.Text + "' , veli_ogr_no='" + TextBox2.Text + "',veli_yakinligi='" + TextBox3.Text + "', is_adresi='" + TextBox4.Text + "',ev_adresi='" + TextBox5.Text + "',p_kodu='" + TextBox6.Text + "',c_telefonu ='" + TextBox7.Text + "',tc_kimlik='" + TextBox8.Text + "',egitim_durumu='" + TextBox9.Text + "',gelir_duzeyi='" + TextBox10.Text & "' where tc_kimlik='" & TextBox11.Text & "'"

        Form2.kmt.ExecuteNonQuery()

        Form2.kmt.Dispose()

        Form2.bag.Close()

        velibilgileri()


        MsgBox("Güncelleme işlemi gerçekleştirildi !")
    End Sub

    Private Sub LinkLabel1_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Form2.Show()
        Me.Hide()

    End Sub

    Private Sub LinkLabel2_LinkClicked(sender As Object, e As LinkLabelLinkClickedEventArgs) Handles LinkLabel2.LinkClicked
        Application.Exit()
    End Sub
End Class