using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CShapLearning
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "a string";
            string b = a;
            System.Console.WriteLine("a is " + a);
            System.Console.WriteLine("b is " + b);

            b = "another string";
            System.Console.WriteLine("a is " + a);
            System.Console.WriteLine("b is " + b);
        }
    }
}
