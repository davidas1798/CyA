#include "number_prod.h"

NumberProd::NumberProd(int a, int b):
  operand_a(a),
  operand_b(b),
  number_(a * b) {}

int NumberProd::GetNumber()
{
  return number_;
}

bool NumberProd::operator<(const NumberProd& other) const
{
  if(number_ == other.number_)
  {
    if((operand_a + operand_b) < (other.operand_a + other.operand_b))
      return true;
    else
      return false;
  }

  else
  {
    if(number_ < other.number_)
      return true;
    else
      return false;
  }
}

ostream& operator<<(ostream& os, NumberProd& input)
{
  os << input.number_ << "  <- " << input.operand_a << " * " << input.operand_b;
  return os;
}
