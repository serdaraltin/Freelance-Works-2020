namespace KomurArdiyesi
{
    partial class Form_Siparisler
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
            this.dg_Siparisler = new System.Windows.Forms.DataGridView();
            this.txt_SiparisId = new System.Windows.Forms.TextBox();
            this.btn_Ekle = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txt_Musteri = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.lst_Urun = new System.Windows.Forms.ListBox();
            this.txt_Miktar = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.txt_Fiyat = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.btn_Sil = new System.Windows.Forms.Button();
            this.btn_Temizle = new System.Windows.Forms.Button();
            this.txt_Id = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Siparisler)).BeginInit();
            this.SuspendLayout();
            // 
            // dg_Siparisler
            // 
            this.dg_Siparisler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Siparisler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Siparisler.Location = new System.Drawing.Point(245, 21);
            this.dg_Siparisler.MultiSelect = false;
            this.dg_Siparisler.Name = "dg_Siparisler";
            this.dg_Siparisler.ReadOnly = true;
            this.dg_Siparisler.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Siparisler.Size = new System.Drawing.Size(503, 413);
            this.dg_Siparisler.TabIndex = 0;
            this.dg_Siparisler.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Siparisler_RowEnter);
            this.dg_Siparisler.DragEnter += new System.Windows.Forms.DragEventHandler(this.dg_Siparisler_DragEnter);
            // 
            // txt_SiparisId
            // 
            this.txt_SiparisId.Location = new System.Drawing.Point(65, 47);
            this.txt_SiparisId.Name = "txt_SiparisId";
            this.txt_SiparisId.ReadOnly = true;
            this.txt_SiparisId.Size = new System.Drawing.Size(76, 20);
            this.txt_SiparisId.TabIndex = 58;
            // 
            // btn_Ekle
            // 
            this.btn_Ekle.Location = new System.Drawing.Point(65, 339);
            this.btn_Ekle.Name = "btn_Ekle";
            this.btn_Ekle.Size = new System.Drawing.Size(157, 36);
            this.btn_Ekle.TabIndex = 61;
            this.btn_Ekle.Text = "Ekle";
            this.btn_Ekle.UseVisualStyleBackColor = true;
            this.btn_Ekle.Click += new System.EventHandler(this.btn_Ekle_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 281);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 13);
            this.label3.TabIndex = 63;
            this.label3.Text = "Miktar";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 62;
            this.label1.Text = "Sipariş Id";
            // 
            // txt_Musteri
            // 
            this.txt_Musteri.Location = new System.Drawing.Point(65, 21);
            this.txt_Musteri.Name = "txt_Musteri";
            this.txt_Musteri.ReadOnly = true;
            this.txt_Musteri.Size = new System.Drawing.Size(157, 20);
            this.txt_Musteri.TabIndex = 67;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(18, 24);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 13);
            this.label2.TabIndex = 68;
            this.label2.Text = "Musteri";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(29, 99);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(30, 13);
            this.label4.TabIndex = 70;
            this.label4.Text = "Urun";
            // 
            // lst_Urun
            // 
            this.lst_Urun.FormattingEnabled = true;
            this.lst_Urun.Location = new System.Drawing.Point(65, 99);
            this.lst_Urun.Name = "lst_Urun";
            this.lst_Urun.Size = new System.Drawing.Size(157, 173);
            this.lst_Urun.TabIndex = 71;
            // 
            // txt_Miktar
            // 
            this.txt_Miktar.Location = new System.Drawing.Point(65, 278);
            this.txt_Miktar.Name = "txt_Miktar";
            this.txt_Miktar.Size = new System.Drawing.Size(122, 20);
            this.txt_Miktar.TabIndex = 72;
            this.txt_Miktar.TextChanged += new System.EventHandler(this.txt_Miktar_TextChanged);
            this.txt_Miktar.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(193, 285);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(29, 13);
            this.label5.TabIndex = 73;
            this.label5.Text = "Adet";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(193, 311);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(20, 13);
            this.label6.TabIndex = 76;
            this.label6.Text = "TL";
            // 
            // txt_Fiyat
            // 
            this.txt_Fiyat.Location = new System.Drawing.Point(65, 304);
            this.txt_Fiyat.Name = "txt_Fiyat";
            this.txt_Fiyat.ReadOnly = true;
            this.txt_Fiyat.Size = new System.Drawing.Size(122, 20);
            this.txt_Fiyat.TabIndex = 75;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(30, 307);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(29, 13);
            this.label7.TabIndex = 74;
            this.label7.Text = "Fiyat";
            // 
            // btn_Sil
            // 
            this.btn_Sil.Enabled = false;
            this.btn_Sil.Location = new System.Drawing.Point(65, 381);
            this.btn_Sil.Name = "btn_Sil";
            this.btn_Sil.Size = new System.Drawing.Size(76, 36);
            this.btn_Sil.TabIndex = 77;
            this.btn_Sil.Text = "Sil";
            this.btn_Sil.UseVisualStyleBackColor = true;
            // 
            // btn_Temizle
            // 
            this.btn_Temizle.Location = new System.Drawing.Point(146, 381);
            this.btn_Temizle.Name = "btn_Temizle";
            this.btn_Temizle.Size = new System.Drawing.Size(76, 36);
            this.btn_Temizle.TabIndex = 78;
            this.btn_Temizle.Text = "Temizle";
            this.btn_Temizle.UseVisualStyleBackColor = true;
            this.btn_Temizle.Click += new System.EventHandler(this.btn_Temizle_Click);
            // 
            // txt_Id
            // 
            this.txt_Id.Location = new System.Drawing.Point(65, 73);
            this.txt_Id.Name = "txt_Id";
            this.txt_Id.ReadOnly = true;
            this.txt_Id.Size = new System.Drawing.Size(76, 20);
            this.txt_Id.TabIndex = 79;
            this.txt_Id.TextChanged += new System.EventHandler(this.txt_Id_TextChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(43, 76);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(16, 13);
            this.label8.TabIndex = 80;
            this.label8.Text = "Id";
            // 
            // Form_Siparisler
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(758, 448);
            this.Controls.Add(this.txt_Id);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.btn_Temizle);
            this.Controls.Add(this.btn_Sil);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txt_Fiyat);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txt_Miktar);
            this.Controls.Add(this.lst_Urun);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txt_Musteri);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txt_SiparisId);
            this.Controls.Add(this.btn_Ekle);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dg_Siparisler);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Siparisler";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Siparişler";
            this.Load += new System.EventHandler(this.Form_SiparisDetay_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dg_Siparisler)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dg_Siparisler;
        private System.Windows.Forms.TextBox txt_SiparisId;
        private System.Windows.Forms.Button btn_Ekle;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txt_Musteri;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox lst_Urun;
        private System.Windows.Forms.TextBox txt_Miktar;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txt_Fiyat;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button btn_Sil;
        private System.Windows.Forms.Button btn_Temizle;
        private System.Windows.Forms.TextBox txt_Id;
        private System.Windows.Forms.Label label8;
    }
}