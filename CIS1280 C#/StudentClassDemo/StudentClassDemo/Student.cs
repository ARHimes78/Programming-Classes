using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StudentClassDemo
{
    class Student
    {
        private string major;
        private int score1;
        private int score2;
        private int score3;
        private string studentFirstName;
        private string studentLastName;
        private string studentNumber;

        public Student()
        {

        }

        public string GetMajor()
        {
            return major;
        }

        public void SetMajor(string newMajor)
        {
            major = newMajor;
        }
    }
}
