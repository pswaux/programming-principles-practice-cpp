/**
 * Exercise 5_12
 * 
 * Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” 
 * The program has a vector of four different integers in the range 0 to 9 
 * (e.g., 1234 but not 1122) and it is the user’s task to discover those numbers by 
 * repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; 
 * the response should be “1 bull and 1 cow” because the user got one digit (1) right and 
 * in the right position (a bull) and one digit (3) right but in the wrong position (a cow).
 * The guessing continues until the user gets four bulls, that is, has the four digits correct 
 * and in the correct order.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
vector<int> guess_parse(int);
int check_bulls(vector<int>, vector<int>);
int check_cows(vector<int>, vector<int>);

//=========================================================

int main()
try {
   vector<int> number = {5, 7, 3, 8};
   vector<int> guess;
   int bulls = 0, cows = 0;
   int user_guess;

   while (bulls != 4) {
      cout << "Please enter your guess: ";
      cin >> user_guess;

      if (!cin) error("bad input");

      guess = guess_parse(user_guess);       // parse user's input into the vector digit by digit
      bulls = check_bulls(number, guess);    // check guess against bulls
      cows = check_cows(number, guess);

      cout << bulls << " bull and " << cows << " cow\n";
   }

   cout << bulls << " bulls! You guessed the number!\n";
} catch (exception& e) {
   cerr << "error: " << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}

//=========================================================

vector<int> guess_parse(int number)
{
   int factor = 1000;
   vector<int> digits;
   
   while (factor != 1) {
      digits.push_back(number / factor);
      number %= factor;
      factor /= 10;
   }
   digits.push_back(number);   // add the last digit

   return digits;
}

//=========================================================

int check_bulls(vector<int> number, vector<int> guess)
{
   int count = 0;
   for (int i = 0; i < number.size(); ++i)
      if (number[i] == guess[i])
         count++;

   return count;
}

//=========================================================

int check_cows(vector<int> number, vector<int> guess)
{
   int count = 0;
   for (int i = 0; i < number.size(); i++)
      for (int j = 0; j < guess.size(); j++) {
         if (i != j && number[i] == guess[j])
            count++;
      }

   return count;
}
