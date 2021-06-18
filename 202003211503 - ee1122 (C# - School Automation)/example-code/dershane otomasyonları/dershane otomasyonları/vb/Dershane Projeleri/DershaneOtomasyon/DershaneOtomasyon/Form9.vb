Imports System.Data

Imports System.Data.OleDb
Public Class Form9
    Public table As New DataTable
    Public table1 As New DataTable
    Public table2 As New DataTable
    Public table3 As New DataTable
    Public table4 As New DataTable
    Dim maas
    Dim gelir
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        table.Clear()

        Dim adtr As New OleDbDataAdapter(" Select SUM(maas) From personel ", Form2.bag)

        adtr.Fill(table)

        DataGridView1.DataSource = table

        Dim toplammaas = DataGridView1.Rows(0).Cells(0).Value

        Label2.Text = toplammaas.ToString

        maas = toplammaas
        table1.Clear()

        Dim adttr As New OleDbDataAdapter(" Select AVG(maas) From personel ", Form2.bag)

        adttr.Fill(table1)

        DataGridView1.DataSource = table1

        Dim ortalamamaas = DataGridView1.Rows(0).Cells(0).Value
        Label4.Text = ortalamamaas.ToString

        table2.Clear()

        Dim aadtr As New OleDbDataAdapter(" Select MAX(maas) From personel ", Form2.bag)

        aadtr.Fill(table2)

        DataGridView1.DataSource = table2

        Dim enyuksekmaas = DataGridView1.Rows(0).Cells(0).Value

        Label6.Text = enyuksekmaas.ToString

        table3.Clear()

        Dim aadtrr As New OleDbDataAdapter(" Select MIN(maas) From personel ", Form2.bag)

        aadtrr.Fill(table3)

        DataGridView1.DataSource = table3

        Dim endusukmaas = DataGridView1.Rows(0).Cells(0).Value

        Label8.Text = endusukmaas.ToString


    End Sub

    Private Sub Form9_Load(sender As Object, e As EventArgs) Handles MyBase.Load

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click

        table4.Clear()

        Dim adtr5 As New OleDbDataAdapter(" Select * from ogr ", Form2.bag)

        adtr5.Fill(table4)

        DataGridView3.DataSource = table4
        Dim ogrencisayisi = (DataGridView3.RowCount - 1).ToString

        Label10.Text = ogrencisayisi
        Label12.Text = 2000 * ogrencisayisi
        gelir = 2000 * ogrencisayisi
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Label14.Text = maas * 12
        Label16.Text = gelir
        Label18.Text = gelir - (maas * 12)
        If Label18.Text >= 0 Then
            Label19.Text = "Cari Açık Yoktur"
        Else
            Label19.Text = "Cari Açık Vardır"
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Form2.Show()
        Me.Hide()

    End Sub
End Class