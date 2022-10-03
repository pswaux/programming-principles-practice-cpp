/**
 * Exercise 5_3
 * 
 * Absolute zero is the lowest temperature that can be reached; it is –273.15°C,
 * or 0K. The above program (exercise 2), even when corrected, will produce erroneous results 
 * when given a temperature below this. Place a check in the main program that will 
 * produce an error if a temperature is given below –273.15°C.
 *
 */
#include "std_lib_facilities.h"

/* constants   */
constexpr double kelvin_scale = 273.15;

//=========================================================

double ctok(double c)      
// converts Celsius to Kelvin
{
   double k = c + kelvin_scale;
   
   return k;
}

//=========================================================

int main()
try {
   double c = 0;          // declare input variable
   cin >> c;              // retrieve temperature to input variable
   
   if (c < -kelvin_scale)
      error("Temprature can't be lower than absolute zero!");

   double k = ctok(c);    // convert temperature
   cout << k << '\n';     // print out temperature
} catch (exception& e) {
   cout << e.what() << '\n';
   return 1;
} catch (...) {
   cout << "Oops! Unknown exception!\n";
   return 2;
}
