#include "palindrome_prod.h"

PalindromeProd::PalindromeProd(int number)
{
  for(int i = 1; IsNDigit(number, i); i++)
    for(int j = 1; IsNDigit(number, j); j++)
    {
      NumberProd possible_palindrome = NumberProd(i, j);
      if(IsPalindrome(possible_palindrome.GetNumber()))
        palindromes_vector_.insert(possible_palindrome);
    }
}

bool PalindromeProd::IsPalindrome(int number)
{
  int *dup_number = new int(number);
  return IsPalindromeRecursive(number, dup_number);
}

bool PalindromeProd::IsPalindromeRecursive(int number, int *dup_number)
{
  if(IsOneDigit(number))
    return (number == (*dup_number) % 10);
  if(!IsPalindromeRecursive(number/10, dup_number))
    return false;
  *dup_number /= 10;
  return (number % 10 == (*dup_number) % 10);
}

bool PalindromeProd::IsOneDigit(int number)
{
  return number >= 0 && number < 10;
}

bool PalindromeProd::IsNDigit(int n, int number)
{
  return number >= 0 && number < pow(10,n-1) * 10;
}

ostream& operator<<(ostream& os, PalindromeProd& input)
{
  for(set<NumberProd>::iterator i = input.palindromes_vector_.begin(); i != input.palindromes_vector_.end(); i++)
  {
    NumberProd aux = *i;
    os << aux;
    os << endl;
  }

  return os;
}