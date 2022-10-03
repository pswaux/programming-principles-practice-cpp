/**
 * Exercise 3_8
 *
 * Write a program to test an integer value to determine if it is odd or even. 
 * As always, make sure your output is clear and complete. In other words, 
 * don’t just output yes or no. Your output should stand alone, 
 * like The value 4 is an even number. Hint: See the remainder (modulo) operator 
 * in section 3.4.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Please enter an integer: ";
   int value;
   cin >> value;

   if (value % 2 == 0)
      cout << "The value " << value << " is an even number.\n";

   if (value % 2 != 0)
      cout << "The value " << value << " is an odd number.\n";
}
