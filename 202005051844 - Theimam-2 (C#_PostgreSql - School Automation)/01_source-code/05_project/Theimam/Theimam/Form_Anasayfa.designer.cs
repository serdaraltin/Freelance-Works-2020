namespace Theimam
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
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
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
            this.menuStrip1.Size = new System.Drawing.Size(1011, 24);
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
            this.btn_OdemeIsl.Text = "YÖNETİM İŞLEMLERİ";
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
            this.statusStrip1.Location = new System.Drawing.Point(0, 435);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1011, 22);
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
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.Indigo;
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button1.ForeColor = System.Drawing.Color.Yellow;
            this.button1.Location = new System.Drawing.Point(803, 303);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(189, 125);
            this.button1.TabIndex = 13;
            this.button1.Text = "AİLE BİRLİĞİ\r\nİŞLEMLERİ";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.Indigo;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button2.ForeColor = System.Drawing.Color.Yellow;
            this.button2.Location = new System.Drawing.Point(803, 172);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(189, 125);
            this.button2.TabIndex = 12;
            this.button2.Text = "BÖLÜM\r\nİŞLEMLERİ";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.Color.Indigo;
            this.button3.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button3.ForeColor = System.Drawing.Color.Yellow;
            this.button3.Location = new System.Drawing.Point(803, 41);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(189, 125);
            this.button3.TabIndex = 11;
            this.button3.Text = "YÖNETİM ALAN İŞLEMLERİ";
            this.button3.UseVisualStyleBackColor = false;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.BackColor = System.Drawing.Color.Indigo;
            this.button4.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button4.ForeColor = System.Drawing.Color.Yellow;
            this.button4.Location = new System.Drawing.Point(413, 303);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(189, 125);
            this.button4.TabIndex = 10;
            this.button4.Text = "PERSONEL ALAN İŞLEMLERİ";
            this.button4.UseVisualStyleBackColor = false;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.BackColor = System.Drawing.Color.Indigo;
            this.button5.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button5.ForeColor = System.Drawing.Color.Yellow;
            this.button5.Location = new System.Drawing.Point(218, 303);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(189, 125);
            this.button5.TabIndex = 9;
            this.button5.Text = "EĞİTMEN ALAN \r\nİŞLEMLERİ";
            this.button5.UseVisualStyleBackColor = false;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.Indigo;
            this.button6.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button6.ForeColor = System.Drawing.Color.Yellow;
            this.button6.Location = new System.Drawing.Point(23, 303);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(189, 125);
            this.button6.TabIndex = 8;
            this.button6.Text = "ÖĞRETMEN İŞLEMLERİ";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // button8
            // 
            this.button8.BackColor = System.Drawing.Color.Indigo;
            this.button8.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button8.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button8.ForeColor = System.Drawing.Color.Yellow;
            this.button8.Location = new System.Drawing.Point(608, 303);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(189, 125);
            this.button8.TabIndex = 16;
            this.button8.Text = "NÖBET ALAN İŞLEMLERİ";
            this.button8.UseVisualStyleBackColor = false;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.Color.Indigo;
            this.button9.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button9.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button9.ForeColor = System.Drawing.Color.Yellow;
            this.button9.Location = new System.Drawing.Point(608, 172);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(189, 125);
            this.button9.TabIndex = 15;
            this.button9.Text = "KULLANICI\r\nİŞLEMLERİ";
            this.button9.UseVisualStyleBackColor = false;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button10
            // 
            this.button10.BackColor = System.Drawing.Color.Indigo;
            this.button10.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button10.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.button10.ForeColor = System.Drawing.Color.Yellow;
            this.button10.Location = new System.Drawing.Point(608, 41);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(189, 125);
            this.button10.TabIndex = 14;
            this.button10.Text = "GİRİŞ \r\nİŞLEMLERİ";
            this.button10.UseVisualStyleBackColor = false;
            this.button10.Click += new System.EventHandler(this.button10_Click);
            // 
            // Form_Anasayfa
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(1011, 457);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.button9);
            this.Controls.Add(this.button10);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
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
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
    }
}