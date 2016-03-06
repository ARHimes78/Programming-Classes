// Python.cs 
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
    class Python : ZooAnimal
    {
        #region
        private string name = "Yo, python here.";
        private string habitat = "I live mostly in swampy areas, I guess.";
        private string food = "I basically eat rodents, but sometimes I like a small mammal every now and then.";
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
