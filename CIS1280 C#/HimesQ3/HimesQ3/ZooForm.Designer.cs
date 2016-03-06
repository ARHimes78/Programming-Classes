namespace HimesQ3
{
    partial class ZooForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.gbxAnimals = new System.Windows.Forms.GroupBox();
            this.rdbPython = new System.Windows.Forms.RadioButton();
            this.rdbDolphin = new System.Windows.Forms.RadioButton();
            this.rdbLion = new System.Windows.Forms.RadioButton();
            this.btnObserve = new System.Windows.Forms.Button();
            this.txbSummary = new System.Windows.Forms.TextBox();
            this.gbxAnimals.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.label1.Font = new System.Drawing.Font("Buxton Sketch", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(40, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(405, 116);
            this.label1.TabIndex = 0;
            this.label1.Text = "Welcome fo the C# Zoo.\r\nIt is feeding time and you are invited to\r\nobserve some o" +
    "f our most interesting\r\nresidents.  Please choose an animal to watch.";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // gbxAnimals
            // 
            this.gbxAnimals.Controls.Add(this.rdbPython);
            this.gbxAnimals.Controls.Add(this.rdbDolphin);
            this.gbxAnimals.Controls.Add(this.rdbLion);
            this.gbxAnimals.Location = new System.Drawing.Point(33, 146);
            this.gbxAnimals.Name = "gbxAnimals";
            this.gbxAnimals.Size = new System.Drawing.Size(103, 89);
            this.gbxAnimals.TabIndex = 1;
            this.gbxAnimals.TabStop = false;
            // 
            // rdbPython
            // 
            this.rdbPython.AutoSize = true;
            this.rdbPython.Location = new System.Drawing.Point(7, 36);
            this.rdbPython.Name = "rdbPython";
            this.rdbPython.Size = new System.Drawing.Size(58, 17);
            this.rdbPython.TabIndex = 2;
            this.rdbPython.Text = "Python";
            this.rdbPython.UseVisualStyleBackColor = true;
            // 
            // rdbDolphin
            // 
            this.rdbDolphin.AutoSize = true;
            this.rdbDolphin.Location = new System.Drawing.Point(7, 59);
            this.rdbDolphin.Name = "rdbDolphin";
            this.rdbDolphin.Size = new System.Drawing.Size(61, 17);
            this.rdbDolphin.TabIndex = 1;
            this.rdbDolphin.Text = "Dolphin";
            this.rdbDolphin.UseVisualStyleBackColor = true;
            // 
            // rdbLion
            // 
            this.rdbLion.AutoSize = true;
            this.rdbLion.Checked = true;
            this.rdbLion.Location = new System.Drawing.Point(7, 13);
            this.rdbLion.Name = "rdbLion";
            this.rdbLion.Size = new System.Drawing.Size(45, 17);
            this.rdbLion.TabIndex = 0;
            this.rdbLion.TabStop = true;
            this.rdbLion.Text = "Lion";
            this.rdbLion.UseVisualStyleBackColor = true;
            // 
            // btnObserve
            // 
            this.btnObserve.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnObserve.Font = new System.Drawing.Font("Times New Roman", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnObserve.Location = new System.Drawing.Point(194, 162);
            this.btnObserve.Name = "btnObserve";
            this.btnObserve.Size = new System.Drawing.Size(235, 57);
            this.btnObserve.TabIndex = 2;
            this.btnObserve.Text = "OBSERVE AN ANIMAL";
            this.btnObserve.UseVisualStyleBackColor = false;
            this.btnObserve.Click += new System.EventHandler(this.btnObserve_Click);
            // 
            // txbSummary
            // 
            this.txbSummary.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txbSummary.Location = new System.Drawing.Point(31, 252);
            this.txbSummary.Multiline = true;
            this.txbSummary.Name = "txbSummary";
            this.txbSummary.ReadOnly = true;
            this.txbSummary.Size = new System.Drawing.Size(422, 97);
            this.txbSummary.TabIndex = 3;
            // 
            // ZooForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(484, 362);
            this.Controls.Add(this.txbSummary);
            this.Controls.Add(this.btnObserve);
            this.Controls.Add(this.gbxAnimals);
            this.Controls.Add(this.label1);
            this.Name = "ZooForm";
            this.Text = "The C# Zoo Observation post";
            this.gbxAnimals.ResumeLayout(false);
            this.gbxAnimals.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gbxAnimals;
        private System.Windows.Forms.RadioButton rdbPython;
        private System.Windows.Forms.RadioButton rdbDolphin;
        private System.Windows.Forms.RadioButton rdbLion;
        private System.Windows.Forms.Button btnObserve;
        private System.Windows.Forms.TextBox txbSummary;
    }
}

