/**
 * Exercise 5_2
 *
 * The following program takes in a temperature value in Celsius and converts
 * it to Kelvin. This code has many errors in it. Find the errors, list them, 
 * and correct the code.
 *
 *    double ctok(double c)      // converts Celsius to Kelvin
 *    {
 *       int k = c + 273.15;
 *       return int
 *    }
 *
 *    int main()
 *    {
 *       double c = 0;           // declare input variable
 *       cin >> d;               // retrieve temperature to input variable
 *       double k = ctok("c");   // convert temperature
 *       Cout << k << '/n' ;     // print out temperature
 *    }
 *
 */
#include "std_lib_facilities.h"

//=========================================================

double ctok(double c)      // converts Celsius to Kelvin
{
   constexpr double kelvin_scale = 273.15;   // "magic constant" was used
   // k should be double instead of int
   double k = c + kelvin_scale;
   
   // should return computed value instead of type
   return k;   //; needed here
}

//=========================================================

int main()
{
   double c = 0;           // declare input variable
   // d is undefined; value should be read into c
   cin >> c;               // retrieve temperature to input variable
   
   // "c" is a string; should be c (double)
   double k = ctok(c);   // convert temperature
   
   // Cout is undefined; Cout => cout
   // wrong escape sequence; '/' => '\' 
   cout << k << '\n';     // print out temperature
}
