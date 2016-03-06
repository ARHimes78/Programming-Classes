using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TaxApp
{
    public partial class TaxForm : Form
    {
        public TaxForm()
        {
            InitializeComponent();
        }

        private void btnCompute_Click(object sender, EventArgs e)
        {
            string inValue;
            double purchaseAmt, percent, ans;

            while (!double.TryParse(txtPurchase.Text, out purchaseAmt))
            {
                MessageBox.Show("value entered must be numeric!");
                txtPurchase.Text = "0.0";
                txtPurchase.Focus();
            }

            inValue = lblTaxPercent.Text;
            inValue = inValue.Remove(inValue.Length - 1, 1);
            percent = double.Parse(inValue) / 100;

            ans = (purchaseAmt * percent) + purchaseAmt;
            txtTotalDue.Text = string.Format("{0:C}", ans).ToString();
        }
    }
}
