/**
 * Exercise 6_2
 *
 * Add the ability to use {} as well as () in the program, so that 
 * {(4+5)*6} / (3+4) will be a valid expression.
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
//    '(' Expression ')'
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
         return t.value;
      default :
         error("primary expected");
   }
}

