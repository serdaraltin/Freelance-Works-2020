namespace MayinTarlasiVeArmstrong
{
    partial class Form_Onizleme
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
            this.pnTarla = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // pnTarla
            // 
            this.pnTarla.BackColor = System.Drawing.SystemColors.Info;
            this.pnTarla.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnTarla.Location = new System.Drawing.Point(3, 3);
            this.pnTarla.Name = "pnTarla";
            this.pnTarla.Size = new System.Drawing.Size(222, 223);
            this.pnTarla.TabIndex = 2;
            // 
            // Form_Onizleme
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(230, 229);
            this.Controls.Add(this.pnTarla);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form_Onizleme";
            this.Text = "Önizleme Ekranı";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form_Onizleme_FormClosing);
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.Panel pnTarla;
    }
}