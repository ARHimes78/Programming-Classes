// Lion.cs 
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
    class Lion : ZooAnimal
    {
        #region
        private string name = "I'm a lion, how ya doin'.";
        private string habitat = "I live in jungles (I'm the king there, but the other lions are also kings) and large fields with tall grass to stalk prey in.";
        private string food = "I eat clueless zebras, antelopes, etc.";
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
