// ComputerOrder.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Computer parts store simulator
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesP2
{
    public class ComputerOrder
    {
        private int mboardOptionIndex;
        private static string[] mboardOptions;
        private static double[] mboardPrice;

        private int memoryOptionIndex;
        private static string[] memoryOptions;
        private static double[] memoryPrice;

        private int driveOptionIndex;
        private static string[] driveOptions;
        private static double[] drivePrice;

        private List<int> periphList;
        private static string[] periphOptions;
        private static float[] periphPrice;

        private double totalPrice;
        private int periphOptionIndex;//Used for the peripheral array elements, has get method.

        public ComputerOrder()
        {
            mboardOptionIndex = 0;
            memoryOptionIndex = 0;
            driveOptionIndex = 0;
            periphOptionIndex = 0;

            //copied computer parts and their prices from newegg.com
            //TODO: To avoid initializing static values each time an onbject is instantiated you can initialize these.
            //in the declarations above or use a static constructor. RJG.

            mboardOptions = new string[]
			{
				"ASUS Z97-A LGA 1150 Intel Motherboard",
				"GIGABYTE GA-Z97X-UD5H-BK LGA 1150 Intel Motherboard",
				"ASUS CROSSBLADE RANGER FM2+ AMD Motherboard",
				"None"
			};
            mboardPrice = new double[] { 144.99, 184.99, 152.99, 0.00 };
            memoryOptions = new string[]
			{
				"Team Elite Plus 8GB (2 x 4GB) 240-Pin DDR3 SDRAM",
				"G.SKILL 4GB (2 x 2GB) 240-Pin DDR2 SDRAM",
				"CORSAIR XMS 4GB (2 x 2GB) 240-Pin DDR3 SDRAM",
				"None"
			};
            memoryPrice = new double[] { 67.99, 64.99, 52.99, 0.00 };
            driveOptions = new string[]
			{
				"HGST Deskstar 6TB 7200 RPM SATA 6.0Gb/s 3.5\"",
				"WD BLACK SERIES 3TB 7200 RPM 64MB Cache SATA 6.0Gb/s 3.5\"",
				"Seagate Barracuda 1TB 7200 RPM 64MB Cache SATA 6.0Gb/s 3.5\"",
				"None"
			};
            drivePrice = new double[] { 299.99, 164.99, 52.49, 0.00 };
            periphList = new List<int>();
            periphList.Clear(); //TODO: your list will start off clear this is not needed. RJG
            periphOptions = new string[]
			{
				"Keyboard",
				"Mouse",
				"Speakers",
				"Joystick",
				"Microphone",
				"I have finished shopping."
			};
            periphPrice = new float[] { 29.99f, 59.99f, 23.35f, 31.99f, 39.99f, 0.00f };

            totalPrice = 0.0;
        }

        public void SetMboard(int index)
        {
            mboardOptionIndex = IndexCheckComponents(index - 1);
            CalculatePrice();
        }

        public void SetMemory(int index)
        {
            memoryOptionIndex = IndexCheckComponents(index - 1);
            CalculatePrice();
        }

        public void SetDrive(int index)
        {
            driveOptionIndex = IndexCheckComponents(index - 1);
            CalculatePrice();
        }

        public void SetList(List<int> periphs)
        {
            periphList = periphs;
            CalculatePrice();//the last time the price is calculated
        }

        public void SetPeriph(int index)
        {
            periphOptionIndex = IndexCheckPeripherals(index - 1);
            CalculatePrice();
        }

        //TODO: -2 need get methods for the index fields per spec. 
        //These are good additions but we will need the getters for the indexes as well. RJG
        public string GetMboardOptions()
        {
            return mboardOptions[mboardOptionIndex];
        }

        public double GetMboardPrice()
        {
            return mboardPrice[mboardOptionIndex];
        }

        public string GetMemoryOptions()
        {
            return memoryOptions[memoryOptionIndex];
        }

        public double GetMemoryPrice()
        {
            return memoryPrice[memoryOptionIndex];
        }

        public string GetDriveOptions()
        {
            return driveOptions[driveOptionIndex];
        }

        public double GetDrivePrice()
        {
            return drivePrice[driveOptionIndex];
        }

        public string GetPeriphOptions()
        {
            return periphOptions[periphOptionIndex];
        }

        public float GetPeriphPrice()
        {
            return periphPrice[periphOptionIndex];
        }

        public string FromPeriphList(int item)
        {
            return periphOptions[item];
        }

        //TODO: Use array count method rather than hard coding upper limits of arrays.
        //This will make it easier to maintain the class if you change the options latter. RJG
        public string GetMboardMenu()
        {
            string mbMenu = "MOTHERBOARD MENU:\n";
            for (int i = 0; i < 3; i++)
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
            for (int i = 0; i < 3; i++)
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
            for (int i = 0; i < 3; i++)
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
            for (int i = 0; i < 5; i++)
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
            summary += GetMboardOptions() + " $" + GetMboardPrice() + "\n";
            summary += GetMemoryOptions() + " $" + GetMemoryPrice() + "\n";
            summary += GetDriveOptions() + " $" + GetDrivePrice() + "\n";

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

        //TODO: rather than hard coding the upper limit consider useing the Array.Count method. RJG
        private int IndexCheckComponents(int index)
        {
            if (index < 0 || index > 3)
            {
                Console.WriteLine("\nInvalid choice, selected \"None\".");
                return 3;
            }
            else
                return index;
        }

        private int IndexCheckPeripherals(int index)
        {
            if (index < 0 || index > 5)
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
            totalPrice += GetMboardPrice();
            totalPrice += GetMemoryPrice();
            totalPrice += GetDrivePrice();

            float price = 0.0f;
            for (int i = 0; i < periphList.Count(); i++)
            {
                price += periphPrice[periphList[i]];
            }
            totalPrice += (double)price;

        }
    }
}