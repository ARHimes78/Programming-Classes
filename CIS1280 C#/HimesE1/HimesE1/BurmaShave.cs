// BurmaShave.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Display Burma Shave rhymes according to user input

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesE1
{
    class BurmaShave
    {
        static void Main(string[] args)
        {
            //program header
            Console.WriteLine("Alan Himes");
            Console.WriteLine("Exercise 1: Burma Shave");
            Console.WriteLine("Display Burma Shave rhymes according to user input");

            string another = "";
            do
            {
                //Menu of choices for user
                Console.WriteLine("\nChoose 1, 2 or 3 to show a Burma-Shave rhyme.");
                Console.WriteLine("--------------------------------------------.");
                Console.WriteLine("1: \"Cheer up face\"");
                Console.WriteLine("2: \"Train approaching\"");
                Console.WriteLine("3: \"Don't take\"");

                bool validChoice = false; //initialized to false if the user chooses to go again.
                string choice;
                
                //loops until 1, 2 or 3 is selected.
                while (!validChoice)
                {
                    choice = Console.ReadLine();

                    if (choice == "1")
                    {
                        validChoice = true;
                        //Burma Shave rhymes found on wikipedia.org
                        Console.WriteLine("\nCheer up face");
                        Console.WriteLine("The war is past");
                        Console.WriteLine("The \"H\" is out");
                        Console.WriteLine("Of shave");
                        Console.WriteLine("At last");
                        Console.WriteLine("Burma-Shave");
                    }
                    else if (choice == "2")
                    {
                        validChoice = true;
                        Console.WriteLine("\nTrain approaching");
                        Console.WriteLine("Whistle squealing");
                        Console.WriteLine("Stop");
                        Console.WriteLine("Avoid that run-down feeling");
                        Console.WriteLine("Burma-Shave");
                    }
                    else if (choice == "3")
                    {
                        validChoice = true;
                        Console.WriteLine("\nDon't take");
                        Console.WriteLine("a curve");
                        Console.WriteLine("at 60 per.");
                        Console.WriteLine("We hate to lose");
                        Console.WriteLine("a customer");
                        Console.WriteLine("Burma-Shave");
                    }
                    else
                    {
                        //validChoice remains false, loop repeats.
                        Console.WriteLine("Please choose 1, 2 or 3.");
                    }
                }

                //prompt user for another Burma-Shave rhyme
                Console.Write("\nDo you want to go again (y/n)? ");
                another = Console.ReadLine();
            } while (another == "y" || another == "Y");

            Console.WriteLine("Goodbye!");
        }
    }
}
