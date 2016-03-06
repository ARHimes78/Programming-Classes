using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseDemo
{
    class Dog
    {
        #region properties
        /// <summary>
        /// Primary key id for dog
        /// </summary>
        public int DogID { get; set; }

        /// <summary>
        /// Dog's breed
        /// </summary>
        public string Breed { get; set; }

        /// <summary>
        /// Color
        /// </summary>
        public string Color { get; set; }

        /// <summary>
        /// Age in years
        /// </summary>
        public int Age { get; set; }

        /// <summary>
        /// Sex "male" or "female"
        /// </summary>
        public string Sex { get; set; }

        /// <summary>
        /// Weight in pounds
        /// </summary>
        public float Weight { get; set; }

        /// <summary>
        /// Birth date
        /// </summary>
        public DateTime Birthday { get; set; }
        #endregion
        #region methods
        public override string ToString()
        {
            return "Dog ID: " + DogID + " " + Color + " " + Breed;
        }
        #endregion

    }
}
