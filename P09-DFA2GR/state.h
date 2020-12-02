/*
 * File: state.h
 * Project: P07-DFA
 * Created Date: Tuesday November 17th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: The objects of this class represents the states of a deterministic finit 
 *              automaton
 */

#ifndef SET_P06_DFA_STATE_H
#define SET_P06_DFA_STATE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class State {
  private:
    string name_;    // índice del estado
    bool acceptation_;   // 0 = no aceptación, 1 = aceptación
	  vector<pair<char, string>> transitions_;		// estructura que almacena las transiciones

  public:
    State();
    State(string name);
    State(string name, bool acceptation);
    ~State();

    void InsertTransition(char symbol, string state);
    void SetAcceptation(bool is_acceptation);

    pair<char,string> GetTransition(unsigned int index);
    string GetName();
    size_t Size();
    bool Acceptation();

    friend ostream& operator<<(ostream& output, State& printing_state);
};

#endif // SET_P07OMPUTABILIDAD Y ALGORITMIA_DFA_STATE_H
