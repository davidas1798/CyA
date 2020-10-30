/*
 * Filename: f_word.h
 * Created Date: Monday, October 26th 2020, 9:09:51 pm
 * Author: David Arteaga Sánchez
 * 
 */

#ifndef FIBONACCI_P4_F_WORD_H_
#define FIBONACCI_P4_F_WORD_H_

class FWord {
  private:
    string word_;
    bool is_fibonacci_;
  public:
    FWord(string);

    static bool IsFibonaccci(string);
    int FibonacciIterations(int word_size);
    static string GenerateFibonacci(int level);
    
    string GetWord();
    bool GetFibonacci();

};

