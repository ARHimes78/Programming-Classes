// Alan Himes
// ahimes1@cnm.edu
// Form1.cs Mileage calculator

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesQ1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
            Mileage mileage;

            double miles;
            double gallons;

            //Obtain values through TryParse check in case of "unparseable" input.
            if (!Double.TryParse(txbMiles.Text, out miles))
                miles = 0;
            if (!Double.TryParse(txbGallons.Text, out gallons))
                gallons = 0;

            //Mileage's  constructor calls the calculate() method.
            mileage = new Mileage(miles, gallons);

            txbMPG.Text = mileage.MPG.ToString();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txbMiles.Clear();
            txbGallons.Clear();
            txbMPG.Clear();
        }
    }
}
