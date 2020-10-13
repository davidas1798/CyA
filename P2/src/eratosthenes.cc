#include "../eratosthenes.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cerr << "Número de argumentos incorrecto" << endl;
        return 1;
    }

    else
    {
        vector<int> number_list
        for(int i = 1; i <= argv[1]; i++)
            number_list.push_back(i);
        
        EratosthenesSieve eratosthenes_sieve(number_list);
        eratosthenes_sieve.Sieve();

        cout << "Números primos del 1 al " << argv[1] << ": ";
        eratosthenes_sieve.Write(cout);
    }
}