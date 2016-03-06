// AliensGauntlet.cs 
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
    public class AlienGauntlet : Weapon
    {
        public AlienGauntlet (int range, int wind, int visibility, int rounds) : base(range, wind, visibility, rounds)
        {
            Name = "Alien Gauntlet";
        }

        public override string Name { get; set; }

        public override double ProbabilityOfHits()
        {
            switch (Range)
            {
                case 0:
                    return .7;
                case 1:
                    return .9;
                case 2:
                    return .9;
                case 3:
                    return .85;
                case 4:
                    return .8;
                case 5:
                    return .7;
                default:
                    return 0.0;
            }
        }
    }
}
