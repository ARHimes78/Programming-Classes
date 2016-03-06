// StoreCheckout.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Office supply store

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesP4
{
    class StoreCheckout
    {
        private int furnIndex;
        private static string[] furniture = new string[] 
            {"Table", "Couch", "Chair", "Desk", "Futon", "Foot rest", "None"};
        private static double[] furnPrices = new double[] 
            {52.99, 299.99, 30.95, 75.45, 149.99, 49.99, 0};

        private List<int> suppliesList;
        private int suppliesIndex;
        private static string[] supplies = new string[]
            {"Pens", "Markers", "Pencils", "Pencil sharpener", "Highlighters", 
            "Correction tape", "Erasers", "Folders", "Tape", "Label maker", "None"};
        private static double[] suppliesPrices = new double[]
            {3.89, 23.99, 6.39, 19.79, 8.39, 4.99, 2.29, 7.49, 4.49, 39.99, 0};

        private double furnitureTotal;
        private double suppliesTotal;
        private double computerTotal;
        private double grandTotal;

        private ComputerOrder compOrder;

        #region
        //Constructor
        public StoreCheckout()
        {
            compOrder = new ComputerOrder();
            compOrder.MboardOptionIndex = 3;
            compOrder.DriveOptionIndex = 3;
            compOrder.MemoryOptionIndex = 3;
            compOrder.PeriphOptionIndex = 5;

            suppliesList = new List<int>();

            furnIndex = 0;
            suppliesIndex = 0;
            furnitureTotal = 0.0;
            suppliesTotal = 0.0;
            computerTotal = 0.0;
        }
        #endregion

        #region
        //Properties
        public int FurnIndex
        {
            get
            {
                return furnIndex;
            }
            set
            {
                furnIndex = value;
                Calculate();
            }
        }

        public List<int> SuppliesList
        {
            get
            {
                return suppliesList;
            }
            set
            {
                suppliesList = value;
                Calculate();
            }
        }

        public int SuppliesIndex
        {
            get
            {
                return suppliesIndex;
            }
            set
            {
                suppliesIndex = value;
                Calculate();
            }
        }

        public string Furniture
        {
            get
            {
                return furniture[furnIndex];
            }
        }

        public string Supplies
        {
            get
            {
                return supplies[suppliesIndex];
            }
        }

        public double FurnPrices
        {
            get
            {
                return furnPrices[furnIndex];
            }
        }

        public double SuppliesPrices
        {
            get
            {
                return suppliesPrices[suppliesIndex];
            }
        }

        public ComputerOrder CompOrder
        {
            get { return compOrder; }
            set 
            { 
                compOrder = value;
                Calculate();
            }
        }
        #endregion

        #region
        //Private methods
        private void Calculate()
        {
            furnitureTotal = 0.0;
            furnitureTotal += FurnPrices;

            suppliesTotal = 0.0;
            for (int i = 0; i < suppliesList.Count(); ++i)
            {
                suppliesTotal += suppliesPrices[suppliesList[i]];
            }
            //TODO: -3 don't do this in the store class. Just make a public property for price in
            //the computer class and use that. RJG
            //computerTotal = 0.0;
            //computerTotal += compOrder.MboardPrice;
            //computerTotal += compOrder.DrivePrice;
            //computerTotal += compOrder.MemoryPrice;

            //double periphPrice = 0.0;

            //for (int i = 0; i < compOrder.PeriphList.Count(); i++)
            //{
            //    compOrder.PeriphOptionIndex = compOrder.PeriphList[i];
            //    periphPrice += compOrder.PeriphPrice;
            //}
            //computerTotal += periphPrice;
            computerTotal = compOrder.TotalPrice;
            grandTotal = furnitureTotal + suppliesTotal + computerTotal;
        }

        public override string ToString()
        {
            string summary = "";
            summary += "Selected furniture:\r\n";
            summary += Furniture + ": " + string.Format("{0:C}",FurnPrices);

            summary += "\r\n\r\nOffice supplies:\r\n";
            if (suppliesList.Count() == 0)
            {
                SuppliesIndex = 10;
                summary += Supplies + ": " + string.Format("{0:C}", SuppliesPrices);
            }

            for (int i = 0; i < suppliesList.Count(); ++i)
            {
                SuppliesIndex = suppliesList[i];                
                if (i == suppliesList.Count() - 1)
                    summary += Supplies + ": " + string.Format("{0:C}", SuppliesPrices);
                else
                    summary += Supplies + ": " + string.Format("{0:C}", SuppliesPrices) + "\r\n";
            }

            summary += "\r\n\r\nComputer order:\r\n";
            summary += compOrder.GetOrderSummary();
            summary += "\r\n\r\n" + "Grand total: " + string.Format("{0:C}", grandTotal);
            return summary;
        }
        #endregion
    }
}
