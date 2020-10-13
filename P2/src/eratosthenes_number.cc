#include "../eratosthenes_number.hpp"

EratosthenesNumber::EratosthenesNumber(int n, bool prime = 1):
    number_(n), 
    prime_(prime) {} 

inline bool EratosthenesNumber::GetPrime() 
{
    return prime_;
}
inline int EratosthenesNumber::GetNumber() 
{
    return number_;
}

inline void EratosthenesNumber::SetPrime(bool prime)
{
    prime_ = prime;
}

inline void EratosthenesNumber::SetNumber(int number)
{
    number_ = number;
}



