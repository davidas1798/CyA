#include "palindrome_prod.h"
#include <fstream>


int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    cerr << "Número incorrecto de parámetros" << endl;
    return 1;
  }

  else
  {
    // Creamos un fichero de salida con el nombre del 3º argumento de entrada
    ofstream output_file(argv[2]);
    // Creamos el vector de palindromos  y lo volcamos en el fichero creado
    PalindromeProd palindromes(strtol(argv[1], NULL, 10));
    output_file << palindromes; 
    output_file.close();
    
    return 0;
  }
}
