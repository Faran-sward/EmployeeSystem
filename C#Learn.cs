using System;

namespace My_TEST
{
    class _test_
    {
        string str = @"test-
                    123 456-
                    444";
        public _test_()
        {
            Console.WriteLine("构造函数");
        }
        public void _print(string str)
        {
            Console.WriteLine(str);
            Console.WriteLine(str.Length);
        }
    }
}