using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentClassDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Student myStudent = new Student();
            myStudent.Major = "Computer Programming";

            Student myOtherStudent = new Student();
            myOtherStudent.Major = "Art History";

            Console.WriteLine("My Major is {0}.", myStudent.Major);          
            Console.WriteLine("The other student's major is {0}.", myOtherStudent.Major);

            Console.WriteLine(myStudent.GetSummary());
        }
    }
}
