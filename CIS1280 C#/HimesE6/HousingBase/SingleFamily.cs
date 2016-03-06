// SingleFamily.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Property Manager

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HousingBase
{
    public class SingleFamily : HousingBase
    {
        int squareFeet;
        bool garage;
        string singleFamilyInfo;
        string subDivName;
        bool porch;
        string style;
        decimal rentAmount;

        public SingleFamily() : base()
        {
            squareFeet = 800;
            garage = false;
            singleFamilyInfo = "This is a single family unit.";
            subDivName = "Default Subdivision";
            porch = false;
            style = "Normal";
            rentAmount = 1000;
        }

        public SingleFamily(int year, string address, string structure, string builder,
            string cleaning, string info, string fire, int sqFeet, bool garage,
            string sfInfo, string sdName, bool porch, string style, decimal amount)
            : base(year, address, structure, builder, cleaning, info, fire)
        {
            squareFeet = sqFeet;
            this.garage = garage;
            singleFamilyInfo = sfInfo;
            subDivName = sdName;
            this.porch = porch;
            this.style = style;
            rentAmount = amount;
        }

        public string Address
        {
            get
            {
                //Address stored in parent class.
                return address;
            }
            set
            {
                address = value;
            }
        }

        public string SingleFamilyInfo
        {
            get
            {
                return singleFamilyInfo;
            }
            set
            {
                singleFamilyInfo = value;
            }
        }

        public override string RentalAmount()
        {
            decimal earnings = rentAmount * 12;
            string amountInfo = base.RentalAmount() + string.Format("{0:C}", earnings);
            return amountInfo;
        }
    }
}
