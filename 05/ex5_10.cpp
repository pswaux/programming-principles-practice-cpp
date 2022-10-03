/**
 * Exercise 5_10
 * 
 * Modify the program from exercise 8 to use double instead of int. Also, 
 * make a vector of doubles containing the N–1 differences between adjacent 
 * values and write out that vector of differences.
 *
 */
#include "std_lib_facilities.h"

int main()
try {
   cout << "Please enter the number of values you want to sum: ";
   int count;
   cin >> count;

   cout << "Please enter some integers (press '|' to stop): ";
   
   vector<double> numbers;
   for (double value; cin >> value; )
      numbers.push_back(value);
   
   if (count > numbers.size())
      error("you attempted to access a value out of defined range!");

   double sum = 0.0;
   for (int i = 0; i < count; ++i) 
      sum += numbers[i];

   cout << "The sum of the first " << count << " numbers ( ";
   for (int number : numbers)
      cout << number << " ";
   cout << ") is " << sum << '\n';

   vector<double> differences;
   for (int i = 0; i < numbers.size() - 1; ++i)
      differences.push_back(numbers[i] - numbers[i + 1]);

   cout << "Differences between adjacent numbers are:\n";
   for (double value : differences)
      cout << value << " ";
   cout << "\n";

} catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}
