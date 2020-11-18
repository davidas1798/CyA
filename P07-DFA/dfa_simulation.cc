/*
 * File: dfa_simulation.cc
 * Project: P07-DFA
 * Created Date: Tuesday November 17th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: This program receives 3 input files: the DFA the input file and the output one. 
 *              It creates the DFA with the first file and check the input file with it, if
 *              the strings satisfies the DFA it will print it in the output file.
 */

#include <fstream>
#include "uncomment.h"
#include "dfa.h"

int main(int argc, char* argv[]) {
  const string kHelp = "--help";

  if(argc > 1 && argv[1] == kHelp) {
    cout << "Ayuda" << endl;
  }

  else if(argc != 4) {
    cerr << "Nº de parámetros incorrecto" << endl;
    cerr << "usage: ./dfa_simulator input.dfa input.txt output.txt" << endl << endl;
    cerr << "Para más ayuda ./dfa_simulator --help" << endl;
  }

  else {
    ifstream input_dfa_file(argv[1]);
    Uncomment uncommented(input_dfa_file);
    ofstream uncommented_dfa_file("tmp");
    uncommented_dfa_file << uncommented;
    uncommented_dfa_file.close();
    ifstream uncommented_dfa_input_file("tmp");
    remove("tmp");
    
    DFA dfa;
    dfa.Read(uncommented_dfa_input_file);

    ifstream input_file(argv[2]);
    ofstream output_file(argv[3]);
    // Leemos cadena por cadena
    string cadena;
    while(!input_file.eof()) {
      input_file >> cadena;
      if(dfa.Analyze(cadena))
        cadena += " -> Sí";
      else
        cadena += " -> No";
      output_file << cadena << endl;
    }
  }
}