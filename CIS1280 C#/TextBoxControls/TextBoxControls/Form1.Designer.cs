namespace TextBoxControls
{
    partial class Form1
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
            this.lblName = new System.Windows.Forms.Label();
            this.lblAddress = new System.Windows.Forms.Label();
            this.lblOccupation = new System.Windows.Forms.Label();
            this.lblAge = new System.Windows.Forms.Label();
            this.lblOutput = new System.Windows.Forms.Label();
            this.txbName = new System.Windows.Forms.TextBox();
            this.txbAddress = new System.Windows.Forms.TextBox();
            this.txbOccupation = new System.Windows.Forms.TextBox();
            this.txbAge = new System.Windows.Forms.TextBox();
            this.txbOutput = new System.Windows.Forms.TextBox();
            this.btnOk = new System.Windows.Forms.Button();
            this.btnHelp = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(13, 14);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(57, 13);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "labelName";
            // 
            // lblAddress
            // 
            this.lblAddress.AutoSize = true;
            this.lblAddress.Location = new System.Drawing.Point(13, 56);
            this.lblAddress.Name = "lblAddress";
            this.lblAddress.Size = new System.Drawing.Size(67, 13);
            this.lblAddress.TabIndex = 1;
            this.lblAddress.Text = "labelAddress";
            // 
            // lblOccupation
            // 
            this.lblOccupation.AutoSize = true;
            this.lblOccupation.Location = new System.Drawing.Point(13, 168);
            this.lblOccupation.Name = "lblOccupation";
            this.lblOccupation.Size = new System.Drawing.Size(84, 13);
            this.lblOccupation.TabIndex = 2;
            this.lblOccupation.Text = "labelOccupation";
            // 
            // lblAge
            // 
            this.lblAge.AutoSize = true;
            this.lblAge.Location = new System.Drawing.Point(13, 210);
            this.lblAge.Name = "lblAge";
            this.lblAge.Size = new System.Drawing.Size(48, 13);
            this.lblAge.TabIndex = 3;
            this.lblAge.Text = "labelAge";
            // 
            // lblOutput
            // 
            this.lblOutput.AutoSize = true;
            this.lblOutput.Location = new System.Drawing.Point(12, 250);
            this.lblOutput.Name = "lblOutput";
            this.lblOutput.Size = new System.Drawing.Size(61, 13);
            this.lblOutput.TabIndex = 4;
            this.lblOutput.Text = "labelOutput";
            // 
            // txbName
            // 
            this.txbName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbName.Location = new System.Drawing.Point(108, 14);
            this.txbName.Name = "txbName";
            this.txbName.Size = new System.Drawing.Size(260, 20);
            this.txbName.TabIndex = 5;
            this.txbName.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxEmpty);
            // 
            // txbAddress
            // 
            this.txbAddress.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbAddress.Location = new System.Drawing.Point(108, 56);
            this.txbAddress.Multiline = true;
            this.txbAddress.Name = "txbAddress";
            this.txbAddress.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbAddress.Size = new System.Drawing.Size(260, 90);
            this.txbAddress.TabIndex = 6;
            this.txbAddress.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxEmpty);
            // 
            // txbOccupation
            // 
            this.txbOccupation.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbOccupation.Location = new System.Drawing.Point(108, 168);
            this.txbOccupation.Name = "txbOccupation";
            this.txbOccupation.Size = new System.Drawing.Size(260, 20);
            this.txbOccupation.TabIndex = 7;
            this.txbOccupation.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxOccupation);
            // 
            // txbAge
            // 
            this.txbAge.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbAge.Location = new System.Drawing.Point(108, 210);
            this.txbAge.MaxLength = 3;
            this.txbAge.Name = "txbAge";
            this.txbAge.Size = new System.Drawing.Size(260, 20);
            this.txbAge.TabIndex = 8;
            this.txbAge.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbAge_KeyPress);
            this.txbAge.Validating += new System.ComponentModel.CancelEventHandler(this.textBoxEmpty);
            // 
            // txbOutput
            // 
            this.txbOutput.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbOutput.Location = new System.Drawing.Point(16, 280);
            this.txbOutput.Multiline = true;
            this.txbOutput.Name = "txbOutput";
            this.txbOutput.ReadOnly = true;
            this.txbOutput.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbOutput.Size = new System.Drawing.Size(358, 153);
            this.txbOutput.TabIndex = 9;
            // 
            // btnOk
            // 
            this.btnOk.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOk.Location = new System.Drawing.Point(433, 14);
            this.btnOk.Name = "btnOk";
            this.btnOk.Size = new System.Drawing.Size(75, 23);
            this.btnOk.TabIndex = 10;
            this.btnOk.Text = "buttonOk";
            this.btnOk.UseVisualStyleBackColor = true;
            this.btnOk.Click += new System.EventHandler(this.btnOk_Click);
            // 
            // btnHelp
            // 
            this.btnHelp.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnHelp.CausesValidation = false;
            this.btnHelp.Location = new System.Drawing.Point(433, 56);
            this.btnHelp.Name = "btnHelp";
            this.btnHelp.Size = new System.Drawing.Size(75, 23);
            this.btnHelp.TabIndex = 11;
            this.btnHelp.Text = "buttonHelp";
            this.btnHelp.UseVisualStyleBackColor = true;
            this.btnHelp.Click += new System.EventHandler(this.btnHelp_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(534, 462);
            this.Controls.Add(this.btnHelp);
            this.Controls.Add(this.btnOk);
            this.Controls.Add(this.txbOutput);
            this.Controls.Add(this.txbAge);
            this.Controls.Add(this.txbOccupation);
            this.Controls.Add(this.txbAddress);
            this.Controls.Add(this.txbName);
            this.Controls.Add(this.lblOutput);
            this.Controls.Add(this.lblAge);
            this.Controls.Add(this.lblOccupation);
            this.Controls.Add(this.lblAddress);
            this.Controls.Add(this.lblName);
            this.MinimumSize = new System.Drawing.Size(550, 500);
            this.Name = "Form1";
            this.Text = "Text Box controls";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblAddress;
        private System.Windows.Forms.Label lblOccupation;
        private System.Windows.Forms.Label lblAge;
        private System.Windows.Forms.Label lblOutput;
        private System.Windows.Forms.TextBox txbName;
        private System.Windows.Forms.TextBox txbAddress;
        private System.Windows.Forms.TextBox txbOccupation;
        private System.Windows.Forms.TextBox txbAge;
        private System.Windows.Forms.TextBox txbOutput;
        private System.Windows.Forms.Button btnOk;
        private System.Windows.Forms.Button btnHelp;
    }
}

