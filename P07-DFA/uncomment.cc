/*
 * File: uncomment.cc
 * Project: P07-DFA
 * Created Date: Wednesday November 18th 2020
 * College: ULL
 * Author: David Arteaga Sánchez
 * 
 * Description: Class that eliminates the comments of an input file
 */

#include "uncomment.h"

/// @brief Constructor of the class Uncomment that removes the comments of an input file
/// @param input file with comments to remove
Uncomment::Uncomment(istream& input) {
  string line, result;
  while(getline(input, line)) {
    for(int i = 0; i < line.size(); i++) {
      if(line[i] != '/' || line[i + 1] != '/')
        result += line[i];
      else {
        break;
      }
    }
    result += '\n';
  }
  result.pop_back();
  uncommented_ = result;
}

/// @brief Destructor of the class
Uncomment::~Uncomment() {}

/// @brief Overload of the operator << to print the new uncommented file
/// @param output the output stream where will be printed the uncommented file
/// @param uncomment the object of the class to print
ostream& operator<<(ostream& output, Uncomment& uncomment) {
  output << uncomment.uncommented_;
  return output;
}