namespace VeritabaniOdev
{
    partial class Form_UretimKaydi
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnYeniUretimEkle = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.ndUretimAdet = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.dtUretimTarih = new System.Windows.Forms.DateTimePicker();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.dgMakine = new System.Windows.Forms.DataGridView();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.dgCalisan = new System.Windows.Forms.DataGridView();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.dgUrun = new System.Windows.Forms.DataGridView();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.dgUretimKaydi = new System.Windows.Forms.DataGridView();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.btnYeniUrunEkle = new System.Windows.Forms.Button();
            this.btnYeniCalisanEkle = new System.Windows.Forms.Button();
            this.btnYeniMakineEkle = new System.Windows.Forms.Button();
            this.txtCalisanSoyadi = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtCalisanAdi = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtUrunAd = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtMakineAd = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.txtUretimAdet = new System.Windows.Forms.TextBox();
            this.txtUretimTarih = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ndUretimAdet)).BeginInit();
            this.groupBox6.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgMakine)).BeginInit();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgCalisan)).BeginInit();
            this.groupBox4.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgUrun)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgUretimKaydi)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnYeniUretimEkle);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.ndUretimAdet);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.dtUretimTarih);
            this.groupBox1.Controls.Add(this.groupBox6);
            this.groupBox1.Controls.Add(this.groupBox5);
            this.groupBox1.Controls.Add(this.groupBox4);
            this.groupBox1.Location = new System.Drawing.Point(12, 46);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(395, 500);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Yeni Üretim Kaydı Ekle";
            // 
            // btnYeniUretimEkle
            // 
            this.btnYeniUretimEkle.Location = new System.Drawing.Point(244, 456);
            this.btnYeniUretimEkle.Name = "btnYeniUretimEkle";
            this.btnYeniUretimEkle.Size = new System.Drawing.Size(133, 33);
            this.btnYeniUretimEkle.TabIndex = 6;
            this.btnYeniUretimEkle.Text = "YENİ ÜRETİM EKLE";
            this.btnYeniUretimEkle.UseVisualStyleBackColor = true;
            this.btnYeniUretimEkle.Click += new System.EventHandler(this.btnYeniUretimEkle_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(11, 404);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(31, 15);
            this.label2.TabIndex = 6;
            this.label2.Text = "Adet";
            // 
            // ndUretimAdet
            // 
            this.ndUretimAdet.Location = new System.Drawing.Point(89, 402);
            this.ndUretimAdet.Maximum = new decimal(new int[] {
            10000,
            0,
            0,
            0});
            this.ndUretimAdet.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.ndUretimAdet.Name = "ndUretimAdet";
            this.ndUretimAdet.Size = new System.Drawing.Size(83, 21);
            this.ndUretimAdet.TabIndex = 5;
            this.ndUretimAdet.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 432);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 15);
            this.label1.TabIndex = 4;
            this.label1.Text = "Tarih/Saat";
            // 
            // dtUretimTarih
            // 
            this.dtUretimTarih.Location = new System.Drawing.Point(89, 429);
            this.dtUretimTarih.Name = "dtUretimTarih";
            this.dtUretimTarih.Size = new System.Drawing.Size(288, 21);
            this.dtUretimTarih.TabIndex = 3;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.dgMakine);
            this.groupBox6.Location = new System.Drawing.Point(10, 268);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(370, 119);
            this.groupBox6.TabIndex = 2;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Makine";
            // 
            // dgMakine
            // 
            this.dgMakine.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgMakine.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgMakine.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgMakine.Location = new System.Drawing.Point(3, 17);
            this.dgMakine.MultiSelect = false;
            this.dgMakine.Name = "dgMakine";
            this.dgMakine.ReadOnly = true;
            this.dgMakine.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgMakine.Size = new System.Drawing.Size(364, 99);
            this.dgMakine.TabIndex = 0;
            this.dgMakine.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgMakine_RowEnter);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.dgCalisan);
            this.groupBox5.Location = new System.Drawing.Point(10, 143);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(370, 119);
            this.groupBox5.TabIndex = 1;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Çalışan";
            // 
            // dgCalisan
            // 
            this.dgCalisan.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgCalisan.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgCalisan.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgCalisan.Location = new System.Drawing.Point(3, 17);
            this.dgCalisan.MultiSelect = false;
            this.dgCalisan.Name = "dgCalisan";
            this.dgCalisan.ReadOnly = true;
            this.dgCalisan.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgCalisan.Size = new System.Drawing.Size(364, 99);
            this.dgCalisan.TabIndex = 0;
            this.dgCalisan.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgCalisan_RowEnter);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.dgUrun);
            this.groupBox4.Location = new System.Drawing.Point(10, 18);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(370, 119);
            this.groupBox4.TabIndex = 0;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Ürün";
            // 
            // dgUrun
            // 
            this.dgUrun.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgUrun.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgUrun.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgUrun.Location = new System.Drawing.Point(3, 17);
            this.dgUrun.MultiSelect = false;
            this.dgUrun.Name = "dgUrun";
            this.dgUrun.ReadOnly = true;
            this.dgUrun.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgUrun.Size = new System.Drawing.Size(364, 99);
            this.dgUrun.TabIndex = 0;
            this.dgUrun.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgUrun_RowEnter);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.dgUretimKaydi);
            this.groupBox2.Location = new System.Drawing.Point(413, 46);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(495, 343);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Üretim Kayıtları";
            // 
            // dgUretimKaydi
            // 
            this.dgUretimKaydi.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgUretimKaydi.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgUretimKaydi.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dgUretimKaydi.Location = new System.Drawing.Point(3, 17);
            this.dgUretimKaydi.MultiSelect = false;
            this.dgUretimKaydi.Name = "dgUretimKaydi";
            this.dgUretimKaydi.ReadOnly = true;
            this.dgUretimKaydi.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgUretimKaydi.Size = new System.Drawing.Size(489, 323);
            this.dgUretimKaydi.TabIndex = 0;
            this.dgUretimKaydi.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dgUretimKaydi_RowEnter);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtUretimTarih);
            this.groupBox3.Controls.Add(this.txtUretimAdet);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.txtMakineAd);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.txtUrunAd);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.txtCalisanSoyadi);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.txtCalisanAdi);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Location = new System.Drawing.Point(413, 395);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(495, 151);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Üretim Kayıt Bilgileri";
            // 
            // btnYeniUrunEkle
            // 
            this.btnYeniUrunEkle.Location = new System.Drawing.Point(12, 7);
            this.btnYeniUrunEkle.Name = "btnYeniUrunEkle";
            this.btnYeniUrunEkle.Size = new System.Drawing.Size(133, 33);
            this.btnYeniUrunEkle.TabIndex = 3;
            this.btnYeniUrunEkle.Text = "YENİ ÜRÜN EKLE";
            this.btnYeniUrunEkle.UseVisualStyleBackColor = true;
            this.btnYeniUrunEkle.Click += new System.EventHandler(this.btnYeniUrunEkle_Click);
            // 
            // btnYeniCalisanEkle
            // 
            this.btnYeniCalisanEkle.Location = new System.Drawing.Point(151, 7);
            this.btnYeniCalisanEkle.Name = "btnYeniCalisanEkle";
            this.btnYeniCalisanEkle.Size = new System.Drawing.Size(133, 33);
            this.btnYeniCalisanEkle.TabIndex = 4;
            this.btnYeniCalisanEkle.Text = "YENİ ÇALIŞAN EKLE";
            this.btnYeniCalisanEkle.UseVisualStyleBackColor = true;
            this.btnYeniCalisanEkle.Click += new System.EventHandler(this.btnYeniCalisanEkle_Click);
            // 
            // btnYeniMakineEkle
            // 
            this.btnYeniMakineEkle.Location = new System.Drawing.Point(290, 7);
            this.btnYeniMakineEkle.Name = "btnYeniMakineEkle";
            this.btnYeniMakineEkle.Size = new System.Drawing.Size(133, 33);
            this.btnYeniMakineEkle.TabIndex = 5;
            this.btnYeniMakineEkle.Text = "YENİ MAKİNE EKLE";
            this.btnYeniMakineEkle.UseVisualStyleBackColor = true;
            this.btnYeniMakineEkle.Click += new System.EventHandler(this.btnYeniMakineEkle_Click);
            // 
            // txtCalisanSoyadi
            // 
            this.txtCalisanSoyadi.Location = new System.Drawing.Point(109, 88);
            this.txtCalisanSoyadi.Name = "txtCalisanSoyadi";
            this.txtCalisanSoyadi.ReadOnly = true;
            this.txtCalisanSoyadi.Size = new System.Drawing.Size(177, 21);
            this.txtCalisanSoyadi.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 91);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(88, 15);
            this.label3.TabIndex = 7;
            this.label3.Text = "Çalışan Soyadı";
            // 
            // txtCalisanAdi
            // 
            this.txtCalisanAdi.Location = new System.Drawing.Point(109, 61);
            this.txtCalisanAdi.Name = "txtCalisanAdi";
            this.txtCalisanAdi.ReadOnly = true;
            this.txtCalisanAdi.Size = new System.Drawing.Size(177, 21);
            this.txtCalisanAdi.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(68, 15);
            this.label4.TabIndex = 6;
            this.label4.Text = "Çalışan Adı";
            // 
            // txtUrunAd
            // 
            this.txtUrunAd.Location = new System.Drawing.Point(109, 34);
            this.txtUrunAd.Name = "txtUrunAd";
            this.txtUrunAd.ReadOnly = true;
            this.txtUrunAd.Size = new System.Drawing.Size(177, 21);
            this.txtUrunAd.TabIndex = 8;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(15, 37);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 15);
            this.label5.TabIndex = 9;
            this.label5.Text = "Ürün Adı";
            // 
            // txtMakineAd
            // 
            this.txtMakineAd.Location = new System.Drawing.Point(109, 115);
            this.txtMakineAd.Name = "txtMakineAd";
            this.txtMakineAd.ReadOnly = true;
            this.txtMakineAd.Size = new System.Drawing.Size(177, 21);
            this.txtMakineAd.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(15, 118);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(48, 15);
            this.label6.TabIndex = 11;
            this.label6.Text = "Makine";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(299, 64);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 15);
            this.label7.TabIndex = 12;
            this.label7.Text = "Tarih";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(305, 37);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(31, 15);
            this.label8.TabIndex = 14;
            this.label8.Text = "Adet";
            // 
            // txtUretimAdet
            // 
            this.txtUretimAdet.Location = new System.Drawing.Point(342, 34);
            this.txtUretimAdet.Name = "txtUretimAdet";
            this.txtUretimAdet.ReadOnly = true;
            this.txtUretimAdet.Size = new System.Drawing.Size(140, 21);
            this.txtUretimAdet.TabIndex = 15;
            // 
            // txtUretimTarih
            // 
            this.txtUretimTarih.Location = new System.Drawing.Point(342, 61);
            this.txtUretimTarih.Name = "txtUretimTarih";
            this.txtUretimTarih.ReadOnly = true;
            this.txtUretimTarih.Size = new System.Drawing.Size(140, 21);
            this.txtUretimTarih.TabIndex = 16;
            // 
            // Form_UretimKaydi
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(919, 558);
            this.Controls.Add(this.btnYeniMakineEkle);
            this.Controls.Add(this.btnYeniCalisanEkle);
            this.Controls.Add(this.btnYeniUrunEkle);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.MaximizeBox = false;
            this.Name = "Form_UretimKaydi";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Üretim Kaydı";
            this.Load += new System.EventHandler(this.Form_UretimKaydi_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ndUretimAdet)).EndInit();
            this.groupBox6.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgMakine)).EndInit();
            this.groupBox5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgCalisan)).EndInit();
            this.groupBox4.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgUrun)).EndInit();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgUretimKaydi)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown ndUretimAdet;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dtUretimTarih;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.DataGridView dgUretimKaydi;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button btnYeniUrunEkle;
        private System.Windows.Forms.Button btnYeniCalisanEkle;
        private System.Windows.Forms.Button btnYeniMakineEkle;
        private System.Windows.Forms.DataGridView dgMakine;
        private System.Windows.Forms.DataGridView dgCalisan;
        private System.Windows.Forms.DataGridView dgUrun;
        private System.Windows.Forms.Button btnYeniUretimEkle;
        private System.Windows.Forms.TextBox txtCalisanSoyadi;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtCalisanAdi;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtUretimTarih;
        private System.Windows.Forms.TextBox txtUretimAdet;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtMakineAd;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtUrunAd;
        private System.Windows.Forms.Label label5;
    }
}