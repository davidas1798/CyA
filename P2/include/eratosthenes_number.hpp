#pragma once

class EratosthenesNumber
{
    private:
        bool prime_;
        int number_;
    public:
        EratosthenesNumber(int n, bool prime = 1);

        bool GetPrime();
        int GetNumber();
        void setPrime(bool prime);
        void setNumber(int number);
};
