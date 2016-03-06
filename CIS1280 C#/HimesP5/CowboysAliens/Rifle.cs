// Rifle.cs 
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
    public class Rifle : Weapon
    {
        public Rifle (int range, int wind, int visibility, int rounds) : base(range, wind, visibility, rounds)
        {
            Name = "Rifle";
        }

        public override string Name { get; set; }

        public override double ProbabilityOfHits()
        {
            switch (Range)
            {
                case 0:
                    return .99;
                case 1:
                    return .8;
                case 2:
                    return .7;
                case 3:
                    return .6;
                case 4:
                    return .5;
                case 5:
                    return .4;
                default:
                    return 0.0;
            }
        }
    }
}
