#include "../include/eratosthenes_number.hpp"

EratosthenesNumber::EratosthenesNumber(int n, bool prime):
    number_(n), 
    prime_(prime) {} 

bool EratosthenesNumber::GetPrime() 
{
    return prime_;
}
int EratosthenesNumber::GetNumber() 
{
    return number_;
}
void EratosthenesNumber::SetPrime(bool prime)
{
    prime_ = prime;
}
void EratosthenesNumber::SetNumber(int number)
{
    number_ = number;
}

ostream& EratosthenesNumber::write(ostream& os)
{
    os << number_;
    return os;
}

ostream& operator<<(std::ostream& os, const EratosthenesNumber& number)
{
    os << number.number_;
    return os;
}



