// StoreCheckoutForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Office supply store

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesP4
{
    public partial class StoreCheckoutForm : Form
    {
        private CheckBox[] supplyCheckBoxes;
        private StoreCheckout storeCheckout;

        public StoreCheckoutForm()
        {
            InitializeComponent();
            InitializeForm();
        }

        //Just like in ComputerOrderForm, initializes and clears everything
        //To be used in StoreCheckoutForm constructor and for the Clear button.
        private void InitializeForm()
        {
            //instantiating storeCheckout here so all ComputerOrder adjustments are reset 
            //when clicking the Clear button.
            storeCheckout = new StoreCheckout();
            
            //Creating a string array to assign to the ListBox.
            string[] furniture = new string[7];
            for (int i = 0; i < furniture.Length; ++i)
            {
                storeCheckout.FurnIndex = i;
                furniture[i] = storeCheckout.Furniture + " $" + storeCheckout.FurnPrices;

            }

            lbxFurn.Items.Clear();
            lbxFurn.Items.AddRange(furniture);
            lbxFurn.SelectedIndex = lbxFurn.Items.Count - 1;

            //Assigning arrays of office supplies to correspond with elements of checkbox array.
            supplyCheckBoxes = new CheckBox[] 
                { chbPens, chbMarkers, chbPencils, chbSharpener, chbHighlighter,
                chbCorrection, chbErasers, chbFolders, chbTape, chbLabelmaker};

            for (int i = 0; i < supplyCheckBoxes.Length; ++i)
            {
                storeCheckout.SuppliesIndex = i;
                supplyCheckBoxes[i].Text = storeCheckout.Supplies + " $" + storeCheckout.SuppliesPrices;
            }

            //Making sure each checkbox is unchecked
            foreach (CheckBox check in supplyCheckBoxes)
            {
                check.Checked = false;
            }

            //Clearing the summary TextBox
            txbSummary.Clear();
        }

        //Uses a list of selected checkboxes to tell the StoreCheckout object when items were selected.
        private void CheckBoxesToSummary()
        {
            List<int> supplies = new List<int>();
            for (int i = 0; i < supplyCheckBoxes.Length; ++i)
            {
                if (supplyCheckBoxes[i].Checked)
                    supplies.Add(i);
            }

            storeCheckout.SuppliesList = supplies;
        }

        //This event handler updates the selected furniture on its own without the use of any buttons.
        private void lbxFurn_SelectedIndexChanged(object sender, EventArgs e)
        {
            storeCheckout.FurnIndex = lbxFurn.SelectedIndex;
        }

        private void btnComputer_Click(object sender, EventArgs e)
        {
            ComputerOrder computerOrder = new ComputerOrder();
            ComputerOrderForm computerOrderForm = new ComputerOrderForm(computerOrder);            
            DialogResult compDialog = computerOrderForm.ShowDialog();

            //When the computer order window is closed by clicking the X, the summary TextBox is updated.
            //TODO: need to check for DialogResult.OK. RJG
            //if (compDialog == DialogResult.Cancel)
            if (compDialog == DialogResult.OK)
            {

                CheckBoxesToSummary();//Makes sure any checkmarked office supplies are included in the summary.
                storeCheckout.CompOrder = computerOrder;//storeCheckout receives updated changes from Form.
                //TODO: Place this in a computer order text box. The summary one should have the full order. RJG
                //txbSummary.Text = storeCheckout.ToString();
                txbCompOrder.Text = computerOrder.GetOrderSummary();
            }
        }

        private void btnOrder_Click(object sender, EventArgs e)
        {
            CheckBoxesToSummary();
            txbSummary.Text = storeCheckout.ToString();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            InitializeForm();
        }
    }
}
