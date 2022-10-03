/**
 * Exercise 4_17
 *
 * Write a program that finds the min, max, and mode of a sequence of strings.
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Enter a series of integers (type q to quit): ";
   vector<string> texts;
   vector<string> modes;

   for (string text; cin >> text && text != "q"; )
      texts.push_back(text);

   sort(texts);

   string min = texts[0];
   string max = texts[texts.size() - 1];

   // generate a vector that holds unique texts
   vector<string> uniques;
   for (int i = 0; i < texts.size() - 1; i++) {
      if (texts[i] != texts[i + 1])
         uniques.push_back(texts[i]);
   }
   uniques.push_back(texts[texts.size()-1]); // add the last value

   // count every number and add them to new vector that
   // has the same size with uniques vector
   // counts[i] holds the number of appearance of uniques[i]
   vector<int> counts;
   for (int i = 0; i < uniques.size(); i++) {
      int count = 0;
      for (int j = 0; j < texts.size(); j++) {
         if (uniques[i] == texts[j])
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
  
   // add the most appeared texts into modes vector
   for (int i = 0; i < counts.size(); i++) {
      if (counts[i] == biggest)
         modes.push_back(uniques[i]);
   }

   cout << "The smallest string: " << min << '\n';
   cout << "The biggest string: " << max << '\n';
   if (modes.size() == 0)
      cout << "There is no mode!";
   else if (modes.size() == 1)
      cout << "The mode is: " << modes[0];
   else {
      cout << "The Modes are: ";
      for (string mode : modes)
         cout << mode << " ";
   }

   cout << '\n';  
}                  
