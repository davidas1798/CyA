/*
 * File: main_set.cc
 * Project: P05-Set
 * Created Date: Saturday October 31st 2020
 * Author: David Arteaga Sánchez
 */


#include <iostream>
#include "set.h"

using namespace std;

int main() {
  Set set;
  int element;
  
  cin >> element;
  while(element != 0) {
    set.Insert(element);
    cin >> element;
  }
  
  Set result;
  result = set + result;
  cout << result << endl;

  return 0;
}