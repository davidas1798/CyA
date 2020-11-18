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

#include "dfa.h"

DFA::DFA() {}

DFA::~DFA() {}

State DFA::Transition(State state, char input) {
  State output;
  for(int i = 0; i < state.Size(); i++)
    if(state.GetTransition(i).first == input)
      output = FindState(state.GetTransition(i).second);

  return output;
}

bool DFA::Analyze(string word) {
  State analyzed = *start_;
  for(int i = 0; i < word.size(); i++) 
    analyzed = Transition(analyzed, word[i]);
  
  return analyzed.Acceptation();
}

State& DFA::FindState(string state_name) {
  for(State& possible_state : states_) {
    if(possible_state.GetName() == state_name)
      return possible_state;
  }
  cerr << "El estado no se encuentra en el DFA" << endl; 
  return states_[states_.size() - 1];
}

size_t DFA::Size() {
  return states_.size();
}

istream& DFA::Read(istream& input) {
  size_t alphabet_size, states_size, acceptation_size, transitions_size;
  char symbol;
  string state_name, start_name;
  // 1. Alfabeto
  input >> alphabet_size;
  for(int i = 0; i < alphabet_size; i++) {
    input >> symbol;
    alphabet_.push_back(symbol);
  }
  // 2. Nombres de estados
  input >> states_size;
  for(int i = 0; i < states_size; i++) {
    input >> state_name;
    State state_to_insert(state_name);
    states_.push_back(state_to_insert);
  }
  // 3. Estado inicial
  input >> start_name;
  start_ = &FindState(start_name);
  // 4. Estados de aceptación
  input >> acceptation_size;
  for(int i = 0; i < acceptation_size; i++) {
    input >> state_name;
    FindState(state_name).SetAcceptation(true);
  }
  // 5. Transiciones
  input >> transitions_size;
  for(int i = 0; i < transitions_size; i++) {
    string starting_state_name, ending_state_name;
    input >> starting_state_name;
    input >> symbol;
    input >> ending_state_name;
    FindState(starting_state_name).InsertTransition(symbol, ending_state_name);
  }
  return input;
}


