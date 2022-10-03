/**
 * Exercise 5_5
 * 
 * Add to the program so that it can also convert from Kelvin to Celsius.
 *
 */
#include "std_lib_facilities.h"

/* constants   */
constexpr double kelvin_scale = 273.15;

//=========================================================

double ctok(double c)      
// converts Celsius to Kelvin
// pre-condition: c shouldn't be lower than absolute zero
{
   if (c < -kelvin_scale)
      error("Temprature can't be lower than absolute zero!");

   double k = c + kelvin_scale;
   
   return k;
}

//=========================================================

double ktoc(double k)
// converts Kelvin to Celcius
// pre-condition: k can't be lower than 273.15
{
   if (k < kelvin_scale)
      error("Temperature can't be lower than 273.15");

   double c = k - kelvin_scale;

   return c;   
}

//=========================================================

int main()
try {
   double k = 0;          // declare input variable
   cin >> k;              // retrieve temperature to input variable

   double c = ktoc(k);    // convert temperature
   cout << c << '\n';     // print out temperature
} catch (exception& e) {
   cout << e.what() << '\n';
   return 1;
} catch (...) {
   cout << "Oops! Unknown exception!\n";
   return 2;
}

