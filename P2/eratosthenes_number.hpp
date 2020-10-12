#pragma once

class EratosthenesNumber
{
    private:
        bool prime_ = 1;
        int number_;
    public:
        EratosthenesNumber(int n);

        bool Prime();
        int Number();
};