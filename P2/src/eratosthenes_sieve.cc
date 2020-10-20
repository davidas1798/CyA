#include "../include/eratosthenes_sieve.h"

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
    for(int i = n.GetNumber() + n.GetNumber()-1; i < v_.size(); i += n.GetNumber())  
    {
        v_[i].SetPrime(0);
        cout << v_[i].GetNumber() << endl;
    }
}

void EratosthenesSieve::EraseNonPrime()
{
    for(int i = 0; i < v_.size(); i++)
        if(!v_[i].GetPrime())
        {
            v_.erase(v_.begin()+i);
            i--;
        }
}

ostream& EratosthenesSieve::Write(ostream& os) const
{
    for(int i = 0; i < v_.size()-1; i++)
    {
        os << v_[i];
        os << ", ";
    }
    os << v_[v_.size()-1];
    os << endl;

    return os;
}

ostream& operator<<(ostream& os, const EratosthenesSieve& vec)
{
    vec.Write(os);

    return os;
}