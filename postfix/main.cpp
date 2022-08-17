#include <iostream>
#include <gmock/gmock.h>
#include "../stack/stack.h"

using namespace testing;

int priority (char ch) {
  if(ch == '+' || ch == '-') {
    return 1;
  }

  if(ch == '*' || ch == '/') {
    return 2;
  }

  if(ch == '^') {
    return 3;
  }

  return 0;
}

string infixToPostfix(string expression) {
  int i = 0;
  string result = "";
  STACK <int> stack;

  for (int i = 0; i < expression.length(); i++) {
    char ch = expression[i];

    // 1. If character is number -> move to result
    if (ch >= '0' && ch <= '9') {
      result += ch;
    }

    // 2.1. If character is opening paranthes `(` -> push() to stack
    else if (ch == '(') {
      stack.push('(');
    }

    // 2.2. If character is closing paranthes `)` -> pop() to output string untild find `(` in stack
    else if (ch == ')') {
      while (stack.peak() != '(') {
        result += stack.peak();
        stack.pop();
      }

      stack.pop();
    }

    // 3. If character is operator
    else {
      // check if character operator has higher priority that in stack
      while (!stack.is_empty() && priority(ch) <= priority(stack.peak())) {
        result += stack.peak();
        char tmp = stack.pop();
      }
      stack.push(ch);
    }
  }

  // 4. Exclude all remaining element from stack
  while (!stack.is_empty()) {
    result += stack.peak();
    stack.pop();
  }

  return result;
}

struct InfixPostfix : public Test {};

// Single operation
TEST_F(InfixPostfix, Single) {
  string infix = "1+2";
  string expected = "12+";
  string result = infixToPostfix(infix);

  EXPECT_EQ(result, expected);
}

// Two different priority operations
TEST_F(InfixPostfix, TwoDiffPriority) {
  string infix = "1+2*3";
  string expected = "123*+";
  string result = infixToPostfix(infix);

  EXPECT_EQ(result, expected);
}

// With parantheses
TEST_F(InfixPostfix, TwoWithParantheses) {
  string infix = "(1+2)*3";
  string expected = "12+3*";

  EXPECT_EQ(infixToPostfix(infix), expected);
}

// Long expression
TEST_F(InfixPostfix, Long) {
  string infix = "5+3*4-6/(2+1)";
  string expected = "534*+621+/-";

  EXPECT_EQ(infixToPostfix(infix), expected);
}
