// BankFormr.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Bank Account program using Exceptions

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesE4
{
    public partial class BankForm : Form
    {
        BankAccount bank;
        public BankForm()
        {
            InitializeComponent();
            bank = new BankAccount();
        }

        private void btnAccount_Click(object sender, EventArgs e)
        {


            try
            {
                /*I couldn't find a way null could be inadvertently passed as an argument to one of
                    BankAccount's properties or methods. A blank TextBox has a blank string,
                    not a null value.
                    Passing null to anything expecting a decimal datatype isn't allowed,
                    and passing null to set the AccountName property or one of the overloaded
                    constructors did not cause an ArgumentNullException.
                    This program will pretend a blank string is a null
                    and throw the exception, and do the same with the Add/Deduct buttons.*/
                if (txbName.Text == "" || txbAmount.Text == "")
                {
                    throw new ArgumentNullException();
                }

                bank.AccountName = txbName.Text;
                bank.Balance = Decimal.Parse(txbAmount.Text);
                lblBalance.Text = bank.ToString();

                //Show Add/Deduct buttons.
                btnAdd.Visible = true;
                btnDeduct.Visible = true;
                btnAccount.Visible = false;
            }
            //Customized exception class
            catch (NegativeException ne)
            {
                ShowError(ne);
            }
            catch (ArgumentNullException ane)
            {
                ShowError(ane);
            }
            //If non-number has been input
            catch (FormatException fe)
            {
                ShowError(fe);
            }
            //If input number is too high or low for a decimal datatype
            catch (OverflowException oe)
            {
                ShowError(oe);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (txbAmount.Text == "")
                {
                    throw new ArgumentNullException();
                }
                bank.IncreaseBalance(Decimal.Parse(txbAmount.Text));
                lblBalance.Text = bank.ToString();
            }
            catch (NegativeException ne)
            {
                ShowError(ne);
            }
            catch (ArgumentNullException ae)
            {
                ShowError(ae);
            }
            catch (FormatException fe)
            {
                ShowError(fe);
            }
            catch (OverflowException oe)
            {
                ShowError(oe);
            }
        }

        private void btnDeduct_Click(object sender, EventArgs e)
        {
            try
            {
                if (txbAmount.Text == "")
                {
                    throw new ArgumentNullException();
                }
                bank.DecreaseBalance(Decimal.Parse(txbAmount.Text));
                lblBalance.Text = bank.ToString();
            }
            catch (NegativeException ne)
            {
                ShowError(ne);
            }
            catch (ArgumentNullException ae)
            {
                ShowError(ae);
            }
            catch (FormatException fe)
            {
                ShowError(fe);
            }
            catch (OverflowException oe)
            {
                ShowError(oe);
            }
        }

        private void ShowError(Exception e)
        {
            MessageBox.Show(e.ToString(), e.Message);
            txbAmount.Clear();
        }
    }
}
