/**
 * Exercise 5_4
 * 
 * Do exercise 3 again, but this time handle the error inside ctok().
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

int main()
try {
   double c = 0;          // declare input variable
   cin >> c;              // retrieve temperature to input variable

   double k = ctok(c);    // convert temperature
   cout << k << '\n';     // print out temperature
} catch (exception& e) {
   cout << e.what() << '\n';
   return 1;
} catch (...) {
   cout << "Oops! Unknown exception!\n";
   return 2;
}
