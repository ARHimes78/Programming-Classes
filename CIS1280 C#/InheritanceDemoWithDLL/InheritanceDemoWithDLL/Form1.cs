using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using VehicleLib;

namespace InheritanceDemoWithDLL
{
    public partial class Form1 : Form
    {
        GasPoweredVehicle gv = new GasPoweredVehicle(4, 100, 1000, 25, 25, 4);
        ElectricVehicle ev = new ElectricVehicle(3, 200, 500, 25, 60, 10);

        public Form1()
        {
            InitializeComponent();
        }

        private void btnGas_Click(object sender, EventArgs e)
        {
            if (btnGas.Text == "Gas Vehicle")
            {
                btnGas.Text = "Electric Vehicle";
                textBox1.Text = "" + ev;
            }
            else
            {
                btnGas.Text = "Gas Vehicle";
                textBox1.Text = "" + gv;
            }
        }
    }
}
