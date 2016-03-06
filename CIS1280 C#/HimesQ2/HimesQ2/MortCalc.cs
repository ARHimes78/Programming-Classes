// MortCalc.cs 
// Programmer: Alan Himes
// Email: ahimes1@cnm.edu
// Purpose: Fix broken code

using System;

namespace HimesQ2
{
    class MortCalc
    {
        private double m, i, p, loanCost, interestPaid;
        private int q,numOfMonths,n;

        public MortCalc()        
        {
            //default constructor
            i = 1.0;
            p = i;
            q = 12; 
            n = 1;
            numOfMonths = q * n;
        }

        public MortCalc( double interest, double principal, int numOfYrs)
        {
            //overloaded constructor 
            i = interest/100;
            p = principal;
            n = numOfYrs;

            //Included assigments of q and numOfMonths, they're needed in Calc(). -ARH
            q = 12;
            numOfMonths = q * n;

            //Added call to calc() -ARH
            calc();
        }

        public double Interest
        {
            //Changed "Interest" to backing field "i" -ARH
            get { return i; }
            //Changed setting to i to value divided by 100. -ARH
            set { i = value/100; calc(); }           
        }

        public double Principal
        {
            //Changed "Principal" to backing field "p" -ARH
            get { return p; }
            set { p = value; calc(); }            
        }

        public int NumOfYrs
        {
            //Changed "NumOfYrs" to backing field "n" -ARH
            get { return n; }
            set { n = value; calc(); }            
        }

        public double Monthly
        {
            //Changed "Monthly" to backing field "m" -ARH
            get { return m; }
        }

        public double TotalLoanCost
        {
            //Changed "TotalLoanCost" to backing field "loanCost" -ARH
            get { return loanCost; }
        }

        public double TotalInterestPaid
        {
            //Changed "TotalInterestPaid" to backing field "interestPaid" -ARH
            get { return interestPaid; }
        }

        private void calc()
        {
            numOfMonths = q * n;
            double a = 0.0; //extra var for math
            a = (1 - (Math.Pow((1+(i/q)),(-1 * n * q))));
            m = (p * i) / (q * a); // monthly payment
            loanCost = m * numOfMonths;
            interestPaid = loanCost - p; 
        }
    }
}

