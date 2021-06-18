namespace kutuphane
{
    partial class frmKitapSilListele
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
            this.dGridKitapListeleSil = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dGridKitapListeleSil)).BeginInit();
            this.SuspendLayout();
            // 
            // dGridKitapListeleSil
            // 
            this.dGridKitapListeleSil.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dGridKitapListeleSil.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGridKitapListeleSil.Location = new System.Drawing.Point(12, 44);
            this.dGridKitapListeleSil.Name = "dGridKitapListeleSil";
            this.dGridKitapListeleSil.RowTemplate.Height = 24;
            this.dGridKitapListeleSil.Size = new System.Drawing.Size(1060, 480);
            this.dGridKitapListeleSil.TabIndex = 0;
            this.dGridKitapListeleSil.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dGridKitapListeleSil_CellMouseDoubleClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial Narrow", 9F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.Location = new System.Drawing.Point(797, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(242, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Kitap Silmek İçin Kitap Üzerine Çift Tıklayın";
            // 
            // frmKitapSilListele
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1084, 536);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dGridKitapListeleSil);
            this.Name = "frmKitapSilListele";
            this.Text = "Kitap Sil Listele";
            this.Load += new System.EventHandler(this.frmKitapSilListele_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dGridKitapListeleSil)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dGridKitapListeleSil;
        private System.Windows.Forms.Label label1;
    }
}