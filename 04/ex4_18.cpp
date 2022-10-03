/**
 * Exercise 4_18
 *
 * Write a program to solve quadratic equations. A quadratic equation is of 
 * the form 
 *
 *       ax² + bx + c = 0
 *
 * If you don’t know the quadratic formula for solving such an expression, 
 * do some research. Remember, researching how to solve a problem is often necessary 
 * before a programmer can teach the computer how to solve it. Use doubles for the user 
 * inputs for a, b, and c. Since there are two solutions to a quadratic equation, 
 * output both x1 and x2.
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
double find_discriminant(double, double, double);

//=========================================================

int main()
{
   cout << "Please enter coefficients a, b, and c: ";
   double a, b, c;
   cin >> a >> b >> c;

   double discriminant = find_discriminant(a, b, c);

   double root1 = (-b + sqrt(discriminant)) / (2 * a);
   double root2 = (-b - sqrt(discriminant)) / (2 * a);

   if (discriminant > 0)
      cout << "The roots are: " << root1 << " and " << root2 << "\n";
   else if (discriminant == 0)
      cout << "The root is: " << root1 << "\n";
   else
      cout << "There is no root!\n";
}

//=========================================================

double find_discriminant(double a, double b, double c) 
{
   return (b * b) - (4 * a * c);
}
