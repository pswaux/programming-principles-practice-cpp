/**
 * Exercise 3_2
 *
 * Write a program in C++ that converts from miles to kilometers. 
 * Your program should have a reasonable prompt for the user to enter a number
 * of miles. 
 * Hint: There are 1.609 kilometers to the mile.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Please enter a number of miles: ";
   double miles;
   cin >> miles;

   cout << miles << " miles is equal to "
        << miles * 1.609 << " kilometers\n";
}
