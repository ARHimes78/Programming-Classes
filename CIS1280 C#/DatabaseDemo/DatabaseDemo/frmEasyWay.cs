using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DatabaseDemo
{
    public partial class frmEasyWay : Form
    {
        public frmEasyWay()
        {
            InitializeComponent();
        }

        private void frmEasyWay_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'demoDBDataSet.tblDog' table. You can move, or remove it, as needed.
            this.tblDogTableAdapter.Fill(this.demoDBDataSet.tblDog);

        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            this.tblDogBindingSource.EndEdit();
            this.tblDogTableAdapter.Update(this.demoDBDataSet.tblDog);
            this.tblDogTableAdapter.Fill(this.demoDBDataSet.tblDog);
        }

        private void frmEasyWay_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.tblDogBindingSource.EndEdit();
            this.tblDogTableAdapter.Update(this.demoDBDataSet.tblDog);
            this.tblDogTableAdapter.Fill(this.demoDBDataSet.tblDog);
        }

        private void dataGridView1_RowLeave(object sender, DataGridViewCellEventArgs e)
        {
            
        }
    }
}
