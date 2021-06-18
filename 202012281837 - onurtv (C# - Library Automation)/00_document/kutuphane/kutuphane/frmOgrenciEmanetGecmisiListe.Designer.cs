namespace kutuphane
{
    partial class frmOgrenciEmanetGecmisiListe
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
            this.dGridEmanetListesi = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dGridEmanetListesi)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(702, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(608, 17);
            this.label1.TabIndex = 5;
            this.label1.Text = "Emanet Alınan Kitabı Teslim Etmek ya da Detayları Görüntülemek İçin Kitap Üzerine" +
    " Çift Tıklayın";
            // 
            // dGridEmanetListesi
            // 
            this.dGridEmanetListesi.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dGridEmanetListesi.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGridEmanetListesi.Location = new System.Drawing.Point(8, 35);
            this.dGridEmanetListesi.Name = "dGridEmanetListesi";
            this.dGridEmanetListesi.RowTemplate.Height = 24;
            this.dGridEmanetListesi.Size = new System.Drawing.Size(1302, 401);
            this.dGridEmanetListesi.TabIndex = 4;
            this.dGridEmanetListesi.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dGridEmanetListesi_CellMouseDoubleClick);
            // 
            // frmOgrenciEmanetGecmisiListe
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1322, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dGridEmanetListesi);
            this.Name = "frmOgrenciEmanetGecmisiListe";
            this.Text = "Emanet Geçmişi ";
            this.Load += new System.EventHandler(this.frmOgrenciEmanetGecmisiListe_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dGridEmanetListesi)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dGridEmanetListesi;
    }
}