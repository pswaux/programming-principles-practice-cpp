/**
 * Exercise 4_6
 *
 * Make a vector holding the ten string values "zero", "one", . . . "nine". 
 * Use that in a program that converts a digit to its corresponding spelled-out value; 
 * e.g., the input 7 gives the output seven. Have the same program, using the same 
 * input loop, convert spelled-out numbers into their digit form; 
 * e.g., the input seven gives the output 7.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   vector<string> string_values = {
      "zero", "one", "two", "three", "four", "five",
      "six", "seven", "eight", "nine"
   };

   vector<string> int_values = {
      "0", "1", "2", "3", "4", "5",
      "6", "7", "8", "9"
   };

   cout << "Please enter a digit (e.g. seven or 7): ";
   string digit;
   cin >> digit;

   for (int i = 0; i < string_values.size(); ++i) {
      if (string_values[i] == digit)
         cout << "Your input: " << int_values[i] << "\n";

      if (int_values[i] == digit)
         cout << "Your input: " << string_values[i] << "\n";
   }
}
