namespace HimesP4
{
    partial class StoreCheckoutForm
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabFurn = new System.Windows.Forms.TabPage();
            this.lbxFurn = new System.Windows.Forms.ListBox();
            this.tabSupplies = new System.Windows.Forms.TabPage();
            this.chbLabelmaker = new System.Windows.Forms.CheckBox();
            this.chbTape = new System.Windows.Forms.CheckBox();
            this.chbFolders = new System.Windows.Forms.CheckBox();
            this.chbErasers = new System.Windows.Forms.CheckBox();
            this.chbCorrection = new System.Windows.Forms.CheckBox();
            this.chbHighlighter = new System.Windows.Forms.CheckBox();
            this.chbSharpener = new System.Windows.Forms.CheckBox();
            this.chbPencils = new System.Windows.Forms.CheckBox();
            this.chbMarkers = new System.Windows.Forms.CheckBox();
            this.chbPens = new System.Windows.Forms.CheckBox();
            this.tabComp = new System.Windows.Forms.TabPage();
            this.btnComputer = new System.Windows.Forms.Button();
            this.txbSummary = new System.Windows.Forms.TextBox();
            this.btnOrder = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.lblComputerOrder = new System.Windows.Forms.Label();
            this.txbCompOrder = new System.Windows.Forms.TextBox();
            this.tabControl1.SuspendLayout();
            this.tabFurn.SuspendLayout();
            this.tabSupplies.SuspendLayout();
            this.tabComp.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblTitle
            // 
            this.lblTitle.AutoSize = true;
            this.lblTitle.Font = new System.Drawing.Font("Lucida Console", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTitle.Location = new System.Drawing.Point(327, 20);
            this.lblTitle.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.lblTitle.Name = "lblTitle";
            this.lblTitle.Size = new System.Drawing.Size(503, 60);
            this.lblTitle.TabIndex = 0;
            this.lblTitle.Text = "Welcome to Office Supply Store\r\nChoose items in tabs to purchase items\r\nand click" +
    " \"Place order\" to check out.\r\n";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabFurn);
            this.tabControl1.Controls.Add(this.tabSupplies);
            this.tabControl1.Controls.Add(this.tabComp);
            this.tabControl1.Location = new System.Drawing.Point(18, 85);
            this.tabControl1.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1140, 465);
            this.tabControl1.TabIndex = 1;
            // 
            // tabFurn
            // 
            this.tabFurn.Controls.Add(this.lbxFurn);
            this.tabFurn.Location = new System.Drawing.Point(4, 29);
            this.tabFurn.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabFurn.Name = "tabFurn";
            this.tabFurn.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabFurn.Size = new System.Drawing.Size(1132, 432);
            this.tabFurn.TabIndex = 0;
            this.tabFurn.Text = "Furniture";
            this.tabFurn.UseVisualStyleBackColor = true;
            // 
            // lbxFurn
            // 
            this.lbxFurn.FormattingEnabled = true;
            this.lbxFurn.ItemHeight = 20;
            this.lbxFurn.Location = new System.Drawing.Point(444, 117);
            this.lbxFurn.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.lbxFurn.Name = "lbxFurn";
            this.lbxFurn.Size = new System.Drawing.Size(240, 144);
            this.lbxFurn.TabIndex = 0;
            this.lbxFurn.SelectedIndexChanged += new System.EventHandler(this.lbxFurn_SelectedIndexChanged);
            // 
            // tabSupplies
            // 
            this.tabSupplies.Controls.Add(this.chbLabelmaker);
            this.tabSupplies.Controls.Add(this.chbTape);
            this.tabSupplies.Controls.Add(this.chbFolders);
            this.tabSupplies.Controls.Add(this.chbErasers);
            this.tabSupplies.Controls.Add(this.chbCorrection);
            this.tabSupplies.Controls.Add(this.chbHighlighter);
            this.tabSupplies.Controls.Add(this.chbSharpener);
            this.tabSupplies.Controls.Add(this.chbPencils);
            this.tabSupplies.Controls.Add(this.chbMarkers);
            this.tabSupplies.Controls.Add(this.chbPens);
            this.tabSupplies.Location = new System.Drawing.Point(4, 29);
            this.tabSupplies.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabSupplies.Name = "tabSupplies";
            this.tabSupplies.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabSupplies.Size = new System.Drawing.Size(1132, 432);
            this.tabSupplies.TabIndex = 1;
            this.tabSupplies.Text = "Office supplies";
            this.tabSupplies.UseVisualStyleBackColor = true;
            // 
            // chbLabelmaker
            // 
            this.chbLabelmaker.AutoSize = true;
            this.chbLabelmaker.Location = new System.Drawing.Point(681, 326);
            this.chbLabelmaker.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbLabelmaker.Name = "chbLabelmaker";
            this.chbLabelmaker.Size = new System.Drawing.Size(22, 21);
            this.chbLabelmaker.TabIndex = 9;
            this.chbLabelmaker.UseVisualStyleBackColor = true;
            // 
            // chbTape
            // 
            this.chbTape.AutoSize = true;
            this.chbTape.Location = new System.Drawing.Point(681, 263);
            this.chbTape.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbTape.Name = "chbTape";
            this.chbTape.Size = new System.Drawing.Size(22, 21);
            this.chbTape.TabIndex = 8;
            this.chbTape.UseVisualStyleBackColor = true;
            // 
            // chbFolders
            // 
            this.chbFolders.AutoSize = true;
            this.chbFolders.Location = new System.Drawing.Point(681, 200);
            this.chbFolders.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbFolders.Name = "chbFolders";
            this.chbFolders.Size = new System.Drawing.Size(22, 21);
            this.chbFolders.TabIndex = 7;
            this.chbFolders.UseVisualStyleBackColor = true;
            // 
            // chbErasers
            // 
            this.chbErasers.AutoSize = true;
            this.chbErasers.Location = new System.Drawing.Point(681, 137);
            this.chbErasers.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbErasers.Name = "chbErasers";
            this.chbErasers.Size = new System.Drawing.Size(22, 21);
            this.chbErasers.TabIndex = 6;
            this.chbErasers.UseVisualStyleBackColor = true;
            // 
            // chbCorrection
            // 
            this.chbCorrection.AutoSize = true;
            this.chbCorrection.Location = new System.Drawing.Point(681, 74);
            this.chbCorrection.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbCorrection.Name = "chbCorrection";
            this.chbCorrection.Size = new System.Drawing.Size(22, 21);
            this.chbCorrection.TabIndex = 5;
            this.chbCorrection.UseVisualStyleBackColor = true;
            // 
            // chbHighlighter
            // 
            this.chbHighlighter.AutoSize = true;
            this.chbHighlighter.Location = new System.Drawing.Point(424, 326);
            this.chbHighlighter.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbHighlighter.Name = "chbHighlighter";
            this.chbHighlighter.Size = new System.Drawing.Size(22, 21);
            this.chbHighlighter.TabIndex = 4;
            this.chbHighlighter.UseVisualStyleBackColor = true;
            // 
            // chbSharpener
            // 
            this.chbSharpener.AutoSize = true;
            this.chbSharpener.Location = new System.Drawing.Point(424, 263);
            this.chbSharpener.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbSharpener.Name = "chbSharpener";
            this.chbSharpener.Size = new System.Drawing.Size(22, 21);
            this.chbSharpener.TabIndex = 3;
            this.chbSharpener.UseVisualStyleBackColor = true;
            // 
            // chbPencils
            // 
            this.chbPencils.AutoSize = true;
            this.chbPencils.Location = new System.Drawing.Point(424, 200);
            this.chbPencils.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbPencils.Name = "chbPencils";
            this.chbPencils.Size = new System.Drawing.Size(22, 21);
            this.chbPencils.TabIndex = 2;
            this.chbPencils.UseVisualStyleBackColor = true;
            // 
            // chbMarkers
            // 
            this.chbMarkers.AutoSize = true;
            this.chbMarkers.Location = new System.Drawing.Point(424, 137);
            this.chbMarkers.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbMarkers.Name = "chbMarkers";
            this.chbMarkers.Size = new System.Drawing.Size(22, 21);
            this.chbMarkers.TabIndex = 1;
            this.chbMarkers.UseVisualStyleBackColor = true;
            // 
            // chbPens
            // 
            this.chbPens.AutoSize = true;
            this.chbPens.Location = new System.Drawing.Point(424, 74);
            this.chbPens.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.chbPens.Name = "chbPens";
            this.chbPens.Size = new System.Drawing.Size(22, 21);
            this.chbPens.TabIndex = 0;
            this.chbPens.UseVisualStyleBackColor = true;
            // 
            // tabComp
            // 
            this.tabComp.Controls.Add(this.txbCompOrder);
            this.tabComp.Controls.Add(this.lblComputerOrder);
            this.tabComp.Controls.Add(this.btnComputer);
            this.tabComp.Location = new System.Drawing.Point(4, 29);
            this.tabComp.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabComp.Name = "tabComp";
            this.tabComp.Padding = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.tabComp.Size = new System.Drawing.Size(1132, 432);
            this.tabComp.TabIndex = 2;
            this.tabComp.Text = "Computers";
            this.tabComp.UseVisualStyleBackColor = true;
            // 
            // btnComputer
            // 
            this.btnComputer.Location = new System.Drawing.Point(494, 307);
            this.btnComputer.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnComputer.Name = "btnComputer";
            this.btnComputer.Size = new System.Drawing.Size(112, 62);
            this.btnComputer.TabIndex = 1;
            this.btnComputer.Text = "Order a computer";
            this.btnComputer.UseVisualStyleBackColor = true;
            this.btnComputer.Click += new System.EventHandler(this.btnComputer_Click);
            // 
            // txbSummary
            // 
            this.txbSummary.Location = new System.Drawing.Point(228, 558);
            this.txbSummary.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.txbSummary.Multiline = true;
            this.txbSummary.Name = "txbSummary";
            this.txbSummary.ReadOnly = true;
            this.txbSummary.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txbSummary.Size = new System.Drawing.Size(720, 286);
            this.txbSummary.TabIndex = 2;
            // 
            // btnOrder
            // 
            this.btnOrder.Location = new System.Drawing.Point(18, 558);
            this.btnOrder.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnOrder.Name = "btnOrder";
            this.btnOrder.Size = new System.Drawing.Size(112, 35);
            this.btnOrder.TabIndex = 3;
            this.btnOrder.Text = "Place order";
            this.btnOrder.UseVisualStyleBackColor = true;
            this.btnOrder.Click += new System.EventHandler(this.btnOrder_Click);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(1040, 811);
            this.btnClear.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(112, 35);
            this.btnClear.TabIndex = 4;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // lblComputerOrder
            // 
            this.lblComputerOrder.AutoSize = true;
            this.lblComputerOrder.Location = new System.Drawing.Point(65, 43);
            this.lblComputerOrder.Name = "lblComputerOrder";
            this.lblComputerOrder.Size = new System.Drawing.Size(0, 20);
            this.lblComputerOrder.TabIndex = 3;
            // 
            // txbCompOrder
            // 
            this.txbCompOrder.Location = new System.Drawing.Point(73, 51);
            this.txbCompOrder.Multiline = true;
            this.txbCompOrder.Name = "txbCompOrder";
            this.txbCompOrder.ReadOnly = true;
            this.txbCompOrder.Size = new System.Drawing.Size(986, 236);
            this.txbCompOrder.TabIndex = 4;
            // 
            // StoreCheckoutForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1176, 865);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnOrder);
            this.Controls.Add(this.txbSummary);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.lblTitle);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "StoreCheckoutForm";
            this.Text = "Alan Himes P4 Office Supply Store";
            this.tabControl1.ResumeLayout(false);
            this.tabFurn.ResumeLayout(false);
            this.tabSupplies.ResumeLayout(false);
            this.tabSupplies.PerformLayout();
            this.tabComp.ResumeLayout(false);
            this.tabComp.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabFurn;
        private System.Windows.Forms.TabPage tabSupplies;
        private System.Windows.Forms.TabPage tabComp;
        private System.Windows.Forms.TextBox txbSummary;
        private System.Windows.Forms.Button btnOrder;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.ListBox lbxFurn;
        private System.Windows.Forms.CheckBox chbLabelmaker;
        private System.Windows.Forms.CheckBox chbTape;
        private System.Windows.Forms.CheckBox chbFolders;
        private System.Windows.Forms.CheckBox chbErasers;
        private System.Windows.Forms.CheckBox chbCorrection;
        private System.Windows.Forms.CheckBox chbHighlighter;
        private System.Windows.Forms.CheckBox chbSharpener;
        private System.Windows.Forms.CheckBox chbPencils;
        private System.Windows.Forms.CheckBox chbMarkers;
        private System.Windows.Forms.CheckBox chbPens;
        private System.Windows.Forms.Button btnComputer;
        private System.Windows.Forms.TextBox txbCompOrder;
        private System.Windows.Forms.Label lblComputerOrder;

    }
}