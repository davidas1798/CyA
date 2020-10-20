#ifndef ERATOSTHENES_INCLUDE_ERATOSTHENES_NUMBER_H
#define ERATOSTHENES_INCLUDE_ERATOSTHENES_NUMBER_H
#include <iostream>

using namespace std;

class EratosthenesNumber
{
    private:
        bool prime_;        // var booleana que devuelve true si el número es primo
        int number_;        // valor del nº almacenado
    public:
        EratosthenesNumber(int n, bool prime = 1);      //constructor

        bool GetPrime();                          // devuelve el valor de prime_
        int GetNumber();                          // devuelve el valor de number_
        void SetPrime(bool prime);                   // establece el valor de prime_
        void SetNumber(int number);                 // establece el valor de number_
        ostream& Write(ostream& os);               // funcion que escribe por pantalla el valor de number_
        friend ostream& operator<<(ostream& os, const EratosthenesNumber& number);
};
#endif //ERATOSTHENES_INCLUDE_ERATOSTHENES_NUMBER_H
