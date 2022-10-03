/**
 * Exercise 5_14
 * 
 * Read (day-of-the-week,value) pairs from standard input. For example:
 *
 *       Tuesday 23 Friday 56 Tuesday –3 Thursday 99
 *
 * Collect all the values for each day of the week in a vector<int>. Write out
 * the values of the seven day-of-the-week vectors. Print out the sum of the
 * values in each vector. Ignore illegal days of the week, such as Funday, but 
 * accept common synonyms such as Mon and monday. Write out the number of rejected 
 * values.
 *
 */
#include "std_lib_facilities.h"

/* prototype   */
void print_vector(vector<int>);
int get_sum(vector<int>);

//=========================================================

int main()
try {
   vector<int> monday;
   vector<int> tuesday;
   vector<int> wednesday;
   vector<int> thursday;
   vector<int> friday;
   vector<int> saturday;
   vector<int> sunday;

   string day;
   int value;
   int rejecteds = 0;

   cout << "Enter a day and value (type \"quit\" for quit):\n";
   while (cin >> day && day != "quit") {
      cin >> value;

      if (day == "Monday" || day == "Mon" || day == "monday")
         monday.push_back(value);
      else if (day == "Tuesday" || day == "Tue" || day == "tuesday")
         tuesday.push_back(value);
      else if (day == "Wednesday" || day == "Wed" || day == "wednesday")
         wednesday.push_back(value);
      else if (day == "Thursday" || day == "Thu" || day == "thursday")
         thursday.push_back(value);
      else if (day == "Friday" || day == "Fri" || day == "friday")
         friday.push_back(value);
      else if (day == "Saturday" || day == "Sat" || day == "saturday")
         saturday.push_back(value);
      else if (day == "Sunday" || day == "Sun" || day == "sunday")
         sunday.push_back(value);
      else {
         cout << "Invalid day! (" << day << ")\n";
         rejecteds++;
      }
   }

   cout << "Monday   : "; print_vector(monday);
   cout << "Tuesday  : "; print_vector(tuesday);
   cout << "Wednesday: "; print_vector(wednesday);
   cout << "Thursday : "; print_vector(thursday);
   cout << "Friday   : "; print_vector(friday);
   cout << "Saturday : "; print_vector(saturday);
   cout << "Sunday   : "; print_vector(sunday);

   cout << "Number of rejected values: " << rejecteds << "\n";

} catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}

//=========================================================

void print_vector(vector<int> vec)
{
   if (vec.size() != 0)
      for (int value : vec)
         cout << value << ", ";
   cout << "Sum: " << get_sum(vec) << "\n";
}

//=========================================================

int get_sum(vector<int> vec)
{
   int sum = 0;

   if (vec.size() != 0)
      for (int value : vec)
         sum += value;

   return sum;
}
