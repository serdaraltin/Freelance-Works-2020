namespace KomurArdiyesi
{
    partial class Form_Toptancilar
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
            this.dg_Toptancilar = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Toptancilar)).BeginInit();
            this.SuspendLayout();
            // 
            // dg_Toptancilar
            // 
            this.dg_Toptancilar.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Toptancilar.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Toptancilar.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Toptancilar.Location = new System.Drawing.Point(0, 0);
            this.dg_Toptancilar.Name = "dg_Toptancilar";
            this.dg_Toptancilar.ReadOnly = true;
            this.dg_Toptancilar.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Toptancilar.Size = new System.Drawing.Size(532, 271);
            this.dg_Toptancilar.TabIndex = 0;
            this.dg_Toptancilar.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Toptancilar_RowEnter);
            this.dg_Toptancilar.DoubleClick += new System.EventHandler(this.dg_Toptancilar_DoubleClick);
            // 
            // Form_Toptancilar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 271);
            this.Controls.Add(this.dg_Toptancilar);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Toptancilar";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Toptancılar";
            this.Load += new System.EventHandler(this.Form_Toptancilar_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dg_Toptancilar)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dg_Toptancilar;
    }
}