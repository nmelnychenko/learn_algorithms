#include <iostream>

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
      cout << "push() did not called. Stack is overflowed!";
    } else {
      stack[top] = item;
      top++;
    }
  }

  T pop() {
    if (top == 0) { // exclude from empty stack
      cout << "Can not call pop() for the stack. The stack is empty!";
      return 0;
    } else {
      top--;
      T item = stack[top];
      return item;
    }
  }

  T peak() { // find top value without exclusion
    if (top == 0) {
      cout << "Stack is empty!";
      return 0;
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
