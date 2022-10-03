/**
 * Exercise 4_14
 *
 * Modify the program described in the previous exercise to take an input 
 * value max and then find all prime numbers from 1 to max.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   int number = 2;            // number to be tested for primeness
   int max;

   cout << "Enter the max number to be tested for primeness: ";
   cin >> max;
   vector<int> primes(max + 1);

   // fill the array with all 1s (true)
   for (int i = 0; i < primes.size(); ++i)
      primes[i] = 1;

   // mark as false numbers with divisible by test number
   // and greater than or equal to square of it
   for ( ; number <= primes.size()-1; number++) {
      for (int i = 2 ; i <= primes.size()-1; i++) {
         if ((i % number == 0) && (i >= number * number))
            primes[i] = 0; // not a prime, mark as false
      }
   }

   for (int i = 2; i <= primes.size() - 1; i++) {
      if (primes[i])
         cout << i << " ";
   }
   cout << '\n';
}
