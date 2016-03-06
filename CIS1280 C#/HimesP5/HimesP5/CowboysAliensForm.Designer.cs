namespace HimesP5
{
    partial class CowboysAliensForm
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
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPageSituation = new System.Windows.Forms.TabPage();
            this.textBoxIntro = new System.Windows.Forms.TextBox();
            this.tabPageEncounter = new System.Windows.Forms.TabPage();
            this.buttonShoot = new System.Windows.Forms.Button();
            this.comboBoxWind = new System.Windows.Forms.ComboBox();
            this.comboBoxVisibility = new System.Windows.Forms.ComboBox();
            this.comboBoxRange = new System.Windows.Forms.ComboBox();
            this.comboBoxRounds = new System.Windows.Forms.ComboBox();
            this.comboBoxWeapons = new System.Windows.Forms.ComboBox();
            this.buttonStart = new System.Windows.Forms.Button();
            this.buttonAlienLocation = new System.Windows.Forms.Button();
            this.buttonHideCheck = new System.Windows.Forms.Button();
            this.textBoxResults = new System.Windows.Forms.TextBox();
            this.textBoxInstructions = new System.Windows.Forms.TextBox();
            this.tabControl1.SuspendLayout();
            this.tabPageSituation.SuspendLayout();
            this.tabPageEncounter.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPageSituation);
            this.tabControl1.Controls.Add(this.tabPageEncounter);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(660, 438);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPageSituation
            // 
            this.tabPageSituation.Controls.Add(this.textBoxIntro);
            this.tabPageSituation.Location = new System.Drawing.Point(4, 22);
            this.tabPageSituation.Name = "tabPageSituation";
            this.tabPageSituation.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageSituation.Size = new System.Drawing.Size(652, 412);
            this.tabPageSituation.TabIndex = 0;
            this.tabPageSituation.Text = "The situation and the mission";
            this.tabPageSituation.UseVisualStyleBackColor = true;
            // 
            // textBoxIntro
            // 
            this.textBoxIntro.BackColor = System.Drawing.Color.Black;
            this.textBoxIntro.Font = new System.Drawing.Font("Playbill", 18F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxIntro.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.textBoxIntro.Location = new System.Drawing.Point(34, 71);
            this.textBoxIntro.Multiline = true;
            this.textBoxIntro.Name = "textBoxIntro";
            this.textBoxIntro.ReadOnly = true;
            this.textBoxIntro.Size = new System.Drawing.Size(584, 271);
            this.textBoxIntro.TabIndex = 0;
            this.textBoxIntro.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tabPageEncounter
            // 
            this.tabPageEncounter.BackgroundImage = global::HimesP5.Properties.Resources.CowboysAliensBG;
            this.tabPageEncounter.Controls.Add(this.buttonShoot);
            this.tabPageEncounter.Controls.Add(this.comboBoxWind);
            this.tabPageEncounter.Controls.Add(this.comboBoxVisibility);
            this.tabPageEncounter.Controls.Add(this.comboBoxRange);
            this.tabPageEncounter.Controls.Add(this.comboBoxRounds);
            this.tabPageEncounter.Controls.Add(this.comboBoxWeapons);
            this.tabPageEncounter.Controls.Add(this.buttonStart);
            this.tabPageEncounter.Controls.Add(this.buttonAlienLocation);
            this.tabPageEncounter.Controls.Add(this.buttonHideCheck);
            this.tabPageEncounter.Controls.Add(this.textBoxResults);
            this.tabPageEncounter.Controls.Add(this.textBoxInstructions);
            this.tabPageEncounter.Location = new System.Drawing.Point(4, 22);
            this.tabPageEncounter.Name = "tabPageEncounter";
            this.tabPageEncounter.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageEncounter.Size = new System.Drawing.Size(652, 412);
            this.tabPageEncounter.TabIndex = 1;
            this.tabPageEncounter.Text = "The Encounter";
            this.tabPageEncounter.UseVisualStyleBackColor = true;
            // 
            // buttonShoot
            // 
            this.buttonShoot.Location = new System.Drawing.Point(289, 195);
            this.buttonShoot.Name = "buttonShoot";
            this.buttonShoot.Size = new System.Drawing.Size(75, 23);
            this.buttonShoot.TabIndex = 10;
            this.buttonShoot.Text = "SHOOT";
            this.buttonShoot.UseVisualStyleBackColor = true;
            this.buttonShoot.Click += new System.EventHandler(this.buttonShoot_Click);
            // 
            // comboBoxWind
            // 
            this.comboBoxWind.FormattingEnabled = true;
            this.comboBoxWind.Location = new System.Drawing.Point(520, 99);
            this.comboBoxWind.Name = "comboBoxWind";
            this.comboBoxWind.Size = new System.Drawing.Size(121, 21);
            this.comboBoxWind.TabIndex = 9;
            // 
            // comboBoxVisibility
            // 
            this.comboBoxVisibility.FormattingEnabled = true;
            this.comboBoxVisibility.Location = new System.Drawing.Point(393, 99);
            this.comboBoxVisibility.Name = "comboBoxVisibility";
            this.comboBoxVisibility.Size = new System.Drawing.Size(121, 21);
            this.comboBoxVisibility.TabIndex = 8;
            // 
            // comboBoxRange
            // 
            this.comboBoxRange.FormattingEnabled = true;
            this.comboBoxRange.Location = new System.Drawing.Point(266, 99);
            this.comboBoxRange.Name = "comboBoxRange";
            this.comboBoxRange.Size = new System.Drawing.Size(121, 21);
            this.comboBoxRange.TabIndex = 7;
            // 
            // comboBoxRounds
            // 
            this.comboBoxRounds.FormattingEnabled = true;
            this.comboBoxRounds.Location = new System.Drawing.Point(139, 99);
            this.comboBoxRounds.Name = "comboBoxRounds";
            this.comboBoxRounds.Size = new System.Drawing.Size(121, 21);
            this.comboBoxRounds.TabIndex = 6;
            // 
            // comboBoxWeapons
            // 
            this.comboBoxWeapons.FormattingEnabled = true;
            this.comboBoxWeapons.Location = new System.Drawing.Point(12, 99);
            this.comboBoxWeapons.Name = "comboBoxWeapons";
            this.comboBoxWeapons.Size = new System.Drawing.Size(121, 21);
            this.comboBoxWeapons.TabIndex = 5;
            // 
            // buttonStart
            // 
            this.buttonStart.Location = new System.Drawing.Point(266, 34);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(124, 23);
            this.buttonStart.TabIndex = 4;
            this.buttonStart.Text = "START A NEW GAME";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // buttonAlienLocation
            // 
            this.buttonAlienLocation.Location = new System.Drawing.Point(453, 250);
            this.buttonAlienLocation.Name = "buttonAlienLocation";
            this.buttonAlienLocation.Size = new System.Drawing.Size(188, 23);
            this.buttonAlienLocation.TabIndex = 3;
            this.buttonAlienLocation.Text = "FIND THE NEXT ALIEN LOCATION";
            this.buttonAlienLocation.UseVisualStyleBackColor = true;
            this.buttonAlienLocation.Click += new System.EventHandler(this.buttonAlienLocation_Click);
            // 
            // buttonHideCheck
            // 
            this.buttonHideCheck.Location = new System.Drawing.Point(12, 250);
            this.buttonHideCheck.Name = "buttonHideCheck";
            this.buttonHideCheck.Size = new System.Drawing.Size(158, 23);
            this.buttonHideCheck.TabIndex = 2;
            this.buttonHideCheck.Text = "CHECK FOR HIDING ALIENS";
            this.buttonHideCheck.UseVisualStyleBackColor = true;
            this.buttonHideCheck.Click += new System.EventHandler(this.buttonHideCheck_Click);
            // 
            // textBoxResults
            // 
            this.textBoxResults.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxResults.Location = new System.Drawing.Point(13, 354);
            this.textBoxResults.Multiline = true;
            this.textBoxResults.Name = "textBoxResults";
            this.textBoxResults.ReadOnly = true;
            this.textBoxResults.Size = new System.Drawing.Size(629, 20);
            this.textBoxResults.TabIndex = 1;
            this.textBoxResults.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxInstructions
            // 
            this.textBoxInstructions.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxInstructions.Location = new System.Drawing.Point(12, 292);
            this.textBoxInstructions.Multiline = true;
            this.textBoxInstructions.Name = "textBoxInstructions";
            this.textBoxInstructions.ReadOnly = true;
            this.textBoxInstructions.Size = new System.Drawing.Size(629, 20);
            this.textBoxInstructions.TabIndex = 0;
            this.textBoxInstructions.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // CowboysAliensForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(684, 462);
            this.Controls.Add(this.tabControl1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "CowboysAliensForm";
            this.Text = "Alan Himes - P5, Cowboys and Aliens";
            this.tabControl1.ResumeLayout(false);
            this.tabPageSituation.ResumeLayout(false);
            this.tabPageSituation.PerformLayout();
            this.tabPageEncounter.ResumeLayout(false);
            this.tabPageEncounter.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPageSituation;
        private System.Windows.Forms.TabPage tabPageEncounter;
        private System.Windows.Forms.TextBox textBoxIntro;
        private System.Windows.Forms.ComboBox comboBoxWind;
        private System.Windows.Forms.ComboBox comboBoxVisibility;
        private System.Windows.Forms.ComboBox comboBoxRange;
        private System.Windows.Forms.ComboBox comboBoxRounds;
        private System.Windows.Forms.ComboBox comboBoxWeapons;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Button buttonAlienLocation;
        private System.Windows.Forms.Button buttonHideCheck;
        private System.Windows.Forms.TextBox textBoxResults;
        private System.Windows.Forms.TextBox textBoxInstructions;
        private System.Windows.Forms.Button buttonShoot;
    }
}

