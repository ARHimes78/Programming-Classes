// Form1.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Revision of P2/E3, using a form.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesP3
{
    public partial class Form1 : Form
    {
        //The radio buttons and checkboxes are stored in arrays for ease of 
        //initializing and obtaining values with for loops.
        RadioButton[] driveRadioButtons;
        RadioButton[] memoryRadioButtons;
        CheckBox[] periphCheckBoxes;

        public Form1()
        {
            InitializeComponent();

            driveRadioButtons = new RadioButton[]
            {
                rbHardDrive1, rbHardDrive2, rbHardDrive3, rbHardDrive4
            };
            memoryRadioButtons = new RadioButton[]
            {
                rbMemory1, rbMemory2, rbMemory3, rbMemory4
            };
            periphCheckBoxes = new CheckBox[]
            {
                chbPeriph1, chbPeriph2, chbPeriph3, chbPeriph4, chbPeriph5
            };

            InitializeForm();//Custom method added to Form1.            
        }

        private void InitializeForm()
        {
            //Using Computer object to initialize parts of the form.
            Computer comp = new Computer();

            //Initializing the combobox with the values from the motherboard string.
            string[] mboard = new string[4];
            string[] drive = new string[4];
            string[] memory = new string[4];
            string[] periph = new string[5];

            for (int i=0; i<mboard.Length; i++)
            {
                comp.MboardOptionIndex = i;
                comp.DriveOptionIndex = i;
                comp.MemoryOptionIndex = i;
                mboard[i] = comp.MboardOptions + " $" + comp.MboardPrice;
                drive[i] = comp.DriveOptions + " $" + comp.DrivePrice;
                memory[i] = comp.MemoryOptions + " $" + comp.MemoryPrice;
            }

            for (int i=0; i<periph.Length; i++)
            {
                comp.PeriphOptionIndex = i;
                periph[i] = comp.PeriphOptions + " $" + comp.PeriphPrice;
            }

            cbxMotherboard.Items.Clear();//Without this the items will duplicate themselves with each "Clear" click.
            cbxMotherboard.Items.AddRange(mboard);
            cbxMotherboard.SelectedIndex = cbxMotherboard.Items.Count - 1;
            
            for (int i=0; i<driveRadioButtons.Length; i++)
            {
                driveRadioButtons[i].Text = drive[i];
                memoryRadioButtons[i].Text = memory[i];
            }

            //Make sure the last of each radio button group ("None") is selected.
            driveRadioButtons[driveRadioButtons.Length - 1].Select();
            memoryRadioButtons[memoryRadioButtons.Length - 1].Select();

            for (int i=0; i<periphCheckBoxes.Length; i++)
            {
                periphCheckBoxes[i].Text = periph[i];
            }

            //Uncheck all CheckBoxes.
            foreach (CheckBox check in periphCheckBoxes)
            {
                check.Checked = false;
            }

            rtbSummary.Clear();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            InitializeForm();
        }

        private void btnOrder_Click(object sender, EventArgs e)
        {
            Computer comp = new Computer();
      
            comp.MboardOptionIndex = cbxMotherboard.SelectedIndex;

            for (int i=0; i<driveRadioButtons.Length; i++)
            {
                if (memoryRadioButtons[i].Checked)
                {
                    comp.MemoryOptionIndex = i;
                }

                if (driveRadioButtons[i].Checked)
                {
                    comp.DriveOptionIndex = i;
                }                
            }

            List<int> periphChoice = new List<int>();

            for (int i=0; i<periphCheckBoxes.Length; i++)
            {
                if (periphCheckBoxes[i].Checked)
                {
                    periphChoice.Add(i);
                }
            }

            comp.PeriphList = periphChoice;

                rtbSummary.Text = comp.GetOrderSummary();
        }
    }
}
