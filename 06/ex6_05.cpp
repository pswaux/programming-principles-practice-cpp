/**
 * Exercise 4_5
 *
 * Add the article the to the “English” grammar in §6.4.1, so that it can
 * describe sentences such as “The birds fly but the fish swim.”
 *
 *    Grammar;
 *
 *       Sentence:
 *             Noun Verb
 *             Sentence Conjunction Sentence
 *       Conjunction:
 *             "and"
 *             "or"
 *             "but"
 *       Noun:
 *             "birds"
 *             "fish"
 *             "C++"
 *       Verb:
 *             "rules"
 *             "fly"
 *             "swim"
 *       Article:
 *             "The"
 *
 */
#include "std_lib_facilities.h"

int main()
{
   cout << "Sentence:\n"
        << "   Noun Verb\n"
        << "   Sentence Conjunction Sentence\n"
        << "Conjunction:\n"
        << "   \"and\"\n"
        << "   \"or\"\n"
        << "   \"but\"\n"
        << "Noun:\n"
        << "   \"birds\"\n"
        << "   \"fish\"\n"
        << "   \"C++\"\n"
        << "Verb:\n"
        << "   \"rules\"\n"
        << "   \"fly\"\n"
        << "   \"swim\"\n"
        << "Article:\n"
        << "   \"the\"\n\n";

   return 0;
}
