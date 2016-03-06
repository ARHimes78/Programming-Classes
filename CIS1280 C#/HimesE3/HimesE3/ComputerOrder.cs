// ComputerOrder.cs 
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
    public class ComputerOrder
    {
        //copied computer parts and their prices from newegg.com
        //Instantiated the static arrays along with their declarations as suggested.
        private int mboardOptionIndex;
        private static string[] mboardOptions = new string[]
			{
				"ASUS Z97-A LGA 1150 Intel Motherboard",
				"GIGABYTE GA-Z97X-UD5H-BK LGA 1150 Intel Motherboard",
				"ASUS CROSSBLADE RANGER FM2+ AMD Motherboard",
				"None"
			};
        private static double[] mboardPrice = new double[] { 144.99, 184.99, 152.99, 0.00 };

        private int memoryOptionIndex;
        private static string[] memoryOptions = new string[]
			{
				"Team Elite Plus 8GB (2 x 4GB) 240-Pin DDR3 SDRAM",
				"G.SKILL 4GB (2 x 2GB) 240-Pin DDR2 SDRAM",
				"CORSAIR XMS 4GB (2 x 2GB) 240-Pin DDR3 SDRAM",
				"None"
			};
        private static double[] memoryPrice = new double[] { 67.99, 64.99, 52.99, 0.00 };

        private int driveOptionIndex;
        private static string[] driveOptions = new string[]
			{
				"HGST Deskstar 6TB 7200 RPM SATA 6.0Gb/s 3.5\"",
				"WD BLACK SERIES 3TB 7200 RPM 64MB Cache SATA 6.0Gb/s 3.5\"",
				"Seagate Barracuda 1TB 7200 RPM 64MB Cache SATA 6.0Gb/s 3.5\"",
				"None"
			};
        private static double[] drivePrice = new double[] { 299.99, 164.99, 52.49, 0.00 };

        private List<int> periphList = new List<int>();
        private static string[] periphOptions = new string[]
			{
				"Keyboard",
				"Mouse",
				"Speakers",
				"Joystick",
				"Microphone",
				"I have finished shopping."
			};
        private static float[] periphPrice = new float[] { 29.99f, 59.99f, 23.35f, 31.99f, 39.99f, 0.00f };

        private double totalPrice;
        private int periphOptionIndex;//Used for the peripheral array elements, has get method.

        public ComputerOrder()
        {
            mboardOptionIndex = 0;
            memoryOptionIndex = 0;
            driveOptionIndex = 0;
            periphOptionIndex = 0;
            totalPrice = 0.0;
        }

        //------------------Properties

        public int MboardOptionIndex
        {
            get
            {
                return mboardOptionIndex;
            }
            set
            {
                mboardOptionIndex = IndexCheckComponents(value - 1);
                CalculatePrice();
            }
        }

        public int MemoryOptionIndex
        {
            get
            {
                return memoryOptionIndex;
            }
            set
            {
                memoryOptionIndex = IndexCheckComponents(value - 1);
                CalculatePrice();
            }
        }

        public int DriveOptionIndex
        {
            get
            {
                return driveOptionIndex;
            }
            set
            {
                driveOptionIndex = IndexCheckComponents(value - 1);
                CalculatePrice();
            }
        }

        public int PeriphOptionIndex
        {
            get
            {
                return periphOptionIndex;
            }
            set
            {
                periphOptionIndex = IndexCheckPeripherals(value - 1);
                CalculatePrice();
            }
        }

        public List<int> PeriphList
        {
            get
            {
                return periphList;
            }
            set
            {
                periphList = value;
                CalculatePrice();
            }
        }

        //Only elements of the string arrays are set/get, not the entire arrays.
        public string MboardOptions
        {
            get
            {
                return mboardOptions[mboardOptionIndex];
            }
            set
            {
                mboardOptions[mboardOptionIndex] = value;//these will never be called
            }
        }

        //public double GetMboardPrice()
        //{
        //    return mboardPrice[mboardOptionIndex];
        //}

        public double MboardPrice
        {
            get
            {
                return mboardPrice[mboardOptionIndex];
            }
            set
            {
                mboardPrice[mboardOptionIndex] = value;
            }
        }

        public string MemoryOptions
        {
            get
            {
                return memoryOptions[memoryOptionIndex];
            }
            set
            {
                memoryOptions[memoryOptionIndex] = value;
            }
        }

        public double MemoryPrice
        {
            get
            {
                return memoryPrice[memoryOptionIndex];
            }
            set
            {
                memoryPrice[memoryOptionIndex] = value;
            }
        }

        public string DriveOptions
        {
            get
            {
                return driveOptions[driveOptionIndex];
            }
            set
            {
                driveOptions[driveOptionIndex] = value;
            }
        }

        public double DrivePrice
        {
            get
            {
                return drivePrice[driveOptionIndex];
            }
            set
            {
                drivePrice[driveOptionIndex] = value;
            }
        }

        public string PeriphOptions
        {
            get
            {
                return periphOptions[periphOptionIndex];
            }
            set
            {
                periphOptions[periphOptionIndex] = value;
            }
        }

        public float PeriphPrice
        {
            get
            {
                return periphPrice[periphOptionIndex];
            }
            set //TODO: -2 dangerous way to change periphPrice array. If you had two programmers writing code they may not realize they
                //are changing the static PeriphPrice array when they think they are changing the price of just the order. RJG
            {
                periphPrice[periphOptionIndex] = value;
            }
        }

        public string FromPeriphList(int item)
        {
            return periphOptions[item];
        }

        public string GetMboardMenu()
        {
            string mbMenu = "MOTHERBOARD MENU:\n";
            for (int i = 0; i < mboardOptions.Count()-1; i++)
            {
                mbMenu += i + 1;
                mbMenu += ": " + mboardOptions[i] + " $" + mboardPrice[i] + "\n";
            }
            mbMenu += "4: " + mboardOptions[3] + "\n";

            return mbMenu;
        }

        public string GetMemoryMenu()
        {
            string memMenu = "\nMEMORY MENU:\n";
            for (int i = 0; i < memoryOptions.Count()-1; i++)
            {
                memMenu += i + 1;
                memMenu += ": " + memoryOptions[i] + " $" + memoryPrice[i] + "\n";
            }
            memMenu += "4: " + memoryOptions[3] + "\n";

            return memMenu;
        }

        public string GetDriveMenu()
        {
            string driveMenu = "\nHARD DRIVE MENU:\n";
            for (int i = 0; i < driveOptions.Count()-1; i++)
            {
                driveMenu += i + 1;
                driveMenu += ": " + driveOptions[i] + " $" + drivePrice[i] + "\n";
            }
            driveMenu += "4: " + driveOptions[3] + "\n";

            return driveMenu;
        }

        public string GetPeripheralsMenu()
        {
            string periphMenu = "\nPERIPHERALS MENU:\n";
            for (int i = 0; i < periphOptions.Count()-1; i++)
            {
                periphMenu += i + 1;
                periphMenu += ": " + periphOptions[i] + " $" + periphPrice[i] + "\n";
            }
            periphMenu += "6: " + periphOptions[5] + "\n";

            return periphMenu;
        }

        public string GetOrderSummary()
        {
            string summary = "\n\nORDER SUMMARY:\n";
            summary += MboardOptions + " $" + MboardPrice + "\n";
            summary += MemoryOptions + " $" + MemoryPrice + "\n";
            summary += DriveOptions + " $" + DrivePrice + "\n";

            summary += "Peripherals:\n";
            if (periphList.Any())//A summary of peripherals bought will only be shown if any were bought.
            {
                for (int i = 0; i < periphList.Count(); i++)
                {
                    summary += periphOptions[periphList[i]] + " $" + periphPrice[periphList[i]] + "\n";
                }
            }
            else
                summary += "None\n";

            //Changing the format of the total before appending to the summary string.
            string total = string.Format("{0:C}", totalPrice);
            summary += "\nTotal: " + total;

            return summary;
        }

        private int IndexCheckComponents(int index)
        {
            /*Using mboardOptions.Count() for upper limit, but this method is also used for
            memoryOptions and driveOptions which also have 4 array elements.*/
            if (index < 0 || index > mboardOptions.Count()-1)
            {
                Console.WriteLine("\nInvalid choice, selected \"None\".");//TODO: -3 do not write from class. Later we will learn to throw exceptions. RJG
                return 3;
            }
            else
                return index;
        }

        private int IndexCheckPeripherals(int index)
        {
            if (index < 0 || index > periphOptions.Count()-1)
            {
                Console.WriteLine("\nInvalid choice. You're done!");
                return 5;
            }
            else
                return index;
        }

        private void CalculatePrice()
        {
            totalPrice = 0;//reset every time
            totalPrice += MboardPrice;
            totalPrice += MemoryPrice;
            totalPrice += DrivePrice;

            float price = 0.0f;
            for (int i = 0; i < periphList.Count(); i++)
            {
                price += periphPrice[periphList[i]];
            }
            totalPrice += (double)price;

        }
    }
}