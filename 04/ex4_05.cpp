/**
 * Exercise 4_5
 *
 * Write a program that performs as a very simple calculator. Your calculator 
 * should be able to handle the four basic math operations 
 * — add, subtract, multiply, and divide — on two input values. Your program should 
 * prompt the user to enter three arguments:
 *
 *    two double values and a character to represent an operation. 
 *    If the entry arguments are 35.6, 24.1, and '+', the program output should be 
 *    The sum of 35.6 and 24.1 is 59.7. 
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Enter two doubles and operator (e.g. 2.5 3.0 +): ";
   double num1, num2;
   char operation;
   cin >> num1 >> num2 >> operation;

   switch (operation) {
      case '+' :
         cout << "The sum of " << num1 << " and " << num2
              << " is " << num1 + num2 << "\n";
         break;
      case '-' :
         cout << "The difference between " << num1 << " and " << num2
              << " is " << num1 - num2 << "\n";
         break;
      case '*' :
         cout << "The multiplication of " << num1 << " and " << num2
              << " is " << num1 * num2 << "\n";
         break;
      case '/' :
         cout << "The division of " << num1 << " and " << num2
              << " is " << num1 / num2 << "\n";
         break;
      default: 
         cout << "Invalid operation!\n";
   }
}
