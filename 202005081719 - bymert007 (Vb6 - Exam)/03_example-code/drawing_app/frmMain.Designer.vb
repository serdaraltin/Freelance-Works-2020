<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.pbCanvas = New System.Windows.Forms.PictureBox()
        Me.pnlCanvas = New System.Windows.Forms.Panel()
        CType(Me.pbCanvas, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.pnlCanvas.SuspendLayout()
        Me.SuspendLayout()
        '
        'pbCanvas
        '
        Me.pbCanvas.Location = New System.Drawing.Point(0, 0)
        Me.pbCanvas.Name = "pbCanvas"
        Me.pbCanvas.Size = New System.Drawing.Size(100, 100)
        Me.pbCanvas.TabIndex = 1
        Me.pbCanvas.TabStop = False
        '
        'pnlCanvas
        '
        Me.pnlCanvas.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
            Or System.Windows.Forms.AnchorStyles.Left) _
            Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
        Me.pnlCanvas.AutoScroll = True
        Me.pnlCanvas.BackColor = System.Drawing.SystemColors.ControlDark
        Me.pnlCanvas.Controls.Add(Me.pbCanvas)
        Me.pnlCanvas.Location = New System.Drawing.Point(399, 0)
        Me.pnlCanvas.Name = "pnlCanvas"
        Me.pnlCanvas.Size = New System.Drawing.Size(793, 773)
        Me.pnlCanvas.TabIndex = 1
        '
        'frmMain
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1192, 773)
        Me.Controls.Add(Me.pnlCanvas)
        Me.Name = "frmMain"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "frmMain"
        CType(Me.pbCanvas, System.ComponentModel.ISupportInitialize).EndInit()
        Me.pnlCanvas.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents pbCanvas As System.Windows.Forms.PictureBox
    Friend WithEvents pnlCanvas As System.Windows.Forms.Panel

End Class
