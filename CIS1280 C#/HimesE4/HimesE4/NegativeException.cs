using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HimesE4
{
    class NegativeException : ApplicationException
    {
        public NegativeException()
            : base("A negative number cannot be entered as an amount.")
        {
        }
    }
}
