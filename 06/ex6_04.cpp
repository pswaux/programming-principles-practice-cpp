/**
 * Exercise 4_4
 *
 * Define a class Name_value that holds a string and a value. Rework 
 * exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
 *
 ********************************************************************************
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

//=========================================================

class Name_value {
public:
   string name;
   int score;

   Name_value(string name, int score)
      : name{name}, score{score} {}
};

//=========================================================

/* prototypes  */
bool isUnique(vector<Name_value>, string);

//=========================================================

int main()
{
   cout << "Enter name-value pairs (e.g. Joe 17. Type NoName 0 to quit):\n";
   string name;
   int value;

   vector<Name_value> list;
   while (cin >> name >> value) {
      if (name == "NoName" && value == 0)
         break;

      if (isUnique(list, name)) {
         list.push_back(Name_value{name, value});
      } else
         simple_error("Names must be unique!");
   }

   for (int i = 0; i < list.size(); i++)
      cout << "(" << list[i].name << ", " 
           << list[i].score
           << ")\n";

}

//=========================================================

bool isUnique(vector<Name_value> list, string name)
{
   for (Name_value item : list) {
      if (item.name == name)
         return false;
   }

   return true;
}
