/**
 * Exercise 5_8
 * 
 * Write a program that reads and stores a series of integers and then computes 
 * the sum of the first N integers. First ask for N, then read the values into a vector, 
 * then calculate the sum of the first N values. For example:
 *
 *    “Please enter the number of values you want to sum:” 3
 *    “Please enter some integers (press '|' to stop):” 12 23 13 24 15 |
 *    “The sum of the first 3 numbers ( 12 23 13 ) is 48.”
 *
 * Handle all inputs. For example, make sure to give an error message if the user asks 
 * for a sum of more numbers than there are in the vector.
 *
 */
#include "std_lib_facilities.h"

int main()
try {
   cout << "Please enter the number of values you want to sum: ";
   int count;
   cin >> count;

   cout << "Please enter some integers (press '|' to stop): ";
   
   vector<int> numbers;
   for (int value; cin >> value; )
      numbers.push_back(value);
   if (!cin) error("integer was expected!");

   if (count > numbers.size())
      error("you attempted to access a value out of defined range!");

   int sum = 0;
   for (int i = 0; i < count; ++i) 
      sum += numbers[i];

   cout << "The sum of the first " << count << " numbers ( ";
   for (int i = 0; i < count; ++i)
      cout << numbers[i] << " ";
   cout << ") is " << sum << '\n';

} catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}
