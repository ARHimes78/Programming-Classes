// ZooForm.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Inheritance and Polymorphism quiz

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HimesQ3
{
    public partial class ZooForm : Form
    {
        ZooAnimal[] zoo;
        RadioButton[] animalChoices; 

        public ZooForm()
        {
            InitializeComponent();
            zoo = new ZooAnimal[] { new Lion(), new Python(), new Dolphin() };
            animalChoices = new RadioButton[] { rdbLion, rdbPython, rdbDolphin };
        }

        private void btnObserve_Click(object sender, EventArgs e)
        {            
            for (int i = 0; i < zoo.Length; i++)
            {
                if (animalChoices[i].Checked)
                    txbSummary.Text = zoo[i].getName()+"\r\n"+zoo[i].getHabitat()+"\r\n"+zoo[i].getFood();
            }
        }
    }
}
