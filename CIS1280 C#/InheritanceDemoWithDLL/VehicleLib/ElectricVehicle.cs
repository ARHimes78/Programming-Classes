using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VehicleLib
{
    public class ElectricVehicle : Vehicle
    {
        public double BateryCapacity { get; set; }
        public double MilesKWh { get; set; }
        public double TimeToCharge { get; set; }

        public ElectricVehicle()
            : base()
        {
            BateryCapacity = 10;
            MilesKWh = 10;
            TimeToCharge = 10;
        }

        public ElectricVehicle(int wheels, double maxSpeed, double maxCargo, 
            double battery, double miles, double time) : base(wheels, maxSpeed, maxCargo)
        {
            BateryCapacity = battery;
            MilesKWh = miles;
            TimeToCharge = time;
        }

        public override string ToString()
        {
            return base.ToString()
                + "I am also an electric powered vehicle. My battery capacity is "
                + BateryCapacity + " KWh. I get "
                + MilesKWh + " miles per KWh. My time to charge is "
                + TimeToCharge + " hours";
        }
    }
}
