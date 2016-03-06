// Outside.cs 
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
    public class Outside : Location
    {
        public Outside(string name)
            : base(name)
        {
        }

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
