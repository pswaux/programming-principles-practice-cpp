/**
 * Exercise 3_5
 *
 * Modify the program above to ask the user to enter floating-point values 
 * and store them in double variables. Compare the outputs of the two programs 
 * for some inputs of your choice. Are the results the same? Should they be? 
 * What’s the difference?
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   double val1 = 0;
   double val2 = 0;

   cout << "Enter two doubles: ";
   cin >> val1 >> val2;

   if (val1 < val2)
      cout << val1 << " is less than " << val2 << '\n';
   if (val1 > val2)
      cout << val1 << " is grater than " << val2 << '\n';

   cout << "Sum of two numbers: " << val1 + val2 << '\n';
   cout << "Difference of two numbers: " << val1 - val2 << '\n';
   cout << "Product of two numbers: " << val1 * val2 << '\n';
   cout << "Ratio of two numbers: " << val1 / val2 << '\n';
}
