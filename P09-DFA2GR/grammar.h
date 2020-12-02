/*
 * File: grammar.h
 * Project: P09-DFA2GR
 * Created Date: Tuesday December 1st 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: The objects of this class represents a context free grammar.
 */

#include "state.h"
#include <iostream>

class Grammar {
  private:
    vector<char> terminal_symbols;    /// símbolos terminales de la gramática
    vector<State> nonterminal_symbols;   /// símbolos no terminales de la gramática

    State* start_;    /// estado de arranque
    size_t size_;     /// nº de producciones

  public:
    Grammar(istream& input);
    Grammar();
    ~Grammar();

    void SetTerminalSymbols(vector<char> symbols);
    void InsertNonterminalSymbols(State state);
    void SetStart(State& start);

    State& GetStart();
    State& GetState(string state_name);
    size_t GetSize();
    
    bool IsInAlphabet(char symbol);

    //Grammar& operator=(const Grammar& other);
    friend ostream& operator<<(ostream& output, Grammar& grammar_to_print);
  
};
