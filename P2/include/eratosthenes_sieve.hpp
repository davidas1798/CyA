#pragma once 
#include <vector>

class EratosthenesSieve
{
    private:
        vector<EratosthenesNumber> v_;
    public:
        EratosthenesSieve(vector<int> v);
        
        void Sieve();
        
        ostream& Write(ostream& os);

    private:
         void Remove(ErastosthenesNumber n);
         void EraseNonPrime();

};