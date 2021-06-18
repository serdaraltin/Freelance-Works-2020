using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace EBilet_Programı
{
    public partial class AsilAnaForm : Form
    {
        public AsilAnaForm()
        {
            InitializeComponent();
        }
        private void btnGeriDon_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        //***************************************************************//

        private void AsilAnaForm_Load(object sender, EventArgs e)
        {
            AsilAnaFormIsimKaydirma.Enabled = true;
            // veritabanına kaydedilen bilet bilgilerini form açılışında data tablosunda gösterir.
            eBiletProgramiDataSet.EBiletTablosu.Clear();
            eBiletTablosuTableAdapter1.Fill(eBiletProgramiDataSet.EBiletTablosu);
        }

        //********************************************************************//

        private void txtIsmeGoreAra_TextChanged(object sender, EventArgs e)
        {
            bsGenelTablo.Filter = "Isim Like '%"+txtIsmeGoreAra.Text+"%'";
            // "Isim Like '%efe%'"  buradaki ' ' tırkan işaretleri bu kolonun string olduğunu 
            //  % %  işareti  '%   koyulursa başı, son gibi aramalar yaptırılır
           // yani '%efe'    ya da 'efe%' gibi '%efe%' yaptığında içinde geçenleri arar..

            //bunu bize Like komutu yaptırıyor, filter komutu filtrele anlamında, Isim de arama yapacağımız kolonun ismi..
        }

        //**********************************************************************//

        private void txtSoyismeGoreAra_TextChanged(object sender, EventArgs e)
        {
            bsGenelTablo.Filter = "SoyIsim Like '%" + txtSoyismeGoreAra.Text + "%'";
            // burdada soyadı kısmından arama işlevini gerçekleştirdik.
        }

        //************************************************************************//

        private void AsilAnaFormIsimKaydirma_Tick(object sender, EventArgs e)
        {
            label3.Text = label3.Text.Substring(1) + label3.Text.Substring(0, 1);
        }

        //************************************************************************//

        private void btnBiletSatinAl_Click(object sender, EventArgs e)
        {
            FilmKoltukSec f = new FilmKoltukSec(); 
            f.Show();
            f.grpBoxKoltuklar.Enabled = false;
            f.grpBoxMenu.Enabled = false;
            this.Hide();
            
        }

        //************************************************************************//

        private void dgvSagClick_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
            if (e.ClickedItem.Name == "kayitDuzelt")
            {
                DataRow drow = ((DataRowView)bsGenelTablo.Current).Row; // bu kod, seçilen satır bilgisini datarow a aktarır o satırı komple

                /* algoritma şöyle ilerleyeck,
                 * buradan çift tıklanan satırı seçeceğiz,
                 * filmkkoltuk seç bölümünü açacağız
                 * oraya tüm bu bbilgilri aktaracağız,
                 * oradaki kaydet yerine düzelt diyeceğiz, 
                 * aynı şekilde farklı bir koltuk seçeceğiz,
                 * seçilen koltuk kaydedildiğinde biraz önceki kurguladığımız, kod çalıştığında
                 * bu sefer yeni koltuğu göreceği için onu işaretleyecek, diğerini es geçecek boş muş gibi olacak.
                 */
                //burada grup box u felan enablelerini true olacak ki açılsın hepsi..
                FilmKoltukSec f = new FilmKoltukSec();

                f.txtIsim.Text = drow["Isim"].ToString();
                f.txtSoyisim.Text = drow["SoyIsim"].ToString();
                f.txtSecilenFilm.Text = drow["SecilenFilm"].ToString();
                f.txtSecilenKoltuk.Text = drow["SecilenKoltuk"].ToString();
                f.txtTarih.Text = drow["BiletiAldigiSaat"].ToString();
                f.comboSeans.Text = drow["FilmSeansSaati"].ToString();
                if (drow["Fiyat"].ToString() == "10")
                    f.rdbutonOgrenci.Checked = true;
                else if (drow["Fiyat"].ToString() == "12")
                    f.rdbutonTam.Checked = true;
                f.btnBiletAl.Text = "Bilet Düzelt";
                string tarife = drow["SecilenTarife"].ToString(); // tıklanan kolon bilgilerindeki secilenkoltuk bilgisini
                // string bir değişkene aktardık. Eğer Tam ise rdbutonTam seçili olacak, eğer değil ise rdbutonOgrenci secili olacak.
                if (tarife == "Tam")
                {
                    f.rdbutonTam.Checked = true;
                }
                else
                {
                    f.rdbutonOgrenci.Checked = true;
                }
                f.KisiID = Convert.ToInt32(drow["KisiID"]);
                f.grpBoxKoltuklar.Enabled = true;
                f.grpBoxMenu.Enabled = true;
                f.btnBiletIptal.Enabled = false;
                this.Hide();
                f.ShowDialog();        

                //düzeltme yapılıp düzelt yani kaydet butonuna basılınca form kapanır, burada
                //dataseti temizler yeniden yükleriz ki değişikliği görebilirelim...

                eBiletProgramiDataSet.EBiletTablosu.Clear();
                eBiletTablosuTableAdapter1.Fill(eBiletProgramiDataSet.EBiletTablosu);
            
            }
            else if (e.ClickedItem.Name == "kayitSil")
            {
                //burada yine seçilen satırı alıyor ki ID v bilgilerini alabilielim...
                DataRow drow = ((DataRowView)bsGenelTablo.Current).Row; // bu kod, seçilen satır bilgisini datarow a aktarır aoa asatırı komple

                /*hatadiaglo adında senin kendi mesajbox unu tasarladık...
                 * tamam butonuna dialog result  una propertiesten OK yaptık... dolayısıyla o bunotana yani
                 * tamam butonuna basılınca bize OK  dönüyüor bizde if le yakalıyoruz...
                 */

                hataDialog hata = new hataDialog();
                hata.txtHataMesaji.Text = drow["Isim"].ToString()+" "+drow["SoyIsim"]+" Adlı kişinin bilet kaydını silmek istediğinizden emin misiniz ?";
                hata.ShowDialog();

                // bu mantık her zaman daha mantıklıdır... eğer OK değilse returmnle çıkar

                //bir müttet sonra görüyorum...
                //burada sana yaptığım senin mesaj box undan dialogunu soruyuoruz...
////eğer OK gelirse....
                //farklı amaçlı kendine güzel tasarlayabilirsin... orada YES seçmiş olsaydık...
                if (hata.DialogResult != DialogResult.OK)
                    return;

                    // bilet silme kısmı
                    SqlConnection con = new SqlConnection();
                    con.ConnectionString = @"Data Source=.\SQLEXPRESS;Initial Catalog=EBiletProgrami;Integrated Security=True";

                    con.Open();

                    SqlCommand cmd = new SqlCommand();
                    cmd.Connection = con;

                    cmd.CommandText = @"delete EBiletTablosu where KisiID=@KisiID";
                    cmd.Parameters.AddWithValue("KisiID", drow["KisiID"]);
                    cmd.ExecuteNonQuery();
                    con.Close();
                    MessageBox.Show(drow["Isim"].ToString() +" "+ drow["SoyIsim"].ToString()+" Adlı kişinin bilet kaydı silinmiştir.", "Durum", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);                   
                    eBiletProgramiDataSet.EBiletTablosu.Clear();
                    eBiletTablosuTableAdapter1.Fill(eBiletProgramiDataSet.EBiletTablosu);
            }
        }        
    }
}