/**
 * Exercise 3_7
 *
 * Do exercise 6, but with three string strues. So, if the user enters the strues 
 * "Steinbeck", "Hemingway", "Fitzgerald", the output should be "Fitzgerald", "Hemingway", "Steinbeck".
 *
 */
#include "std_lib_facilities.h"

int main() 
{
   cout << "Please enter three strings: ";
   string str1, str2, str3;
   cin >> str1 >> str2 >> str3;

   string min = str1;
   if (str2 <= min) 
      min = str2;
   if (str3 <= min)
      min = str3;

   string max = str1;
   if (str1 >= max)
      max = str1;
   if (str2 >= max)
      max = str2;
   if (str3 >= max)
      max = str3;

   string mid = str1;
   if (str1 > min)
      if (str1 < max)
         mid = str1;
   if (str2 > min)
      if (str2 < max)
         mid = str2;
   if (str3 > min)
      if (str3 < max)
         mid = str3;

   cout << min << ", " << mid 
        << ", " << max << '\n';
}
