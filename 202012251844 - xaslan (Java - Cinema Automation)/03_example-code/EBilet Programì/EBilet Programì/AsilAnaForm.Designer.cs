namespace EBilet_Programı
{
    partial class AsilAnaForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(AsilAnaForm));
            this.btnGeriDon = new System.Windows.Forms.Button();
            this.ImgSimgeler = new System.Windows.Forms.ImageList(this.components);
            this.gridListe = new System.Windows.Forms.DataGridView();
            this.kisiIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ısimDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.soyIsimDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.secilenFilmDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.secilenKoltukDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.biletiAldigiGunDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.biletiAldigiSaatDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.filmSeansSaatiDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.SecilenTarife = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.fiyatDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dgvSagClick = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.kayitDuzelt = new System.Windows.Forms.ToolStripMenuItem();
            this.kayitSil = new System.Windows.Forms.ToolStripMenuItem();
            this.bsGenelTablo = new System.Windows.Forms.BindingSource(this.components);
            this.eBiletProgramiDataSet = new EBilet_Programı.EBiletProgramiDataSet();
            this.eBiletTablosuTableAdapter1 = new EBilet_Programı.EBiletProgramiDataSetTableAdapters.EBiletTablosuTableAdapter();
            this.label3 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label4 = new System.Windows.Forms.Label();
            this.AsilAnaFormIsimKaydirma = new System.Windows.Forms.Timer(this.components);
            this.btnBiletSatinAl = new System.Windows.Forms.Button();
            this.txtSoyismeGoreAra = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtIsmeGoreAra = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.gridListe)).BeginInit();
            this.dgvSagClick.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bsGenelTablo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.eBiletProgramiDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnGeriDon
            // 
            this.btnGeriDon.BackColor = System.Drawing.Color.Transparent;
            this.btnGeriDon.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnGeriDon.ImageKey = "delete2.ico";
            this.btnGeriDon.ImageList = this.ImgSimgeler;
            this.btnGeriDon.Location = new System.Drawing.Point(1117, 2);
            this.btnGeriDon.Name = "btnGeriDon";
            this.btnGeriDon.Size = new System.Drawing.Size(42, 38);
            this.btnGeriDon.TabIndex = 0;
            this.btnGeriDon.UseVisualStyleBackColor = false;
            this.btnGeriDon.Click += new System.EventHandler(this.btnGeriDon_Click);
            // 
            // ImgSimgeler
            // 
            this.ImgSimgeler.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("ImgSimgeler.ImageStream")));
            this.ImgSimgeler.TransparentColor = System.Drawing.Color.Transparent;
            this.ImgSimgeler.Images.SetKeyName(0, "Comic Icons 3 floppy.png");
            this.ImgSimgeler.Images.SetKeyName(1, "Comic Icons 3 private.png");
            this.ImgSimgeler.Images.SetKeyName(2, "Comic_Tiger_2 folder_tiger.png");
            this.ImgSimgeler.Images.SetKeyName(3, "table_sql_view.ico");
            this.ImgSimgeler.Images.SetKeyName(4, "arrow_left_green.ico");
            this.ImgSimgeler.Images.SetKeyName(5, "delete2.ico");
            this.ImgSimgeler.Images.SetKeyName(6, "movies.ico");
            this.ImgSimgeler.Images.SetKeyName(7, "disk_blue_error.ico");
            this.ImgSimgeler.Images.SetKeyName(8, "YazarKasa.png");
            // 
            // gridListe
            // 
            this.gridListe.AllowUserToAddRows = false;
            this.gridListe.AllowUserToDeleteRows = false;
            this.gridListe.AutoGenerateColumns = false;
            this.gridListe.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.gridListe.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            this.gridListe.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.kisiIDDataGridViewTextBoxColumn,
            this.ısimDataGridViewTextBoxColumn,
            this.soyIsimDataGridViewTextBoxColumn,
            this.secilenFilmDataGridViewTextBoxColumn,
            this.secilenKoltukDataGridViewTextBoxColumn,
            this.biletiAldigiGunDataGridViewTextBoxColumn,
            this.biletiAldigiSaatDataGridViewTextBoxColumn,
            this.filmSeansSaatiDataGridViewTextBoxColumn,
            this.SecilenTarife,
            this.fiyatDataGridViewTextBoxColumn});
            this.gridListe.ContextMenuStrip = this.dgvSagClick;
            this.gridListe.DataSource = this.bsGenelTablo;
            this.gridListe.Location = new System.Drawing.Point(12, 100);
            this.gridListe.MultiSelect = false;
            this.gridListe.Name = "gridListe";
            this.gridListe.ReadOnly = true;
            this.gridListe.RowHeadersVisible = false;
            this.gridListe.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gridListe.Size = new System.Drawing.Size(881, 209);
            this.gridListe.StandardTab = true;
            this.gridListe.TabIndex = 6;
            // 
            // kisiIDDataGridViewTextBoxColumn
            // 
            this.kisiIDDataGridViewTextBoxColumn.DataPropertyName = "KisiID";
            this.kisiIDDataGridViewTextBoxColumn.HeaderText = "KisiID";
            this.kisiIDDataGridViewTextBoxColumn.Name = "kisiIDDataGridViewTextBoxColumn";
            this.kisiIDDataGridViewTextBoxColumn.ReadOnly = true;
            this.kisiIDDataGridViewTextBoxColumn.Width = 55;
            // 
            // ısimDataGridViewTextBoxColumn
            // 
            this.ısimDataGridViewTextBoxColumn.DataPropertyName = "Isim";
            this.ısimDataGridViewTextBoxColumn.HeaderText = "Isim";
            this.ısimDataGridViewTextBoxColumn.Name = "ısimDataGridViewTextBoxColumn";
            this.ısimDataGridViewTextBoxColumn.ReadOnly = true;
            this.ısimDataGridViewTextBoxColumn.Width = 96;
            // 
            // soyIsimDataGridViewTextBoxColumn
            // 
            this.soyIsimDataGridViewTextBoxColumn.DataPropertyName = "SoyIsim";
            this.soyIsimDataGridViewTextBoxColumn.HeaderText = "SoyIsim";
            this.soyIsimDataGridViewTextBoxColumn.Name = "soyIsimDataGridViewTextBoxColumn";
            this.soyIsimDataGridViewTextBoxColumn.ReadOnly = true;
            this.soyIsimDataGridViewTextBoxColumn.Width = 97;
            // 
            // secilenFilmDataGridViewTextBoxColumn
            // 
            this.secilenFilmDataGridViewTextBoxColumn.DataPropertyName = "SecilenFilm";
            this.secilenFilmDataGridViewTextBoxColumn.HeaderText = "SecilenFilm";
            this.secilenFilmDataGridViewTextBoxColumn.Name = "secilenFilmDataGridViewTextBoxColumn";
            this.secilenFilmDataGridViewTextBoxColumn.ReadOnly = true;
            this.secilenFilmDataGridViewTextBoxColumn.Width = 125;
            // 
            // secilenKoltukDataGridViewTextBoxColumn
            // 
            this.secilenKoltukDataGridViewTextBoxColumn.DataPropertyName = "SecilenKoltuk";
            this.secilenKoltukDataGridViewTextBoxColumn.HeaderText = "SecilenKoltuk";
            this.secilenKoltukDataGridViewTextBoxColumn.Name = "secilenKoltukDataGridViewTextBoxColumn";
            this.secilenKoltukDataGridViewTextBoxColumn.ReadOnly = true;
            this.secilenKoltukDataGridViewTextBoxColumn.Width = 97;
            // 
            // biletiAldigiGunDataGridViewTextBoxColumn
            // 
            this.biletiAldigiGunDataGridViewTextBoxColumn.DataPropertyName = "BiletiAldigiGun";
            this.biletiAldigiGunDataGridViewTextBoxColumn.HeaderText = "BiletiAldigiGun";
            this.biletiAldigiGunDataGridViewTextBoxColumn.Name = "biletiAldigiGunDataGridViewTextBoxColumn";
            this.biletiAldigiGunDataGridViewTextBoxColumn.ReadOnly = true;
            this.biletiAldigiGunDataGridViewTextBoxColumn.Width = 84;
            // 
            // biletiAldigiSaatDataGridViewTextBoxColumn
            // 
            this.biletiAldigiSaatDataGridViewTextBoxColumn.DataPropertyName = "BiletiAldigiSaat";
            this.biletiAldigiSaatDataGridViewTextBoxColumn.HeaderText = "BiletiAldigiSaat";
            this.biletiAldigiSaatDataGridViewTextBoxColumn.Name = "biletiAldigiSaatDataGridViewTextBoxColumn";
            this.biletiAldigiSaatDataGridViewTextBoxColumn.ReadOnly = true;
            this.biletiAldigiSaatDataGridViewTextBoxColumn.Width = 97;
            // 
            // filmSeansSaatiDataGridViewTextBoxColumn
            // 
            this.filmSeansSaatiDataGridViewTextBoxColumn.DataPropertyName = "FilmSeansSaati";
            this.filmSeansSaatiDataGridViewTextBoxColumn.HeaderText = "FilmSeansSaati";
            this.filmSeansSaatiDataGridViewTextBoxColumn.Name = "filmSeansSaatiDataGridViewTextBoxColumn";
            this.filmSeansSaatiDataGridViewTextBoxColumn.ReadOnly = true;
            this.filmSeansSaatiDataGridViewTextBoxColumn.Width = 89;
            // 
            // SecilenTarife
            // 
            this.SecilenTarife.DataPropertyName = "SecilenTarife";
            this.SecilenTarife.HeaderText = "SecilenTarife";
            this.SecilenTarife.Name = "SecilenTarife";
            this.SecilenTarife.ReadOnly = true;
            this.SecilenTarife.Width = 78;
            // 
            // fiyatDataGridViewTextBoxColumn
            // 
            this.fiyatDataGridViewTextBoxColumn.DataPropertyName = "Fiyat";
            this.fiyatDataGridViewTextBoxColumn.HeaderText = "Fiyat";
            this.fiyatDataGridViewTextBoxColumn.Name = "fiyatDataGridViewTextBoxColumn";
            this.fiyatDataGridViewTextBoxColumn.ReadOnly = true;
            this.fiyatDataGridViewTextBoxColumn.Width = 60;
            // 
            // dgvSagClick
            // 
            this.dgvSagClick.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kayitDuzelt,
            this.kayitSil});
            this.dgvSagClick.Name = "dgvSagClick";
            this.dgvSagClick.Size = new System.Drawing.Size(137, 48);
            this.dgvSagClick.Text = "Kayıt Düzelt";
            this.dgvSagClick.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.dgvSagClick_ItemClicked);
            // 
            // kayitDuzelt
            // 
            this.kayitDuzelt.Name = "kayitDuzelt";
            this.kayitDuzelt.Size = new System.Drawing.Size(136, 22);
            this.kayitDuzelt.Text = "Kayıt Düzelt";
            // 
            // kayitSil
            // 
            this.kayitSil.Name = "kayitSil";
            this.kayitSil.Size = new System.Drawing.Size(136, 22);
            this.kayitSil.Text = "Kayıt Sil";
            // 
            // bsGenelTablo
            // 
            this.bsGenelTablo.DataMember = "EBiletTablosu";
            this.bsGenelTablo.DataSource = this.eBiletProgramiDataSet;
            // 
            // eBiletProgramiDataSet
            // 
            this.eBiletProgramiDataSet.DataSetName = "EBiletProgramiDataSet";
            this.eBiletProgramiDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // eBiletTablosuTableAdapter1
            // 
            this.eBiletTablosuTableAdapter1.ClearBeforeFill = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Eras Medium ITC", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(136, 20);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(187, 43);
            this.label3.TabIndex = 7;
            this.label3.Text = "MY BİLET  ";
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Image = global::EBilet_Programı.Properties.Resources.hollywood_ticket;
            this.pictureBox1.Location = new System.Drawing.Point(-2, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(137, 92);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 8;
            this.pictureBox1.TabStop = false;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label4.Location = new System.Drawing.Point(141, 63);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(243, 31);
            this.label4.TabIndex = 9;
            this.label4.Text = "Bilet Kayıt İşlemleri";
            // 
            // AsilAnaFormIsimKaydirma
            // 
            this.AsilAnaFormIsimKaydirma.Interval = 125;
            this.AsilAnaFormIsimKaydirma.Tick += new System.EventHandler(this.AsilAnaFormIsimKaydirma_Tick);
            // 
            // btnBiletSatinAl
            // 
            this.btnBiletSatinAl.BackColor = System.Drawing.Color.Transparent;
            this.btnBiletSatinAl.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.btnBiletSatinAl.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnBiletSatinAl.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.btnBiletSatinAl.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnBiletSatinAl.ImageKey = "YazarKasa.png";
            this.btnBiletSatinAl.ImageList = this.ImgSimgeler;
            this.btnBiletSatinAl.Location = new System.Drawing.Point(1022, 232);
            this.btnBiletSatinAl.Name = "btnBiletSatinAl";
            this.btnBiletSatinAl.Size = new System.Drawing.Size(127, 53);
            this.btnBiletSatinAl.TabIndex = 12;
            this.btnBiletSatinAl.Text = "Bilet Satın Al";
            this.btnBiletSatinAl.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnBiletSatinAl.UseVisualStyleBackColor = false;
            this.btnBiletSatinAl.Click += new System.EventHandler(this.btnBiletSatinAl_Click);
            // 
            // txtSoyismeGoreAra
            // 
            this.txtSoyismeGoreAra.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtSoyismeGoreAra.Location = new System.Drawing.Point(141, 75);
            this.txtSoyismeGoreAra.Name = "txtSoyismeGoreAra";
            this.txtSoyismeGoreAra.Size = new System.Drawing.Size(100, 21);
            this.txtSoyismeGoreAra.TabIndex = 3;
            this.txtSoyismeGoreAra.TextChanged += new System.EventHandler(this.txtSoyismeGoreAra_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Location = new System.Drawing.Point(6, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(129, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "Soyisme Göre Arama :";
            // 
            // txtIsmeGoreAra
            // 
            this.txtIsmeGoreAra.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtIsmeGoreAra.Location = new System.Drawing.Point(141, 26);
            this.txtIsmeGoreAra.Name = "txtIsmeGoreAra";
            this.txtIsmeGoreAra.Size = new System.Drawing.Size(100, 21);
            this.txtIsmeGoreAra.TabIndex = 3;
            this.txtIsmeGoreAra.TextChanged += new System.EventHandler(this.txtIsmeGoreAra_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Location = new System.Drawing.Point(6, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(109, 15);
            this.label1.TabIndex = 2;
            this.label1.Text = "İsme Göre Arama :";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 50);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(239, 15);
            this.label5.TabIndex = 11;
            this.label5.Text = "----------------------------------------------------------";
            this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.Color.Transparent;
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.txtIsmeGoreAra);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.txtSoyismeGoreAra);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.groupBox1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.groupBox1.Location = new System.Drawing.Point(899, 100);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(250, 112);
            this.groupBox1.TabIndex = 10;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Arama İşlemleri";
            // 
            // AsilAnaForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::EBilet_Programı.Properties.Resources.arka_planlar1;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1161, 322);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.gridListe);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnGeriDon);
            this.Controls.Add(this.btnBiletSatinAl);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.Name = "AsilAnaForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AsilAnaForm";
            this.Load += new System.EventHandler(this.AsilAnaForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gridListe)).EndInit();
            this.dgvSagClick.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.bsGenelTablo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.eBiletProgramiDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnGeriDon;
        private System.Windows.Forms.BindingSource bsGenelTablo;
        private System.Windows.Forms.DataGridView gridListe;
        private EBiletProgramiDataSetTableAdapters.EBiletTablosuTableAdapter eBiletTablosuTableAdapter1;
        private EBiletProgramiDataSet eBiletProgramiDataSet;
        private System.Windows.Forms.ImageList ImgSimgeler;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Timer AsilAnaFormIsimKaydirma;
        public System.Windows.Forms.Button btnBiletSatinAl;
        private System.Windows.Forms.ContextMenuStrip dgvSagClick;
        private System.Windows.Forms.ToolStripMenuItem kayitDuzelt;
        private System.Windows.Forms.ToolStripMenuItem kayitSil;
        private System.Windows.Forms.TextBox txtSoyismeGoreAra;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtIsmeGoreAra;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.DataGridViewTextBoxColumn kisiIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ısimDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn soyIsimDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn secilenFilmDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn secilenKoltukDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn biletiAldigiGunDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn biletiAldigiSaatDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn filmSeansSaatiDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn SecilenTarife;
        private System.Windows.Forms.DataGridViewTextBoxColumn fiyatDataGridViewTextBoxColumn;
    }
}