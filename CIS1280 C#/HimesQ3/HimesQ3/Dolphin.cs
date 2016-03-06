// Dolphin.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Inheritance and Polymorphism quiz

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesQ3
{
    class Dolphin : ZooAnimal
    {
        #region
        private string name = "I'm a dolphin! Wee!!";
        private string habitat = "I'd *prefer* to live in the ocean.";
        private string food = "I mainly eat fish, but sometimes I eat seaweed (by accident).";
        #endregion

        #region
        public override string getName()
        {
            return name;
        }

        public override string getHabitat()
        {
            return habitat;
        }

        public override string getFood()
        {
            return food;
        }
        #endregion
    }
}
