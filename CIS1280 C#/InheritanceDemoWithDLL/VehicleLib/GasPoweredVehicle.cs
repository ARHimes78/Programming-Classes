using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VehicleLib
{
    public class GasPoweredVehicle : Vehicle
    {
        public double GallonsGas { get; set; }
        public double MPG { get; set; }
        public int DriveWheels { get; set; }

        public GasPoweredVehicle()
            : base()
        {
            GallonsGas = 100;
            MPG = 20;
            DriveWheels = 4;
        }

        public GasPoweredVehicle(int wheels, double maxSpeed, double maxCargo, 
            double gallonsGas, double mpg, int driveWheels) : base(wheels, maxSpeed, maxCargo)
        {
            GallonsGas = gallonsGas;
            MPG = mpg;
            DriveWheels = driveWheels;
        }

        public bool allWheelDrive
        {
            get { return DriveWheels == Wheels; }
        }

        public override string ToString()
        {
            return base.ToString()
                + "I am also a gas powered vehicle. I can carry "
                + GallonsGas + " gallons of gas. I get "
                + MPG + " miles per gallon."
                + (allWheelDrive ? " I am also all-wheel drive!" : "");
        }
    }
}
