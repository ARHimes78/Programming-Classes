using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InheritanceDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Vehicle genericVehicle = new Vehicle();
            genericVehicle.Wheels = 3;
            genericVehicle.MaxCargo = 1000.00;
            genericVehicle.MaxSpeed = 150.00;

            Console.WriteLine("Generic Vehicle: {0}", genericVehicle.ToString());

            GasPoweredVehicle gasVehicle = new GasPoweredVehicle();
            gasVehicle.Wheels = 4;
            gasVehicle.MaxCargo = 100.00;
            gasVehicle.MaxSpeed = 200.00;
            gasVehicle.GallonsGas = 30.00;
            gasVehicle.MPG = 24.00;
            gasVehicle.DriveWheels = 4;//Added to show extra part of the string

            Console.WriteLine("Gas Vehicle: {0}", gasVehicle.ToString());
        }
    }
}
