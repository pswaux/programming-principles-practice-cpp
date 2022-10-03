/**
 * Exercise 5_7
 * 
 * Quadratic equations are of the form
 *
 *    a⋅x² + b⋅x + c = 0
 *
 * To solve these, one uses the quadratic formula:
 *
 *        −b ± square_root(b² − 4ac)
 *    x = --------------------------
 *                   2a
 *
 * There is a problem, though: if b2–4ac is less than zero, then it will fail.
 * Write a program that can calculate x for a quadratic equation. Create a function 
 * that prints out the roots of a quadratic equation, given a, b, c. When the program 
 * detects an equation with no real roots, have it print out a message. How do you know 
 * that your results are plausible? Can you check that they are correct?
 *
 */
#include "std_lib_facilities.h"

/* prototypes  */
void solve_equation(int, int, int);
int discriminant(int, int, int);

//=========================================================

int main()
try {
   cout << "Enter coefficients a, b, and c: ";
   int a, b, c;
   cin >> a >> b >> c;

   solve_equation(a, b, c);

   return 0;
} catch (exception& e) {
   cerr << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "Unknown exception!\n";
   return 2;
}

//=========================================================

void solve_equation(int a, int b, int c)
// prints out the roots of quadratic equation
{
   if (a == 0) error("error: coefficient 'a' can't be negative!\n");

   int root1, root2;
   int disc = discriminant(a, b, c);

   root1 = (-b + sqrt(disc)) / (2 * a);
   root2 = (-b - sqrt(disc)) / (2 * a);

   if (disc == 0)
      cout << "There is one real root: " << root1 << '\n';
   else
      cout << "The real roots: " << root1 << " and "
           << root2 << '\n';
}

//=========================================================

int discriminant(int a, int b, int c)
// calculate the discriminant of equation
// post-condition: return a positive result
{
   int result = (b * b) - (4 * a * c);

   if (result < 0)
      error("Equation has no real roots!\n");

   return result;
}      
