/*
 * File: dfa2g.cc
 * Project: P09-DFA2GR
 * Created Date: Wednesday December 2nd 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: Main file of the grammar code
 */

#include "dfa.h"
#include "uncomment.h"
#include <fstream>

int main(int argc, char* argv[]) {
  const string kHelp = "--help";

  if(argc > 1 && argv[1] == kHelp) {
    cout << "Programa que convierte un DFA a una gramática que repreasente el mismo lenguaje" << endl;
    cout << "usage: ./dfa2g input.dfa output.gra" << endl;
  }

  else if(argc != 3) {
    cerr << "Nº de parámetros incorrecto" << endl;
    cerr << "usage: ./dfa2g input.dfa output.gra" << endl << endl;
    cerr << "Para más ayuda ./dfa_simulator --help" << endl;
  }

  else {
  ifstream input_dfa_file(argv[1]);
  ofstream output_grammar(argv[2]);
  Uncomment uncommented(input_dfa_file);
  ofstream uncommented_dfa_file("tmp");
  uncommented_dfa_file << uncommented;
  uncommented_dfa_file.close();
  ifstream uncommented_dfa_input_file("tmp");
  remove("tmp");
  
  Dfa dfa;
  dfa.Read(uncommented_dfa_input_file);
  Grammar grammar;
  grammar = dfa.ConvertToGrammar();

  output_grammar << grammar;
  }
}
