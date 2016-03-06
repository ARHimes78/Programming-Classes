// Coverter.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Inches to feet and yard converter
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesE2
{
    public class Converter
    {
        public static void Main()
        {
            Header();

            int inches;
            string another = "";

            do
            {
                //yards is not initialized because it will be passed as "out". Re-initializes upon repeat.
                int newInches = 0;
                int feet = 0;
                int yards;

                Console.Write("\nEnter an amount in inches: ");
                inches = int.Parse(Console.ReadLine());

                ConvertToFeet(inches, ref newInches, ref feet);

                Console.WriteLine("\n" + inches + " inches = " + feet + " feet and " + newInches + " inches,");
                Console.WriteLine("or,");

                //Running the two methods back to back could change the feet value.
                ConvertToYards(inches, ref newInches, ref feet, out yards);

                Console.WriteLine(yards + " yards, " + feet + " feet and " + newInches + " inches.");

                //Prompt user for another inches converter
                Console.Write("\nConvert to inches again? (y/n): ");
                another = Console.ReadLine();

            } while (another[0].ToString().ToLower() == "y");

            Console.WriteLine("\nBye!");
        }

        private static void Header()
        {
            //program header
            Console.WriteLine("Alan Himes");
            Console.WriteLine("Exercise 2: Converter.cs");
            Console.WriteLine("Inches to feet converter");
        }

        //TODO: -3 use more verbose parameter names. RJG
        private static void ConvertToFeet(int i, ref int nI, ref int ft)
        {
            if (i >= 12)
            {
                ft = i / 12;
                nI = i % 12;
            }
            else
            {
                nI = i;
            }
        }

        private static void ConvertToYards(int i, ref int nI, ref int ft, out int yds)
        {
            /*
            It's redundant but ConvertToFeet() is being called again here
            because the inches have already been calculated. If the user wanted only
            yards, feet and inches, only ConvertToYards() would need to be called.
            If anything, it's for the sake of doing something with the first 2 arguments of this method.
            */
            ConvertToFeet(i, ref nI, ref ft);

            if (ft >= 3)
            {
                yds = ft / 3;
                ft = ft % 3;
            }
            else
            {
                yds = 0;//the out int needs to be initialized either way.
            }
        }
    }
}