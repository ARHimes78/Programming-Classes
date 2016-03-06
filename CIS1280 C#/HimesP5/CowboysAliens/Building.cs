// Building.cs 
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
    public class Building : Location, IHidingPlace
    {
        public Building(string name) : base(name)
        {
        }

        public string HidingPlaceName { get; set; }

        public override string Description
        {
            get
            {
                return base.Description;
            }
            set
            {
                base.Description = value;
            }
        }
    }
}
