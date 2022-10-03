/**
 * Exercise 4_15
 *
 * Write a program that takes an input value n and then finds 
 * the first n primes.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
bool isPrime(int);

//=========================================================

int main()
{
   int number = 2;      // number to be tested for primeness
   vector<int> primes;

   cout << "How many primes do you want to find? ";
   int limit;
   cin >> limit;
   int prime_count = 0;

   while (prime_count < limit) {
      if (isPrime(number)) {
         primes.push_back(number);
         prime_count++;
      }
      number++;
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
