#include <iostream>
#include <exception>
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
  STACK <char> stack;

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
        result += stack.pop();
      }

      stack.pop();
    }

    // 3. If character is operator
    else {
      // check if character operator has higher priority that in stack
      while (!stack.is_empty() && priority(ch) < priority(stack.peak())) {
        result += stack.pop();
      }
      stack.push(ch);
    }
  }

  // 4. Exclude all remaining element from stack
  while (!stack.is_empty()) {
    result += stack.pop();
  }

  return result;
}


float calculatePostfix(string postfix) {
  float a, b;
  STACK <float> stack; // stack would have only calculated and postponed values

  for(int i = 0; i < postfix.length(); i++) {
    char ch = postfix[i];
    if (ch >= '0' && ch <= '9') {
      stack.push(postfix[i] - '0'); // return float from char
    }

    // if symbol is an operator then pop top 2 elements from stack,
    // perform specific operation and push the result back into stack
    else {
      b = stack.pop();
      a = stack.pop();

      switch(postfix[i]) {
        case '+':
          stack.push(a + b);
          break;
        case '-':
          stack.push(a - b);
          break;
        case '*':
          stack.push(a * b);
          break;
        case '/':
          stack.push(a / b);
          break;
        case '^':
          stack.push(pow(a, b));
          break;
        default:
          throw invalid_argument("unhandled symbol");
      }
    }
  }

  return stack.pop();
}


struct InfixPostfix : public Test {};

// Single operation
TEST_F(InfixPostfix, Single) {
  string infix = "1+2";
  string expected = "12+";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 3);
}

// Two different priority operations
TEST_F(InfixPostfix, TwoDiffPriority) {
  string infix = "1+2*3";
  string expected = "123*+";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 7);
}

// With parantheses
TEST_F(InfixPostfix, TwoWithParantheses) {
  string infix = "(1+2)*3";
  string expected = "12+3*";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 9);
}

// Long expression
TEST_F(InfixPostfix, Long) {
  string infix = "5+3*4-6/(2+1)";
  string expected = "534*621+/-+";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 15);
}

// single pow
TEST_F(InfixPostfix, SinglePow) {
  string infix = "2^3";
  string expected = "23^";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 8);
}

// long expression with pow operation
TEST_F(InfixPostfix, LongWithPow) {
  string infix = "4*((2+3)*2)^2+5*(2^3+2)";
  string expected = "423+2*2^*523^2+*+";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 450);
}

// nested pow operation
TEST_F(InfixPostfix, NestedPow) {
  string infix = "4^3^2";
  string expected = "432^^";
  string result = infixToPostfix(infix);
  float evaluatePostfix = calculatePostfix(result);

  EXPECT_EQ(result, expected);
  EXPECT_EQ(evaluatePostfix, 262144);
}
