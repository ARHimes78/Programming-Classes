// Program.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Fix broken code

using System;

namespace HimesQ2
{
    class Program
    {
        static void Main(string[] args)
        {
            double prin, interest;
            int years;

            Console.WriteLine(" \n\n Welcome to the C# Mortgage Calculator \n" +
                " This Program will demonstrate using both a parameterless\n" +
                " and an overloaded constructor to calculate monthly\n" +
                " payment, total interest paid over the life of the loan,\n" +
                " and the total loan cost.");

            MortCalc calc = new MortCalc();  // instantiate parameterless constructor

            //Get user information
            Console.Write(" \n Please enter the principal of your loan : $");
            prin = Convert.ToDouble(Console.ReadLine());
            calc.Principal = prin;

            Console.Write(" \n Please enter the interest rate in %: ");
            interest = Convert.ToDouble(Console.ReadLine());
            calc.Interest = interest;

            Console.Write(" \n Please enter the duration of your loan in years: ");
            //Changed Convert method from ToDouble() to ToInt32(), years will be assigned to an int in calc. -ARH
            years = Convert.ToInt32(Console.ReadLine());
            calc.NumOfYrs = years;            

            MortCalc mc = new MortCalc(interest,prin, years);   //instantiate overloaded constructor

            //Report results
            Console.WriteLine("\n\n Parameterless Constructor");
            Console.WriteLine("\n Your monthly payment will be: {0}" + 
                " \n Your total interest to be paid will be: {1}" +
                //Added a , to complete the string in line below -ARH
                "\n Your total loan to be paid will be: {2}",
                calc.Monthly.ToString("c"), calc.TotalInterestPaid.ToString("c"), calc.TotalLoanCost.ToString("c"));

            Console.WriteLine("\n\n Overloaded Constructor");
            Console.WriteLine("\n Your monthly payment will be: {0}" +
                " \n Your total interest to be paid will be: {1}" +
                //Added a , to complete the string in line below -ARH
                "\n Your total loan to be paid will be: {2}",
                mc.Monthly.ToString("c"), mc.TotalInterestPaid.ToString("c"), mc.TotalLoanCost.ToString("c"));


        }
    }
}
