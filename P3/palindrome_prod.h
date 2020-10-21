#ifndef PALINDROME_INCLUDE_PALINDROMEPROD_H
#define PALINDROME_INCLUDE_PALINDROMEPROD_H
#include <set>
#include <cmath>
#include "number_prod.h"

class PalindromeProd
{
  private:
    set<NumberProd> palindromes_vector_;
    int sz_;

  public:
    PalindromeProd(int n);

    bool IsPalindrome(int number);

    friend ostream& operator<<(ostream& os, PalindromeProd& input);

  private:
    bool IsPalindromeRecursive(int number, int *dup_number);
    bool IsOneDigit(int number);
    bool IsNDigit(int n, int number);
};

#endif // PALINDROME_INCLUDE_PALINDROMEPROD_H
