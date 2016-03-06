using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MetricConversion
{
    /// <summary>
    /// Program: MetricConversion
    /// Date: 21040520
    /// Programmer: Rob Garner (email: aperson@aserver.net)
    /// Purpose: Converts user input in inches to cm
    /// </summary>
    class Program
    {
        static void Main(string[] args)
        {
            //Start Loop
            string doAnother;
            do
            {

                //Get number of inches to convert from user
                Console.Write("Please enter number of inches to convert: ");
                string inchesToConvert = Console.ReadLine();

                //Check to see if input is a number
                double inches;
                if (double.TryParse(inchesToConvert, out inches))
                {
                    //If number convert to cm
                    Console.WriteLine("Centimeters: " + ConvertInToCm(inches));
                }
                else
                {
                    //If not number display error message
                    Console.WriteLine("Not a number! Can't convert!");
                }

                //Ask "Do another? (y/n)
                Console.Write("Do another (y/n): ");
                doAnother = Console.ReadLine();

                //Loop back if y
            } while (doAnother == "y");
        }

        //function to convert in to cm
        private static double ConvertInToCm(double inches)
        {
            return inches * 2.54;
        }
    }

}
