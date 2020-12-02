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

/// @brief Constructor of the class Dfa
Dfa::Dfa(istream& input) {
  Read(input);
}

/// @brief Default constructor of the class Dfa
Dfa::Dfa() {}

/// @brief Destructor of the class Dfa
Dfa::~Dfa() {}

/// @brief Does the transition introduced
/// @param state the state where it begins the transition
/// @param input the input symbol of the transition
/// @return Resulting state of the transition
State Dfa::Transition(State state, char input) {
  State output;
  for(int i = 0; i < state.Size(); i++)
    if(state.GetTransition(i).first == input)
      output = FindState(state.GetTransition(i).second);

  return output;
}

/// @brief Analyze a word and checks if it is valid
/// @param word the word to analyze
/// @return true if it is valid, false if it is not
bool Dfa::Analyze(string word) {
  State analyzed = *start_;
  for(int i = 0; i < word.size(); i++) 
    analyzed = Transition(analyzed, word[i]);
  
  return analyzed.Acceptation();
}

bool Dfa::IsInAlphabet(char symbol) {
  for(char alphabet_symbol : alphabet_) {
    if(alphabet_symbol == symbol)
      return true;
  }
  return false;
}

/// @brief Finds the state with the name introduced
/// @param state_name name of the state
/// @return State searched, if it is not in the Dfa it returns the last state
State& Dfa::FindState(string state_name) {
  for(State& possible_state : states_) {
    if(possible_state.GetName() == state_name)
      return possible_state;
  }
  cerr << "El estado no se encuentra en el DFA" << endl; 
  return states_[states_.size() - 1];
}

/// @brief Gets the number of states of the DFA
/// @return Number of states of the DFA
size_t Dfa::Size() {
  return states_.size();
}

/// @brief Converts the dfa to a free context grammar
/// @return the equivalent grammar
Grammar Dfa::ConvertToGrammar() {
  Grammar grammar;
  grammar.SetTerminalSymbols(alphabet_);
  for(size_t i = 0; i < states_.size(); i++)
    grammar.InsertNonterminalSymbols(states_[i]); 
  grammar.SetStart(*start_);
  
  
  return grammar;
}

/// @brief Read the input DFA file and initialize it
/// @param input the input stream that will initialize the DFA
istream& Dfa::Read(istream& input) {
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


