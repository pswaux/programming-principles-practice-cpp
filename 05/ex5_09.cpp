/**
 * Exercise 5_9
 * 
 * Modify the program from exercise 8 to write out an error if the result
 * cannot be represented as an int.
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
   // get doubles and apply narrow_cast() onto them to see
   // if they will fit as an int;
   // 12.0 will be ok as an input, for example, but 12.5 won't
   for (double value; cin >> value; )
      numbers.push_back(narrow_cast<int>(value));
   //if (!cin) error("integer was expected!");
   
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
