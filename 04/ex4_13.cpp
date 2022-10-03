/**
 * Exercise 4_13
 *
 * Create a program to find all the prime numbers between 1 and 100. 
 * There is a classic method for doing this, called the “Sieve of Eratosthenes.” 
 * If you don’t know that method, get on the web and look it up. Write your 
 * program using this method.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   int number = 2;            // number to be tested for primeness
   vector<int> primes(101);

   // fill the array with all 1s (as true)
   for (int i = 0; i < primes.size(); ++i)
      primes[i] = 1;

   // mark as false numbers with divisible by test number
   // and greater than or equal to square of it
   for ( ; number <= 100; number++) {
      for (int i = 2 ; i <= 100; i++) {
         if ((i % number == 0) && (i >= number * number))
            primes[i] = 0; // not a prime, mark as false
      }
   }

   for (int i = 2; i <= 100; i++) {
      if (primes[i])
         cout << i << " ";
   }
   cout << '\n';
}
