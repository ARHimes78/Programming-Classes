namespace DatabaseDemo
{
    partial class SQLCommandDemo
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
            this.dgvDogs = new System.Windows.Forms.DataGridView();
            this.DogID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Breed = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Color = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDogs)).BeginInit();
            this.SuspendLayout();
            // 
            // dgvDogs
            // 
            this.dgvDogs.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDogs.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.DogID,
            this.Breed,
            this.Color});
            this.dgvDogs.Location = new System.Drawing.Point(44, 32);
            this.dgvDogs.Name = "dgvDogs";
            this.dgvDogs.Size = new System.Drawing.Size(686, 318);
            this.dgvDogs.TabIndex = 0;
            // 
            // DogID
            // 
            this.DogID.HeaderText = "ID";
            this.DogID.Name = "DogID";
            this.DogID.ReadOnly = true;
            // 
            // Breed
            // 
            this.Breed.HeaderText = "breed";
            this.Breed.Name = "Breed";
            // 
            // Color
            // 
            this.Color.HeaderText = "color";
            this.Color.Name = "Color";
            // 
            // SQLCommandDemo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(776, 516);
            this.Controls.Add(this.dgvDogs);
            this.Name = "SQLCommandDemo";
            this.Text = "SQLCommandDemo";
            ((System.ComponentModel.ISupportInitialize)(this.dgvDogs)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dgvDogs;
        private System.Windows.Forms.DataGridViewTextBoxColumn DogID;
        private System.Windows.Forms.DataGridViewTextBoxColumn Breed;
        private System.Windows.Forms.DataGridViewTextBoxColumn Color;
    }
}