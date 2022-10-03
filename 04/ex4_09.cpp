/**
 * Exercise 4_9
 *
 * Try to calculate the number of rice grains that the inventor asked for in 
 * exercise 8 above. You’ll find that the number is so large that it won’t fit 
 * in an int or a double. Observe what happens when the number gets too large to 
 * represent exactly as an int and as a double. What is the largest number of 
 * squares for which you can calculate the exact number of grains (using an int)? 
 * What is the largest number of squares for which you can calculate the approximate 
 * number of grains (using a double)?
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
void grains_number_int(int);
void grains_number_double(int);

//=========================================================

int main() 
{
   printf("Please enter number of squares to be tested: ");
   int squares;
   cin >> squares;

   grains_number_int(squares);
   grains_number_double(squares);

   // max 32 squares for integer and
   // max 1024 squares for double
}

//=========================================================

void grains_number_int(int squares) 
{
   int square = 2;   
   int previous_grains = 1;   // number of grains on the previous square
   int current_grains = 1;    // number of grains on the current square

   while (square < squares) {
      current_grains *= 2;
      previous_grains += current_grains;

      square++;
   }

   cout << square << " squares can hold (using an integer) "
      << previous_grains + current_grains << " rice grains\n";
}

//=========================================================

void grains_number_double(int squares)
{
   int square = 2;
   double previous_grains = 1;
   double current_grains = 1;

   while (square < squares) {
      current_grains *= 2;
      previous_grains += current_grains;

      square++;
   }

   cout << square << " squares can hold (using a double) "
      << previous_grains + current_grains << " rice grains\n";
}
