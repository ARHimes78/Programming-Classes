namespace HimesE6
{
    partial class PresentationGUI
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
            this.gbxType = new System.Windows.Forms.GroupBox();
            this.rbSingle = new System.Windows.Forms.RadioButton();
            this.rbMulti = new System.Windows.Forms.RadioButton();
            this.lblTitle = new System.Windows.Forms.Label();
            this.gbxInfo = new System.Windows.Forms.GroupBox();
            this.txbInfo = new System.Windows.Forms.TextBox();
            this.gbxType.SuspendLayout();
            this.gbxInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // gbxType
            // 
            this.gbxType.Controls.Add(this.rbSingle);
            this.gbxType.Controls.Add(this.rbMulti);
            this.gbxType.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbxType.ForeColor = System.Drawing.Color.Blue;
            this.gbxType.Location = new System.Drawing.Point(33, 161);
            this.gbxType.Name = "gbxType";
            this.gbxType.Size = new System.Drawing.Size(200, 141);
            this.gbxType.TabIndex = 0;
            this.gbxType.TabStop = false;
            this.gbxType.Text = "Select a housing type:";
            // 
            // rbSingle
            // 
            this.rbSingle.AutoSize = true;
            this.rbSingle.Location = new System.Drawing.Point(16, 83);
            this.rbSingle.Name = "rbSingle";
            this.rbSingle.Size = new System.Drawing.Size(115, 20);
            this.rbSingle.TabIndex = 1;
            this.rbSingle.Text = "Single family";
            this.rbSingle.UseVisualStyleBackColor = true;
            this.rbSingle.CheckedChanged += new System.EventHandler(this.rbSingle_CheckedChanged);
            // 
            // rbMulti
            // 
            this.rbMulti.AutoSize = true;
            this.rbMulti.Checked = true;
            this.rbMulti.Location = new System.Drawing.Point(16, 38);
            this.rbMulti.Name = "rbMulti";
            this.rbMulti.Size = new System.Drawing.Size(87, 20);
            this.rbMulti.TabIndex = 0;
            this.rbMulti.TabStop = true;
            this.rbMulti.Text = "Multi-unit";
            this.rbMulti.UseVisualStyleBackColor = true;
            this.rbMulti.CheckedChanged += new System.EventHandler(this.rbMulti_CheckedChanged);
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.ForeColor = System.Drawing.Color.Blue;
            this.lblTitle.Location = new System.Drawing.Point(181, 25);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(222, 25);
            this.lblTitle.TabIndex = 1;
            this.lblTitle.Text = "Housing Information";
            // 
            // gbxInfo
            // 
            this.gbxInfo.BackColor = System.Drawing.SystemColors.ControlDark;
            this.gbxInfo.Controls.Add(this.txbInfo);
            this.gbxInfo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbxInfo.ForeColor = System.Drawing.Color.Blue;
            this.gbxInfo.Location = new System.Drawing.Point(266, 111);
            this.gbxInfo.Name = "gbxInfo";
            this.gbxInfo.Size = new System.Drawing.Size(286, 241);
            this.gbxInfo.TabIndex = 2;
            this.gbxInfo.TabStop = false;
            this.gbxInfo.Text = "Multi-unit";
            // 
            // txbInfo
            // 
            this.txbInfo.Location = new System.Drawing.Point(13, 24);
            this.txbInfo.Multiline = true;
            this.txbInfo.Name = "txbInfo";
            this.txbInfo.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbInfo.Size = new System.Drawing.Size(260, 199);
            this.txbInfo.TabIndex = 0;
            // 
            // PresentationGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 462);
            this.Controls.Add(this.gbxInfo);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.gbxType);
            this.Name = "PresentationGUI";
            this.Text = "Alan Himes - E6, Property Manager";
            this.gbxType.ResumeLayout(false);
            this.gbxType.PerformLayout();
            this.gbxInfo.ResumeLayout(false);
            this.gbxInfo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox gbxType;
        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox gbxInfo;
        private System.Windows.Forms.TextBox txbInfo;
        private System.Windows.Forms.RadioButton rbSingle;
        private System.Windows.Forms.RadioButton rbMulti;
    }
}

