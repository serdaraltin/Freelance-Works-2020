namespace DershaneOtomasyon
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
            this.cb_Dal = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Ekle = new System.Windows.Forms.Button();
            this.txt_Telefon = new System.Windows.Forms.MaskedTextBox();
            this.cb_Cinsiyet = new System.Windows.Forms.ComboBox();
            this.txt_TcNo = new System.Windows.Forms.MaskedTextBox();
            this.txt_Adres = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.txt_Soyad = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_Ad = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_Maas = new System.Windows.Forms.MaskedTextBox();
            this.cb_Bolum = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // cb_Dal
            // 
            this.cb_Dal.FormattingEnabled = true;
            this.cb_Dal.Items.AddRange(new object[] {
            "Matematik",
            "Fen",
            "Türkçe",
            "Felsefe"});
            this.cb_Dal.Location = new System.Drawing.Point(81, 214);
            this.cb_Dal.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Dal.Name = "cb_Dal";
            this.cb_Dal.Size = new System.Drawing.Size(144, 24);
            this.cb_Dal.TabIndex = 6;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(44, 217);
            this.label12.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(29, 17);
            this.label12.TabIndex = 63;
            this.label12.Text = "Dal";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(232, 252);
            this.label10.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(25, 17);
            this.label10.TabIndex = 62;
            this.label10.Text = "TL";
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(218, 370);
            this.btn_Sil.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(91, 46);
            this.btn_Sil.TabIndex = 10;
            this.btn_Sil.Text = "SİL";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Ekle
            // 
            this.btn_Ekle.Location = new System.Drawing.Point(81, 370);
            this.btn_Ekle.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Ekle.Name = "btn_Ekle";
            this.btn_Ekle.Size = new System.Drawing.Size(129, 46);
            this.btn_Ekle.TabIndex = 9;
            this.btn_Ekle.Text = "EKLE";
            this.btn_Ekle.UseVisualStyleBackColor = true;
            this.btn_Ekle.Click += new System.EventHandler(this.btn_Ekle_Click);
            // 
            // txt_Telefon
            // 
            this.txt_Telefon.Location = new System.Drawing.Point(81, 151);
            this.txt_Telefon.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Telefon.Mask = "(999) 000-0000";
            this.txt_Telefon.Name = "txt_Telefon";
            this.txt_Telefon.Size = new System.Drawing.Size(144, 23);
            this.txt_Telefon.TabIndex = 4;
            // 
            // cb_Cinsiyet
            // 
            this.cb_Cinsiyet.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Cinsiyet.FormattingEnabled = true;
            this.cb_Cinsiyet.Items.AddRange(new object[] {
            "Erkek",
            "Kız",
            "Diğer"});
            this.cb_Cinsiyet.Location = new System.Drawing.Point(81, 118);
            this.cb_Cinsiyet.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Cinsiyet.Name = "cb_Cinsiyet";
            this.cb_Cinsiyet.Size = new System.Drawing.Size(144, 24);
            this.cb_Cinsiyet.TabIndex = 3;
            // 
            // txt_TcNo
            // 
            this.txt_TcNo.Location = new System.Drawing.Point(81, 23);
            this.txt_TcNo.Margin = new System.Windows.Forms.Padding(4);
            this.txt_TcNo.Mask = "00000000000";
            this.txt_TcNo.Name = "txt_TcNo";
            this.txt_TcNo.Size = new System.Drawing.Size(144, 23);
            this.txt_TcNo.TabIndex = 0;
            // 
            // txt_Adres
            // 
            this.txt_Adres.Location = new System.Drawing.Point(82, 279);
            this.txt_Adres.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Adres.Multiline = true;
            this.txt_Adres.Name = "txt_Adres";
            this.txt_Adres.Size = new System.Drawing.Size(227, 83);
            this.txt_Adres.TabIndex = 8;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(29, 283);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(45, 17);
            this.label8.TabIndex = 60;
            this.label8.Text = "Adres";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(32, 252);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(42, 17);
            this.label7.TabIndex = 59;
            this.label7.Text = "Maaş";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(16, 155);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 17);
            this.label5.TabIndex = 57;
            this.label5.Text = "Telefon";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(16, 123);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(57, 17);
            this.label4.TabIndex = 56;
            this.label4.Text = "Cinsiyet";
            // 
            // txt_Soyad
            // 
            this.txt_Soyad.Location = new System.Drawing.Point(81, 87);
            this.txt_Soyad.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Soyad.Name = "txt_Soyad";
            this.txt_Soyad.Size = new System.Drawing.Size(227, 23);
            this.txt_Soyad.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(24, 91);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(48, 17);
            this.label3.TabIndex = 55;
            this.label3.Text = "Soyad";
            // 
            // txt_Ad
            // 
            this.txt_Ad.Location = new System.Drawing.Point(81, 55);
            this.txt_Ad.Margin = new System.Windows.Forms.Padding(4);
            this.txt_Ad.Name = "txt_Ad";
            this.txt_Ad.Size = new System.Drawing.Size(227, 23);
            this.txt_Ad.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 59);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 17);
            this.label2.TabIndex = 54;
            this.label2.Text = "Ad";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 27);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(46, 17);
            this.label1.TabIndex = 53;
            this.label1.Text = "Tc No";
            // 
            // txt_Maas
            // 
            this.txt_Maas.Location = new System.Drawing.Point(81, 249);
            this.txt_Maas.Mask = "00000000";
            this.txt_Maas.Name = "txt_Maas";
            this.txt_Maas.Size = new System.Drawing.Size(144, 23);
            this.txt_Maas.TabIndex = 7;
            this.txt_Maas.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // cb_Bolum
            // 
            this.cb_Bolum.FormattingEnabled = true;
            this.cb_Bolum.Items.AddRange(new object[] {
            "İlkokul",
            "Lise",
            "Üniversite"});
            this.cb_Bolum.Location = new System.Drawing.Point(81, 182);
            this.cb_Bolum.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Bolum.Name = "cb_Bolum";
            this.cb_Bolum.Size = new System.Drawing.Size(144, 24);
            this.cb_Bolum.TabIndex = 5;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(25, 185);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(47, 17);
            this.label6.TabIndex = 66;
            this.label6.Text = "Bölüm";
            // 
            // Form_Personel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(332, 436);
            this.Controls.Add(this.cb_Bolum);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txt_Maas);
            this.Controls.Add(this.cb_Dal);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Ekle);
            this.Controls.Add(this.txt_Telefon);
            this.Controls.Add(this.cb_Cinsiyet);
            this.Controls.Add(this.txt_TcNo);
            this.Controls.Add(this.txt_Adres);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
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
            this.Load += new System.EventHandler(this.Form_Personel_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cb_Dal;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Ekle;
        private System.Windows.Forms.MaskedTextBox txt_Telefon;
        private System.Windows.Forms.ComboBox cb_Cinsiyet;
        private System.Windows.Forms.MaskedTextBox txt_TcNo;
        private System.Windows.Forms.TextBox txt_Adres;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txt_Soyad;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_Ad;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MaskedTextBox txt_Maas;
        private System.Windows.Forms.ComboBox cb_Bolum;
        private System.Windows.Forms.Label label6;
    }
}