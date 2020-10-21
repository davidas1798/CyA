#ifndef PALINDROME_INCLUDE_NUMBERPROD_H_
#define PALINDROME_INCLUDE_NUMBERPROD_H_
#include <iostream>

using namespace std;

class NumberProd
{
  private:
    int number_;
    int operand_a;
    int operand_b;
  
  public:
    NumberProd(int a, int b);
    int GetNumber();

    bool operator<(const NumberProd& other) const;
    //bool operator==(const NumberProd& other) const;
    //bool operator!=(const NumberProd& other) const;
    friend ostream& operator<<(ostream& os, NumberProd& input);
};

#endif //PALINDROME_INCLUDE_NUMBERPROD_H_