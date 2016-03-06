// ZooAnimal.cs 
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
    public abstract class ZooAnimal
    {
        #region
        public abstract string getName();
        public abstract string getHabitat();
        public abstract string getFood();
        #endregion
    }
}
