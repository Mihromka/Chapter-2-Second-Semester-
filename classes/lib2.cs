using System;
using ClassLibrary1;


namespace ConsoleApptest1
{
    class Program
    {
        static double MinAVG(string[] marks)
        {

            int[] a = new int[marks.Length];
            Library.test_function();
            Console.WriteLine();
            int b = 0;
            for (int i = 0; i < marks.Length; i++)
            {
                //Console.WriteLine(marks[i]);
                a[i] = Convert.ToInt32(marks[i]);
                b += a[i];
                int c = (b / marks.Length);
                Console.WriteLine(b);
                Console.WriteLine(c);
            }
            return 0;
        }
        static void Main(string[] args)
        {
            string[] marks = { "5", "4", "3" };
            
            MinAVG(marks);
   
        }

    }
}
