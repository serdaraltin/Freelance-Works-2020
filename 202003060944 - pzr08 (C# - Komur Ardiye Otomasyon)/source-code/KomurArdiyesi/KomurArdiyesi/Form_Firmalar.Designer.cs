namespace KomurArdiyesi
{
    partial class Form_Firmalar
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
            this.dg_Firmalar = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dg_Firmalar)).BeginInit();
            this.SuspendLayout();
            // 
            // dg_Firmalar
            // 
            this.dg_Firmalar.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dg_Firmalar.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dg_Firmalar.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dg_Firmalar.Location = new System.Drawing.Point(0, 0);
            this.dg_Firmalar.Name = "dg_Firmalar";
            this.dg_Firmalar.ReadOnly = true;
            this.dg_Firmalar.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dg_Firmalar.Size = new System.Drawing.Size(517, 274);
            this.dg_Firmalar.TabIndex = 1;
            this.dg_Firmalar.RowEnter += new System.Windows.Forms.DataGridViewCellEventHandler(this.dg_Firmalar_RowEnter);
            this.dg_Firmalar.DoubleClick += new System.EventHandler(this.dg_Firmalar_DoubleClick);
            // 
            // Form_Firmalar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(517, 274);
            this.Controls.Add(this.dg_Firmalar);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.SizableToolWindow;
            this.Name = "Form_Firmalar";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Firmalar";
            this.Load += new System.EventHandler(this.Form_Firmalar_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dg_Firmalar)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dg_Firmalar;
    }
}