using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InheritanceDemo
{
    class GasPoweredVehicle : Vehicle
    {
        public double GallonsGas { get; set; }
        public double MPG { get; set; }
        public int DriveWheels { get; set; }

        public bool allWheelDrive
        {
            get { return DriveWheels == Wheels; }
        }

        public override string ToString()
        {
            return base.ToString()
                + " I am also a gas powered vehicle. I can carry "
                + GallonsGas + " gallons of gas. I get "
                + MPG + " miles per gallon."
    + (allWheelDrive ? " I am also all-wheel drive!" : ""); ;
        }

    }
}
