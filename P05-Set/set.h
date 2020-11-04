/*
 * File: set.h
 * Project: P05-Set
 * Created Date: Friday October 30th 2020
 * Author: David Arteaga Sánchez
 */

#ifndef SET_P05_SET_SET_H_
#define SET_P05_SET_SET_H_

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const size_t kLongSize = 4 * 8;
const size_t kBlockSize = kLongSize+1;

class Set {
  private:
    int max_value_;

  public:
    vector<long> set_;
    Set();
    Set(int max_value);

    void Insert(int element);
    void Erase(int element);

    void operator++(int);
    
    Set operator+(Set const &other);
    Set operator-(Set const &other);
    Set operator*(Set const &other);
    Set operator!();
    Set& operator=(Set const &other);

    vector<long> GetSet() {return set_;}

    friend ostream& operator<<(ostream& output, Set& set);

  private:
    bool GetBit(int index);
};

#endif // SET_P05_SET_SET_H_