// MultiUnit.cs 
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
    public class MultiUnit : HousingBase
    {
        private int units;
        private string complexName;
        private decimal rentAmount;
        private string multiUnitInfo;

        public MultiUnit() : base()
        {
            units = 2;
            complexName = "Default Complex";
            rentAmount = 2500;
            multiUnitInfo = "This is a multi-unit.";
        }

        public MultiUnit(int year, string address, string structure, string builder,
            string cleaning, string info, string fire, int units, string name, 
            decimal amount, string multiInfo) : base(year, address, structure,
            builder, cleaning, info, fire)
        {
            this.units = units;
            complexName = name;
            rentAmount = amount;
            multiUnitInfo = multiInfo;
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

        public string MultiUnitInfo
        {
            get
            {
                return multiUnitInfo;
            }
            set
            {
                multiUnitInfo = value;
            }
        }

        public int Units
        {
            get
            {
                return units;
            }
            set
            {
                units = value;
            }
        }

        public override string RentalAmount()
        {
            decimal earnings = rentAmount * 12 * units; 
            string amountInfo = base.RentalAmount() + string.Format("{0:C}",earnings);
            return amountInfo;
        }
    }
}
