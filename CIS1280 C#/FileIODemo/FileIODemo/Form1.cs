using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace FileIODemo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            saveFileDialogText.ShowDialog();
            string filename = saveFileDialogText.FileName;            
            try
            {
                using (StreamWriter outFile = new StreamWriter(filename))
                {
                    outFile.Write(txbText.Text);
                    outFile.Close();
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message);
            }
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            openFileDialogText.ShowDialog();

            string inValue;
            try
            {
                txbText.Text = "";
                using (StreamReader inFile = new StreamReader(openFileDialogText.FileName))
                {
                    while ((inValue = inFile.ReadLine()) != null)
                    {
                        txbText.Text = inValue + "\r\n";
                    }
                }
            }
            catch (FileNotFoundException exc)
            {
                MessageBox.Show(exc.Message);
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message);
            }
        }
    }
}
