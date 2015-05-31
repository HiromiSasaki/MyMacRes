namespace LogisticMapForm
{
    partial class logisticMapForm
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.resetButton = new System.Windows.Forms.Button();
            this.glControl = new OpenTK.GLControl();
            this.returnMapGlControl = new OpenTK.GLControl();
            this.paramTrackBar = new System.Windows.Forms.TrackBar();
            this.paramALabel = new System.Windows.Forms.Label();
            this.periodLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.paramTrackBar)).BeginInit();
            this.SuspendLayout();
            // 
            // resetButton
            // 
            this.resetButton.Location = new System.Drawing.Point(895, 419);
            this.resetButton.Name = "resetButton";
            this.resetButton.Size = new System.Drawing.Size(174, 23);
            this.resetButton.TabIndex = 0;
            this.resetButton.Text = "Cut Transient";
            this.resetButton.UseVisualStyleBackColor = true;
            this.resetButton.Click += new System.EventHandler(this.resetButton_Click);
            // 
            // glControl
            // 
            this.glControl.BackColor = System.Drawing.Color.Black;
            this.glControl.Location = new System.Drawing.Point(18, 12);
            this.glControl.Name = "glControl";
            this.glControl.Size = new System.Drawing.Size(700, 300);
            this.glControl.TabIndex = 1;
            this.glControl.VSync = false;
            // 
            // returnMapGlControl
            // 
            this.returnMapGlControl.BackColor = System.Drawing.Color.Black;
            this.returnMapGlControl.Location = new System.Drawing.Point(769, 12);
            this.returnMapGlControl.Name = "returnMapGlControl";
            this.returnMapGlControl.Size = new System.Drawing.Size(300, 300);
            this.returnMapGlControl.TabIndex = 1;
            this.returnMapGlControl.VSync = false;
            // 
            // paramTrackBar
            // 
            this.paramTrackBar.Location = new System.Drawing.Point(12, 368);
            this.paramTrackBar.Maximum = 4000;
            this.paramTrackBar.Name = "paramTrackBar";
            this.paramTrackBar.Size = new System.Drawing.Size(1057, 45);
            this.paramTrackBar.TabIndex = 2;
            this.paramTrackBar.ValueChanged += new System.EventHandler(this.paramTrackBar_ValueChanged);
            // 
            // paramALabel
            // 
            this.paramALabel.AutoSize = true;
            this.paramALabel.Font = new System.Drawing.Font("MS UI Gothic", 24F);
            this.paramALabel.Location = new System.Drawing.Point(12, 332);
            this.paramALabel.Name = "paramALabel";
            this.paramALabel.Size = new System.Drawing.Size(82, 33);
            this.paramALabel.TabIndex = 3;
            this.paramALabel.Text = "a = 0";
            // 
            // periodLabel
            // 
            this.periodLabel.AutoSize = true;
            this.periodLabel.Font = new System.Drawing.Font("MS UI Gothic", 24F);
            this.periodLabel.Location = new System.Drawing.Point(809, 332);
            this.periodLabel.Name = "periodLabel";
            this.periodLabel.Size = new System.Drawing.Size(153, 33);
            this.periodLabel.TabIndex = 4;
            this.periodLabel.Text = "Period = 1";
            // 
            // logisticMapForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1082, 451);
            this.Controls.Add(this.periodLabel);
            this.Controls.Add(this.paramALabel);
            this.Controls.Add(this.paramTrackBar);
            this.Controls.Add(this.resetButton);
            this.Controls.Add(this.glControl);
            this.Controls.Add(this.returnMapGlControl);
            this.Name = "logisticMapForm";
            this.Text = "LogisticMapForm";
            ((System.ComponentModel.ISupportInitialize)(this.paramTrackBar)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button resetButton;
        private OpenTK.GLControl glControl;
        private OpenTK.GLControl returnMapGlControl;
        private System.Windows.Forms.TrackBar paramTrackBar;
        private System.Windows.Forms.Label paramALabel;
        private System.Windows.Forms.Label periodLabel;
    }
}

