/**
 * Exercise 5_6
 * 
 * Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to 
 * Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your results are plausible.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
double ctof(double c);
double ftoc(double f);

//=========================================================

int main()
try {
   cout << "Please enter a temperature (e.g. 50c or 100F): ";
   double temp;
   char unit;
   cin >> temp >> unit;

   if (unit == 'c' || unit == 'C')
      cout << temp << " Celsius is: " << ctof(temp)
           << " Fahrenheit\n";
   else if (unit == 'f' || unit == 'F')
      cout << temp << " Fahrenheit is: " << ftoc(temp)
           << " Celsius\n";
   else
      error("Unknown temperature unit!\n");

} catch (exception& e) {
   cerr << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}

//=========================================================

double ctof(double c)
// converts Celsius to Fahrenheit
// pre-condition: c shouldn't below absolute zero
{
   constexpr double abs_zero_c = -273.15;

   if (c < abs_zero_c)
      error("Temperature can't below absolute zero!\n");

   return 1.8 * c + 32;
}

//=========================================================

double ftoc(double f)
// converts Fahrenheit to Celsius
// pre-condition: f shouldn't below -459.67 F
{
   constexpr double min_fahrenheit = -549.67;

   if (f < min_fahrenheit)
      error("Temperature can't below -459.67 F\n");

   return (f - 32) / 1.8;
}
