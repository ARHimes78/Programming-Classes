using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentClassDemo
{
    class Student
    {
        //-------------------------------------
        //Private Fields
        //-------------------------------------

        private int score1;
        private int score2;
        private int score3;
        
        //-------------------------------------
        //Constructors
        //-------------------------------------

        //default constructor
        public Student()
            : this("Number Pending", "TBD", "TBD", "Undeclared")
        {
        }

        //single parameter constructor
        public Student(string sID)
            : this(sID, "TBD", "TBD", "Undeclared")
        {
        }

        //constructor when we have student ID information and major
        public Student(string sID, string firstName, string lastName, string maj)
        {
            StudentNumber = sID;
            FirstName = firstName;
            LastName = lastName;
            Major = maj;
        }

        //constructor when we have student information and score information
        public Student(string sID, string firstName, string lastName,
            int s1, int s2, int s3, string maj)
            : this(sID, firstName, lastName, maj)
        {
            score1 = s1;
            score2 = s2;
            score3 = s3;
            CalcAverage();
        }

        //-------------------------------------
        //Properties
        //-------------------------------------
        public string Major { get; set; }

        public int Score1
        {
            get
            {
                return score1;
            }
            set
            {
                if (value >= 0 && value <= 100)
                {
                    score1 = value;
                }
                else
                {
                    score1 = 0;
                }
                CalcAverage();
            }
        }

        public int Score2
        {
            get
            {
                return score2;
            }
            set
            {
                if (value >= 0 && value <= 100)
                {
                    score2 = value;
                }
                else
                {
                    score2 = 0;
                }
                CalcAverage();
            }
        }

        public int Score3
        {
            get
            {
                return score3;
            }
            set
            {
                if (value >= 0 && value <= 100)
                {
                    score3 = value;
                }
                else
                {
                    score3 = 0;
                }
                CalcAverage();
            }
        }

        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string StudentNumber { get; set; }
        public double Average { get; private set; }

        public string GetSummary()
        {
            return "Name: " + FirstName + " " + LastName + "\n"
                    + "Average: " + Average;
        }

        //-------------------------------------
        //Instance Methods
        //------------------------------------
        public void CalcAverage()
        {
            Average = score1 + score2 + score3 / 3.0;
        }
    }
}
