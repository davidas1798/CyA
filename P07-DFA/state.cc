/*
 * File: state.cc
 * Project: P07-DFA
 * Created Date: Tuesday November 17th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: The objects of this class represents the states of a deterministic finit 
 *              automaton
 */

#include "state.h"

/// @brief Creates an empty State (without transitions)
State::State() {}

/// @brief Creates a state with the name introduced and without transitions
/// @param name is the name that the state will have
State::State(string name) {
  name_ = name;
  acceptation_ = false;
}

/** @brief Creates a state with the name introduced and setting if is or not an acceptation 
*   state without transitions **/
/// @param name is the name that the state will have
/// @param acceptation is true if the state is an acceptation one
State::State(string name, bool acceptation) {
  name_ = name;
  acceptation_ = acceptation;
}

/// @brief The destructor of the class State
State::~State() {}

/// @brief Inserts a transition in the state
/// @param symbol the input symbol of the transition
/// @param state the name of the state that returns the transition
void State::InsertTransition(char symbol, string state) {
  pair<char, string> new_transition(symbol, state);
  transitions_.push_back(new_transition);
}

/// @brief Sets the value of the attribute acceptation_
/// @param is_acceptation the value that will be set in acceptation_
void State::SetAcceptation(bool is_acceptation) {
  acceptation_ = is_acceptation;
}

/// @brief Gets the transition in the index position
/// @param index the index of the transition
/// @return the transition in the index position
pair<char, string> State::GetTransition(unsigned int index)  {
  return transitions_[index];
}

/// @brief Gets the name of the state
/// @return Name of the state
string State::GetName() {
  return name_;
}

/// @brief Gets the number of transitions of the state
/// @return Number of transitions of the state
size_t State::Size() {
  return transitions_.size();
}

/// @brief Gets if the state is or not an acceptation one
/// @return Value of acceptation_ attribute
bool State::Acceptation() {
  return acceptation_;
}

/// @brief Overload of the operator << to print the state
/// @param output output stream that will be used to print the state
/// @param printing_state the state that will be printed
ostream& operator<<(ostream& output, State& printing_state) {
  // Esto imprime la parte final del fichero
  vector<pair<char, string>>& transitions = printing_state.transitions_;
  string name = printing_state.name_;

  for(int i = 0; i < transitions.size(); i++)
    output << name << " " << transitions[i].first << " " << transitions[i].second << endl;
  return output;
}


