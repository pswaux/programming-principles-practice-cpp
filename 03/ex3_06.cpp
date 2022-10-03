/**
 * Exercise 3_6
 *
 * Write a program that prompts the user to enter three integer values, and 
 * then outputs the values in numerical sequence separated by commas. So, 
 * if the user enters the values 10 4 6, the output should be 4, 6, 10. If 
 * two values are the same, they should just be ordered together. So, the input 
 * 4 5 4 should give 4, 4, 5.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Please enter three integers: ";
   int val1, val2, val3;
   cin >> val1 >> val2 >> val3;

   // find the minimum and the maximum numbers
   int min = val1;
   if (val2 <= min) 
      min = val2;
   if (val3 <= min)
      min = val3;

   int max = val1;
   if (val1 >= max)
      max = val1;
   if (val2 >= max)
      max = val2;
   if (val3 >= max)
      max = val3;

   int mid = val1;
   if (val1 > min)
      if (val1 < max)
         mid = val1;
   if (val2 > min)
      if (val2 < max)
         mid = val2;
   if (val3 > min)
      if (val3 < max)
         mid = val3;

   cout << min << ", " << mid 
        << ", " << max << '\n';
}
