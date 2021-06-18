using System;
using System.Windows.Forms;

namespace Theimam
{
    public partial class Form_Islem : Form
    {
        string tablo = "";
        public Form_Islem()
        {
            InitializeComponent();
        }
        public Form_Islem(string tabloAdi)
        {
            InitializeComponent();
            tablo = tabloAdi;
        }
        Class_Islemler islemler = new Class_Islemler();
       
        int Id = 0, IdLoc = 0;
        Form form = null;
        public void Listele()
        {
            dg_Veriler.DataSource = islemler.Kayitlar(tablo).Tables[0];
        }
        public void FormTanimla()
        {
            switch (tablo)
            {
                case "aile_birligi": //+
                    form = new Form_Aile_Birligi();
                    break;
                case "bolum": //+
                    form = new Form_Bolum_();
                    break;
                case "ders": //+
                    form = new Form_Ders();
                    break;
                case "egitmen_alan": //+
                    form = new Form_Egitmen_Alan();
                    break;
                case "giris": //+
                    form = null;
                    btn_Ekle.Enabled = false;
                    btn_Guncelle.Enabled = false;
                    btn_Sil.Enabled = false;
                    break;
                case "kullanici"://+
                    form = new Form_Kullanici();
                    break;
                case "nobet": //+
                    form = new Form_Nobet();
                    break;
                case "ogrenci": //+
                    form = new Form_Ogrenci();
                    IdLoc = 6;
                    break;
                case "ogretmen": //+
                    form = new Form_Ogretmen();
                    IdLoc = 6;
                    break;
                case "personel"://+
                    form = new Form_Personel();
                    IdLoc = 6;
                    break;
                case "personel_alan"://+
                    form = new Form_Personel_Alan();
                    break;
                case "sinif"://+
                    form = new Form_Sinif();
                    break;
                case "veli"://+
                    form = new Form_Veli();
                    IdLoc = 6;
                    break;
                case "yonetim"://+
                    form = new Form_Yonetim();
                    IdLoc = 6;
                    break;
                case "yonetim_tur"://+
                    form = new Form_Yonetim_Tur();
                    break;
            }
        }
        private void Form_OgrenciIslem_Load(object sender, EventArgs e)
        {
            this.Text = tablo.ToUpper() + " İşlemleri";
            Listele();
            FormTanimla();
        }
        private void btn_Yenile_Click(object sender, EventArgs e)
        {
            Listele();
        }
        private void btn_Ekle_Click(object sender, EventArgs e)
        {
            FormTanimla();
            form.ShowDialog();
        }
        private void btn_Guncelle_Click(object sender, EventArgs e)
        {

            switch (tablo)
            {
                case "aile_birligi":
                    form = new Form_Aile_Birligi(Id);
                    break;
                case "bolum":
                    form = new Form_Bolum_(Id);
                    break;
                case "ders":
                    form = new Form_Ders(Id);
                    break;
                case "egitmen_alan":
                    form = new Form_Egitmen_Alan(Id);
                    break;
                case "giris":
                    form = new Form_Giris_Kaydi(Id);
                    break;
                case "kullanici":
                    form = new Form_Kullanici(Id);
                    break;
                case "nobet":
                    form = new Form_Nobet(Id);
                    break;
                case "ogrenci":
                    form = new Form_Ogrenci(Id);
                    IdLoc = 6;
                    break;
                case "ogretmen":
                    form = new Form_Ogretmen(Id);
                    break;
                case "personel":
                    form = new Form_Personel(Id);
                    break;
                case "personel_alan":
                    form = new Form_Personel_Alan(Id);
                    break;
                case "sinif":
                    form = new Form_Sinif(Id);
                    break;
                case "veli":
                    form = new Form_Veli(Id);
                    break;
                case "yonetim":
                    form = new Form_Yonetim(Id);
                    break;
                case "yonetim_tur":
                    form = new Form_Yonetim_Tur(Id);
                    break;
            }

            form.ShowDialog();
        }
        private void btn_Sil_Click(object sender, EventArgs e)
        {
            if (Id == 0)
                islemler.MesajKutu(1, "seçim yapınız");
            if (islemler.Sil(tablo, Id))
            {
                islemler.MesajKutu("silme");
                Listele();
            }
            else
                islemler.MesajKutu(2, "silme");
        }

        private void btn_Kapat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void dg_Veriler_RowEnter(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                Id = Convert.ToInt32(dg_Veriler.Rows[e.RowIndex].Cells[IdLoc].Value);
            }
            catch { }
        }

        private void dg_Veriler_DoubleClick(object sender, EventArgs e)
        {
            if(btn_Guncelle.Enabled)
                btn_Guncelle.PerformClick();
        }

        private void btn_Ara_Click(object sender, EventArgs e)
        {
            string searchValue = txt_Aranan.Text;

            dg_Veriler.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            try
            {
                foreach (DataGridViewRow row in dg_Veriler.Rows)
                {
                    int cellCount = row.Cells.Count;
                    for (int i = 0; i < cellCount; i++)
                    {
                        if (row.Cells[i].Value.ToString().Equals(searchValue))
                        {
                            row.Selected = true;
                            break;
                        }
                    }

                }
            }
            catch
            {
                return;
            }
        }
    }
}
