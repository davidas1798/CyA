#pragma once
#include <iostream>

using namespace std;

class EratosthenesNumber
{
    private:
        bool prime_;
        int number_;
    public:
        EratosthenesNumber(int n, bool prime = 1);

        bool GetPrime();
        int GetNumber();
        void SetPrime(bool prime);
        void SetNumber(int number);
        ostream& write(ostream& os);
        friend ostream& operator<<(ostream& os, const EratosthenesNumber& number);
};
