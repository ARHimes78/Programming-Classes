// ComputerOrderForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Office supply store

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesP4
{
    public partial class ComputerOrderForm : Form
    {
        //The radio buttons and checkboxes are stored in arrays for ease of 
        //initializing and obtaining values with for loops.
        private RadioButton[] driveRadioButtons;
        private RadioButton[] memoryRadioButtons;
        private CheckBox[] periphCheckBoxes;

        private ComputerOrder compOrder;//added to P4

        public ComputerOrderForm() : this(new ComputerOrder())
        {        
        }

        public ComputerOrderForm(ComputerOrder compOrder)
        {
            InitializeComponent();
            this.compOrder = compOrder;

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

        public ComputerOrder CompOrder
        {
            get { return compOrder; }
            set { compOrder = value; }
        }

        private void InitializeForm()
        {
            //Using Computer object to initialize parts of the form.

            //Initializing the combobox with the values from the motherboard string.
            string[] mboard = new string[4];
            string[] drive = new string[4];
            string[] memory = new string[4];
            string[] periph = new string[5];

            for (int i = 0; i < mboard.Length; i++)
            {
                compOrder.MboardOptionIndex = i;
                compOrder.DriveOptionIndex = i;
                compOrder.MemoryOptionIndex = i;
                mboard[i] = compOrder.MboardOptions + " $" + compOrder.MboardPrice;
                drive[i] = compOrder.DriveOptions + " $" + compOrder.DrivePrice;
                memory[i] = compOrder.MemoryOptions + " $" + compOrder.MemoryPrice;
            }

            for (int i = 0; i < periph.Length; i++)
            {
                compOrder.PeriphOptionIndex = i;
                periph[i] = compOrder.PeriphOptions + " $" + compOrder.PeriphPrice;
            }

            cbxMotherboard.Items.Clear();//Without this the items will duplicate themselves with each "Clear" click.
            cbxMotherboard.Items.AddRange(mboard);
            cbxMotherboard.SelectedIndex = cbxMotherboard.Items.Count - 1;

            for (int i = 0; i < driveRadioButtons.Length; i++)
            {
                driveRadioButtons[i].Text = drive[i];
                memoryRadioButtons[i].Text = memory[i];
            }

            //Make sure the last of each radio button group ("None") is selected.
            driveRadioButtons[driveRadioButtons.Length - 1].Select();
            memoryRadioButtons[memoryRadioButtons.Length - 1].Select();

            for (int i = 0; i < periphCheckBoxes.Length; i++)
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
            compOrder.MboardOptionIndex = cbxMotherboard.SelectedIndex;

            for (int i = 0; i < driveRadioButtons.Length; i++)
            {
                if (memoryRadioButtons[i].Checked)
                {
                    compOrder.MemoryOptionIndex = i;
                }

                if (driveRadioButtons[i].Checked)
                {
                    compOrder.DriveOptionIndex = i;
                }
            }

            List<int> periphChoice = new List<int>();

            for (int i = 0; i < periphCheckBoxes.Length; i++)
            {
                if (periphCheckBoxes[i].Checked)
                {
                    periphChoice.Add(i);
                }
            }

            compOrder.PeriphList = periphChoice;

            rtbSummary.Text = compOrder.GetOrderSummary();
            //TODO: -3 need to set dialog result to ok and close form. RJG
            this.DialogResult = DialogResult.OK;
            this.Close();

        }
    }
}
