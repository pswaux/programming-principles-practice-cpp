/**
 * Exercise 4_2
 *
 * If we define the median of a sequence as “a number so that exactly as 
 * many elements come before it in the sequence as come after it,” fix the 
 * program in §4.6.3 so that it always prints out a median. 
 * Hint: A median need not be an element of the sequence.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   vector<double> temps;
   double median;

   for (double temp; cin >> temp; )
      temps.push_back(temp);

   sort(temps);

   // if the element number of vector is odd, pick the middle element
   if (temps.size() % 2 == 1)
      median = temps[temps.size() / 2];
   else  // otherwise, get the average of two middle values in the vector
      median = (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2;

   cout << "The median is: " << median << "\n";
}
