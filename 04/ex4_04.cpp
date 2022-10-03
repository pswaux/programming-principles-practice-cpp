/**
 * Exercise 4_4
 *
 * Write a program to play a numbers guessing game. The user thinks of a number 
 * between 1 and 100 and your program asks questions to figure out what the 
 * number is (e.g., “Is the number you are thinking of less than 50?”). Your program 
 * should be able to identify the number after asking no more than seven questions. 
 * 
 * Hint: Use the < and <= operators and the if-else construct.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   char answer = 'n';
   int low = 1;
   int mid = 50;
   int high = 100;
   int count = 0;

   while (++count < 8 && (mid != high - 1)) {
      cout << "Is the number you are thinking of less than " << mid << "? ";
      cin >> answer;

      if (answer == 'y') {
         high = mid;
         mid = (low + high) / 2;
      } else {
         low = mid;
         mid = (low + high) / 2;
      }
   }

   cout << "You picked number: " << mid << "\n";
}
