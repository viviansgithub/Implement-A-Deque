# Implement-A-Deque
 This is one of the assignments I completed for my UTS Data Structures & Algorithms subject and I implemented a toy version of a deque using 2 std::vectors.  The type of element the deque holds can be passed as a template parameter and my solution was tested by instantiating the template type with int, double, char, and std::string.  I was not allowed to use std::deque itself in this exercise. There are 5 groups of member functions described below which I needed to implement for this assignment.

Constructors:
I implemented 3 constructors:

  // Default constructor
  MyDeque();
  
  // Construct a deque of size n where all entries are value initialised
  // e.g. for a numeric template type T initialise to 0, if T is std::string
  // initialise to the empty string
  explicit MyDeque(int n);

  // Construct a deque from an initializer list
  MyDeque(std::initializer_list<T> vals);

Front and Back
Member functions to get the first and last element of the deque.  These functions should work in constant time.

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

Operator[]
Access an element of the deque by its index.  This function should work in constant time.

  // Indexing operator.  Return by reference so entry can be modified.
  T& operator[](int);
  // const version can be used to access an entry of a const MyDeque
  const T& operator[](int) const;
Push/Pop Back/Front
Add/Remove an element from the front or back of the deque.  These functions should work in constant amortised time.

  // add an element to the back of the MyDeque
  void push_back(T);
  // remove last element
  void pop_back();
  // add an element to the front of the MyDeque
  void push_front(T);
  // remove first element
  void pop_front();

Functions Related to the Number of Elements
Two functions related to the number of elements in the MyDeque and these should work in constant time.

  // does the MyDeque have any elements?
  bool empty() const;
  // Getter for the size
  int size() const;


The Code
There are three files provided in the scaffold :
The header file myDeque.hpp contains the definitions of all member functions of the MyDeque class. 
The implementation file myDeque.cpp which is where I implemented all the required member functions.
The main.cpp file is provided for my own testing and debugging purposes.  This is the file that is compiled and executed when "Run" is pressed.
