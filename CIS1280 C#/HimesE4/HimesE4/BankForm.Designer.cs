namespace HimesE4
{
    partial class BankForm
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
            this.lblAmount = new System.Windows.Forms.Label();
            this.txbName = new System.Windows.Forms.TextBox();
            this.txbAmount = new System.Windows.Forms.TextBox();
            this.btnAccount = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnDeduct = new System.Windows.Forms.Button();
            this.lblBalance = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lblName
            // 
            this.lblName.AutoSize = true;
            this.lblName.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblName.Location = new System.Drawing.Point(58, 53);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(43, 13);
            this.lblName.TabIndex = 0;
            this.lblName.Text = "Name:";
            // 
            // lblAmount
            // 
            this.lblAmount.AutoSize = true;
            this.lblAmount.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblAmount.Location = new System.Drawing.Point(58, 105);
            this.lblAmount.Name = "lblAmount";
            this.lblAmount.Size = new System.Drawing.Size(53, 13);
            this.lblAmount.TabIndex = 1;
            this.lblAmount.Text = "Amount:";
            // 
            // txbName
            // 
            this.txbName.Location = new System.Drawing.Point(117, 46);
            this.txbName.Name = "txbName";
            this.txbName.Size = new System.Drawing.Size(274, 20);
            this.txbName.TabIndex = 2;
            // 
            // txbAmount
            // 
            this.txbAmount.Location = new System.Drawing.Point(117, 98);
            this.txbAmount.Name = "txbAmount";
            this.txbAmount.Size = new System.Drawing.Size(123, 20);
            this.txbAmount.TabIndex = 3;
            // 
            // btnAccount
            // 
            this.btnAccount.Location = new System.Drawing.Point(353, 95);
            this.btnAccount.Name = "btnAccount";
            this.btnAccount.Size = new System.Drawing.Size(114, 23);
            this.btnAccount.TabIndex = 4;
            this.btnAccount.Text = "Create account";
            this.btnAccount.UseVisualStyleBackColor = true;
            this.btnAccount.Click += new System.EventHandler(this.btnAccount_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Location = new System.Drawing.Point(61, 157);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(61, 59);
            this.btnAdd.TabIndex = 5;
            this.btnAdd.Text = "Add amount";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Visible = false;
            this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
            // 
            // btnDeduct
            // 
            this.btnDeduct.Location = new System.Drawing.Point(171, 158);
            this.btnDeduct.Name = "btnDeduct";
            this.btnDeduct.Size = new System.Drawing.Size(61, 59);
            this.btnDeduct.TabIndex = 6;
            this.btnDeduct.Text = "Deduct amount";
            this.btnDeduct.UseVisualStyleBackColor = true;
            this.btnDeduct.Visible = false;
            this.btnDeduct.Click += new System.EventHandler(this.btnDeduct_Click);
            // 
            // lblBalance
            // 
            this.lblBalance.AutoSize = true;
            this.lblBalance.Location = new System.Drawing.Point(281, 158);
            this.lblBalance.Name = "lblBalance";
            this.lblBalance.Size = new System.Drawing.Size(0, 13);
            this.lblBalance.TabIndex = 7;
            // 
            // BankForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(524, 262);
            this.Controls.Add(this.lblBalance);
            this.Controls.Add(this.btnDeduct);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.btnAccount);
            this.Controls.Add(this.txbAmount);
            this.Controls.Add(this.txbName);
            this.Controls.Add(this.lblAmount);
            this.Controls.Add(this.lblName);
            this.Name = "BankForm";
            this.Text = "Alan Himes - E3 - Bank Account";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.Label lblAmount;
        private System.Windows.Forms.TextBox txbName;
        private System.Windows.Forms.TextBox txbAmount;
        private System.Windows.Forms.Button btnAccount;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnDeduct;
        private System.Windows.Forms.Label lblBalance;
    }
}

