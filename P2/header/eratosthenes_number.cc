#include "eratosthenes_number.hpp"

EratosthenesNumber::EratosthenesNumber(int n):
    number_(n) {} 

inline bool EratosthenesNumber::Prime() {return prime_;}
inline int EratosthenesNumber::Number() {return number_;}