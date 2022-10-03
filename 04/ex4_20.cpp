/**
 * Exercise 4_20
 *
 * Modify the program from exercise 19 so that when you enter a name, 
 * the program will output the corresponding score or name not found.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
bool isUnique(vector<string>, string);
int getScore(vector<string>, string);

//=========================================================

int main()
{
   cout << "Enter name-value pairs (e.g. Joe 17. Type NoName 0 to quit): ";
   string name;
   int value;

   vector<string> names;
   vector<int> scores;
   while (cin >> name >> value) {
      if (name == "NoName" && value == 0)
         break;

      if (isUnique(names, name)) {
         names.push_back(name);
         scores.push_back(value);
      } else
         simple_error("Names must be unique!");
   }

   char answer = 'y';
   string query;
   while (answer == 'y') {
      cout << "Enter the name to be searched: ";
      cin >> query;

      int index = getScore(names, query);
      if (index >= 0)
         cout << query << "'s score: " << scores[index] << '\n';
      else
         cout << "Name not found\n";

      cout << "Do you want to do an another search (y or n)? ";
      cin >> answer;
   }
}

//=========================================================

bool isUnique(vector<string> names, string name)
{
   for (string str : names) {
      if (str == name)
         return false;
   }

   return true;
}

//=========================================================

int getScore(vector<string> names, string name) {
   for (int i = 0; i < names.size(); ++i) {
      if (names[i] == name)
         return i;
   }

   return -1;
}
