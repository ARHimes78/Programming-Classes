using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            string doAnother;
            
            do
            {
                Console.Write("What's your name? ");
                string name = Console.ReadLine();
                Console.WriteLine("Hello, " + name + "!");

                Console.Write("Do another? ");
                doAnother = Console.ReadLine();
            } while (doAnother == "y");
        }
    }
}
