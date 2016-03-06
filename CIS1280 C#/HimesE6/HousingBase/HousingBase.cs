// HousingBase.cs 
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
    public class HousingBase
    {
        private int yearBuilt;
        protected string address;//Protected so the subclasses could use it.
        private string structureType;
        private string builder;
        private string cleaningCrewNameNum;
        private string housingInfo;
        private string fireHistory;
        
        public HousingBase()
            : this(1980, "123 Main Street", "House", "Builder's Building Inc.",
                "Default Cleaning Crew #7", "Has walls, ceilings, plumbing and electricity", 
                "Not TOO many fires have happened")
        {
        }

        public HousingBase(int year, string address, string structure, string builder, 
            string cleaning, string info, string fire)
        {
            yearBuilt = year;
            this.address = address;
            structureType = structure;
            this.builder = builder;
            cleaningCrewNameNum = cleaning;
            housingInfo = info;
            fireHistory = fire;
        }

        public virtual string RentalAmount()
        {

            return "Total projected rental amount: ";
        }
    }
}
