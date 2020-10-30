/*
 * Filename: fibonacci_words.cc
 * Created Date: Saturday, October 24th 2020, 5:31:18 pm
 * Author: David Arteaga Sánchez
 * 
 */

#include "fibonacci_words.h"

FibonacciWords::FibonacciWords() {}

FibonacciWords::FibonacciWords(ifstream& input) {
  string word;
  
  while(!input.eof()){
    input >> word;
    words_.push_back(word);
  }
}

FibonacciWords::FibonacciWords(vector<string> words) {
  words_ = words;
}

bool FibonacciWords::IsFibonacciWord(string word) {
  if(word == "a" || word == "b")
    return true;
  else {
    /*fibonacci_serie_ = GenerateFibonacci(FibonacciIterations(word.size()));

    if(word == fibonacci_serie_)
      return true;
    else 
      return false;*/
  }
  return false;
}

string FibonacciWords::GenerateFibonacci(int level) {
  if(level == 1)
    return "a";
  else if(level == 2)
    return "b";
  else
    return GenerateFibonacci(level - 2) + GenerateFibonacci(level - 1);
}

int FibonacciWords::FibonacciIterations(int word_size) {
  int prev_size = 1;
  int fibonacci_size = 2;
  int aux;
  
  for(int iteration = 3; fibonacci_size <= word_size; iteration++) {
    if(fibonacci_size == word_size)
      return iteration;
    else {
      aux = fibonacci_size;
      fibonacci_size += prev_size;
      prev_size = aux;
    }
  }
  return 0;
}

