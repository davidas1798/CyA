/*
 * File: main_set.cc
 * Project: P05-Set
 * Created Date: Saturday October 31st 2020
 * Author: David Arteaga Sánchez
 */


#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>
#include "set.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  if(arv[1] == "--help") {
    cout << "Calculadora de conjuntos:" << endl;
    cout << "Este programa realiza operaciones con conjuntos, ";
    cout << "introduzca un fichero de entrada con el formato {elemento1, elemento2...} [operación] {elemento1, elemento2...} ";
    cout << "y se realizarán dichas operaciones imprimiendose en un fichero de salida" << endl;
  }
  
  else if(argc != 3) {
    cerr << "Número de parámetros incorrecto" << endl;
    cerr << "Usage: ./set_calculator inputfile.txt outputfile.txt" << endl;
    return 2;
  }
  
  else {
    ifstream input_file(argv[1]);
    string line, number;
    int int_number = 0;
    bool suma, resta, multiplicacion, complemento;
    Set* new_set;
    vector<Set> sets;
    vector<int> operaciones;
    
    while(getline(input_file, line)) {
      for(int i = 0; i < line.size(); i++) {
        if(line[i] == '{') {
          new_set = new Set;
        }

        else if(line[i] == '}' || line[i] == ',') {
          int_number = stoi(number);
          new_set->Insert(int_number);
          number.clear();
        }

        else if(line[i] == '+') {
          operaciones.push_back(1);
        }
        else if(line[i] == '-') {
          operaciones.push_back(2);
        }
        else if(line[i] == '*') {
          operaciones.push_back(3)
        }
        else if(line[i] == '!') {
          operaciones.push_back(0);
        }

        else {
          if(isdigit(line[i]))
            number.push_back(line[i]);
        }
      }
    }

    for(int i = 0; i < sets.size(); i++)
      cout << sets[i] << endl;

    return 0;
  }
}