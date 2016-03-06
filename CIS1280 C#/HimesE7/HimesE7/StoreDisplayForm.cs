// StoreDisplayForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Database demo

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesE7
{
    public partial class StoreDisplayForm : Form
    {
        public StoreDisplayForm()
        {
            InitializeComponent();
        }

        private void StoreDisplayForm_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'e7DBDataSet.stores' table. You can move, or remove it, as needed.
            this.storesTableAdapter.Fill(this.e7DBDataSet.stores);

        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            updateTable();
        }        

        private void StoreDisplayForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            updateTable();
        }

        private void updateTable()
        {
            this.storesBindingSource.EndEdit();
            this.storesTableAdapter.Update(this.e7DBDataSet.stores);
            this.storesTableAdapter.Fill(this.e7DBDataSet.stores);
        }
    }
}
