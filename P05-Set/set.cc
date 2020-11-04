/*
 * File: set.cc
 * Project: P05-Set
 * Created Date: Friday October 30th 2020
 * Author: David Arteaga Sánchez
 */

#include "set.h"

Set::Set() {
  set_.push_back(0);
  max_value_ = kLongSize;
}

Set::Set(int max_value) {
  max_value_ = 0;
  while(max_value_ < max_value) {
    set_.push_back(0);
    max_value_ += kLongSize;
  }
  max_value_ = max_value;
}

void Set::Insert(int element) {
  if(element > max_value_)
    cerr << "El elemento " << element << " sobrepasa el máximo permitido por el conjunto" << endl;
  else if(element < 0)
    cerr << "No puede introducir elementos negativos" << endl;
  else {
      int index = (1 / kBlockSize);
      set_[index] = set_[index] | 1 << ((element-1) % kLongSize);
  }
}

void Set::Erase(int element) {
  if(GetBit(element)) {
    int index = element / kBlockSize;
    set_[index] = set_[index] & ~(1 << element % (kLongSize));
  }
}

void Set::operator++(int) {
  set_.push_back(0);
  max_value_ += kLongSize;
}

Set Set::operator+(Set const &other) {
  Set operand_a, operand_b;
  operand_a = *this;
  operand_b = other;
  // Igualamos el tamaño de los operandos
  while(operand_a.set_.size() < operand_b.set_.size())
    operand_a++;
  while(operand_b.set_.size() < operand_a.set_.size())
    operand_b++;
  // Hacemos la operación intersección y lo guardamos en result
  Set result(operand_a.max_value_);
  /*for(int i = 0; i < result.set_.size(); i++)
    result.set_[i] = operand_a.set_[i] & operand_b.set_[i];*/

  return result;
}

Set Set::operator-(Set const &other) {
  Set operand_a, operand_b;
  operand_a = *this;
  operand_b = other;
  // Igualamos el tamaño de los operandos
  while(operand_a.set_.size() < operand_b.set_.size())
    operand_a++;
  while(operand_b.set_.size() < operand_a.set_.size())
    operand_b++;
  // Hacemos la operación complemento, después intersección y lo guardamos en result
  Set result(operand_a.max_value_);
  
  result = operand_a * !operand_b;

  return result;
}

Set Set::operator*(Set const &other) {
  Set operand_a, operand_b;
  operand_a = *this;
  operand_b = other;
  // Igualamos el tamaño de los operandos
  while(operand_a.set_.size() < operand_b.set_.size())
    operand_a++;
  while(operand_b.set_.size() < operand_a.set_.size())
    operand_b++;
  // Hacemos la operación intersección y lo guardamos en result
  Set result(operand_a.max_value_);
  for(size_t i = 0; i < result.set_.size(); i++)
    result.set_[i] = operand_a.set_[i] & operand_b.set_[i];

  return result;
}

Set Set::operator!() {
  // Hacemos la operación complemento y lo guardamos en result
  Set result(max_value_);
  for(size_t i = 0; i < result.set_.size(); i++)
    result.set_[i] = ~set_[i];

  return result;
}

Set& Set::operator=(Set const &other) { 
  set_ = other.set_;
  max_value_ = other.max_value_;
  return *this;
}

ostream& operator<<(ostream& output, Set& set) {
  output << '{';
  for(int i = 0; i <= set.max_value_; i++) {
    if(set.GetBit(i))
      output << i << ", ";
  }
  output << "\b\b" << '}' << endl;
  return output;
}

/*istream& operator>>(istream& input, Set& set)
{
  input.getline(input, line);


}*/

bool Set::GetBit(int index) {
  int set_index = index / kBlockSize;
  long position = ((index-1) % kBlockSize);
  long result = ((set_[set_index] & 1<<position));

  return result == 1<<position;
}