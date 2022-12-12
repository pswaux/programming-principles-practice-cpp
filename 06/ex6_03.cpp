/**
 * Exercise 6_3
 *
 * Add a factorial operator: use a suffix ! operator to represent “factorial.”
 * For example, the expression 7! means 7 * 6 * 5 * 4 * 3 * 2 * 1. Make ! bind
 * tighter than * and /; that is, 7*8! means 7*(8!) rather than (7*8)!. Begin by
 * modifying the grammar to account for a higher-level operator. To agree with the 
 * standard mathematical definition of factorial, let 0! evaluate to 1. 
 * Hint: The calculator functions deal with doubles, but factorial is defined only 
 * for ints, so just for x!, assign the x to an int and calculate the factorial
 * of that int.
 * 
 * ---------------------------------------------
 *
 * Grammer;
 *
 *       Expression:
 *             Term
 *             Expression "+" Term
 *             Expression "-" Term
 *       Term:
 *             Primary 
 *             Term "*" Primary
 *             Term "/" Primary
 *             Term "%" Primary
 *       Primary:
 *             Number
 *             "{" Expression "}" 
 *             "(" Expression ")"
 *       Number:
 *             floating-point literal
 *
 *
 */
#include "std_lib_facilities.h"

class Token {
public:
   char kind;
   double value;

   Token(char ch)    // make a Token from a char
     :kind(ch), value(0) { }
      
   Token(char ch, double val)     // make a Token from a char and a double
     :kind(ch), value(val) { }
};

//==========================================================

class Token_stream {
public:
   Token_stream();
   Token get();
   void putback(Token t);

private:
   bool full {false};
   Token buffer;
};

//==========================================================

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//==========================================================

void Token_stream::putback(Token t)
{
   if (full) error("putback() into a full buffer");
   buffer = t;    // copy t to buffer
   full = true;   // buffer is now full
}

//==========================================================

Token Token_stream::get()
{
   if (full) {          // do we already have a Token ready?
      full = false;     // remove Token from buffer
      return buffer;
   }

   char ch;
   cin >> ch;

   switch (ch) {
      case ';' :  // for "print"
      case 'q' :  // for "quit"
      case '(' : case ')' : case '+' : case '-' :
      case '*' : case '/' : case '{' : case '}' :
      case '!' :
         return Token{ch}; // let each character represent itself
      case '.' :
      case '0' : case '1' : case '2' : case '3' : case '4' :
      case '5' : case '6' : case '7' : case '8' : case '9' :
         {
            cin.putback(ch);  // put digit back into the input stream
            double val;
            cin >> val;

            return Token{'8', val}; // let '8' represent "a number"
         }
      default :
         error("Bad token");
   }
}

//==========================================================

Token_stream ts;

/* prototypes  */
double expression(); // deal with + and -
double term();       // deal with *,/, and %
double primary();    // deal with numbers and parentheses
double factorial(int);

//==========================================================

int main()
try {
   double val = 0;
   while (cin) {
      Token t = ts.get();

      if (t.kind == 'q') break;
      if (t.kind == ';')
         cout << "= " << val << '\n';
      else
         ts.putback(t);
      val = expression();
   }
} catch (exception& e) {
   cerr << e.what() << '\n';
   return 1;
} catch (...) {
   cerr << "exception\n";
   return 2;
}

//==========================================================

double expression()
// Expression:
//    Term
//    Expression '+' Term
//    Expression '-' Term
{
   double left = term();      // read and evaluate a Term
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
         case '+' :
            left += term();   // evaluate Term and add
            t = ts.get();
            break;
         case '-' :
            left -= term();   // evaluate Term and subtract
            t= ts.get();
            break;
         default :
            ts.putback(t);
            return left;      // finally: no more + or -; return the answer
      }
   }
}

//==========================================================

double term()
// Term:
//    Primary
//    Term '*' Primary
//    Term '/' Primary
//    Term '%' Primary
{
   double left = primary();
   Token t = ts.get();

   while (true) {
      switch (t.kind) {
         case '*' :
            left *= primary();
            t = ts.get();
            break;
         case '/' : 
            {
               double d = primary();
               if (d == 0) error("divide by zero");
               left /= d;
               t = ts.get();
               break;
            }
         default :
            ts.putback(t);
            return left;
      }
   }
}

//==========================================================

double primary()
// Primary:
//    Number
//    Number '!'
//    '(' Expression ')'
//    '{' Expression '}'
{
   Token t = ts.get();

   switch (t.kind) {
      case '(' :
         {
            double d = expression();
            t = ts.get();

            if (t.kind != ')') error("')' expected");
            return d;
         }
      case '{' :
         {
            double d = expression();
            t = ts.get();

            if (t.kind != '}') error("'}' expected");
            return d;
         }
      case '8' :
         {
            int val = t.value;
            Token t2 = ts.get();

            if (t2.kind == '!')
               t.value = factorial(val);
            else
               ts.putback(t2);

            return t.value;
         }
      default :
         error("primary expected");
   }
}

//==========================================================

double factorial(int value)
{
   int fact = 1;

   while (value > 1) {
      fact *= value;
      --value;
   }
   return fact;
}
