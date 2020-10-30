/*
 * Filename: f_word.cc
 * Created Date: Monday, October 26th 2020, 9:09:51 pm
 * Author: David Arteaga Sánchez
 * 
 */

#include "f_word.h"

FWord::FWord(string word) {
  word_ = word;
  is_fibonacci_ = IsFibonacci(word);  
}

bool FWord::IsFibonacci(string word) {
  int iterations = FibonacciIterations(word.size());
  string possible_fibonacci = GenerateFibonacci(iterations);

  if(word_ == possible_fibonacci)
    return true;
  else
    return false;
}

int FWord::FibonacciIterations(int word_size)
{
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

string FWord::GenerateFibonacci(int level)
{
  if(level == 1)
    return "a";
  else if(level == 2)
    return "b";
  else
    return GenerateFibonacci(level - 2) + GenerateFibonacci(level - 1);
}

int FWord::GetWord() {
  return word_;
}

bool FWord::GetFibonacci() {
  return is_fibonacci_;
}