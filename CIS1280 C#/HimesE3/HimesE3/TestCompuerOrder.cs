// TestComputerOrder.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Revision of P2, accessors/mutators changed to properties
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesP2
{
    class TestComputerOrder
    {
        public static void Main(string[] args)
        {
            Header();

            string another = "";

            do
            {
                ComputerOrder order = new ComputerOrder();
                int mbChoice;
                int memChoice;
                int driveChoice;

                //Take input from user, pass into ComputerOrder object to be used as array indexes.
                Console.WriteLine(order.GetMboardMenu());
                Console.Write("Please choose a motherboard (1-4): ");
                mbChoice = Convert.ToInt32(Console.ReadLine());
                order.MboardOptionIndex = mbChoice;
                Console.WriteLine("\n{0} selected.", order.MboardOptions);

                Console.WriteLine(order.GetMemoryMenu());
                Console.Write("Please choose memory (1-4): ");
                memChoice = Convert.ToInt32(Console.ReadLine());
                order.MemoryOptionIndex = memChoice;
                Console.WriteLine("\n{0} selected.", order.MemoryOptions);

                Console.WriteLine(order.GetDriveMenu());
                Console.Write("Please choose a hard drive (1-4): ");
                driveChoice = Convert.ToInt32(Console.ReadLine());
                order.DriveOptionIndex = driveChoice;
                Console.WriteLine("\n{0} selected.", order.DriveOptions);

                int periphChoice;
                int limit = 0;
                List<int> periphOrderList = new List<int>();
                periphOrderList.Clear();

                //Loop will continue so user can add up to 99 peripherals or finish shopping by choosing "6".
                do
                {
                    Console.WriteLine(order.GetPeripheralsMenu());
                    Console.Write("Please choose a peripheral (1-6): ");
                    periphChoice = Convert.ToInt32(Console.ReadLine());
                    if (periphChoice >= 6)//Choice 6 to finish shopping
                    {
                        order.PeriphOptionIndex = periphChoice;
                        break;
                    }
                    else
                    {
                        order.PeriphOptionIndex = periphChoice;

                        periphOrderList.Add(periphChoice - 1);
                        Console.WriteLine("\n{0} added.", order.PeriphOptions);

                        /*
                        Created ComputerOrder method FromPeriphList(int) so a list of every peripheral selected 
                        could be shown after each choice.
                        */
                        Console.Write("\nSelected peripherals so far: ");
                        for (int i = 0; i < periphOrderList.Count(); i++)
                        {
                            if (i == periphOrderList.Count() - 1)
                                Console.Write(order.FromPeriphList(periphOrderList[i]) + ".\n");
                            else
                                Console.Write(order.FromPeriphList(periphOrderList[i]) + ", ");
                        }
                        limit++;
                    }
                } while (limit < 99);

                order.PeriphList = periphOrderList;
                Console.WriteLine(order.GetOrderSummary());

                //Prompt user for another computer parts purchase
                Console.Write("\nPlace another order for computer parts? (y/n): ");
                another = Console.ReadLine();
            } while (another[0].ToString().ToLower() == "y");

            Console.WriteLine("\nBye!");
            Console.ReadLine();
        }

        private static void Header()
        {
            //program header
            Console.WriteLine("Alan Himes");
            Console.WriteLine("Program 2: TestComputerOrder.cs");
            Console.WriteLine("Revision of P2, accessors/mutators changed to properties\n");
        }
    }
}