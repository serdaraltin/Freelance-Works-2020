namespace Dosya_Tasima
{
    partial class Form_Main
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtDosya = new System.Windows.Forms.TextBox();
            this.btnDosyaSec = new System.Windows.Forms.Button();
            this.btnKonumSec = new System.Windows.Forms.Button();
            this.txtKonum = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnDosyayiTasi = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 74);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(115, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "Taşınacak Dosya";
            // 
            // txtDosya
            // 
            this.txtDosya.Location = new System.Drawing.Point(136, 71);
            this.txtDosya.Name = "txtDosya";
            this.txtDosya.ReadOnly = true;
            this.txtDosya.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.txtDosya.Size = new System.Drawing.Size(332, 22);
            this.txtDosya.TabIndex = 0;
            this.txtDosya.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnDosyaSec
            // 
            this.btnDosyaSec.Location = new System.Drawing.Point(474, 67);
            this.btnDosyaSec.Name = "btnDosyaSec";
            this.btnDosyaSec.Size = new System.Drawing.Size(114, 31);
            this.btnDosyaSec.TabIndex = 1;
            this.btnDosyaSec.Text = "Dosya Seç";
            this.btnDosyaSec.UseVisualStyleBackColor = true;
            this.btnDosyaSec.Click += new System.EventHandler(this.btnDosyaSec_Click);
            // 
            // btnKonumSec
            // 
            this.btnKonumSec.Location = new System.Drawing.Point(474, 104);
            this.btnKonumSec.Name = "btnKonumSec";
            this.btnKonumSec.Size = new System.Drawing.Size(114, 31);
            this.btnKonumSec.TabIndex = 3;
            this.btnKonumSec.Text = "Konum Seç";
            this.btnKonumSec.UseVisualStyleBackColor = true;
            this.btnKonumSec.Click += new System.EventHandler(this.btnKonumSec_Click);
            // 
            // txtKonum
            // 
            this.txtKonum.Location = new System.Drawing.Point(136, 108);
            this.txtKonum.Name = "txtKonum";
            this.txtKonum.ReadOnly = true;
            this.txtKonum.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.txtKonum.Size = new System.Drawing.Size(332, 22);
            this.txtKonum.TabIndex = 2;
            this.txtKonum.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 111);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(116, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Taşınacak Konum";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label4.ForeColor = System.Drawing.Color.Navy;
            this.label4.Location = new System.Drawing.Point(52, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(513, 25);
            this.label4.TabIndex = 8;
            this.label4.Text = "DOSYA İŞLEMLERİ - DOSYA TAŞIMA (MP3,WAV)";
            // 
            // btnDosyayiTasi
            // 
            this.btnDosyayiTasi.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnDosyayiTasi.Location = new System.Drawing.Point(161, 163);
            this.btnDosyayiTasi.Name = "btnDosyayiTasi";
            this.btnDosyayiTasi.Size = new System.Drawing.Size(283, 40);
            this.btnDosyayiTasi.TabIndex = 9;
            this.btnDosyayiTasi.Text = "DOSYAYI TAŞI";
            this.btnDosyayiTasi.UseVisualStyleBackColor = true;
            this.btnDosyayiTasi.Click += new System.EventHandler(this.btnDosyayiTasi_Click);
            // 
            // Form_Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.BackColor = System.Drawing.Color.DimGray;
            this.ClientSize = new System.Drawing.Size(606, 228);
            this.Controls.Add(this.btnDosyayiTasi);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.btnKonumSec);
            this.Controls.Add(this.txtKonum);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btnDosyaSec);
            this.Controls.Add(this.txtDosya);
            this.Controls.Add(this.label1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "Form_Main";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Dosya İşlemleri";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtDosya;
        private System.Windows.Forms.Button btnDosyaSec;
        private System.Windows.Forms.Button btnKonumSec;
        private System.Windows.Forms.TextBox txtKonum;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnDosyayiTasi;
    }
}

