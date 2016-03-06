// BlenderForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Using Input Form Filters

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesE5
{
    public partial class BlenderForm : Form
    {
        public BlenderForm()
        {
            InitializeComponent();
            btnOrder.Enabled = false;
        }

        private void TextBoxEmpty(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text == "")
            {
                tb.BackColor = Color.Red;
            }
            else
            {
                tb.BackColor = System.Drawing.SystemColors.Window;
            }
            ValidateOrder();
        }

        private void TextBoxState(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            string[] states = new string[] 
            {"al", "ak", "az", "ar", "ca", "co", "ct", "de", "fl", "ga", 
            "hi", "id", "il", "in", "ia", "ks", "ky", "la", "me", "md",
            "ma", "mi", "mn", "ms", "mo", "mt", "ne", "nv", "nh", "nj",
            "nm", "ny", "nc", "nd", "oh", "ok", "or", "pa", "ri", "sc",
            "sd", "tn", "tx", "ut", "vt", "va", "wa", "wv", "wi", "wy"};

            //Compare input with array of the state abbreviations.
            for (int i=0; i<50; ++i)
            {
                if (tb.Text.ToLower() != states[i])
                    tb.BackColor = Color.Red;
                else
                {
                    tb.BackColor = System.Drawing.SystemColors.Window;
                    break;
                }
            }
            ValidateOrder();
        }

        private void TextBoxZip(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;
            int numCheck;

            //Check to see if numbers were input, and if so, see if they're 5 digits.
            if (!int.TryParse(tb.Text, out numCheck))
                tb.BackColor = Color.Red;
            else
            {
                if (tb.Text.Length != 5)
                    tb.BackColor = Color.Red;
                else
                    tb.BackColor = System.Drawing.SystemColors.Window;
            }

            ValidateOrder();
        }

        private void txbQty_KeyPress(object sender, KeyPressEventArgs e)
        {
            //Only numbers and backspace input are allowed.
            if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8)
                e.Handled = true;
        }

        private void btnOrder_Click(object sender, EventArgs e)
        {
            try
            {
                double price = int.Parse(txbQty.Text) * 59.95;
                double tax = price * .07;
                double pricePlusTax = price + tax;

                string summary = "Name: " + txbName.Text + "\r\n"
                    + "Address: " + txbAddress.Text + "\r\n"
                    + "State: " + txbState.Text + "\r\n"
                    + "Zip code: " + txbZip.Text + "\r\n"
                    + "Quanitiy: " + txbQty.Text + "\r\n\r\n"
                    + "Amount due: " + string.Format("{0:C}", price) + "\r\n"
                    + "Sales tax: " + string.Format("{0:C}", tax) + "\r\n"
                    + "Net due: " + string.Format("{0:C}", pricePlusTax);

                txbSummary.Text = summary;                
            }
            
            catch (OverflowException oe)
            {
                MessageBox.Show(oe.ToString(), oe.Message);
            }            
        }

        private void ValidateOrder()
        {
            btnOrder.Enabled = (txbName.BackColor != Color.Red
                && txbAddress.BackColor != Color.Red
                && txbCity.BackColor != Color.Red
                && txbState.BackColor != Color.Red
                && txbZip.BackColor != Color.Red
                && txbQty.BackColor != Color.Red);
        }        
    }
}
