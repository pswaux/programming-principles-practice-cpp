/**
 * Exercise 5_13
 * 
 * The program is a bit tedious because the answer is hard-coded into the program. 
 * Make a version where the user can play repeatedly (without stopping and restarting 
 * the program) and each game has a new set of four digits. You can get four random digits 
 * by calling the random number generator "randint(10)" from std_lib_facilities.h four times. 
 * You will note that if you run that program repeatedly, it will pick the same sequence of
 * four digits each time you start the program. To avoid that, ask the user to enter a number 
 * (any number) and call srand(n) where n is the number the user entered before calling 
 * randint(10). Such an "n" is called a seed, and different seeds give different sequences of 
 * random numbers.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
vector<int> guess_parse(int);
int check_bulls(vector<int>, vector<int>);
int check_cows(vector<int>, vector<int>);
vector<int> create_number();
bool check_digit(vector<int>, int);

//=========================================================

int main()
try {
   vector<int> number;
   vector<int> guess;
   int bulls = 0, cows = 0;
   int user_guess;
   char answer = 'y';

   while (answer == 'y' || answer == 'Y') {
      number = create_number();
      bulls = 0;
      while (bulls != 4) {
         cout << "Please enter your guess: ";
         cin >> user_guess;

         if (!cin) error("bad input");

         guess = guess_parse(user_guess);    // parse user's input into the vector digit by digit
         bulls = check_bulls(number, guess); // check guess against bulls
         cows = check_cows(number, guess);
         
         if (bulls == 4) {
            cout << bulls << " bulls! You guessed the number!\n";
            break;
         } else
            cout << bulls << " bull and " << cows << " cow\n";
      }

      cout << "Do you want to play another game? ";
      cin >> answer;
   }
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

//=========================================================

vector<int> create_number()
{
   cout << "Please enter seed number: ";
   int seed;
   cin >> seed;
   srand(seed);

   vector<int> number;
   int digit;
   while (number.size() != 4) {
      digit = randint(9);

      if (!check_digit(number, digit))
         number.push_back(digit);

      if (number[0] == 0)
         number[0] = randint(9);
   }

   return number;
}

//=========================================================

bool check_digit(vector<int> vec, int value)
{
   for (int digit : vec)
      if (value == digit)
         return true;
   
   return false;
}
