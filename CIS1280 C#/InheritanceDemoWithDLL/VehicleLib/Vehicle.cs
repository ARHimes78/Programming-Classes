using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VehicleLib
{
    public class Vehicle
    {
        public int Wheels { get; set; }
        public double MaxSpeed { get; set; }
        public double MaxCargo { get; set; }

        public Vehicle() : this(0, 500, 2000)
        {
        }

        public Vehicle(int wheels, double maxSpeed, double maxCargo)
        {
            Wheels = wheels;
            MaxSpeed = maxSpeed;
            MaxCargo = maxCargo;
        }

        public override string ToString()
        {
            return "I am a vehicle. I have "
                + Wheels + " wheels, a max speed of "
                + MaxSpeed + " miles per hour, and a max cargo of "
                + MaxCargo + " lbs.";
        }
    }
}
