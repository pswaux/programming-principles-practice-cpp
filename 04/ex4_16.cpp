/**
 * Exercise 4_16
 *
 * In the drill, you wrote a program that, given a series of numbers, 
 * found the max and min of that series. The number that appears the most times 
 * in a sequence is called the "mode". Create a program that finds the mode of 
 * a set of positive integers.
 *
 */
#include "std_lib_facilities.h"

int main()
{
   cout << "Enter a series of integers (type q to quit): ";
   vector<int> numbers;
   vector<int> modes;

   for (int value; cin >> value; )
      numbers.push_back(value);

   sort(numbers);

   // generate a vector that holds unique numbers
   vector<int> uniques;
   for (int i = 0; i < numbers.size() - 1; i++) {
      if (numbers[i] != numbers[i + 1])
         uniques.push_back(numbers[i]);
   }
   uniques.push_back(numbers[numbers.size()-1]); // add the last value

   // count every number and add them to new vector that
   // has the same size with uniques vector
   // counts[i] holds the number of appearance of uniques[i]
   vector<int> counts;
   for (int i = 0; i < uniques.size(); i++) {
      int count = 0;
      for (int j = 0; j < numbers.size(); j++) {
         if (uniques[i] == numbers[j])
            count++;
      }

      counts.push_back(count);
   }

   // find the biggest number
   int biggest = 0;
   for (int count : counts) {
      if (count > biggest)
         biggest = count;
   }
  
   // add the most appeared numbers into modes vector
   for (int i = 0; i < counts.size(); i++) {
      if (counts[i] == biggest)
         modes.push_back(uniques[i]);
   }

   if (modes.size() == 0)
      cout << "There is no mode!";
   else if (modes.size() == 1)
      cout << "The mode is: " << modes[0];
   else {
      cout << "The Modes are: ";
      for (int mode : modes)
         cout << mode << " ";
   }

   cout << '\n';  
}                  
