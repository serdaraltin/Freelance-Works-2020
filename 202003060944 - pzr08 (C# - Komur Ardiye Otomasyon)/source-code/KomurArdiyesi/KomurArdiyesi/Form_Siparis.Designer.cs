namespace KomurArdiyesi
{
    partial class Form_Siparis
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
            this.txt_Musteri = new System.Windows.Forms.TextBox();
            this.dt_SiparisTarih = new System.Windows.Forms.DateTimePicker();
            this.dt_TeslimatTarih = new System.Windows.Forms.DateTimePicker();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Isle = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_TeslimatAdres = new System.Windows.Forms.TextBox();
            this.btn_SiparisDetay = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txt_Musteri
            // 
            this.txt_Musteri.Location = new System.Drawing.Point(98, 29);
            this.txt_Musteri.Name = "txt_Musteri";
            this.txt_Musteri.ReadOnly = true;
            this.txt_Musteri.Size = new System.Drawing.Size(157, 20);
            this.txt_Musteri.TabIndex = 40;
            // 
            // dt_SiparisTarih
            // 
            this.dt_SiparisTarih.Location = new System.Drawing.Point(98, 55);
            this.dt_SiparisTarih.Name = "dt_SiparisTarih";
            this.dt_SiparisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_SiparisTarih.TabIndex = 41;
            // 
            // dt_TeslimatTarih
            // 
            this.dt_TeslimatTarih.Location = new System.Drawing.Point(98, 81);
            this.dt_TeslimatTarih.Name = "dt_TeslimatTarih";
            this.dt_TeslimatTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_TeslimatTarih.TabIndex = 45;
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(161, 229);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(94, 36);
            this.btn_Sil.TabIndex = 48;
            this.btn_Sil.Text = "Sil";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Isle
            // 
            this.btn_Isle.Location = new System.Drawing.Point(45, 187);
            this.btn_Isle.Name = "btn_Isle";
            this.btn_Isle.Size = new System.Drawing.Size(210, 36);
            this.btn_Isle.TabIndex = 47;
            this.btn_Isle.Text = "İşle";
            this.btn_Isle.UseVisualStyleBackColor = true;
            this.btn_Isle.Click += new System.EventHandler(this.btn_Isle_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(16, 110);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(76, 13);
            this.label8.TabIndex = 56;
            this.label8.Text = "Teslimat Adres";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(19, 85);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(73, 13);
            this.label7.TabIndex = 55;
            this.label7.Text = "Teslimat Tarih";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 58);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 13);
            this.label3.TabIndex = 51;
            this.label3.Text = "Siparis Tarihi";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(51, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 49;
            this.label1.Text = "Musteri";
            // 
            // txt_TeslimatAdres
            // 
            this.txt_TeslimatAdres.Location = new System.Drawing.Point(98, 107);
            this.txt_TeslimatAdres.Multiline = true;
            this.txt_TeslimatAdres.Name = "txt_TeslimatAdres";
            this.txt_TeslimatAdres.Size = new System.Drawing.Size(157, 70);
            this.txt_TeslimatAdres.TabIndex = 57;
            // 
            // btn_SiparisDetay
            // 
            this.btn_SiparisDetay.Location = new System.Drawing.Point(45, 229);
            this.btn_SiparisDetay.Name = "btn_SiparisDetay";
            this.btn_SiparisDetay.Size = new System.Drawing.Size(110, 36);
            this.btn_SiparisDetay.TabIndex = 58;
            this.btn_SiparisDetay.Text = "Sipariş Detay";
            this.btn_SiparisDetay.UseVisualStyleBackColor = true;
            this.btn_SiparisDetay.Visible = false;
            this.btn_SiparisDetay.Click += new System.EventHandler(this.btn_SiparisDetay_Click);
            // 
            // Form_Siparis
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(282, 273);
            this.Controls.Add(this.btn_SiparisDetay);
            this.Controls.Add(this.txt_TeslimatAdres);
            this.Controls.Add(this.txt_Musteri);
            this.Controls.Add(this.dt_SiparisTarih);
            this.Controls.Add(this.dt_TeslimatTarih);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Isle);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Siparis";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Sipariş";
            this.Load += new System.EventHandler(this.Form_Siparis_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txt_Musteri;
        private System.Windows.Forms.DateTimePicker dt_SiparisTarih;
        private System.Windows.Forms.DateTimePicker dt_TeslimatTarih;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Isle;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_TeslimatAdres;
        private System.Windows.Forms.Button btn_SiparisDetay;
    }
}