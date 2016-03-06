using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesQ1
{
    class Mileage
    {
        private double miles;
        private double gallons;
        private double mpg;

        //Constructors
        public Mileage() : this(0.0, 0.0) {}

        public Mileage(double miles, double gallons)
        {
            //Constructor parameters assigned to the properties.
            Miles = miles;
            Gallons = gallons;

            Calculate();//TODO: Call private void calculate method. RJG
        }

        //Properties
        public double Miles
        {
            get
            {
                return miles;
            }
            set
            {
                miles = value;
                //TODO: -5 call calculate method from sets that affect other fields. RJG
                Calculate();
            }
        }

        public double Gallons
        {
            get
            {
                return gallons;
            }
            set
            {
                gallons = value;
                //TODO: call calculate method from sets that affect other fields. RJG
                Calculate();
            }
        }

        public double MPG
        {
            get
            {
                return mpg;
            }
            //TODO: -3 should not provide set for MPG. RJG
            //set
            //{
            //    mpg = value;
            //}
        }

        //Calculate method

        //TODO: -5 calculates must be private void and parameterless. RJG
        //private double calculate(double miles, double gallons)
        private void Calculate()
        {
            //miles divided by gallon = miles per gallon
            //Assigning results of calculation to mpg's property.
            mpg = miles / gallons;
            //return MPG;
        }
    }
}
