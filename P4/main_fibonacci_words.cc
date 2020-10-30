/*
 * Filename: main_fibonacci_words.cc
 * Created Date: Sunday, October 25th 2020, 6:43:58 pm
 * Author: David Arteaga Sánchez
 * 
 */

#include "fibonacci_words.h"

int main(int argc, char *argv[]) {
  if(argc != 3 && argv[1] != "--help") {
    cerr << "Uso incorrecto del programa" << endl;
    cerr << "./fibonacci_words --help" << endl;

    return 1;
  }

  else if(argv[1] == "--help") {
    cout << "usage: ./fibonacci_words [input_file] [output_file]" << endl << endl;
    cout << "This program receive an input text file and returns another one specifying";
    cout << " the ones which are fibonacci words" << endl;

    return 2;
  }

  else {
    int palabra;
    cin >> palabra;

    cout << endl << FibonacciWords::GenerateFibonacci(palabra) << endl;

    return 0;
  }
}
