/*
 * File: set.cc
 * Project: P05-Set
 * Created Date: Friday October 30th 2020
 * Author: David Arteaga Sánchez
 */

#include "set.h"

/// @brief Constructor por defecto
Set::Set() {
  set_.push_back(0);
  max_value_ = kLongSize;
}

/// @brief Constructor con parámetro de máximo valor
/// @param max_value es el máximo valor que se puede almacenar en el conjunto
Set::Set(int max_value) {
  max_value_ = 0;
  while(max_value_ < max_value) {
    set_.push_back(0);
    max_value_ += kLongSize;
  }
  max_value_ = max_value;
}

/// @brief Inserta un elemento en el conjunto
/// @param element elemento a insertar en el conjunto
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

/// @brief Elimina un elemento del conjunto
/// @param element elemento a eliminar del conjunto
void Set::Erase(int element) {
  if(GetBit(element)) {
    int index = element / kBlockSize;
    set_[index] = set_[index] & ~(1 << element % (kLongSize));
  }
}

/// @brief Aumenta el tamaño del conjunto
void Set::operator++(int) {
  set_.push_back(0);
  max_value_ += kLongSize;
}

/// @brief Realiza la operación de concatenación con otro conjunto
/// @param other es el otro conjunto con el que se concatena
/// @return El conjunto resultado de la operación
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
  for(size_t i = 0; i < result.set_.size(); i++)
    result.set_[i] = operand_a.set_[i] | operand_b.set_[i];

  return result;
}

/// @brief Realiza la operación de diferencia con otro conjunto
/// @param other es el otro conjunto con el que se concatena
/// @return El conjunto resultado de la operación
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

/// @brief Realiza la operación de intersección con otro conjunto
/// @param other es el otro conjunto con el que se concatena
/// @return El conjunto resultado de la operación
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

/// @brief Realiza la operación de complemento
/// @return El conjunto resultado de la operación
Set Set::operator!() {
  // Hacemos la operación complemento y lo guardamos en result
  Set result(max_value_);
  for(size_t i = 0; i < result.set_.size(); i++)
    result.set_[i] = ~set_[i];

  return result;
}

/// @brief Operador de asignación
/// @param other es el conjunto al que se va a igualar
Set& Set::operator=(Set const &other) { 
  set_ = other.set_;
  max_value_ = other.max_value_;
  return *this;
}

/// @brief Operador de salida de flujo
/// @param output canal de salida
/// @param set conjunto que se va a imprimir
ostream& operator<<(ostream& output, Set& set) {
  output << '{';
  for(int i = 0; i <= set.max_value_; i++) {
    if(set.GetBit(i))
      output << i << ", ";
  }
  output << "\b\b" << '}' << endl;
  return output;
}

/// @brief Indica si un número se encuentra en el conjunto
/// @param index número que queremos saber si está en el conjunto
/// @return true si index está, false si no está
bool Set::GetBit(int index) {
  int set_index = index / kBlockSize;
  long position = ((index-1) % kBlockSize);
  long result = ((set_[set_index] & 1<<position));

  return result == 1<<position;
}