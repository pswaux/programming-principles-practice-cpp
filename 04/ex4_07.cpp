/**
 * Exercise 4_7
 *
 * Modify the “mini calculator” from exercise 5 to accept (just) single-digit 
 * numbers written as either digits or spelled out.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
int string_to_int(string);

//=========================================================

int main() 
{
   cout << "Enter two digit and operation\n"
      << "(e.g. 2 3 +, or two three +): ";
   string num1, num2;
   char operation;
   cin >> num1 >> num2 >> operation;

   // turn string digits to correponding int digits 
   int val1 = string_to_int(num1);
   int val2 = string_to_int(num2);

   switch (operation) {
      case '+' :
         cout << "The sum of " << val1 << " and " << val2
            << " is " << val1 + val2 << "\n";
         break;
      case '-' :
         cout << "The difference between " << val1 << " and " << val2
            << " is " << val1 - val2 << "\n";
         break;
      case '*' :
         cout << "The multiplication of " << val1 << " and " << val2
            << " is " << val1 * val2 << "\n";
         break;
      case '/' :
         cout << "The division of " << val1 << " and " << val2
            << " is " << val1 / val2 << "\n";
         break;
      default: 
         cout << "Invalid operation!\n";
   }
}

//=========================================================

int string_to_int(string num) 
{
   vector<string> string_values = {
      "zero", "one", "two", "three", "four", "five",
      "six", "seven", "eight", "nine"
   };

   vector<string> int_values = {
      "0", "1", "2", "3", "4", "5",
      "6", "7", "8", "9"
   };

   int index = 0;
   for ( ; index < string_values.size(); ++index) {
      if (string_values[index] == num || int_values[index] == num)
         break;
   }

   return index;
}
