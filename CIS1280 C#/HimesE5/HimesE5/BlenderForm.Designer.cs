namespace HimesE5
{
    partial class BlenderForm
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
            this.lblTitle = new System.Windows.Forms.Label();
            this.txbName = new System.Windows.Forms.TextBox();
            this.txbAddress = new System.Windows.Forms.TextBox();
            this.txbCity = new System.Windows.Forms.TextBox();
            this.txbState = new System.Windows.Forms.TextBox();
            this.txbZip = new System.Windows.Forms.TextBox();
            this.txbQty = new System.Windows.Forms.TextBox();
            this.btnOrder = new System.Windows.Forms.Button();
            this.txbSummary = new System.Windows.Forms.TextBox();
            this.lblPrice = new System.Windows.Forms.Label();
            this.lblName = new System.Windows.Forms.Label();
            this.lblAddress = new System.Windows.Forms.Label();
            this.lblCity = new System.Windows.Forms.Label();
            this.lblState = new System.Windows.Forms.Label();
            this.lblZip = new System.Windows.Forms.Label();
            this.lblQty = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Arial Narrow", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(185, 27);
            this.lblTitle.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(376, 31);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Magic Blender Company Order Sheet";
            // 
            // txbName
            // 
            this.txbName.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbName.BackColor = System.Drawing.Color.Red;
            this.txbName.Location = new System.Drawing.Point(160, 86);
            this.txbName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbName.Name = "txbName";
            this.txbName.Size = new System.Drawing.Size(459, 22);
            this.txbName.TabIndex = 1;
            this.txbName.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxEmpty);
            // 
            // txbAddress
            // 
            this.txbAddress.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbAddress.BackColor = System.Drawing.Color.Red;
            this.txbAddress.Location = new System.Drawing.Point(160, 139);
            this.txbAddress.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbAddress.Multiline = true;
            this.txbAddress.Name = "txbAddress";
            this.txbAddress.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbAddress.Size = new System.Drawing.Size(459, 85);
            this.txbAddress.TabIndex = 2;
            this.txbAddress.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxEmpty);
            // 
            // txbCity
            // 
            this.txbCity.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbCity.BackColor = System.Drawing.Color.Red;
            this.txbCity.Location = new System.Drawing.Point(160, 254);
            this.txbCity.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbCity.Name = "txbCity";
            this.txbCity.Size = new System.Drawing.Size(459, 22);
            this.txbCity.TabIndex = 3;
            this.txbCity.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxEmpty);
            // 
            // txbState
            // 
            this.txbState.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbState.BackColor = System.Drawing.Color.Red;
            this.txbState.Location = new System.Drawing.Point(160, 306);
            this.txbState.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbState.MaxLength = 2;
            this.txbState.Name = "txbState";
            this.txbState.Size = new System.Drawing.Size(459, 22);
            this.txbState.TabIndex = 4;
            this.txbState.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxState);
            // 
            // txbZip
            // 
            this.txbZip.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbZip.BackColor = System.Drawing.Color.Red;
            this.txbZip.Location = new System.Drawing.Point(160, 359);
            this.txbZip.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbZip.MaxLength = 5;
            this.txbZip.Name = "txbZip";
            this.txbZip.Size = new System.Drawing.Size(459, 22);
            this.txbZip.TabIndex = 5;
            this.txbZip.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxZip);
            // 
            // txbQty
            // 
            this.txbQty.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbQty.BackColor = System.Drawing.Color.Red;
            this.txbQty.Location = new System.Drawing.Point(160, 412);
            this.txbQty.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbQty.Name = "txbQty";
            this.txbQty.Size = new System.Drawing.Size(343, 22);
            this.txbQty.TabIndex = 6;
            this.txbQty.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbQty_KeyPress);
            this.txbQty.Validating += new System.ComponentModel.CancelEventHandler(this.TextBoxEmpty);
            // 
            // btnOrder
            // 
            this.btnOrder.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btnOrder.Location = new System.Drawing.Point(520, 465);
            this.btnOrder.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnOrder.Name = "btnOrder";
            this.btnOrder.Size = new System.Drawing.Size(100, 28);
            this.btnOrder.TabIndex = 7;
            this.btnOrder.Text = "Place order";
            this.btnOrder.UseVisualStyleBackColor = true;
            this.btnOrder.Click += new System.EventHandler(this.btnOrder_Click);
            // 
            // txbSummary
            // 
            this.txbSummary.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txbSummary.Location = new System.Drawing.Point(160, 522);
            this.txbSummary.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txbSummary.Multiline = true;
            this.txbSummary.Name = "txbSummary";
            this.txbSummary.ReadOnly = true;
            this.txbSummary.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbSummary.Size = new System.Drawing.Size(459, 253);
            this.txbSummary.TabIndex = 8;
            // 
            // lblPrice
            // 
            this.lblPrice.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.lblPrice.AutoSize = true;
            this.lblPrice.Location = new System.Drawing.Point(512, 421);
            this.lblPrice.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblPrice.Name = "lblPrice";
            this.lblPrice.Size = new System.Drawing.Size(105, 17);
            this.lblPrice.TabIndex = 9;
            this.lblPrice.Text = "@ $59.95 each";
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Location = new System.Drawing.Point(56, 95);
            this.lblName.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(49, 17);
            this.lblName.TabIndex = 10;
            this.lblName.Text = "Name:";
            // 
            // lblAddress
            // 
            this.lblAddress.AutoSize = true;
            this.lblAddress.Location = new System.Drawing.Point(56, 148);
            this.lblAddress.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblAddress.Name = "lblAddress";
            this.lblAddress.Size = new System.Drawing.Size(64, 17);
            this.lblAddress.TabIndex = 11;
            this.lblAddress.Text = "Address:";
            // 
            // lblCity
            // 
            this.lblCity.AutoSize = true;
            this.lblCity.Location = new System.Drawing.Point(56, 262);
            this.lblCity.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblCity.Name = "lblCity";
            this.lblCity.Size = new System.Drawing.Size(31, 17);
            this.lblCity.TabIndex = 12;
            this.lblCity.Text = "City";
            // 
            // lblState
            // 
            this.lblState.AutoSize = true;
            this.lblState.Location = new System.Drawing.Point(56, 315);
            this.lblState.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblState.Name = "lblState";
            this.lblState.Size = new System.Drawing.Size(45, 17);
            this.lblState.TabIndex = 13;
            this.lblState.Text = "State:";
            // 
            // lblZip
            // 
            this.lblZip.AutoSize = true;
            this.lblZip.Location = new System.Drawing.Point(56, 368);
            this.lblZip.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblZip.Name = "lblZip";
            this.lblZip.Size = new System.Drawing.Size(67, 17);
            this.lblZip.TabIndex = 14;
            this.lblZip.Text = "Zip code:";
            // 
            // lblQty
            // 
            this.lblQty.AutoSize = true;
            this.lblQty.Location = new System.Drawing.Point(56, 421);
            this.lblQty.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblQty.Name = "lblQty";
            this.lblQty.Size = new System.Drawing.Size(65, 17);
            this.lblQty.TabIndex = 15;
            this.lblQty.Text = "Quantity:";
            // 
            // BlenderForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(779, 815);
            this.Controls.Add(this.lblQty);
            this.Controls.Add(this.lblZip);
            this.Controls.Add(this.lblState);
            this.Controls.Add(this.lblCity);
            this.Controls.Add(this.lblAddress);
            this.Controls.Add(this.lblName);
            this.Controls.Add(this.lblPrice);
            this.Controls.Add(this.txbSummary);
            this.Controls.Add(this.btnOrder);
            this.Controls.Add(this.txbQty);
            this.Controls.Add(this.txbZip);
            this.Controls.Add(this.txbState);
            this.Controls.Add(this.txbCity);
            this.Controls.Add(this.txbAddress);
            this.Controls.Add(this.txbName);
            this.Controls.Add(this.lblTitle);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "BlenderForm";
            this.Text = "Alan Himes - E5 - Magic Blender";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.TextBox txbName;
        private System.Windows.Forms.TextBox txbAddress;
        private System.Windows.Forms.TextBox txbCity;
        private System.Windows.Forms.TextBox txbState;
        private System.Windows.Forms.TextBox txbZip;
        private System.Windows.Forms.TextBox txbQty;
        private System.Windows.Forms.Button btnOrder;
        private System.Windows.Forms.TextBox txbSummary;
        private System.Windows.Forms.Label lblPrice;
        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblAddress;
        private System.Windows.Forms.Label lblCity;
        private System.Windows.Forms.Label lblState;
        private System.Windows.Forms.Label lblZip;
        private System.Windows.Forms.Label lblQty;
    }
}

