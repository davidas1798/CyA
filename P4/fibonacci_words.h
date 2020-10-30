/*
 * Filename: fibonacci_words.h
 * Created Date: Saturday, October 24th 2020, 2:33:02 pm
 * Author: David Arteaga Sánchez
 * 
 */

 #ifndef FIBONACCI_P4_FIBONACCI_WORDS_H_
 #define FIBONACCI_P4_FIBONACCI_WORDS_H_
 #include <fstream>
 #include <vector>
 #include <string>
 #include <iostream>

 using namespace std;

 class FibonacciWords{
  private:
    vector<string> words_;
  public:
    FibonacciWords();
    FibonacciWords(ifstream& input);
    FibonacciWords(vector<string> words);

    static bool IsFibonacciWord(string word);
    void CheckFibonacciWords(vector<string> words);
    int FibonacciIterations(int word_size);
    static string GenerateFibonacci(int level);

    void push_back(string& word);

    string operator[](int& index);
    friend ostream& operator<<(FibonacciWords& words, ostream& os);
 };
 
 #endif  // FIBONACCI_P4_FIBONACCI_WORDS_H_