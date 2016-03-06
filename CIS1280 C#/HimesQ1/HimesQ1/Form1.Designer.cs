namespace HimesQ1
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
            this.lblDescription = new System.Windows.Forms.Label();
            this.lblMiles = new System.Windows.Forms.Label();
            this.lblGallons = new System.Windows.Forms.Label();
            this.txbMiles = new System.Windows.Forms.TextBox();
            this.txbGallons = new System.Windows.Forms.TextBox();
            this.lblMPG = new System.Windows.Forms.Label();
            this.txbMPG = new System.Windows.Forms.TextBox();
            this.btnCalc = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblDescription
            // 
            this.lblDescription.AutoSize = true;
            this.lblDescription.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDescription.Location = new System.Drawing.Point(15, 27);
            this.lblDescription.Name = "lblDescription";
            this.lblDescription.Size = new System.Drawing.Size(555, 32);
            this.lblDescription.TabIndex = 0;
            this.lblDescription.Text = "Input amount of miles and gallons, then click Calculate to show miles per gallon." +
    "\r\n\r\n";
            // 
            // lblMiles
            // 
            this.lblMiles.AutoSize = true;
            this.lblMiles.Location = new System.Drawing.Point(72, 114);
            this.lblMiles.Name = "lblMiles";
            this.lblMiles.Size = new System.Drawing.Size(34, 13);
            this.lblMiles.TabIndex = 1;
            this.lblMiles.Text = "Miles:";
            // 
            // lblGallons
            // 
            this.lblGallons.AutoSize = true;
            this.lblGallons.Location = new System.Drawing.Point(362, 114);
            this.lblGallons.Name = "lblGallons";
            this.lblGallons.Size = new System.Drawing.Size(45, 13);
            this.lblGallons.TabIndex = 2;
            this.lblGallons.Text = "Gallons:";
            // 
            // txbMiles
            // 
            this.txbMiles.Location = new System.Drawing.Point(112, 107);
            this.txbMiles.Name = "txbMiles";
            this.txbMiles.Size = new System.Drawing.Size(100, 20);
            this.txbMiles.TabIndex = 3;
            // 
            // txbGallons
            // 
            this.txbGallons.Location = new System.Drawing.Point(413, 107);
            this.txbGallons.Name = "txbGallons";
            this.txbGallons.Size = new System.Drawing.Size(100, 20);
            this.txbGallons.TabIndex = 4;
            // 
            // lblMPG
            // 
            this.lblMPG.AutoSize = true;
            this.lblMPG.Location = new System.Drawing.Point(197, 242);
            this.lblMPG.Name = "lblMPG";
            this.lblMPG.Size = new System.Drawing.Size(83, 13);
            this.lblMPG.TabIndex = 5;
            this.lblMPG.Text = "Miles per gallon:";
            // 
            // txbMPG
            // 
            this.txbMPG.Location = new System.Drawing.Point(287, 234);
            this.txbMPG.Name = "txbMPG";
            this.txbMPG.ReadOnly = true;
            this.txbMPG.Size = new System.Drawing.Size(100, 20);
            this.txbMPG.TabIndex = 6;
            // 
            // btnCalc
            // 
            this.btnCalc.Location = new System.Drawing.Point(255, 174);
            this.btnCalc.Name = "btnCalc";
            this.btnCalc.Size = new System.Drawing.Size(75, 23);
            this.btnCalc.TabIndex = 7;
            this.btnCalc.Text = "Calculate";
            this.btnCalc.UseVisualStyleBackColor = true;
            this.btnCalc.Click += new System.EventHandler(this.btnCalc_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(472, 310);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 8;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 362);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnCalc);
            this.Controls.Add(this.txbMPG);
            this.Controls.Add(this.lblMPG);
            this.Controls.Add(this.txbGallons);
            this.Controls.Add(this.txbMiles);
            this.Controls.Add(this.lblGallons);
            this.Controls.Add(this.lblMiles);
            this.Controls.Add(this.lblDescription);
            this.Name = "Form1";
            this.Text = "Alan Himes - Mileage calculator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblDescription;
        private System.Windows.Forms.Label lblMiles;
        private System.Windows.Forms.Label lblGallons;
        private System.Windows.Forms.TextBox txbMiles;
        private System.Windows.Forms.TextBox txbGallons;
        private System.Windows.Forms.Label lblMPG;
        private System.Windows.Forms.TextBox txbMPG;
        private System.Windows.Forms.Button btnCalc;
        private System.Windows.Forms.Button btnClear;
    }
}

