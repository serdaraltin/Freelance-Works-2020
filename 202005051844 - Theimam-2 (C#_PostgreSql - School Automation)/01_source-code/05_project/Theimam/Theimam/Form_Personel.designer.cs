﻿namespace Theimam
{
    partial class Form_Personel
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
            this.txt_Eposta = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Ekle = new System.Windows.Forms.Button();
            this.txt_Telefon = new System.Windows.Forms.MaskedTextBox();
            this.txt_TcNo = new System.Windows.Forms.MaskedTextBox();
            this.cb_Alan = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txt_Adres = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txt_Soyad = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_Ad = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txt_Eposta
            // 
            this.txt_Eposta.Location = new System.Drawing.Point(82, 183);
            this.txt_Eposta.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Eposta.Name = "txt_Eposta";
            this.txt_Eposta.Size = new System.Drawing.Size(227, 23);
            this.txt_Eposta.TabIndex = 44;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(25, 187);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 17);
            this.label4.TabIndex = 54;
            this.label4.Text = "Eposta";
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(219, 305);
            this.btn_Sil.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(91, 46);
            this.btn_Sil.TabIndex = 47;
            this.btn_Sil.Text = "SİL";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Ekle
            // 
            this.btn_Ekle.Location = new System.Drawing.Point(82, 305);
            this.btn_Ekle.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Ekle.Name = "btn_Ekle";
            this.btn_Ekle.Size = new System.Drawing.Size(129, 46);
            this.btn_Ekle.TabIndex = 46;
            this.btn_Ekle.Text = "EKLE";
            this.btn_Ekle.UseVisualStyleBackColor = true;
            this.btn_Ekle.Click += new System.EventHandler(this.btn_Ekle_Click);
            // 
            // txt_Telefon
            // 
            this.txt_Telefon.Location = new System.Drawing.Point(82, 153);
            this.txt_Telefon.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Telefon.Mask = "(999) 000-0000";
            this.txt_Telefon.Name = "txt_Telefon";
            this.txt_Telefon.Size = new System.Drawing.Size(144, 23);
            this.txt_Telefon.TabIndex = 43;
            // 
            // txt_TcNo
            // 
            this.txt_TcNo.Location = new System.Drawing.Point(82, 58);
            this.txt_TcNo.Margin = new System.Windows.Forms.Padding(4);
            this.txt_TcNo.Mask = "00000000000";
            this.txt_TcNo.Name = "txt_TcNo";
            this.txt_TcNo.Size = new System.Drawing.Size(144, 23);
            this.txt_TcNo.TabIndex = 40;
            // 
            // cb_Alan
            // 
            this.cb_Alan.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Alan.FormattingEnabled = true;
            this.cb_Alan.Location = new System.Drawing.Point(82, 25);
            this.cb_Alan.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Alan.Name = "cb_Alan";
            this.cb_Alan.Size = new System.Drawing.Size(227, 24);
            this.cb_Alan.TabIndex = 39;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(35, 28);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(36, 17);
            this.label9.TabIndex = 53;
            this.label9.Text = "Alan";
            // 
            // txt_Adres
            // 
            this.txt_Adres.Location = new System.Drawing.Point(82, 214);
            this.txt_Adres.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Adres.Multiline = true;
            this.txt_Adres.Name = "txt_Adres";
            this.txt_Adres.Size = new System.Drawing.Size(227, 83);
            this.txt_Adres.TabIndex = 45;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(29, 218);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(45, 17);
            this.label8.TabIndex = 52;
            this.label8.Text = "Adres";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(17, 157);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 17);
            this.label5.TabIndex = 51;
            this.label5.Text = "Telefon";
            // 
            // txt_Soyad
            // 
            this.txt_Soyad.Location = new System.Drawing.Point(82, 122);
            this.txt_Soyad.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Soyad.Name = "txt_Soyad";
            this.txt_Soyad.Size = new System.Drawing.Size(227, 23);
            this.txt_Soyad.TabIndex = 42;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(25, 126);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 17);
            this.label3.TabIndex = 50;
            this.label3.Text = "Soyad";
            // 
            // txt_Ad
            // 
            this.txt_Ad.Location = new System.Drawing.Point(82, 90);
            this.txt_Ad.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Ad.Name = "txt_Ad";
            this.txt_Ad.Size = new System.Drawing.Size(227, 23);
            this.txt_Ad.TabIndex = 41;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(47, 94);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 17);
            this.label2.TabIndex = 49;
            this.label2.Text = "Ad";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 62);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 48;
            this.label1.Text = "Tc No";
            // 
            // Form_Personel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(348, 368);
            this.Controls.Add(this.txt_Eposta);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Ekle);
            this.Controls.Add(this.txt_Telefon);
            this.Controls.Add(this.txt_TcNo);
            this.Controls.Add(this.cb_Alan);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txt_Adres);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txt_Soyad);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txt_Ad);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form_Personel";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Personel";
            this.Load += new System.EventHandler(this.Form_Ogrenci_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txt_Eposta;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Ekle;
        private System.Windows.Forms.MaskedTextBox txt_Telefon;
        private System.Windows.Forms.MaskedTextBox txt_TcNo;
        private System.Windows.Forms.ComboBox cb_Alan;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txt_Adres;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txt_Soyad;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_Ad;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}