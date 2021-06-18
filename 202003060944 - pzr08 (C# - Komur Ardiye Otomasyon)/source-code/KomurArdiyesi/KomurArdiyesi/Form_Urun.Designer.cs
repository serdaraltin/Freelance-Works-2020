namespace KomurArdiyesi
{
    partial class Form_Urun
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
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Ekle = new System.Windows.Forms.Button();
            this.txt_Fiyat = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_UrunAd = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_Barkod = new System.Windows.Forms.MaskedTextBox();
            this.dt_GirisTarih = new System.Windows.Forms.DateTimePicker();
            this.dt_CikisTarih = new System.Windows.Forms.DateTimePicker();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.cb_Birim = new System.Windows.Forms.ComboBox();
            this.txt_Miktar = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(161, 204);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(94, 36);
            this.btn_Sil.TabIndex = 29;
            this.btn_Sil.Text = "Sil";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Ekle
            // 
            this.btn_Ekle.Location = new System.Drawing.Point(37, 204);
            this.btn_Ekle.Name = "btn_Ekle";
            this.btn_Ekle.Size = new System.Drawing.Size(118, 36);
            this.btn_Ekle.TabIndex = 27;
            this.btn_Ekle.Text = "Ekle";
            this.btn_Ekle.UseVisualStyleBackColor = true;
            this.btn_Ekle.Click += new System.EventHandler(this.btn_Ekle_Click);
            // 
            // txt_Fiyat
            // 
            this.txt_Fiyat.Location = new System.Drawing.Point(98, 116);
            this.txt_Fiyat.Name = "txt_Fiyat";
            this.txt_Fiyat.Size = new System.Drawing.Size(157, 20);
            this.txt_Fiyat.TabIndex = 4;
            this.txt_Fiyat.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_Fiyat_KeyPress);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(63, 119);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(29, 13);
            this.label5.TabIndex = 28;
            this.label5.Text = "Fiyat";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(56, 93);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(36, 13);
            this.label4.TabIndex = 25;
            this.label4.Text = "Miktar";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(63, 67);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(29, 13);
            this.label3.TabIndex = 21;
            this.label3.Text = "Birim";
            // 
            // txt_UrunAd
            // 
            this.txt_UrunAd.Location = new System.Drawing.Point(98, 38);
            this.txt_UrunAd.Name = "txt_UrunAd";
            this.txt_UrunAd.Size = new System.Drawing.Size(157, 20);
            this.txt_UrunAd.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 41);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 13);
            this.label2.TabIndex = 18;
            this.label2.Text = "Ürün Ad";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(34, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 13);
            this.label1.TabIndex = 15;
            this.label1.Text = "Barkod No";
            // 
            // txt_Barkod
            // 
            this.txt_Barkod.Location = new System.Drawing.Point(98, 12);
            this.txt_Barkod.Mask = "00000000000";
            this.txt_Barkod.Name = "txt_Barkod";
            this.txt_Barkod.Size = new System.Drawing.Size(100, 20);
            this.txt_Barkod.TabIndex = 0;
            // 
            // dt_GirisTarih
            // 
            this.dt_GirisTarih.Location = new System.Drawing.Point(98, 142);
            this.dt_GirisTarih.Name = "dt_GirisTarih";
            this.dt_GirisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_GirisTarih.TabIndex = 5;
            // 
            // dt_CikisTarih
            // 
            this.dt_CikisTarih.Location = new System.Drawing.Point(98, 168);
            this.dt_CikisTarih.Name = "dt_CikisTarih";
            this.dt_CikisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_CikisTarih.TabIndex = 6;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(36, 171);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(56, 13);
            this.label7.TabIndex = 59;
            this.label7.Text = "Çıkış Tarih";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(38, 146);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 58;
            this.label6.Text = "Giriş Tarih";
            // 
            // cb_Birim
            // 
            this.cb_Birim.FormattingEnabled = true;
            this.cb_Birim.Items.AddRange(new object[] {
            "Kilogram",
            "Litre"});
            this.cb_Birim.Location = new System.Drawing.Point(98, 64);
            this.cb_Birim.Name = "cb_Birim";
            this.cb_Birim.Size = new System.Drawing.Size(121, 21);
            this.cb_Birim.TabIndex = 2;
            this.cb_Birim.Text = "Kilogram";
            // 
            // txt_Miktar
            // 
            this.txt_Miktar.Location = new System.Drawing.Point(98, 90);
            this.txt_Miktar.Name = "txt_Miktar";
            this.txt_Miktar.Size = new System.Drawing.Size(121, 20);
            this.txt_Miktar.TabIndex = 3;
            this.txt_Miktar.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_Miktar_KeyPress);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(226, 94);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(29, 13);
            this.label8.TabIndex = 62;
            this.label8.Text = "Adet";
            // 
            // Form_Urun
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(284, 253);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.txt_Miktar);
            this.Controls.Add(this.cb_Birim);
            this.Controls.Add(this.dt_GirisTarih);
            this.Controls.Add(this.dt_CikisTarih);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Ekle);
            this.Controls.Add(this.txt_Barkod);
            this.Controls.Add(this.txt_Fiyat);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txt_UrunAd);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Urun";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ürün";
            this.Load += new System.EventHandler(this.Form_Urun_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Ekle;
        private System.Windows.Forms.TextBox txt_Fiyat;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_UrunAd;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MaskedTextBox txt_Barkod;
        private System.Windows.Forms.DateTimePicker dt_GirisTarih;
        private System.Windows.Forms.DateTimePicker dt_CikisTarih;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cb_Birim;
        private System.Windows.Forms.TextBox txt_Miktar;
        private System.Windows.Forms.Label label8;
    }
}