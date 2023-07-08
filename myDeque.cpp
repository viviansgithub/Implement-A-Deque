#include <iostream>
#include <vector>
#include <string>
#include "myDeque.hpp"

// default constructor (nothing to do here)
template <typename T>
MyDeque<T>::MyDeque() {}

// construct a zero-initialized deque of size n
template <typename T>
MyDeque<T>::MyDeque(int n) : backVector(n) {
}

// Constructor from initializer list
template <typename T>
MyDeque<T>::MyDeque(std::initializer_list<T> vals) : backVector(vals) {
}

template <typename T>
void MyDeque<T>::push_back(T val) {
  backVector.push_back(val);
}

template <typename T>
void MyDeque<T>::push_front(T val) {
  frontVector.push_back(val);
}

template <typename T>
void MyDeque<T>::pop_back() {
  if (backVector.empty()) {
    for (int i = (frontVector.size() - 1) / 2; i >= 0; --i) {
      backVector.push_back(frontVector[i]);
    }
    frontVector.erase(frontVector.begin(), frontVector.begin() + (frontVector.size() + 1) / 2);
  }
  backVector.pop_back();
}

template <typename T>
void MyDeque<T>::pop_front() {
  if (frontVector.empty()) {
    for (int i = (backVector.size() - 1) / 2; i >= 0; --i) {
      frontVector.push_back(backVector[i]);
    }
    backVector.erase(backVector.begin(), backVector.begin() + (backVector.size() + 1) / 2);
  }
  frontVector.pop_back();
}

template <typename T>
T& MyDeque<T>::back() {
if (backVector.empty()) {
    return frontVector.front();
  }
  return backVector.back();
}

template <typename T>
const T& MyDeque<T>::back() const {
if (backVector.empty()) {
    return frontVector.front();
  }
  return backVector.back();
}

template <typename T>
T& MyDeque<T>::front() {
  if (frontVector.empty()) {
    return backVector.front();
  }
  return frontVector.back();
}

template <typename T>
const T& MyDeque<T>::front() const {
  if (frontVector.empty()) {
    return backVector.front();
  }
  return frontVector.back();
}

template <typename T>
bool MyDeque<T>::empty() const {
  if (frontVector.empty()&&backVector.empty()) {
    return true;
  };
    return false;
}

template <typename T>
int MyDeque<T>::size() const {
  return frontVector.size() + backVector.size();
}

template <typename T>
T& MyDeque<T>::operator[](int i) {
  if (i < frontVector.size()) {
    return frontVector[frontVector.size() - i - 1];
  }
  return backVector[i - frontVector.size()];
}
template <typename T>
const T& MyDeque<T>::operator[](int i) const {
  if (i < frontVector.size()) {
    return frontVector[frontVector.size() - i - 1];
  }
  return backVector[i - frontVector.size()];
}

// Do not modify these lines.
// They are needed for the marker.
template class MyDeque<int>;
template class MyDeque<double>;
template class MyDeque<char>;
template class MyDeque<std::string>;
