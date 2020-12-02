/*
 * File: grammar.cc
 * Project: P09-DFA2GR
 * Created Date: Tuesday December 1st 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: The objects of this class represents a context free grammar.
 */

#include "grammar.h"

/// @brief Constructor of the class Grammar
/// @param input input stream wich will initialize
Grammar::Grammar(istream& input) {
  size_t alphabet_size, states_size, productions_size;
  string state_name, start_name;
  char symbol;
  /// 1. Símbolos terminales
  input >> alphabet_size;
  for(size_t i = 0; i < alphabet_size; i++) {
    input >> symbol;
    terminal_symbols.push_back(symbol);
  }
  /// 2. Símbolos no terminales
  input >> states_size;
  for(size_t i = 0; i < states_size; i++) {
    input >> state_name;
    State state_to_insert(state_name);
    nonterminal_symbols.push_back(state_to_insert);
  }
  /// 3. Arranque
  input >> start_name;
  cout << "ESTO ES: " << start_name;
  start_ = &GetState(start_name);
  /// 4. Producciones
  State ending_state("ending", true);
  input >> productions_size;
  size_ = productions_size;
  for(size_t i = 0; i < productions_size; i++) {
    string starting_state_name, destiny_state_name, arrow, line;
    input >> starting_state_name;
    input >> arrow;
    if(arrow != "->" && arrow != "−>")
      cerr << "Error creando la producción. Uso correcto: A -> a" << endl;
    input >> line;
    if((line.size() == 1 && IsInAlphabet(line[0])))
      GetState(starting_state_name).InsertTransition(line[0], ending_state.GetName());
    else if(line == "~")
      GetState(starting_state_name).SetAcceptation(true);
    else {
      destiny_state_name = line[line.size() - 1];
      for(size_t i = 0; i < line.size() - 1; i++) {
        symbol = line[i];
        GetState(starting_state_name).InsertTransition(symbol, destiny_state_name);
      }
    }
  }
}

/// @brief Default constructor of the grammar
Grammar::Grammar() {
  start_ = NULL;
  size_ = 0;
}

/// @brief Sets the terminal symbols
/// @param symbols the vector that will be used to initialize the terminal symbols
void Grammar::SetTerminalSymbols(vector<char> symbols) {
  terminal_symbols = symbols;
}

/// @brief Sets the nonterminal symbols
/// @param symbols the vector that will be used to initialize the nonterminal symbols
void Grammar::InsertNonterminalSymbols(State state) {
  nonterminal_symbols.push_back(state);
}

/// @brief Destructor of the class Grammar
Grammar::~Grammar() {
  terminal_symbols.clear();
  nonterminal_symbols.clear();
}

/// @brief Gets the start production of the grammar
/// @return the start production of the grammar
State& Grammar::GetStart() {
  return *start_;
}

/// @brief Sets the start production
void Grammar::SetStart(State& start) {
  start_ = &start;
}

/// @brief Finds the state with the name introduced
/// @param state_name name of the state that will be searched
/// @return the state with the name state_name
State& Grammar::GetState(string state_name) {
  for(State& possible_state : nonterminal_symbols) {
    if(possible_state.GetName() == state_name)
      return possible_state;
  }
  cerr << "El estado no se encuentra en el DFA" << endl; 
  return nonterminal_symbols[nonterminal_symbols.size() - 1];
}

/// @brief Gets the number of productions
size_t Grammar::GetSize() {
  return size_;
}

/// @brief Checks if a symbol is in the alphabet
/// @param symbol the character to check
bool Grammar::IsInAlphabet(char symbol) {
  for(char alphabet_symbol : terminal_symbols) {
    if(alphabet_symbol == symbol)
      return true;
  }
  return false;
}
/*
/// @brief operator = overloaded
Grammar& Grammar::operator=(const Grammar& other) {
  *this->terminal_symbols = other.terminal_symbols;
  for(int i = 0; i < other.nonterminal_symbols; i++) 
    *this->nonterminal_symbols.push_back(other.nonterminal_symbols[i])
  return *this;
}*/

/// @brief prints the grammar
/// @param output the output stream where the grammar will be printed
ostream& operator<<(ostream& output, Grammar& grammar_to_print) {
  /// 1. Terminales
  output << grammar_to_print.terminal_symbols.size() << endl;
  for(size_t i = 0; i < grammar_to_print.terminal_symbols.size(); i++)
    output << grammar_to_print.terminal_symbols[i] << endl;
  /// 2. No terminales
  output << grammar_to_print.nonterminal_symbols.size() << endl;
  for(size_t i = 0; i < grammar_to_print.nonterminal_symbols.size(); i++)
    output << grammar_to_print.nonterminal_symbols[i].GetName() << endl;
  /// 3. Inicio
  output << grammar_to_print.GetStart().GetName() << endl;
  /// 4. Producciones
  output << grammar_to_print.size_ << endl;
  for(size_t i = 0; i < grammar_to_print.nonterminal_symbols.size(); i++) {
    for(size_t j = 0; j < grammar_to_print.nonterminal_symbols[i].Size(); j++) {
      output << grammar_to_print.nonterminal_symbols[i].GetName();
      output << " -> ";
      output << grammar_to_print.nonterminal_symbols[i].GetTransition(j).first;
      output << grammar_to_print.nonterminal_symbols[i].GetTransition(j).second << endl;
    }
    if(grammar_to_print.nonterminal_symbols[i].Acceptation())
      output << grammar_to_print.nonterminal_symbols[i].GetName() << " -> ~" << endl;
  }
  return output;
}