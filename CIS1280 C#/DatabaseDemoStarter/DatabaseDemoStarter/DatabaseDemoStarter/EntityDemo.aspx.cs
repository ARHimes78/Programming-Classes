using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace DatabaseDemoStarter
{
    public partial class EntityDemo : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                BindData();
            }

        }        

        protected void GridView1_RowEditing(object sender, GridViewEditEventArgs e)
        {
            //Put GridView into edit mode and bind data
            GridView1.EditIndex = e.NewEditIndex;
            BindData();

        }

        protected void GridView1_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            //Take GridView out of edit mode and bind data
            GridView1.EditIndex = -1;
            BindData();

        }

        protected void GridView1_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            //Instantiate an entity object that points to our db
            DemoDBEntities dbe = new DemoDBEntities();

            //Find the employee row in the db
            tblEmployee employee = dbe.tblEmployees.Find(e.Keys["pkEmployeeID"]);

            //Update the employee's fields
            employee.Name = e.NewValues["Name"].ToString();
            //employee.website = e.NewValues["website"].ToString();
            employee.website = e.NewValues["website"] == null ? null : e.NewValues["website"].ToString();

            //Save changes in db
            dbe.SaveChanges();

            //Take GridView out of edit mode
            GridView1.EditIndex = -1;

            //Rebind our data to our GridView
            BindData();
        }        

        protected void GridView1_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            //Instantiate an entity object that points to our db
            DemoDBEntities dbe = new DemoDBEntities();

            //Find the employee row in the db
            tblEmployee employee = dbe.tblEmployees.Find(e.Keys["pkEmployeeID"]);

            //Remove that row
            dbe.tblEmployees.Remove(employee);

            //Save changes in db
            dbe.SaveChanges();

            //Rebind our data to our GridView
            BindData();

        }
        
        protected void btnSubmit_Click(object sender, EventArgs e)
        {
            //Instantiate an entity object that points to our db
            DemoDBEntities dbe = new DemoDBEntities();

            //Create a new employee
            tblEmployee employee = new tblEmployee();

            //Update the employee's fields
            employee.Name = txbName.Text;
            employee.website = txbWebsite.Text == null ? null : txbWebsite.Text;

            //Add our new employee:
            dbe.tblEmployees.Add(employee);

            //Save changes in db
            dbe.SaveChanges();

            //Rebind our data to our GridView
            BindData();
        }

        private void BindData()
        {
            //Instantiate an entity object that points to our db
            DemoDBEntities dbe = new DemoDBEntities();

            //Just point the grids data source to the appropriate 
            //table object converted to a list
            GridView1.DataSource = dbe.tblEmployees.ToList();
            GridView1.DataBind();
        }

    }
}