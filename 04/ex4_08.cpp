/**
 * Exercise 4_8
 *
 * There is an old story that the emperor wanted to thank the inventor of the 
 * game of chess and asked the inventor to name his reward. The inventor asked for 
 * one grain of rice for the first square, 2 for the second, 4 for the third, and so on, 
 * doubling for each of the 64 squares. That may sound modest, but there wasn’t that much 
 * rice in the empire! 
 *
 * Write a program to calculate how many squares are required to give the inventor at 
 * least 1000 grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains.
 * You’ll need a loop, of course, and probably an int to keep track of which square you are at, 
 * an int to keep the number of grains on the current square, and an int to keep track of the 
 * grains on all previous squares. We suggest that you write out the value of all your variables 
 * for each iteration of the loop so that you can see what’s going on.
 *
 */
#include "std_lib_facilities.h"

int find_square_number(int);

int main() 
{
   int grains = 1000;
   cout << find_square_number(grains) << " square need at least " << grains
        << " grains of rice\n";
   
   grains = 1000000;
   cout << find_square_number(grains) << " square need at least " << grains
        << " grains of rice\n";

   grains = 1000000000;
   cout << find_square_number(grains) << " square need at least " << grains
        << " grains of rice\n";
}

int find_square_number(int grains) 
{
   int square = 2;   
   int previous_grains = 1; // number of grains on the previous square
   int current_grains = 1;  // number of grains on the current square

   while (square <= 64) {
      current_grains *= 2;
      previous_grains += current_grains;

      if (current_grains + previous_grains > grains)
         break;
      square++;
   }

   return square - 1;
}
