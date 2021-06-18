namespace kutuphane
{
    partial class frmOgrenciSilListele
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
            this.dGridMusteler = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dGridMusteler)).BeginInit();
            this.SuspendLayout();
            // 
            // dGridMusteler
            // 
            this.dGridMusteler.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dGridMusteler.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dGridMusteler.Location = new System.Drawing.Point(3, 37);
            this.dGridMusteler.Name = "dGridMusteler";
            this.dGridMusteler.RowTemplate.Height = 24;
            this.dGridMusteler.Size = new System.Drawing.Size(785, 401);
            this.dGridMusteler.TabIndex = 0;
            this.dGridMusteler.CellMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dGridMusteler_CellMouseDoubleClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(516, 17);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(272, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Silmek istediğiniz veri üzerine çift tıklayınız";
            // 
            // frmOgrenciSilListele
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dGridMusteler);
            this.Name = "frmOgrenciSilListele";
            this.Text = "Öğrenci Sil";
            this.Load += new System.EventHandler(this.frmMusteriSilListele_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dGridMusteler)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dGridMusteler;
        private System.Windows.Forms.Label label1;
    }
}