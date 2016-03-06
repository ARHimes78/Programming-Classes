// Alien.cs 
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
    public class Alien
    {
        private Random random;
        private int alienLocation;

        #region
        public Alien(int startingLocation)
        {
            alienLocation = startingLocation;
            random = new Random();
        }
        #endregion

        #region
        public int AlienLocation
        {
            get { return alienLocation; }
            set { alienLocation = value; }
        }
        #endregion

        #region
        public void Move()
        {
            alienLocation = random.Next(0,7);
        }

        public bool Check()
        {
            if (random.Next(0,2) == 0)
                return false;
            else
                return true;
        }
        #endregion
    }
}