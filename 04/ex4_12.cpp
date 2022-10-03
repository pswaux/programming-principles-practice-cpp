/**
 * Exercise 4_12
 *
 * Modify the program described in the previous exercise to take an input 
 * value max and then find all prime numbers from 1 to max.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
bool isPrime(int);

//=========================================================

int main()
{
   int number = 2;   // number to be tested for primeness
   vector<int> primes;

   cout << "Enter the max value to be tested for primeness: ";
   int max;
   cin >> max;

   for ( ; number <= max; number++) {
      if (isPrime(number))
         primes.push_back(number);
   }

   for (int i = 0; i < primes.size(); i++) {
      cout << primes[i] << " ";

      if ((i + 1) % 10 == 0)
         cout << "\n";
   }
   cout << '\n';
}

//=========================================================

bool isPrime(int number) 
{
   for (int divisor = 2; divisor <= number / 2; divisor++) {
      if (number % divisor == 0)
         return false;
   }

   return true;
}      
