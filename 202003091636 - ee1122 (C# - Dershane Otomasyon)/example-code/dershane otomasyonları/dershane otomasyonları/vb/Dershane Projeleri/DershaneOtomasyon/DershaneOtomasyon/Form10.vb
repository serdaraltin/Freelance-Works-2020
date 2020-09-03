Imports System.Data

Imports System.Data.OleDb
Public Class Form10
    Public table As New DataTable
    Public Sub odev()


        table.Clear()

        Dim adtr As New OleDbDataAdapter(" Select * from ödev ", Form2.bag)

        adtr.Fill(table)

        DataGridView1.DataSource = table


    End Sub
    Private Sub Form10_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        odev()

        ComboBox1.Items.Add("BİLGİSAYAR BÖLÜMÜ")

        ComboBox1.Items.Add("ELEKTRİK-ELEKTRONİK BÖLÜMÜ")

        ComboBox1.Items.Add("METAL BÖLÜMÜ")

        ComboBox1.Items.Add("MOBİLYA DEKORASYON BÖLÜMÜ")

        ComboBox1.Items.Add("MAKİNA RESSAMLIĞI BÖLÜMÜ")

        ComboBox1.Items.Add("YİYECEK İÇECEK BÖLÜMÜ")

        ComboBox1.Items.Add("KİMYA BÖLÜMÜ")

        ComboBox2.Items.Add("Dil Ve Anlatım")

        ComboBox2.Items.Add("Türk Edebiyatı")

        ComboBox2.Items.Add("Kimya")

        ComboBox2.Items.Add("Coğrafya")

        ComboBox2.Items.Add("Tarih")

        ComboBox2.Items.Add("Analitik Geometri")

        ComboBox2.Items.Add("Biyoloji")

        ComboBox2.Items.Add("Din Kültürü")

        ComboBox2.Items.Add("Geometri")

        ComboBox2.Items.Add("Fizik")

        ComboBox2.Items.Add("Matematik")
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click

        Form2.bag.Open()

        Form2.kmt.Connection = Form2.bag

        Form2.kmt.CommandText = "INSERT INTO ödev(ogrenci_adi,soyadi,sinifi,bolumu,dersi,konusu,verilis_tarihi,teslim_tarihi,verilen_not,mail_adresi) VALUES ('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + ComboBox1.Text + "','" + ComboBox2.Text + "','" + ComboBox3.Text + "','" + TextBox4.Text + "','" + TextBox5.Text + "','" + TextBox6.Text + "','" + TextBox7.Text + "')"

        Form2.kmt.ExecuteNonQuery()

        Form2.bag.Close()

        Form2.kmt.Dispose()

        MsgBox("Kayıt işlemi gerçekleştirildi !")

        odev()

    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox2.SelectedIndexChanged
        If ComboBox2.Text = "Dil Ve Anlatım" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Anlatım Bozuklukları")

            ComboBox3.Items.Add("Ses Bilgisi")

            ComboBox3.Items.Add("Yazım Kuralları")

            ComboBox3.Items.Add("Noktalama İşaretleri")

            ComboBox3.Items.Add("Tamlamalar")

            ComboBox3.Items.Add("Sözcükte Yapı")

        End If

        If ComboBox2.Text = "Türk Edebiyatı" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Servet-i Fünun Edebiyatı")

            ComboBox3.Items.Add("Tanzimat Edebiyatı")

            ComboBox3.Items.Add("Düz Yazı Türleri")

            ComboBox3.Items.Add("Fecr-i Ati Edebiyatı")

            ComboBox3.Items.Add("Mili Edebiyat")

        End If

        If ComboBox2.Text = "Kimya" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Mol Kavramı")

            ComboBox3.Items.Add("Kimyasal Bağlar")

            ComboBox3.Items.Add("Bileşikler")

            ComboBox3.Items.Add("Alkoller Ve Eterler")

            ComboBox3.Items.Add("Karbonhidratlar")

            ComboBox3.Items.Add("Alifatik Amonyak Türevleri")

            ComboBox3.Items.Add("Esterler")

            ComboBox3.Items.Add("Organik Kimya")

        End If

        If ComboBox2.Text = "Coğrafya" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Türkiye'nın Beşeri Coğrafyası")

            ComboBox3.Items.Add("Türkiye'de Ulaşım")

            ComboBox3.Items.Add("Türkiye'nin enerji Kaynakları")

            ComboBox3.Items.Add("Türkiye'de Ormancılık")

            ComboBox3.Items.Add("Türkiye'de Hayvancılık")

            ComboBox3.Items.Add("İklim Tipleri")

        End If

        If ComboBox2.Text = "Tarih" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Osmanlı Devletinin Kuruluşu")

            ComboBox3.Items.Add("Fetret Devri")

            ComboBox3.Items.Add("İstanbul'un Fethi")

            ComboBox3.Items.Add("Kapitülasyonlar")

            ComboBox3.Items.Add("Viyana Kuşatması")

        End If

        If ComboBox2.Text = "Analitik Geometri" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Doğrunun Analitik İncelenmesi")

            ComboBox3.Items.Add("Noktanın Analitiği")

            ComboBox3.Items.Add("Çemberin Analitik İncelenmesi")

            ComboBox3.Items.Add("elipsin Analitik İncelenmesi")

        End If

        If ComboBox2.Text = "Biyoloji" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Nükleik Asit ATP")

            ComboBox3.Items.Add("Mitoz ve Mayoz Bölünme")

            ComboBox3.Items.Add("Hayvansal Dokular")

            ComboBox3.Items.Add("İnsanda Duyu Organları")

            ComboBox3.Items.Add("Solunum Sistemi")

            ComboBox3.Items.Add("Boşaltım Sistemi")

            ComboBox3.Items.Add("Destek ve İskelet Sistemleri")

            ComboBox3.Items.Add("Kalıtım")

            ComboBox3.Items.Add("Popülasyon Genetiği")

        End If

        If ComboBox2.Text = "Din Kültürü" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Dünya Hayatı ve Ahiret")

            ComboBox3.Items.Add("Dinlerde İbadet")

            ComboBox3.Items.Add("Tövbe ve Bağışlama")

            ComboBox3.Items.Add("Yaşayan Dinler ve Benzerlikler,")

        End If

        If ComboBox2.Text = "Fizik" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Vektörler")

            ComboBox3.Items.Add("Kuvvet")

            ComboBox3.Items.Add("Bağıl Hız")

            ComboBox3.Items.Add("Sürtünme Kuvveti")

            ComboBox3.Items.Add("İş-Güç-Enerji")

            ComboBox3.Items.Add("Akımın Manyetik Etkisi")

        End If

        If ComboBox2.Text = "Matematik" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Basit Eşitsizlikler")

            ComboBox3.Items.Add("OBEB-OKEK")

            ComboBox3.Items.Add("Fonksiyonlar")

            ComboBox3.Items.Add("Oran-Orantı")

            ComboBox3.Items.Add("Üslü Sayılar")

            ComboBox3.Items.Add("Modüler Aritmetik")

            ComboBox3.Items.Add("Polinomlar")

            ComboBox3.Items.Add("Parabol")

            ComboBox3.Items.Add("Trigonometir")

        End If

        If ComboBox2.Text = "Geometri" Then

            ComboBox3.Items.Clear()

            ComboBox3.Items.Add("Özel Üçgenler")

            ComboBox3.Items.Add("Kare")

            ComboBox3.Items.Add("Dikdörtgen")

            ComboBox3.Items.Add("Yamuk")

            ComboBox3.Items.Add("Üçgen")

            ComboBox3.Items.Add("Çember")

            ComboBox3.Items.Add("Çemberde Kuvvet ")

            ComboBox3.Items.Add("Düzgün Çokgenler")

            ComboBox3.Items.Add("Deltoid")
        End If

    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Form2.Show()
        Me.Hide()

    End Sub

    Private Sub GroupBox1_Enter(sender As Object, e As EventArgs) Handles GroupBox1.Enter

    End Sub
End Class