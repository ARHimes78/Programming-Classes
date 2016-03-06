namespace TaxApp
{
    partial class TaxForm
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
            this.lblAmount = new System.Windows.Forms.Label();
            this.lblPercentage = new System.Windows.Forms.Label();
            this.lblDue = new System.Windows.Forms.Label();
            this.lblTaxPercent = new System.Windows.Forms.Label();
            this.txtPurchase = new System.Windows.Forms.TextBox();
            this.txtTotalDue = new System.Windows.Forms.TextBox();
            this.btnCompute = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Bookman Old Style", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(67, 9);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(151, 22);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Tax Calculator";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // lblAmount
            // 
            this.lblAmount.AutoSize = true;
            this.lblAmount.Location = new System.Drawing.Point(12, 33);
            this.lblAmount.Name = "lblAmount";
            this.lblAmount.Size = new System.Drawing.Size(115, 20);
            this.lblAmount.TabIndex = 1;
            this.lblAmount.Text = "Total Amount";
            // 
            // lblPercentage
            // 
            this.lblPercentage.AutoSize = true;
            this.lblPercentage.Location = new System.Drawing.Point(12, 66);
            this.lblPercentage.Name = "lblPercentage";
            this.lblPercentage.Size = new System.Drawing.Size(128, 20);
            this.lblPercentage.TabIndex = 2;
            this.lblPercentage.Text = "Tax Percentage";
            // 
            // lblDue
            // 
            this.lblDue.AutoSize = true;
            this.lblDue.Location = new System.Drawing.Point(12, 98);
            this.lblDue.Name = "lblDue";
            this.lblDue.Size = new System.Drawing.Size(85, 20);
            this.lblDue.TabIndex = 3;
            this.lblDue.Text = "Total Due";
            // 
            // lblTaxPercent
            // 
            this.lblTaxPercent.AutoSize = true;
            this.lblTaxPercent.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(192)))));
            this.lblTaxPercent.Font = new System.Drawing.Font("Bookman Old Style", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTaxPercent.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.lblTaxPercent.Location = new System.Drawing.Point(172, 70);
            this.lblTaxPercent.Name = "lblTaxPercent";
            this.lblTaxPercent.Size = new System.Drawing.Size(50, 19);
            this.lblTaxPercent.TabIndex = 4;
            this.lblTaxPercent.Text = "7.5%";
            // 
            // txtPurchase
            // 
            this.txtPurchase.Location = new System.Drawing.Point(172, 34);
            this.txtPurchase.Name = "txtPurchase";
            this.txtPurchase.Size = new System.Drawing.Size(100, 26);
            this.txtPurchase.TabIndex = 5;
            this.txtPurchase.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // txtTotalDue
            // 
            this.txtTotalDue.Enabled = false;
            this.txtTotalDue.Location = new System.Drawing.Point(172, 99);
            this.txtTotalDue.Name = "txtTotalDue";
            this.txtTotalDue.Size = new System.Drawing.Size(100, 26);
            this.txtTotalDue.TabIndex = 6;
            this.txtTotalDue.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnCompute
            // 
            this.btnCompute.BackColor = System.Drawing.Color.Navy;
            this.btnCompute.Font = new System.Drawing.Font("Bookman Old Style", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCompute.ForeColor = System.Drawing.Color.Yellow;
            this.btnCompute.Location = new System.Drawing.Point(89, 160);
            this.btnCompute.Name = "btnCompute";
            this.btnCompute.Size = new System.Drawing.Size(106, 40);
            this.btnCompute.TabIndex = 2;
            this.btnCompute.Text = "Compute";
            this.btnCompute.UseVisualStyleBackColor = false;
            this.btnCompute.Click += new System.EventHandler(this.btnCompute_Click);
            // 
            // TaxForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.ClientSize = new System.Drawing.Size(284, 242);
            this.Controls.Add(this.btnCompute);
            this.Controls.Add(this.txtTotalDue);
            this.Controls.Add(this.txtPurchase);
            this.Controls.Add(this.lblTaxPercent);
            this.Controls.Add(this.lblDue);
            this.Controls.Add(this.lblPercentage);
            this.Controls.Add(this.lblAmount);
            this.Controls.Add(this.lblTitle);
            this.Font = new System.Drawing.Font("Bookman Old Style", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Margin = new System.Windows.Forms.Padding(5);
            this.Name = "TaxForm";
            this.Text = "Windows Tax App";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.Label lblAmount;
        private System.Windows.Forms.Label lblPercentage;
        private System.Windows.Forms.Label lblDue;
        private System.Windows.Forms.Label lblTaxPercent;
        private System.Windows.Forms.TextBox txtPurchase;
        private System.Windows.Forms.TextBox txtTotalDue;
        private System.Windows.Forms.Button btnCompute;
    }
}

