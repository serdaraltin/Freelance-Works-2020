namespace kutuphane
{
    partial class frmKitapListesi
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
            this.dGridKitapListele = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dGridKitapListele)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial Narrow", 9F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.Location = new System.Drawing.Point(741, 4);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(331, 20);
            this.label1.TabIndex = 3;
            this.label1.Text = "Kitap Detayını Görüntülemek İçin Kitap Üzerine Çift Tıklayın";
            // 
            // dGridKitapListele
            // 
            this.dGridKitapListele.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dGridKitapListele.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGridKitapListele.Location = new System.Drawing.Point(12, 27);
            this.dGridKitapListele.Name = "dGridKitapListele";
            this.dGridKitapListele.RowTemplate.Height = 24;
            this.dGridKitapListele.Size = new System.Drawing.Size(1060, 480);
            this.dGridKitapListele.TabIndex = 2;
            this.dGridKitapListele.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dGridKitapListele_CellMouseDoubleClick);
            // 
            // frmKitapListesi
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1079, 505);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dGridKitapListele);
            this.Name = "frmKitapListesi";
            this.Text = "frmKitapListesi";
            this.Load += new System.EventHandler(this.frmKitapListesi_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dGridKitapListele)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dGridKitapListele;
    }
}