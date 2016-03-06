// Weapon.cs 
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
    public abstract class Weapon
    {
        public abstract double ProbabilityOfHits();

        public Weapon(int range, int wind, int visibility, int rounds)
        {
            Range = range;
            Wind = wind;
            Visibility = visibility;
            Rounds = rounds;
        }

        #region
        public abstract string Name { get; set; }
        public int Range { get; set; }
        public int Wind { get; set; }
        public int Visibility { get; set; }
        public int Rounds { get; set; }
        #endregion

        #region
        public int ComputeHits()
        {
            return (int)Math.Round(Rounds * ProbabilityOfHits() * ComputeWind() * ComputeVis());
        }
        public double ComputeVis()
        {
            switch (Visibility) //visibility is in yards
            {
                //Each case corresponds to Visibility combobox elements 1-5.
                case 0: // "clear day"
                    return 1;
                case 1: // "clear night"
                    return .9;
                case 2: // "dusk"
                    return .6;
                case 3: // "fog"
                    return .5;
                case 4: // "smoke"
                    return .7;
                default:
                    return 1;
            }
        }
        public double ComputeWind()
        {
            switch (Wind) //wind is in mph
            {
                    //changed the cases to correspond to Wind combobox elements.
                case 0:
                    return 1;
                case 1:
                    return .9;
                case 2:
                    return .8;
                case 3:
                    return .75;
                case 4:
                    return .7;
                case 5:
                    return .65;
                default:
                    return 1;
            }
        }
        #endregion
    }
}
