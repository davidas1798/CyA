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
  
  const string kHelp = "--help";
  
  if(argv[1] == kHelp) {
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
    Set* new_set;
    vector<Set> sets;
    vector<int> operaciones;
    vector<Set> resultados;
    
    while(getline(input_file, line)) {
      for(size_t i = 0; i < line.size(); i++) {
        if(line[i] == '{') {
          new_set = new Set;
        }

        else if(line[i] == ',') {
          int_number = stoi(number);
          new_set->Insert(int_number);
          number.clear();
        }

        else if(line[i] == '}') {
          int_number = stoi(number);
          new_set->Insert(int_number);
          number.clear();

          sets.push_back(*new_set);
        }

        else if(line[i] == '+') {
          operaciones.push_back(1);
        }
        else if(line[i] == '-') {
          operaciones.push_back(2);
        }
        else if(line[i] == '*') {
          operaciones.push_back(3);
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

    for(size_t i = 0, j = 0; i < operaciones.size(); i++, j+=2) {
        switch(operaciones[i])
        {
          case 1:
            resultados.push_back(sets[j] + sets[j+1]);
            break;
          case 2:
            resultados.push_back(sets[j] - sets[j+1]);
            break;
          case 3:
            resultados.push_back(sets[j] * sets[j+1]);
            break;
        }
    }
    
    ofstream output(argv[2]);
    for(size_t i = 0; i < resultados.size(); i++)
      output << resultados[i] << endl;
    output.close();

    return 0;
  }
}