namespace kutuphane
{
    partial class frmKiradakiKitaplar
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
            this.dgridKiradakiKitapListesi = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dgridKiradakiKitapListesi)).BeginInit();
            this.SuspendLayout();
            // 
            // dgridKiradakiKitapListesi
            // 
            this.dgridKiradakiKitapListesi.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dgridKiradakiKitapListesi.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgridKiradakiKitapListesi.Location = new System.Drawing.Point(1, 2);
            this.dgridKiradakiKitapListesi.Name = "dgridKiradakiKitapListesi";
            this.dgridKiradakiKitapListesi.RowTemplate.Height = 24;
            this.dgridKiradakiKitapListesi.Size = new System.Drawing.Size(1037, 535);
            this.dgridKiradakiKitapListesi.TabIndex = 0;
            this.dgridKiradakiKitapListesi.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dgridKiradakiKitapListesi_CellMouseDoubleClick);
            // 
            // frmKiradakiKitaplar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1044, 545);
            this.Controls.Add(this.dgridKiradakiKitapListesi);
            this.Name = "frmKiradakiKitaplar";
            this.Text = "frmKiradakiKitaplar";
            this.Load += new System.EventHandler(this.frmKiradakiKitaplar_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgridKiradakiKitapListesi)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dgridKiradakiKitapListesi;
    }
}