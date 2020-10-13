#include "eratosthenes_sieve.hpp"

EratosthenesSieve::EratosthenesSieve(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        EratosthenesNumber n(v[i]);
        v_.push_back(n);
    }
}

void EratosthenesSieve::Sieve()
{
    for(int i = 1; i < v_.size(); i++)
    {
        if(v_[i].GetPrime())
            Remove(v_[i]);
    }
}

void EratosthenesSieve::Remove(EratosthenesNumber n)
{
    for(int i = n+n; i < v_.size(); i += n)
        v_[i].setPrime(0);
}

void EratosthenesSieve::EraseNonPrime()
{
    for(int i = 0; i < v_.size(); i++)
        if(!v[i].GetPrime())
            v_.erase(i);
}

ostream& Write(ostream& os)
{
    for(int i = 0; i < v_.size()-1; i++)
        os << v_[i] << ", ";
    os << v_[v_.size()-1] << endl;
}