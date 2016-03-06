using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data.SqlClient;

namespace DatabaseDemo
{
    public partial class DataAdapterDemo : Form
    {
        DataTable dt;

        public DataAdapterDemo()
        {
            InitializeComponent();
            BindData();
        }

        private void BindData()
        {
            string connStr = ConfigurationManager.ConnectionStrings["DemoDBConnectionString"].ConnectionString;

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                conn.Open();
                SqlCommand cmd = new SqlCommand("SELECT * FROM tblDog", conn);
                SqlDataAdapter da = new SqlDataAdapter(cmd);
                dt = new DataTable();
                da.Fill(dt);
                dgvDogs.DataSource = dt; //source
            }
        }

        private void UpdateDB()
        {
            string connStr = ConfigurationManager.ConnectionStrings["DemoDBConnectionString"].ConnectionString;
            string insStr = "INSERT INTO tblDog (breed, color, age, sex, weight) " + "VALUES (@breed, @color, @age, @sex, @weight)";
            string delStr = "DELETE FROM tblDog WHERE pkDogID = @DogID";
            string updStr = "UPDATE tblDog "
                            + "SET breed = @breed, color = @color, age = @age, sex = @sex, "
                            + "weight = @weight WHERE pkDogID = @DogID";

            using (SqlConnection conn = new SqlConnection(connStr))
            {
                SqlCommand insCmd = new SqlCommand(insStr);
                insCmd.Parameters.Add("@breed", SqlDbType.NVarChar, 10, "breed");
                insCmd.Parameters.Add("@color", SqlDbType.NVarChar, 10, "color");
                insCmd.Parameters.Add("@age", SqlDbType.NVarChar, 10, "age");
                insCmd.Parameters.Add("@sex", SqlDbType.NVarChar, 10, "sex");
                insCmd.Parameters.Add("@weight", SqlDbType.NVarChar, 10, "weight");
                insCmd.Connection = conn;
                insCmd.UpdatedRowSource = UpdateRowSource.None;

                SqlCommand delCmd = new SqlCommand(delStr);
                delCmd.Parameters.Add("@DogID", SqlDbType.Int, 4, "pkDogID");
                delCmd.Connection = conn;
                delCmd.UpdatedRowSource = UpdateRowSource.None;

                SqlCommand updCmd = new SqlCommand(updStr);
                updCmd.Parameters.Add("@DogID", SqlDbType.Int, 4, "pkDogID");
                updCmd.Parameters.Add("@breed", SqlDbType.NVarChar, 10, "breed");
                updCmd.Parameters.Add("@color", SqlDbType.NVarChar, 10, "color");
                updCmd.Parameters.Add("@age", SqlDbType.NVarChar, 10, "age");
                updCmd.Parameters.Add("@sex", SqlDbType.NVarChar, 10, "sex");
                updCmd.Parameters.Add("@weight", SqlDbType.NVarChar, 10, "weight");
                updCmd.Connection = conn;
                updCmd.UpdatedRowSource = UpdateRowSource.None;


                conn.Open();
                SqlDataAdapter da = new SqlDataAdapter();
                da.InsertCommand = insCmd;
                da.DeleteCommand = delCmd;
                da.UpdateCommand = updCmd;
                da.Update(dt);
            }
            BindData();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            DataRow dr = dt.NewRow();
            dr["breed"] = txbBreed.Text;
            dr["color"] = txbColor.Text;
            dr["age"] = int.Parse(txbAge.Text);
            dr["weight"] = float.Parse(txbWeight.Text);
            dt.Rows.Add(dr);

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            UpdateDB();
        }


    }
}
