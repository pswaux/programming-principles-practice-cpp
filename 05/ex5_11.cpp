/**
 * Exercise 5_11
 * 
 * Write a program that writes out the first so many values of the Fibonacci series, 
 * that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number of the 
 * series is the sum of the two previous ones. Find the largest Fibonacci number that 
 * fits in an int.
 *
 */
#include "std_lib_facilities.h"

int main()
try {
   cout << "How many fibonacci numbers do you want to see? ";
   int count;
   cin >> count;

   vector<int> fibs = {1, 1, 2};
   int prev = 1;
   int curr = 2;
   int next;

   for (int i = 0; i < count - 3; ++i) {  // vector has three values already
      next = prev + curr;
      fibs.push_back(next);
      prev = curr;
      curr = next;
   }

   cout << "Fibonacci numbers:\n";
   for (int i = 0; i < fibs.size(); ++i) {
      cout << fibs[i] << " ";

      if ((i + 1) % 10 == 0) // 10 value per line
         cout << "\n";
   }
   cout << "\n";
} catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}
