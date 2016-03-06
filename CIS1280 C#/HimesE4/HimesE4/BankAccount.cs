using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesE4
{
    class BankAccount
    {
        private string accountName;
        private decimal balance;

        #region
        //Constructors
        public BankAccount() : this("", 0)
        {
        }

        public BankAccount(string name) : this(name, 0)
        {
        }

        public BankAccount(string name, decimal bal)
        {
            accountName = name;
            balance = bal;
        }
        #endregion

        #region
        //Properties
        public string AccountName
        {
            get
            {
                return accountName;
            }
            set
            {
                accountName = value;
            }
        }

        public decimal Balance
        {
            get
            {
                return balance;
            }
            set
            {
                if (value < 0)
                {
                    throw new NegativeException();
                }
                balance = value;
            }
        }
        #endregion

        #region
        //Methods
        public void IncreaseBalance(decimal bal)
        {
            if (bal < 0)
            {
                throw new NegativeException();
            }
            balance += bal;
        }

        public void DecreaseBalance(decimal bal)
        {
            if (bal < 0)
            {
                throw new NegativeException();
            }
            balance -= bal;
        }

        public override string ToString()
        {
            string transaction = AccountName + "'s balance:\n\n $" + balance;
            return transaction;
        }
        #endregion
    }
}
