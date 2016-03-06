using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextBoxControls
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            btnOk.Enabled = false;
        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            string output;

            output = " Name: " + txbName.Text + "\r\n";
            output += " Address: " + txbAddress.Text + "\r\n"; ;
            output += " Occupation: " + txbOccupation.Text + "\r\n"; ;
            output += " Age: " + txbAge.Text + "\r\n"; ;
        }

        private void btnHelp_Click(object sender, EventArgs e)
        {
            string output;

            output = " Name = Your name\r\n";
            output += " Address = Your address\r\n";
            output += " Occupation = Your occupation\r\n";
            output += " Age = Your age\r\n";

            txbOutput.Text = output;
        }

        private void textBoxEmpty(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text.Length == 0)
                tb.BackColor = Color.Red;
            else
                tb.BackColor = System.Drawing.SystemColors.Window;

            ValidateOK();
        }

        private void txbAge_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8)
                e.Handled = true;
        }

        private void TextBoxOccupation(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb.Text == "Programmer" || tb.Text.Length == 0)
                tb.BackColor = System.Drawing.SystemColors.Window;
            else
                tb.BackColor = Color.Red;
            ValidateOK();
        }

        private void ValidateOK()
        {
            btnOk.Enabled = (txbName.BackColor != Color.Red &&
                txbAddress.BackColor != Color.Red &&
                txbOccupation.BackColor != Color.Red &&
                txbAge.BackColor != Color.Red);
        }

    }
}
