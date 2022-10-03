/**
 * Exercise 3_4
 *
 * Write a program that prompts the user to enter two integer values. 
 * Store these values in int variables named val1 and val2. Write your program 
 * to determine the smaller, larger, sum, difference, product, and ratio of these 
 * values and report them to the user.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   int val1 = 0;
   int val2 = 0;

   cout << "Enter two integers: ";
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
