namespace KomurArdiyesi
{
    partial class Form_AnaPencere
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.programToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yenidenBaşlatToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kapatToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yöneticiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.parolaDeğiştirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yöneticiEkleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hakkındaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1 = new System.Windows.Forms.Panel();
            this.btn_Toptancilar = new System.Windows.Forms.Button();
            this.btn_Firmalar = new System.Windows.Forms.Button();
            this.btn_ToptanciEkle = new System.Windows.Forms.Button();
            this.btn_FirmaEkle = new System.Windows.Forms.Button();
            this.btn_MusteriEkle = new System.Windows.Forms.Button();
            this.btn_OdemeEkle = new System.Windows.Forms.Button();
            this.btn_SiparisEkle = new System.Windows.Forms.Button();
            this.btn_UrunEkle = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.dg_Musteriler = new System.Windows.Forms.DataGridView();
            this.dg_Odemeler = new System.Windows.Forms.DataGridView();
            this.dg_Urunler = new System.Windows.Forms.DataGridView();
            this.dg_Siparisler = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.stLb_KullaniciAd = new System.Windows.Forms.ToolStripStatusLabel();
            this.stLb_Saat = new System.Windows.Forms.ToolStripStatusLabel();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Musteriler)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Odemeler)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Urunler)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Siparisler)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.programToolStripMenuItem,
            this.yöneticiToolStripMenuItem,
            this.hakkındaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1037, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // programToolStripMenuItem
            // 
            this.programToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yenidenBaşlatToolStripMenuItem,
            this.kapatToolStripMenuItem});
            this.programToolStripMenuItem.Name = "programToolStripMenuItem";
            this.programToolStripMenuItem.Size = new System.Drawing.Size(65, 20);
            this.programToolStripMenuItem.Text = "Program";
            // 
            // yenidenBaşlatToolStripMenuItem
            // 
            this.yenidenBaşlatToolStripMenuItem.Name = "yenidenBaşlatToolStripMenuItem";
            this.yenidenBaşlatToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.yenidenBaşlatToolStripMenuItem.Text = "Yeniden Başlat";
            this.yenidenBaşlatToolStripMenuItem.Click += new System.EventHandler(this.yenidenBaşlatToolStripMenuItem_Click);
            // 
            // kapatToolStripMenuItem
            // 
            this.kapatToolStripMenuItem.Name = "kapatToolStripMenuItem";
            this.kapatToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.kapatToolStripMenuItem.Text = "Kapat";
            this.kapatToolStripMenuItem.Click += new System.EventHandler(this.kapatToolStripMenuItem_Click);
            // 
            // yöneticiToolStripMenuItem
            // 
            this.yöneticiToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.parolaDeğiştirToolStripMenuItem,
            this.yöneticiEkleToolStripMenuItem});
            this.yöneticiToolStripMenuItem.Name = "yöneticiToolStripMenuItem";
            this.yöneticiToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
            this.yöneticiToolStripMenuItem.Text = "Yönetici";
            // 
            // parolaDeğiştirToolStripMenuItem
            // 
            this.parolaDeğiştirToolStripMenuItem.Name = "parolaDeğiştirToolStripMenuItem";
            this.parolaDeğiştirToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.parolaDeğiştirToolStripMenuItem.Text = "Parola Değiştir";
            this.parolaDeğiştirToolStripMenuItem.Click += new System.EventHandler(this.parolaDeğiştirToolStripMenuItem_Click);
            // 
            // yöneticiEkleToolStripMenuItem
            // 
            this.yöneticiEkleToolStripMenuItem.Name = "yöneticiEkleToolStripMenuItem";
            this.yöneticiEkleToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.yöneticiEkleToolStripMenuItem.Text = "Yönetici Ekle";
            this.yöneticiEkleToolStripMenuItem.Click += new System.EventHandler(this.yöneticiEkleToolStripMenuItem_Click);
            // 
            // hakkındaToolStripMenuItem
            // 
            this.hakkındaToolStripMenuItem.Name = "hakkındaToolStripMenuItem";
            this.hakkındaToolStripMenuItem.Size = new System.Drawing.Size(69, 20);
            this.hakkındaToolStripMenuItem.Text = "Hakkında";
            this.hakkındaToolStripMenuItem.Click += new System.EventHandler(this.hakkındaToolStripMenuItem_Click);
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.panel1.Controls.Add(this.btn_Toptancilar);
            this.panel1.Controls.Add(this.btn_Firmalar);
            this.panel1.Controls.Add(this.btn_ToptanciEkle);
            this.panel1.Controls.Add(this.btn_FirmaEkle);
            this.panel1.Controls.Add(this.btn_MusteriEkle);
            this.panel1.Controls.Add(this.btn_OdemeEkle);
            this.panel1.Controls.Add(this.btn_SiparisEkle);
            this.panel1.Controls.Add(this.btn_UrunEkle);
            this.panel1.Location = new System.Drawing.Point(8, 36);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1017, 44);
            this.panel1.TabIndex = 1;
            // 
            // btn_Toptancilar
            // 
            this.btn_Toptancilar.Location = new System.Drawing.Point(851, 4);
            this.btn_Toptancilar.Name = "btn_Toptancilar";
            this.btn_Toptancilar.Size = new System.Drawing.Size(77, 35);
            this.btn_Toptancilar.TabIndex = 7;
            this.btn_Toptancilar.Text = "Toptancılar";
            this.btn_Toptancilar.UseVisualStyleBackColor = true;
            this.btn_Toptancilar.Click += new System.EventHandler(this.btn_Toptancilar_Click);
            // 
            // btn_Firmalar
            // 
            this.btn_Firmalar.Location = new System.Drawing.Point(934, 4);
            this.btn_Firmalar.Name = "btn_Firmalar";
            this.btn_Firmalar.Size = new System.Drawing.Size(77, 35);
            this.btn_Firmalar.TabIndex = 6;
            this.btn_Firmalar.Text = "Firmalar";
            this.btn_Firmalar.UseVisualStyleBackColor = true;
            this.btn_Firmalar.Click += new System.EventHandler(this.btn_Firmalar_Click);
            // 
            // btn_ToptanciEkle
            // 
            this.btn_ToptanciEkle.Location = new System.Drawing.Point(420, 4);
            this.btn_ToptanciEkle.Name = "btn_ToptanciEkle";
            this.btn_ToptanciEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_ToptanciEkle.TabIndex = 5;
            this.btn_ToptanciEkle.Text = "Toptancı Ekle";
            this.btn_ToptanciEkle.UseVisualStyleBackColor = true;
            this.btn_ToptanciEkle.Click += new System.EventHandler(this.btn_ToptanciEkle_Click);
            // 
            // btn_FirmaEkle
            // 
            this.btn_FirmaEkle.Location = new System.Drawing.Point(337, 4);
            this.btn_FirmaEkle.Name = "btn_FirmaEkle";
            this.btn_FirmaEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_FirmaEkle.TabIndex = 4;
            this.btn_FirmaEkle.Text = "Firma Ekle";
            this.btn_FirmaEkle.UseVisualStyleBackColor = true;
            this.btn_FirmaEkle.Click += new System.EventHandler(this.btn_FirmaEkle_Click);
            // 
            // btn_MusteriEkle
            // 
            this.btn_MusteriEkle.Location = new System.Drawing.Point(254, 4);
            this.btn_MusteriEkle.Name = "btn_MusteriEkle";
            this.btn_MusteriEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_MusteriEkle.TabIndex = 3;
            this.btn_MusteriEkle.Text = "Müşteri Ekle";
            this.btn_MusteriEkle.UseVisualStyleBackColor = true;
            this.btn_MusteriEkle.Click += new System.EventHandler(this.btn_MusteriEkle_Click);
            // 
            // btn_OdemeEkle
            // 
            this.btn_OdemeEkle.Location = new System.Drawing.Point(171, 4);
            this.btn_OdemeEkle.Name = "btn_OdemeEkle";
            this.btn_OdemeEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_OdemeEkle.TabIndex = 2;
            this.btn_OdemeEkle.Text = "Ödeme Ekle";
            this.btn_OdemeEkle.UseVisualStyleBackColor = true;
            this.btn_OdemeEkle.Click += new System.EventHandler(this.btn_OdemeEkle_Click);
            // 
            // btn_SiparisEkle
            // 
            this.btn_SiparisEkle.Location = new System.Drawing.Point(88, 4);
            this.btn_SiparisEkle.Name = "btn_SiparisEkle";
            this.btn_SiparisEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_SiparisEkle.TabIndex = 1;
            this.btn_SiparisEkle.Text = "Sipariş Ekle";
            this.btn_SiparisEkle.UseVisualStyleBackColor = true;
            this.btn_SiparisEkle.Click += new System.EventHandler(this.btn_SiparisEkle_Click);
            // 
            // btn_UrunEkle
            // 
            this.btn_UrunEkle.Location = new System.Drawing.Point(5, 4);
            this.btn_UrunEkle.Name = "btn_UrunEkle";
            this.btn_UrunEkle.Size = new System.Drawing.Size(77, 35);
            this.btn_UrunEkle.TabIndex = 0;
            this.btn_UrunEkle.Text = "Ürün Ekle";
            this.btn_UrunEkle.UseVisualStyleBackColor = true;
            this.btn_UrunEkle.Click += new System.EventHandler(this.btn_UrunEkle_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Controls.Add(this.dg_Musteriler, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.dg_Odemeler, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.dg_Urunler, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.dg_Siparisler, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(8, 86);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1017, 517);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // dg_Musteriler
            // 
            this.dg_Musteriler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Musteriler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Musteriler.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Musteriler.Location = new System.Drawing.Point(511, 261);
            this.dg_Musteriler.Name = "dg_Musteriler";
            this.dg_Musteriler.ReadOnly = true;
            this.dg_Musteriler.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Musteriler.Size = new System.Drawing.Size(503, 253);
            this.dg_Musteriler.TabIndex = 3;
            this.dg_Musteriler.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Musteriler_RowEnter);
            this.dg_Musteriler.DoubleClick += new System.EventHandler(this.dg_Musteriler_DoubleClick);
            // 
            // dg_Odemeler
            // 
            this.dg_Odemeler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Odemeler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Odemeler.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Odemeler.Location = new System.Drawing.Point(3, 261);
            this.dg_Odemeler.Name = "dg_Odemeler";
            this.dg_Odemeler.ReadOnly = true;
            this.dg_Odemeler.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Odemeler.Size = new System.Drawing.Size(502, 253);
            this.dg_Odemeler.TabIndex = 2;
            this.dg_Odemeler.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Odemeler_RowEnter);
            this.dg_Odemeler.DoubleClick += new System.EventHandler(this.dg_Odemeler_DoubleClick);
            // 
            // dg_Urunler
            // 
            this.dg_Urunler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Urunler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Urunler.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Urunler.Location = new System.Drawing.Point(511, 3);
            this.dg_Urunler.Name = "dg_Urunler";
            this.dg_Urunler.ReadOnly = true;
            this.dg_Urunler.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Urunler.Size = new System.Drawing.Size(503, 252);
            this.dg_Urunler.TabIndex = 1;
            this.dg_Urunler.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Urunler_RowEnter);
            this.dg_Urunler.DoubleClick += new System.EventHandler(this.dg_Urunler_DoubleClick);
            // 
            // dg_Siparisler
            // 
            this.dg_Siparisler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Siparisler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Siparisler.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Siparisler.Location = new System.Drawing.Point(3, 3);
            this.dg_Siparisler.Name = "dg_Siparisler";
            this.dg_Siparisler.ReadOnly = true;
            this.dg_Siparisler.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Siparisler.Size = new System.Drawing.Size(502, 252);
            this.dg_Siparisler.TabIndex = 0;
            this.dg_Siparisler.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Siparisler_RowEnter);
            this.dg_Siparisler.DoubleClick += new System.EventHandler(this.dg_Siparisler_DoubleClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 82);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(70, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "SİPARİŞLER";
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(523, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "ÜRÜNLER";
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(524, 342);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "MÜŞTERİLER";
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 342);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(67, 13);
            this.label4.TabIndex = 5;
            this.label4.Text = "ÖDEMELER";
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.stLb_KullaniciAd,
            this.stLb_Saat});
            this.statusStrip1.Location = new System.Drawing.Point(0, 606);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1037, 22);
            this.statusStrip1.TabIndex = 7;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // stLb_KullaniciAd
            // 
            this.stLb_KullaniciAd.Name = "stLb_KullaniciAd";
            this.stLb_KullaniciAd.Size = new System.Drawing.Size(67, 17);
            this.stLb_KullaniciAd.Text = "KullaniciAd";
            // 
            // stLb_Saat
            // 
            this.stLb_Saat.Name = "stLb_Saat";
            this.stLb_Saat.Size = new System.Drawing.Size(16, 17);
            this.stLb_Saat.Text = "...";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // Form_AnaPencere
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1037, 628);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form_AnaPencere";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ana Pencere";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form_AnaPencere_FormClosing);
            this.Load += new System.EventHandler(this.Form_AnaPencere_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dg_Musteriler)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Odemeler)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Urunler)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Siparisler)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem programToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yenidenBaşlatToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kapatToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hakkındaToolStripMenuItem;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btn_UrunEkle;
        private System.Windows.Forms.ToolStripMenuItem yöneticiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem parolaDeğiştirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yöneticiEkleToolStripMenuItem;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.DataGridView dg_Siparisler;
        private System.Windows.Forms.DataGridView dg_Odemeler;
        private System.Windows.Forms.DataGridView dg_Urunler;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btn_ToptanciEkle;
        private System.Windows.Forms.Button btn_FirmaEkle;
        private System.Windows.Forms.Button btn_MusteriEkle;
        private System.Windows.Forms.Button btn_OdemeEkle;
        private System.Windows.Forms.Button btn_SiparisEkle;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel stLb_Saat;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ToolStripStatusLabel stLb_KullaniciAd;
        private System.Windows.Forms.Button btn_Toptancilar;
        private System.Windows.Forms.Button btn_Firmalar;
        private System.Windows.Forms.DataGridView dg_Musteriler;
    }
}