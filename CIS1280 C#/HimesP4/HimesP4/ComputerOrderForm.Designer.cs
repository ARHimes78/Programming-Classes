namespace HimesP4
{
    partial class ComputerOrderForm
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
            this.lblTitle = new System.Windows.Forms.Label();
            this.periphListBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.computerBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rbMemory4 = new System.Windows.Forms.RadioButton();
            this.rbMemory1 = new System.Windows.Forms.RadioButton();
            this.rbMemory3 = new System.Windows.Forms.RadioButton();
            this.rbMemory2 = new System.Windows.Forms.RadioButton();
            this.rbHardDrive4 = new System.Windows.Forms.RadioButton();
            this.rbHardDrive3 = new System.Windows.Forms.RadioButton();
            this.rbHardDrive2 = new System.Windows.Forms.RadioButton();
            this.rbHardDrive1 = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.chbPeriph1 = new System.Windows.Forms.CheckBox();
            this.lblPeriphs = new System.Windows.Forms.Label();
            this.chbPeriph2 = new System.Windows.Forms.CheckBox();
            this.chbPeriph3 = new System.Windows.Forms.CheckBox();
            this.chbPeriph5 = new System.Windows.Forms.CheckBox();
            this.chbPeriph4 = new System.Windows.Forms.CheckBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnOrder = new System.Windows.Forms.Button();
            this.rtbSummary = new System.Windows.Forms.RichTextBox();
            this.lblMotherboards = new System.Windows.Forms.Label();
            this.cbxMotherboard = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.periphListBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.computerBindingSource)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Lucida Console", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(182, 13);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(520, 52);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "WELCOME TO COMPUTER STORE\r\nChoose Motherboard, Hard Drive, Memory and Peripheral(" +
    "s) \r\nto customize your computer purchase.\r\nClick the \"Place order\" button to con" +
    "firm your purchase.";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // periphListBindingSource
            // 
            this.periphListBindingSource.DataMember = "PeriphList";
            this.periphListBindingSource.DataSource = this.computerBindingSource;
            // 
            // computerBindingSource
            // 
            this.computerBindingSource.DataSource = typeof(HimesP4.ComputerOrder);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbMemory4);
            this.groupBox1.Controls.Add(this.rbMemory1);
            this.groupBox1.Controls.Add(this.rbMemory3);
            this.groupBox1.Controls.Add(this.rbMemory2);
            this.groupBox1.Location = new System.Drawing.Point(35, 152);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(424, 120);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Memory";
            // 
            // rbMemory4
            // 
            this.rbMemory4.AutoSize = true;
            this.rbMemory4.Location = new System.Drawing.Point(10, 91);
            this.rbMemory4.Name = "rbMemory4";
            this.rbMemory4.Size = new System.Drawing.Size(14, 13);
            this.rbMemory4.TabIndex = 7;
            this.rbMemory4.TabStop = true;
            this.rbMemory4.UseVisualStyleBackColor = true;
            // 
            // rbMemory1
            // 
            this.rbMemory1.AutoSize = true;
            this.rbMemory1.Location = new System.Drawing.Point(10, 19);
            this.rbMemory1.Name = "rbMemory1";
            this.rbMemory1.Size = new System.Drawing.Size(14, 13);
            this.rbMemory1.TabIndex = 4;
            this.rbMemory1.TabStop = true;
            this.rbMemory1.UseVisualStyleBackColor = true;
            // 
            // rbMemory3
            // 
            this.rbMemory3.AutoSize = true;
            this.rbMemory3.Location = new System.Drawing.Point(10, 67);
            this.rbMemory3.Name = "rbMemory3";
            this.rbMemory3.Size = new System.Drawing.Size(14, 13);
            this.rbMemory3.TabIndex = 6;
            this.rbMemory3.TabStop = true;
            this.rbMemory3.UseVisualStyleBackColor = true;
            // 
            // rbMemory2
            // 
            this.rbMemory2.AutoSize = true;
            this.rbMemory2.Location = new System.Drawing.Point(10, 43);
            this.rbMemory2.Name = "rbMemory2";
            this.rbMemory2.Size = new System.Drawing.Size(14, 13);
            this.rbMemory2.TabIndex = 5;
            this.rbMemory2.TabStop = true;
            this.rbMemory2.UseVisualStyleBackColor = true;
            // 
            // rbHardDrive4
            // 
            this.rbHardDrive4.AutoSize = true;
            this.rbHardDrive4.Location = new System.Drawing.Point(10, 91);
            this.rbHardDrive4.Name = "rbHardDrive4";
            this.rbHardDrive4.Size = new System.Drawing.Size(14, 13);
            this.rbHardDrive4.TabIndex = 3;
            this.rbHardDrive4.TabStop = true;
            this.rbHardDrive4.UseVisualStyleBackColor = true;
            // 
            // rbHardDrive3
            // 
            this.rbHardDrive3.AutoSize = true;
            this.rbHardDrive3.Location = new System.Drawing.Point(10, 67);
            this.rbHardDrive3.Name = "rbHardDrive3";
            this.rbHardDrive3.Size = new System.Drawing.Size(14, 13);
            this.rbHardDrive3.TabIndex = 2;
            this.rbHardDrive3.TabStop = true;
            this.rbHardDrive3.UseVisualStyleBackColor = true;
            // 
            // rbHardDrive2
            // 
            this.rbHardDrive2.AutoSize = true;
            this.rbHardDrive2.Location = new System.Drawing.Point(10, 43);
            this.rbHardDrive2.Name = "rbHardDrive2";
            this.rbHardDrive2.Size = new System.Drawing.Size(14, 13);
            this.rbHardDrive2.TabIndex = 1;
            this.rbHardDrive2.TabStop = true;
            this.rbHardDrive2.UseVisualStyleBackColor = true;
            // 
            // rbHardDrive1
            // 
            this.rbHardDrive1.AutoSize = true;
            this.rbHardDrive1.Location = new System.Drawing.Point(10, 19);
            this.rbHardDrive1.Name = "rbHardDrive1";
            this.rbHardDrive1.Size = new System.Drawing.Size(14, 13);
            this.rbHardDrive1.TabIndex = 0;
            this.rbHardDrive1.TabStop = true;
            this.rbHardDrive1.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.rbHardDrive1);
            this.groupBox2.Controls.Add(this.rbHardDrive4);
            this.groupBox2.Controls.Add(this.rbHardDrive2);
            this.groupBox2.Controls.Add(this.rbHardDrive3);
            this.groupBox2.Location = new System.Drawing.Point(35, 283);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(424, 120);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Hard drives";
            // 
            // chbPeriph1
            // 
            this.chbPeriph1.AutoSize = true;
            this.chbPeriph1.Location = new System.Drawing.Point(509, 195);
            this.chbPeriph1.Name = "chbPeriph1";
            this.chbPeriph1.Size = new System.Drawing.Size(15, 14);
            this.chbPeriph1.TabIndex = 4;
            this.chbPeriph1.UseVisualStyleBackColor = true;
            // 
            // lblPeriphs
            // 
            this.lblPeriphs.AutoSize = true;
            this.lblPeriphs.Location = new System.Drawing.Point(506, 152);
            this.lblPeriphs.Name = "lblPeriphs";
            this.lblPeriphs.Size = new System.Drawing.Size(59, 13);
            this.lblPeriphs.TabIndex = 5;
            this.lblPeriphs.Text = "Peripherals";
            // 
            // chbPeriph2
            // 
            this.chbPeriph2.AutoSize = true;
            this.chbPeriph2.Location = new System.Drawing.Point(509, 239);
            this.chbPeriph2.Name = "chbPeriph2";
            this.chbPeriph2.Size = new System.Drawing.Size(15, 14);
            this.chbPeriph2.TabIndex = 6;
            this.chbPeriph2.UseVisualStyleBackColor = true;
            // 
            // chbPeriph3
            // 
            this.chbPeriph3.AutoSize = true;
            this.chbPeriph3.Location = new System.Drawing.Point(509, 283);
            this.chbPeriph3.Name = "chbPeriph3";
            this.chbPeriph3.Size = new System.Drawing.Size(15, 14);
            this.chbPeriph3.TabIndex = 7;
            this.chbPeriph3.UseVisualStyleBackColor = true;
            // 
            // chbPeriph5
            // 
            this.chbPeriph5.AutoSize = true;
            this.chbPeriph5.Location = new System.Drawing.Point(509, 371);
            this.chbPeriph5.Name = "chbPeriph5";
            this.chbPeriph5.Size = new System.Drawing.Size(15, 14);
            this.chbPeriph5.TabIndex = 9;
            this.chbPeriph5.UseVisualStyleBackColor = true;
            // 
            // chbPeriph4
            // 
            this.chbPeriph4.AutoSize = true;
            this.chbPeriph4.Location = new System.Drawing.Point(509, 327);
            this.chbPeriph4.Name = "chbPeriph4";
            this.chbPeriph4.Size = new System.Drawing.Size(15, 14);
            this.chbPeriph4.TabIndex = 8;
            this.chbPeriph4.UseVisualStyleBackColor = true;
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(764, 577);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(75, 23);
            this.btnClear.TabIndex = 11;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnOrder
            // 
            this.btnOrder.Location = new System.Drawing.Point(42, 414);
            this.btnOrder.Name = "btnOrder";
            this.btnOrder.Size = new System.Drawing.Size(75, 23);
            this.btnOrder.TabIndex = 12;
            this.btnOrder.Text = "Place order";
            this.btnOrder.UseVisualStyleBackColor = true;
            this.btnOrder.Click += new System.EventHandler(this.btnOrder_Click);
            // 
            // rtbSummary
            // 
            this.rtbSummary.Location = new System.Drawing.Point(184, 414);
            this.rtbSummary.Name = "rtbSummary";
            this.rtbSummary.ReadOnly = true;
            this.rtbSummary.Size = new System.Drawing.Size(517, 186);
            this.rtbSummary.TabIndex = 13;
            this.rtbSummary.Text = "";
            // 
            // lblMotherboards
            // 
            this.lblMotherboards.AutoSize = true;
            this.lblMotherboards.Location = new System.Drawing.Point(42, 96);
            this.lblMotherboards.Name = "lblMotherboards";
            this.lblMotherboards.Size = new System.Drawing.Size(72, 13);
            this.lblMotherboards.TabIndex = 14;
            this.lblMotherboards.Text = "Motherboards";
            // 
            // cbxMotherboard
            // 
            this.cbxMotherboard.FormattingEnabled = true;
            this.cbxMotherboard.Location = new System.Drawing.Point(42, 120);
            this.cbxMotherboard.Name = "cbxMotherboard";
            this.cbxMotherboard.Size = new System.Drawing.Size(417, 21);
            this.cbxMotherboard.TabIndex = 15;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(884, 612);
            this.Controls.Add(this.cbxMotherboard);
            this.Controls.Add(this.lblMotherboards);
            this.Controls.Add(this.rtbSummary);
            this.Controls.Add(this.btnOrder);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.chbPeriph5);
            this.Controls.Add(this.chbPeriph4);
            this.Controls.Add(this.chbPeriph3);
            this.Controls.Add(this.chbPeriph2);
            this.Controls.Add(this.lblPeriphs);
            this.Controls.Add(this.chbPeriph1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.lblTitle);
            this.Name = "Form1";
            this.Text = "Alan Himes P4 Office Supply Store";
            ((System.ComponentModel.ISupportInitialize)(this.periphListBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.computerBindingSource)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.BindingSource computerBindingSource;
        private System.Windows.Forms.BindingSource periphListBindingSource;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rbHardDrive4;
        private System.Windows.Forms.RadioButton rbHardDrive3;
        private System.Windows.Forms.RadioButton rbHardDrive2;
        private System.Windows.Forms.RadioButton rbHardDrive1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton rbMemory4;
        private System.Windows.Forms.RadioButton rbMemory1;
        private System.Windows.Forms.RadioButton rbMemory3;
        private System.Windows.Forms.RadioButton rbMemory2;
        private System.Windows.Forms.CheckBox chbPeriph1;
        private System.Windows.Forms.Label lblPeriphs;
        private System.Windows.Forms.CheckBox chbPeriph2;
        private System.Windows.Forms.CheckBox chbPeriph3;
        private System.Windows.Forms.CheckBox chbPeriph5;
        private System.Windows.Forms.CheckBox chbPeriph4;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnOrder;
        private System.Windows.Forms.RichTextBox rtbSummary;
        private System.Windows.Forms.Label lblMotherboards;
        private System.Windows.Forms.ComboBox cbxMotherboard;
    }
}

