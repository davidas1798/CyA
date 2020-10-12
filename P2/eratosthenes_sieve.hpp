#pragma once 
#include <vector>

class EratosthenesSieve
{
    private:
        vector<EratosthenesNumber> v_;
    public:
        EratosthenesSieve(vector<int> v);
        
        void Sieve();

    private:
         void Remove(ErastosthenesNumber n);
         void EraseNonPrime();

};