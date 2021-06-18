namespace KomurArdiyesi
{
    partial class Form_Odeme
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
            this.btn_Isle = new System.Windows.Forms.Button();
            this.cb_OdemeYontem = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.txt_FaturaNo = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.dt_CikisTarih = new System.Windows.Forms.DateTimePicker();
            this.dt_GirisTarih = new System.Windows.Forms.DateTimePicker();
            this.dt_OdemeTarih = new System.Windows.Forms.DateTimePicker();
            this.dt_SiparisTarih = new System.Windows.Forms.DateTimePicker();
            this.txt_Musteri = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txt_Tutar = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(161, 242);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(94, 36);
            this.btn_Sil.TabIndex = 9;
            this.btn_Sil.Text = "Sil";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Isle
            // 
            this.btn_Isle.Location = new System.Drawing.Point(39, 242);
            this.btn_Isle.Name = "btn_Isle";
            this.btn_Isle.Size = new System.Drawing.Size(116, 36);
            this.btn_Isle.TabIndex = 8;
            this.btn_Isle.Text = "İşle";
            this.btn_Isle.UseVisualStyleBackColor = true;
            this.btn_Isle.Click += new System.EventHandler(this.btn_Isle_Click);
            // 
            // cb_OdemeYontem
            // 
            this.cb_OdemeYontem.FormattingEnabled = true;
            this.cb_OdemeYontem.Items.AddRange(new object[] {
            "Nakit",
            "Havale",
            "Çek",
            "Kredi Kartı"});
            this.cb_OdemeYontem.Location = new System.Drawing.Point(98, 151);
            this.cb_OdemeYontem.Name = "cb_OdemeYontem";
            this.cb_OdemeYontem.Size = new System.Drawing.Size(157, 21);
            this.cb_OdemeYontem.TabIndex = 5;
            this.cb_OdemeYontem.Text = "Nakit";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(36, 207);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(56, 13);
            this.label8.TabIndex = 32;
            this.label8.Text = "Çıkış Tarih";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(38, 181);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(54, 13);
            this.label7.TabIndex = 31;
            this.label7.Text = "Giriş Tarih";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(10, 154);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(82, 13);
            this.label6.TabIndex = 30;
            this.label6.Text = "Ödeme Yöntemi";
            // 
            // txt_FaturaNo
            // 
            this.txt_FaturaNo.Location = new System.Drawing.Point(98, 126);
            this.txt_FaturaNo.Name = "txt_FaturaNo";
            this.txt_FaturaNo.Size = new System.Drawing.Size(157, 20);
            this.txt_FaturaNo.TabIndex = 4;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(38, 129);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(54, 13);
            this.label5.TabIndex = 28;
            this.label5.Text = "Fatura No";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(22, 103);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 13);
            this.label4.TabIndex = 25;
            this.label4.Text = "Ödeme Tarihi";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 77);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 13);
            this.label3.TabIndex = 21;
            this.label3.Text = "Siparis Tarihi";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(60, 51);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 13);
            this.label2.TabIndex = 18;
            this.label2.Text = "Tutar";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(51, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 13);
            this.label1.TabIndex = 15;
            this.label1.Text = "Musteri";
            // 
            // dt_CikisTarih
            // 
            this.dt_CikisTarih.Location = new System.Drawing.Point(98, 204);
            this.dt_CikisTarih.Name = "dt_CikisTarih";
            this.dt_CikisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_CikisTarih.TabIndex = 7;
            // 
            // dt_GirisTarih
            // 
            this.dt_GirisTarih.Location = new System.Drawing.Point(98, 178);
            this.dt_GirisTarih.Name = "dt_GirisTarih";
            this.dt_GirisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_GirisTarih.TabIndex = 6;
            // 
            // dt_OdemeTarih
            // 
            this.dt_OdemeTarih.Location = new System.Drawing.Point(98, 100);
            this.dt_OdemeTarih.Name = "dt_OdemeTarih";
            this.dt_OdemeTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_OdemeTarih.TabIndex = 3;
            // 
            // dt_SiparisTarih
            // 
            this.dt_SiparisTarih.Location = new System.Drawing.Point(98, 74);
            this.dt_SiparisTarih.Name = "dt_SiparisTarih";
            this.dt_SiparisTarih.Size = new System.Drawing.Size(157, 20);
            this.dt_SiparisTarih.TabIndex = 2;
            // 
            // txt_Musteri
            // 
            this.txt_Musteri.Location = new System.Drawing.Point(98, 22);
            this.txt_Musteri.Name = "txt_Musteri";
            this.txt_Musteri.ReadOnly = true;
            this.txt_Musteri.Size = new System.Drawing.Size(157, 20);
            this.txt_Musteri.TabIndex = 0;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(178, 52);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(20, 13);
            this.label9.TabIndex = 38;
            this.label9.Text = "TL";
            // 
            // txt_Tutar
            // 
            this.txt_Tutar.Location = new System.Drawing.Point(98, 48);
            this.txt_Tutar.Name = "txt_Tutar";
            this.txt_Tutar.Size = new System.Drawing.Size(74, 20);
            this.txt_Tutar.TabIndex = 39;
            this.txt_Tutar.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_Tutar_KeyPress);
            // 
            // Form_Odeme
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(288, 298);
            this.Controls.Add(this.txt_Tutar);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txt_Musteri);
            this.Controls.Add(this.dt_SiparisTarih);
            this.Controls.Add(this.dt_OdemeTarih);
            this.Controls.Add(this.dt_GirisTarih);
            this.Controls.Add(this.dt_CikisTarih);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Isle);
            this.Controls.Add(this.cb_OdemeYontem);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txt_FaturaNo);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Odeme";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Ödeme";
            this.Load += new System.EventHandler(this.Form_Odeme_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Isle;
        private System.Windows.Forms.ComboBox cb_OdemeYontem;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txt_FaturaNo;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dt_CikisTarih;
        private System.Windows.Forms.DateTimePicker dt_GirisTarih;
        private System.Windows.Forms.DateTimePicker dt_OdemeTarih;
        private System.Windows.Forms.DateTimePicker dt_SiparisTarih;
        private System.Windows.Forms.TextBox txt_Musteri;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txt_Tutar;
    }
}