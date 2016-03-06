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
    public partial class SQLCommandDemo : Form
    {
        public SQLCommandDemo()
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
                SqlDataReader dr = cmd.ExecuteReader();
                while (dr.Read())
                {
                    Dog newDog = new Dog();
                    newDog.DogID = int.Parse(dr["pkDogID"].ToString());
                    newDog.Breed = dr["breed"].ToString();
                    newDog.Color = dr["color"].ToString();
                    newDog.Age = int.Parse(dr["age"].ToString());
                    newDog.Sex = dr["sex"].ToString();
                    newDog.Weight = float.Parse(dr["weight"].ToString());
                    newDog.Birthday = DateTime.Parse(dr["birthday"].ToString());
                    string[] newRow = { newDog.DogID.ToString(), newDog.Breed, newDog.Color };
                    dgvDogs.Rows.Add(newRow);
                }

            }

        }

    }
}
