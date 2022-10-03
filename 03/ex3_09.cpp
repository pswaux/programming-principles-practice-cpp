/**
 * Exercise 3_9
 *
 * Write a program that converts spelled-out numbers such as “zero” and “two” into digits, 
 * such as 0 and 2. When the user inputs a number, the program should print out the 
 * corresponding digit. Do it for the values 0, 1, 2, 3, and 4 and write out 
 * "not a number I know" if the user enters something that doesn’t correspond, 
 * such as stupid computer!.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Please enter spelled-out number between 0 and 4, (e.g. \"zero\"): ";
   string number;
   cin >> number;

   if (number == "zero")
      cout << "You entered 0\n";
   else 
      if (number == "one")
         cout << "You entered 1\n";
      else 
         if (number == "two")
            cout << "You entered 2\n";
         else 
            if (number == "three")
               cout << "You entered 3\n";
            else 
               if (number == "four")
                  cout << "You entered 4\n";
               else
                  cout << "Not a number I know!\n";
} 
