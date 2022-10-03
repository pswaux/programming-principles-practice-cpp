/**
 * Exercise 3_11
 *
 * Write a program that prompts the user to enter some number of pennies (1-cent coins), 
 * nickels (5-cent coins), dimes (10-cent coins), quarters (25-cent coins), 
 * half dollars (50-cent coins), and one-dollar coins (100-cent coins). Query the user 
 * separately for the number of each size coin, e.g., “How many pennies do you have?” 
 * Then your program should print out something like this:
 *
 *    You have 23 pennies.
 *    You have 17 nickels.
 *    You have 14 dimes.
 *    You have 7 quarters.
 *    You have 3 half dollars.
 *
 * The value of all of your coins is 573 cents. Make some improvements: 
 * if only one of a coin is reported, make the output grammatically correct, 
 * e.g., 14 dimes and 1 dime (not 1 dimes). Also, report the sum in dollars and cents, 
 * i.e., $5.73 instead of 573 cents.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   int sum = 0;

   cout << "How many pennies do you have: ";
   int pennies;
   cin >> pennies;
   sum += pennies;

   cout << "How many nickels do you have: ";
   int nickels;
   cin >> nickels;
   sum += nickels * 5;

   cout << "How many dimes do you have: ";
   int dimes;
   cin >> dimes;
   sum += dimes * 10;

   cout << "How many quarters do you have: ";
   int quarters;
   cin >> quarters;
   sum += quarters * 25;

   cout << "How many half dollars do you have: ";
   int half_dollars;
   cin >> half_dollars;
   sum += half_dollars * 50;

   cout << "How many one-dollar do you have: ";
   int dollars;
   cin >> dollars;
   sum += dollars * 100;


   if (pennies > 1)
      cout << "You have " << pennies << " pennies\n";
   else
      cout << "You have " << pennies << " penny\n";

   if (nickels > 1)
      cout << "You have " << nickels << " nickels\n";
   else
      cout << "You have " << nickels << " nickel\n";

   if (dimes > 1)
      cout << "You have " << dimes << " dimes\n";
   else
      cout << "You have " << dimes << " dime\n";

   if (quarters > 1)
      cout << "You have " << quarters << " quarters\n";
   else
      cout << "You have " << quarters << " quarter\n";

   if (half_dollars > 1)
      cout << "You have " << half_dollars << " half dollars\n";
   else
      cout << "You have " << half_dollars << " half dollar\n";

   if (dollars > 1)
      cout << "You have " << dollars << " dollars\n";
   else
      cout << "You have " << dollars << " dollar\n";

   cout << "The value of all your coins is " << sum << " cents "
      << "($" << sum / 100 << "." << sum % 100 << ")\n";
} 
