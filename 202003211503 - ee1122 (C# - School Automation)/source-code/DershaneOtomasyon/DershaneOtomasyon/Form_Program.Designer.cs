namespace DershaneOtomasyon
{
    partial class Form_Program
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
            this.cb_Sinif = new System.Windows.Forms.ComboBox();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Ekle = new System.Windows.Forms.Button();
            this.cb_Ders = new System.Windows.Forms.ComboBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.cb_Gun = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_Baslangic = new System.Windows.Forms.MaskedTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_Bitis = new System.Windows.Forms.MaskedTextBox();
            this.SuspendLayout();
            // 
            // cb_Sinif
            // 
            this.cb_Sinif.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Sinif.FormattingEnabled = true;
            this.cb_Sinif.Location = new System.Drawing.Point(89, 47);
            this.cb_Sinif.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Sinif.Name = "cb_Sinif";
            this.cb_Sinif.Size = new System.Drawing.Size(227, 24);
            this.cb_Sinif.TabIndex = 1;
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(226, 146);
            this.btn_Sil.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(91, 46);
            this.btn_Sil.TabIndex = 6;
            this.btn_Sil.Text = "SİL";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Ekle
            // 
            this.btn_Ekle.Location = new System.Drawing.Point(89, 146);
            this.btn_Ekle.Margin = new System.Windows.Forms.Padding(4);
            this.btn_Ekle.Name = "btn_Ekle";
            this.btn_Ekle.Size = new System.Drawing.Size(129, 46);
            this.btn_Ekle.TabIndex = 5;
            this.btn_Ekle.Text = "EKLE";
            this.btn_Ekle.UseVisualStyleBackColor = true;
            this.btn_Ekle.Click += new System.EventHandler(this.btn_Ekle_Click);
            // 
            // cb_Ders
            // 
            this.cb_Ders.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Ders.FormattingEnabled = true;
            this.cb_Ders.Location = new System.Drawing.Point(89, 15);
            this.cb_Ders.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Ders.Name = "cb_Ders";
            this.cb_Ders.Size = new System.Drawing.Size(227, 24);
            this.cb_Ders.TabIndex = 0;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(43, 18);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(38, 17);
            this.label9.TabIndex = 71;
            this.label9.Text = "Ders";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(46, 50);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(35, 17);
            this.label6.TabIndex = 69;
            this.label6.Text = "Sınıf";
            // 
            // cb_Gun
            // 
            this.cb_Gun.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Gun.FormattingEnabled = true;
            this.cb_Gun.Items.AddRange(new object[] {
            "Pazartesi",
            "Salı",
            "Çarşamba",
            "Perşembe",
            "Cuma",
            "Cumartesi",
            "Pazar"});
            this.cb_Gun.Location = new System.Drawing.Point(89, 79);
            this.cb_Gun.Margin = new System.Windows.Forms.Padding(4);
            this.cb_Gun.Name = "cb_Gun";
            this.cb_Gun.Size = new System.Drawing.Size(227, 24);
            this.cb_Gun.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(46, 82);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 17);
            this.label1.TabIndex = 73;
            this.label1.Text = "Gün";
            // 
            // txt_Baslangic
            // 
            this.txt_Baslangic.Location = new System.Drawing.Point(89, 110);
            this.txt_Baslangic.Mask = "00:00";
            this.txt_Baslangic.Name = "txt_Baslangic";
            this.txt_Baslangic.Size = new System.Drawing.Size(76, 23);
            this.txt_Baslangic.TabIndex = 3;
            this.txt_Baslangic.ValidatingType = typeof(System.DateTime);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 113);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 17);
            this.label2.TabIndex = 75;
            this.label2.Text = "Başlangıç";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(199, 113);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(34, 17);
            this.label3.TabIndex = 77;
            this.label3.Text = "Bitiş";
            // 
            // txt_Bitis
            // 
            this.txt_Bitis.Location = new System.Drawing.Point(240, 110);
            this.txt_Bitis.Mask = "00:00";
            this.txt_Bitis.Name = "txt_Bitis";
            this.txt_Bitis.Size = new System.Drawing.Size(76, 23);
            this.txt_Bitis.TabIndex = 4;
            this.txt_Bitis.ValidatingType = typeof(System.DateTime);
            // 
            // Form_Program
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(341, 208);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txt_Bitis);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txt_Baslangic);
            this.Controls.Add(this.cb_Gun);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cb_Sinif);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Ekle);
            this.Controls.Add(this.cb_Ders);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label6);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form_Program";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Program";
            this.Load += new System.EventHandler(this.Form_Program_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cb_Sinif;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Ekle;
        private System.Windows.Forms.ComboBox cb_Ders;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cb_Gun;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MaskedTextBox txt_Baslangic;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.MaskedTextBox txt_Bitis;
    }
}