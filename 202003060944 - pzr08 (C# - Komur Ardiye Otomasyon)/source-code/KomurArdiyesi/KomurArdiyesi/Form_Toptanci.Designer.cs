namespace KomurArdiyesi
{
    partial class Form_Toptanci
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
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Isle = new System.Windows.Forms.Button();
            this.cb_Firma = new System.Windows.Forms.ComboBox();
            this.txt_Mail = new System.Windows.Forms.TextBox();
            this.txt_Adres = new System.Windows.Forms.TextBox();
            this.txt_Telefon = new System.Windows.Forms.MaskedTextBox();
            this.SuspendLayout();
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(34, 13);
            this.label4.TabIndex = 50;
            this.label4.Text = "Adres";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(31, 77);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 13);
            this.label3.TabIndex = 49;
            this.label3.Text = "Mail";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(43, 13);
            this.label2.TabIndex = 48;
            this.label2.Text = "Telefon";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 21);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(32, 13);
            this.label1.TabIndex = 47;
            this.label1.Text = "Firma";
            // 
            // btn_Sil
            // 
            this.btn_Sil.Location = new System.Drawing.Point(151, 183);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(69, 36);
            this.btn_Sil.TabIndex = 58;
            this.btn_Sil.Text = "Sil";
            this.btn_Sil.UseVisualStyleBackColor = true;
            this.btn_Sil.Visible = false;
            this.btn_Sil.Click += new System.EventHandler(this.btn_Sil_Click);
            // 
            // btn_Isle
            // 
            this.btn_Isle.Location = new System.Drawing.Point(34, 183);
            this.btn_Isle.Name = "btn_Isle";
            this.btn_Isle.Size = new System.Drawing.Size(110, 36);
            this.btn_Isle.TabIndex = 57;
            this.btn_Isle.Text = "İşle";
            this.btn_Isle.UseVisualStyleBackColor = true;
            this.btn_Isle.Click += new System.EventHandler(this.btn_Isle_Click);
            // 
            // cb_Firma
            // 
            this.cb_Firma.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cb_Firma.FormattingEnabled = true;
            this.cb_Firma.Location = new System.Drawing.Point(63, 18);
            this.cb_Firma.Name = "cb_Firma";
            this.cb_Firma.Size = new System.Drawing.Size(157, 21);
            this.cb_Firma.TabIndex = 59;
            // 
            // txt_Mail
            // 
            this.txt_Mail.Location = new System.Drawing.Point(63, 71);
            this.txt_Mail.Name = "txt_Mail";
            this.txt_Mail.Size = new System.Drawing.Size(157, 20);
            this.txt_Mail.TabIndex = 61;
            // 
            // txt_Adres
            // 
            this.txt_Adres.Location = new System.Drawing.Point(63, 97);
            this.txt_Adres.Multiline = true;
            this.txt_Adres.Name = "txt_Adres";
            this.txt_Adres.Size = new System.Drawing.Size(157, 76);
            this.txt_Adres.TabIndex = 62;
            // 
            // txt_Telefon
            // 
            this.txt_Telefon.Location = new System.Drawing.Point(63, 45);
            this.txt_Telefon.Mask = "(999) 000-0000";
            this.txt_Telefon.Name = "txt_Telefon";
            this.txt_Telefon.Size = new System.Drawing.Size(157, 20);
            this.txt_Telefon.TabIndex = 63;
            // 
            // Form_Toptanci
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(235, 239);
            this.Controls.Add(this.txt_Telefon);
            this.Controls.Add(this.txt_Adres);
            this.Controls.Add(this.txt_Mail);
            this.Controls.Add(this.cb_Firma);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.btn_Isle);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Toptanci";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Toptancı";
            this.Load += new System.EventHandler(this.Form_Toptanci_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Isle;
        private System.Windows.Forms.ComboBox cb_Firma;
        private System.Windows.Forms.TextBox txt_Mail;
        private System.Windows.Forms.TextBox txt_Adres;
        private System.Windows.Forms.MaskedTextBox txt_Telefon;
    }
}