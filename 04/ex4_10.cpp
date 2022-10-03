/**
 * Exercise 4_10
 *
 * Write a program that plays the game “Rock, Paper, Scissors.” If you are not 
 * familiar with the game do some research (e.g., on the web using Google). 
 * Research is a common task for programmers. Use a switch-statement to solve this exercise. 
 * Also, the machine should give random answers (i.e., select the next rock, paper, 
 * or scissors randomly). Real randomness is too hard to provide just now, so just 
 * build a vector with a sequence of values to be used as “the next value.” If you 
 * build the vector into the program, it will always play the same game, so maybe 
 * you should let the user enter some values. Try variations to make it less easy for 
 * the user to guess which move the machine will make next.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
void shuffle(vector<string>);

//=========================================================

int main() 
{
   vector<string> items = {
      "scissors", "paper", "scissors", "rock", "paper", "rock",
      "rock", "scissors", "paper", "rock", "paper", "scissors"
   };
   char user_input;
   string computer_input;
   char answer = 'y';
   int select = 0;   // represents index number for items vector

   while (answer == 'y') {
      cout << "(R)ock, (P)aper, or (S)cissors? ";
      cin >> user_input;

      // shuffle the vector before the pick an item
      shuffle(items);

      computer_input = items[select++ % 12];

      switch (user_input) {
         case 'r' : case 'R' :
            if (computer_input == "rock")
               cout << "The computer picked \"Rock\" too! It's a draw!\n";
            else if (computer_input == "paper")
               cout << "The computer picked \"Paper\"! You lose!\n";
            else
               cout << "The computer picked \"Scissors\"! You win!\n";
            break;
         case 'p' : case 'P' :
            if (computer_input == "rock")
               cout << "The computer picked \"Rock\"! You win!\n";
            else if (computer_input == "paper")
               cout << "The computer picked \"Paper\" too! It's a draw!\n";
            else
               cout << "The computer picked \"Scissors\"! You lose!\n";
            break;
         case 's' : case 'S' :
            if (computer_input == "rock")
               cout << "The computer picked \"Rock\"! You lose!\n";
            else if (computer_input == "paper")
               cout << "The computer picked \"Paper\"! You win!\n";
            else
               cout << "The computer picked \"Scissors\" too! It's a draw!\n";
            break;
      }

      cout << "Do you wanna play another game? (y or n): ";
      cin >> answer;
   }
}

//=========================================================

void shuffle(vector<string> items)
{
   string temp;
   
   for (int i = 0; i < items.size() - 2; i += 2) {
      temp = items[i];
      items[i] = items[i + 2];
      items[i + 2] = temp;
   }

   for (int i = 1; i < items.size() - 2; i += 2) {
      temp = items[i];
      items[i] = items[i + 2];
      items[i + 2] = temp;
   }
}
