// StoreDisplayForm.axpx.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Database on a web form

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace HimesP6
{
    public partial class StoresWebForm : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                lblError.Text = "";
                sdsStores.Insert();
            }
            catch (Exception ex)
            {
                lblError.Text = "Error: " + ex;
            }
        }

        protected void BtnClear_Click(object sender, EventArgs e)
        {
            txbName.Text = "";
            txbAddress.Text = "";
            txbPhone.Text = "";
            txbCity.Text = "";
            txbState.Text = "";
            txbZip.Text = "";
            txbHours.Text = "";
        }
    }
}