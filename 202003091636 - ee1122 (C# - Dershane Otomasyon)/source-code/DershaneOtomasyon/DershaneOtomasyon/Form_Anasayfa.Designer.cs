namespace DershaneOtomasyon
{
    partial class Form_Anasayfa
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.programToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.yenidenBaşlatToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kapatToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.veritabanıToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kontrolToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.hakkındaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btn_OgrenciIsl = new System.Windows.Forms.Button();
            this.btn_VeliIsl = new System.Windows.Forms.Button();
            this.btn_PersonelIsl = new System.Windows.Forms.Button();
            this.btn_OdemeIsl = new System.Windows.Forms.Button();
            this.btn_SinifIsl = new System.Windows.Forms.Button();
            this.btn_DersIsl = new System.Windows.Forms.Button();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.stLb_Durum = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.programToolStripMenuItem,
            this.veritabanıToolStripMenuItem,
            this.hakkındaToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(626, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // programToolStripMenuItem
            // 
            this.programToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.yenidenBaşlatToolStripMenuItem,
            this.kapatToolStripMenuItem});
            this.programToolStripMenuItem.Name = "programToolStripMenuItem";
            this.programToolStripMenuItem.Size = new System.Drawing.Size(65, 20);
            this.programToolStripMenuItem.Text = "Program";
            // 
            // yenidenBaşlatToolStripMenuItem
            // 
            this.yenidenBaşlatToolStripMenuItem.Name = "yenidenBaşlatToolStripMenuItem";
            this.yenidenBaşlatToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.yenidenBaşlatToolStripMenuItem.Text = "Yeniden Başlat";
            this.yenidenBaşlatToolStripMenuItem.Click += new System.EventHandler(this.yenidenBaşlatToolStripMenuItem_Click);
            // 
            // kapatToolStripMenuItem
            // 
            this.kapatToolStripMenuItem.Name = "kapatToolStripMenuItem";
            this.kapatToolStripMenuItem.Size = new System.Drawing.Size(150, 22);
            this.kapatToolStripMenuItem.Text = "Kapat";
            this.kapatToolStripMenuItem.Click += new System.EventHandler(this.kapatToolStripMenuItem_Click);
            // 
            // veritabanıToolStripMenuItem
            // 
            this.veritabanıToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kontrolToolStripMenuItem});
            this.veritabanıToolStripMenuItem.Name = "veritabanıToolStripMenuItem";
            this.veritabanıToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.veritabanıToolStripMenuItem.Text = "Veritabanı";
            // 
            // kontrolToolStripMenuItem
            // 
            this.kontrolToolStripMenuItem.Name = "kontrolToolStripMenuItem";
            this.kontrolToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.kontrolToolStripMenuItem.Text = "Kontrol";
            this.kontrolToolStripMenuItem.Click += new System.EventHandler(this.kontrolToolStripMenuItem_Click);
            // 
            // hakkındaToolStripMenuItem
            // 
            this.hakkındaToolStripMenuItem.Name = "hakkındaToolStripMenuItem";
            this.hakkındaToolStripMenuItem.Size = new System.Drawing.Size(69, 20);
            this.hakkındaToolStripMenuItem.Text = "Hakkında";
            this.hakkındaToolStripMenuItem.Click += new System.EventHandler(this.hakkındaToolStripMenuItem_Click);
            // 
            // btn_OgrenciIsl
            // 
            this.btn_OgrenciIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_OgrenciIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_OgrenciIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_OgrenciIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_OgrenciIsl.Location = new System.Drawing.Point(23, 41);
            this.btn_OgrenciIsl.Name = "btn_OgrenciIsl";
            this.btn_OgrenciIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_OgrenciIsl.TabIndex = 1;
            this.btn_OgrenciIsl.Text = "ÖĞRENCİ İŞLEMLERİ";
            this.btn_OgrenciIsl.UseVisualStyleBackColor = false;
            this.btn_OgrenciIsl.Click += new System.EventHandler(this.btn_OgrenciIsl_Click);
            // 
            // btn_VeliIsl
            // 
            this.btn_VeliIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_VeliIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_VeliIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_VeliIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_VeliIsl.Location = new System.Drawing.Point(218, 41);
            this.btn_VeliIsl.Name = "btn_VeliIsl";
            this.btn_VeliIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_VeliIsl.TabIndex = 2;
            this.btn_VeliIsl.Text = "VELİ\r\nİŞLEMLERİ";
            this.btn_VeliIsl.UseVisualStyleBackColor = false;
            this.btn_VeliIsl.Click += new System.EventHandler(this.btn_VeliIsl_Click);
            // 
            // btn_PersonelIsl
            // 
            this.btn_PersonelIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_PersonelIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_PersonelIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_PersonelIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_PersonelIsl.Location = new System.Drawing.Point(413, 41);
            this.btn_PersonelIsl.Name = "btn_PersonelIsl";
            this.btn_PersonelIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_PersonelIsl.TabIndex = 3;
            this.btn_PersonelIsl.Text = "PERSONEL İŞLEMLERİ";
            this.btn_PersonelIsl.UseVisualStyleBackColor = false;
            this.btn_PersonelIsl.Click += new System.EventHandler(this.btn_PersonelIsl_Click);
            // 
            // btn_OdemeIsl
            // 
            this.btn_OdemeIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_OdemeIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_OdemeIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_OdemeIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_OdemeIsl.Location = new System.Drawing.Point(23, 172);
            this.btn_OdemeIsl.Name = "btn_OdemeIsl";
            this.btn_OdemeIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_OdemeIsl.TabIndex = 4;
            this.btn_OdemeIsl.Text = "ÖDEME İŞLEMLERİ";
            this.btn_OdemeIsl.UseVisualStyleBackColor = false;
            this.btn_OdemeIsl.Click += new System.EventHandler(this.btn_OdemeIsl_Click);
            // 
            // btn_SinifIsl
            // 
            this.btn_SinifIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_SinifIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_SinifIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_SinifIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_SinifIsl.Location = new System.Drawing.Point(218, 172);
            this.btn_SinifIsl.Name = "btn_SinifIsl";
            this.btn_SinifIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_SinifIsl.TabIndex = 5;
            this.btn_SinifIsl.Text = "SINIF\r\nİŞLEMLERİ";
            this.btn_SinifIsl.UseVisualStyleBackColor = false;
            this.btn_SinifIsl.Click += new System.EventHandler(this.btn_SinifIsl_Click);
            // 
            // btn_DersIsl
            // 
            this.btn_DersIsl.BackColor = System.Drawing.Color.Indigo;
            this.btn_DersIsl.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btn_DersIsl.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btn_DersIsl.ForeColor = System.Drawing.Color.Yellow;
            this.btn_DersIsl.Location = new System.Drawing.Point(413, 172);
            this.btn_DersIsl.Name = "btn_DersIsl";
            this.btn_DersIsl.Size = new System.Drawing.Size(189, 125);
            this.btn_DersIsl.TabIndex = 6;
            this.btn_DersIsl.Text = "DERS\r\nİŞLEMLERİ";
            this.btn_DersIsl.UseVisualStyleBackColor = false;
            this.btn_DersIsl.Click += new System.EventHandler(this.btn_DersIsl_Click);
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.stLb_Durum});
            this.statusStrip1.Location = new System.Drawing.Point(0, 316);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(626, 22);
            this.statusStrip1.SizingGrip = false;
            this.statusStrip1.TabIndex = 7;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // stLb_Durum
            // 
            this.stLb_Durum.Name = "stLb_Durum";
            this.stLb_Durum.Size = new System.Drawing.Size(16, 17);
            this.stLb_Durum.Text = "...";
            // 
            // Form_Anasayfa
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(626, 338);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.btn_DersIsl);
            this.Controls.Add(this.btn_SinifIsl);
            this.Controls.Add(this.btn_OdemeIsl);
            this.Controls.Add(this.btn_PersonelIsl);
            this.Controls.Add(this.btn_VeliIsl);
            this.Controls.Add(this.btn_OgrenciIsl);
            this.Controls.Add(this.menuStrip1);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "Form_Anasayfa";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Anasayfa";
            this.Load += new System.EventHandler(this.Form_Anasayfa_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem programToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem yenidenBaşlatToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kapatToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem veritabanıToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kontrolToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem hakkındaToolStripMenuItem;
        private System.Windows.Forms.Button btn_OgrenciIsl;
        private System.Windows.Forms.Button btn_VeliIsl;
        private System.Windows.Forms.Button btn_PersonelIsl;
        private System.Windows.Forms.Button btn_OdemeIsl;
        private System.Windows.Forms.Button btn_SinifIsl;
        private System.Windows.Forms.Button btn_DersIsl;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel stLb_Durum;
    }
}