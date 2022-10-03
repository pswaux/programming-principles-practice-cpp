/**
 * Exercise 4_19
 *
 * Write a program where you first enter a set of name-and-value pairs, 
 * such as Joe 17 and Barbara 22. For each pair, add the name to a vector called 
 * names and the number to a vector called scores (in corresponding positions, 
 * so that if names[7]=="Joe" then scores[7]==17). Terminate input with NoName 0. 
 * Check that each name is unique and terminate with an error message if a name is 
 * entered twice. Write out all the (name,score) pairs, one per line.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
bool isUnique(vector<string>, string);

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

   for (int i = 0; i < names.size(); i++)
      cout << "(" << names[i] << ", " << scores[i]
           << ")\n";

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
