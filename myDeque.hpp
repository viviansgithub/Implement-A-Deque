#ifndef MYDEQUE_HPP_
#define MYDEQUE_HPP_

#include <vector>

template <typename T>
class MyDeque {
 private:
  std::vector<T> frontVector {};
  std::vector<T> backVector {};
  // you can add additional member variables 
  // or member functions as needed.

 public:
  // Default Constructor
  MyDeque();

  // Construct a deque of size n where all entries are value initialised
  // e.g. for a numeric type T initialise to 0, if T is std::string
  // initialise to the empty string
  explicit MyDeque(int n);
  

  // Construct a deque from an initializer list
  MyDeque(std::initializer_list<T> vals);

  // return the last element by reference
  T& back();
  // return the last element by const reference
  // this one can be used on a const MyDeque
  const T& back() const;
  // return the first element by reference
  T& front();
  // return the first element by const reference
  // this one can be used on a const MyDeque
  const T& front() const;

  // add an element to the back of the MyDeque
  void push_back(T);
  // remove last element
  void pop_back();
  // add an element to the front of the MyDeque
  void push_front(T);
  // remove first element
  void pop_front();

  // does the MyDeque have any elements?
  bool empty() const;

  // Getter for the size
  int size() const;

  // Indexing operator.  Return by reference so entry can be modified.
  T& operator[](int);
  // const version can be used to access an entry of a const MyDeque
  const T& operator[](int) const;

 private:
  // in our solution we used a rebalance function with a boolean
  // parameter indicating if the front or back vector is empty.
  // we leave it up to you if you want to include such a function 
  // in your solution.
  // void rebalance(bool);
};
#endif      // MYDEQUE_HPP_
