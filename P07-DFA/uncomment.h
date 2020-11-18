/*
 * File: uncomment.h
 * Project: P07-DFA
 * Created Date: Wednesday November 18th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: Class that eliminates the comments of an input file
 */

#include <iostream>
#include <string>

using namespace std;

class Uncomment {
  private:
    string uncommented_;

  public:
    Uncomment(istream& input);
    ~Uncomment();

    friend ostream& operator<<(ostream& output, Uncomment& uncomment);
};