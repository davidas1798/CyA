#pragma once 
#include <vector>
#include <algorithm>
#include "../include/eratosthenes_number.hpp"

class EratosthenesSieve
{
    private:
        vector<EratosthenesNumber> v_;
    public:
        EratosthenesSieve(vector<int> v);
        
        void Sieve();
        void EraseNonPrime();
        
        ostream& Write(ostream& os) const;
        friend ostream& operator<<(ostream& os, const EratosthenesSieve& vec);

    private:
         void Remove(EratosthenesNumber n);
};