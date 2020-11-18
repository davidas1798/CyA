/*
 * File: dfa.h
 * Project: P07-DFA
 * Created Date: Tuesday November 17th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: The objects of this class represents deterministic finit automatons. It will
 *              contain objects from class State.
 */


#ifndef SET_P07_DFA_DFA_H
#define SET_P07_DFA_DFA_H

#include "state.h"

class DFA {
  private:
    vector<char> alphabet_;   // vector de símbolos del alfabeto
    vector<State> states_;    // vector que almacena los estados del dfa
    State* start_;   // estado de inicio

  public: 
    DFA();
    ~DFA();

    State Transition(State state, char input);
    bool Analyze(string word);

    State& FindState(string state_name);
    size_t Size();

    istream& Read(istream& input);
    friend ostream& operator<<(ostream& output, DFA& printing_dfa);
    
};

#endif //SET_P07_DFA_DFA_H