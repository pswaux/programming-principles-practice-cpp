/**
 * Exercise 4_21
 *
 * Modify the program from exercise 19 so that when you enter a integer, 
 * the program will output all the names with that score or score not found.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
bool isUnique(vector<string>, string);
void getName(vector<int>, vector<string>, int);

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
   int query;
   while (answer == 'y') {
      cout << "Enter a score to be searched? ";
      cin >> query;

      getName(scores, names, query);

      cout << "Do you want to do another search (y or n)? ";
      cin >> answer;
   }

   cout << '\n';
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

void getName(vector<int> scores, vector<string> names, int query) 
{
   int success = 0;  // how many names returned?

   for (int i = 0; i < scores.size(); ++i) {
      if (scores[i] == query) {
         cout << names[i] << "\n";
         success++;
      }
   }

   if (success == 0)
      cout << "Score not found\n";
}
