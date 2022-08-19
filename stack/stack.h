#include <iostream>
#include <exception>
#include <stdexcept>

#define MAX_SIZE 1000

using namespace std;

template <typename T>
class STACK {
  private:
    T *stack; // stack as dynamic array
    int top;

  public:
    // default constructor
    STACK() {
      stack = new T[MAX_SIZE];
      top = 0;
    }

  void push(T item) {
    if (top >= MAX_SIZE) { // putting on an overflowing stack
      throw length_error("push(): overflowed stack");
    } else {
      stack[top] = item;
      top++;
    }
  }

  T pop() {
    if (top == 0) { // exclude from empty stack
      throw length_error("pop(): empty stack");
    } else {
      top--;
      T item = stack[top];
      return item;
    }
  }

  T peak() { // find top value without exclusion
    if (top == 0) {
      throw length_error("peak(): empty stack");
    } else {
      int peakValue = stack[top - 1];
      return peakValue;
    }
  }

  bool is_empty() {
    return top == 0;
  }

  bool is_full() {
    return top == MAX_SIZE;
  }

  int size() {
    return top;
  }

  // copy constructor STACK(const STACK&)
  STACK(const STACK& copy) {
    // 0. Initialize fields
    stack = nullptr;
    top = 0;

    try {
      // 1. New memory cell for stack array
      stack = new T[copy.top];

      // 2. Copy data from st
      top = copy.top;
      for (int i = 0; i < top; i++)
        stack[i] = copy.stack[i];
    } catch (bad_alloc e) {
      // if memory cell doesn't allocated
      cout << e.what() << endl;
    }
  }

  // assignment operator function
  STACK operator=(const STACK &st) {
    /* SELF ASSIGNMENT CHECK */
    if(this != &st) {
      // 1. Deallocate old memory
      top = 0;
      delete[] stack;

      // 2. Allocate memory for array stack
      try {
        stack = new T[st.top];

        // 3. Copy data from st
        top = st.top;
        for (int i = 0; i < top; i++) {
          stack[i] = st.stack[i];
        }
      } catch (bad_alloc e) {
        cout << e.what() << endl;
      }
    }

    // 4. Return current object
    return *this;
  }

  ~STACK() {
    delete[] stack;
  }

  void print() {
    T* p; // temporary pointer to stack;
    p = stack; // set pointer to top of the stack;

    if (top == 0) {
      cout << "Stack is empty!";
    } else {
      cout << "Stack: ";
      for (int i = 0; i <= top; i++) {
        cout << "Item[" << i << "]" << *p << "/n";
        p++; // set pointer to next element
      }
    }
  }
};
