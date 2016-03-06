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
            myStudent.SetMajor("Computer Programming");

            Student myOtherStudent = new Student();
            myOtherStudent.SetMajor("Art History");

            Console.WriteLine("My major is {0}.", myStudent.GetMajor());
            Console.WriteLine("My other student's major is {0}.", myOtherStudent.GetMajor());
        }
    }
}
