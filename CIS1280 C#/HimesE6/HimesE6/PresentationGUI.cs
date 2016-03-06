// PresentationGUI.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Property Manager

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using HousingBase;

namespace HimesE6
{
    public partial class PresentationGUI : Form
    {
        private MultiUnit multi;
        private SingleFamily single;

        public PresentationGUI()
        {
            InitializeComponent();
            multi = new MultiUnit();
            multi.Address = "12700 Multi Houses St.";
            multi.MultiUnitInfo = "Two bedroom, Two bathroom";
            multi.Units = 3;

            single = new SingleFamily();
            single.Address = "3885 That Way Rd.";
            single.SingleFamilyInfo = "Two bedroom, One bathroom";
        }

        private void rbMulti_CheckedChanged(object sender, EventArgs e)
        {
            gbxInfo.Text = rbMulti.Text;

            string summary = "Address: " + multi.Address + "\r\n";
            summary += "Specification: " + multi.MultiUnitInfo + "\r\n";
            summary += "Number of units: " + multi.Units + "\r\n\r\n";
            summary += multi.RentalAmount();

            txbInfo.Text = summary;
        }

        private void rbSingle_CheckedChanged(object sender, EventArgs e)
        {
            gbxInfo.Text = rbSingle.Text;

            string summary = "Address: " + single.Address + "\r\n";
            summary += "Specification: " + single.SingleFamilyInfo + "\r\n\r\n";
            summary += single.RentalAmount();

            txbInfo.Text = summary;
        }
    }
}
