/**
 * Exercise 4_11
 *
 * Create a program to find all the prime numbers between 1 and 100. 
 * One way to do this is to write a function that will check if a number is prime 
 * (i.e., see if the number can be divided by a prime number smaller than itself) 
 * using a vector of primes in order (so that if the vector is called primes, 
 * primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop that goes 
 * from 1 to 100, checks each number to see if it is a prime, and stores each prime 
 * found in a vector. Write another loop that lists the primes you found. You might check 
 * your result by comparing your vector of prime numbers with primes. Consider 2 the first prime.
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

   for ( ; number <= 100; number++) {
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
