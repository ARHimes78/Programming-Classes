// Location.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Create Cowboys and Aliens game

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CowboysAliens
{
    public abstract class Location
    {
        private string name;
        private string description;

        #region
        public Location(string name)
        {
            this.name = name;
        }
        #endregion

        #region
        public string Name
        {
            get {return name;}
        }

        public virtual string Description
        {
            get {return description;}
            set {description = value;}
        }
        #endregion
    }
}
