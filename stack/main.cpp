#include <gmock/gmock.h>
#include "stack.h"

using namespace testing;

struct Stack : public Test {};

// Test size
TEST_F(Stack, size) {
  STACK <int> testStack;
  int testValue = 5;
  int testValue2 = 55;

  // add first test item
  testStack.push(testValue);

  int size = testStack.size();

  // Test that size has correct value
  EXPECT_EQ(size, 1);

  // add one more element
  // add second test item
  testStack.push(testValue2);

  // update size
  size = testStack.size();

  // Test that size has correct value
  EXPECT_EQ(size, 2);

  // overflow stack, MAX = 1000
  for (int i = 0; i < 1000; i++) { // MAX size of stack is defined inside STACK class
    int val = rand() % 1000;
    testStack.push(val);
  }

  // update size
  size = testStack.size();

  // Test that size has correct value
  EXPECT_EQ(size, 1000);

  // push to full stack should not change stack
  testStack.push(testValue);
  // update size
  size = testStack.size();

  // Test that size has correct value
  EXPECT_EQ(size, 1000);
}



// Test is_empty
TEST_F(Stack, isEmpty) {
  STACK <int> testStack;
  int testValue = 5;

  // stack should be empty
  EXPECT_TRUE(testStack.is_empty());

  // add first test item
  testStack.push(testValue);

  // stack should not be empty
  EXPECT_FALSE(testStack.is_empty());
}



// Test is_full
TEST_F(Stack, isFull) {
  STACK <int> testStack;
  int testValue = 5;

  // stack should not be full
  EXPECT_FALSE(testStack.is_full());

  // add first test item
  testStack.push(testValue);

  // stack should not be full
  EXPECT_FALSE(testStack.is_full());

  // overflow stack, MAX = 1000
  for (int i = 0; i < 1000; i++) { // MAX size of stack is defined inside STACK class
    int val = rand() % 1000;
    testStack.push(val);
  }

  // stack should be full
  EXPECT_TRUE(testStack.is_full());
}



// Test push 1 element
TEST_F(Stack, pushSingle) {
  STACK <int> testStack1;
  int testValue = 5;

  testStack1.push(testValue);

  // Test that stack is not empty
  EXPECT_FALSE(testStack1.is_empty());
  // Test that peak value same as pushed value
  EXPECT_EQ(testStack1.peak(), testValue);
  // Test that stack has only 1 elements
  EXPECT_TRUE(testStack1.size() == 1);
}



// Test push in full stack
TEST_F(Stack, pushToFull) {
  STACK <int> testStack;
  int testValue = 5;

  // generate full stack
  for (int i = 0; i < 1000; i++) { // MAX size of stack is defined inside STACK class
    int val = rand() % 1000;
    testStack.push(val);
  }

  // Test that stack is full
  EXPECT_TRUE(testStack.is_full());
  // Test that stack has only 1000 elements
  EXPECT_EQ(testStack.size(), 1000);

  // Trying push to full size stack
  testStack.push(testValue);

  // Expect that stack is not changed
  // Test that stack is full
  EXPECT_TRUE(testStack.is_full());
  // Test that stack has only 1000 elements
  EXPECT_TRUE(testStack.size() == 1000);
}



// Test pop from empty stack
TEST_F(Stack, popFromEmpty) {
  STACK <int> testStack;
  int testValue = 5;

  // Test that stack is empty
  EXPECT_TRUE(testStack.is_empty());

  testStack.pop();

  // Test that stack still empty
  EXPECT_EQ(testStack.size(), 0);
}



// Test pop 1 element
TEST_F(Stack, popSingle) {
  STACK <int> testStack;
  int testValue = 5;

  testStack.push(testValue);

  // Test that element added
  EXPECT_EQ(testStack.size(), 1);

  // Test that top has correct value
  EXPECT_EQ(testStack.peak(), testValue);

  int popValue = testStack.pop();
  // Test that pop() return correct value
  EXPECT_EQ(popValue, testValue);

  // Test that element excluded
  EXPECT_EQ(testStack.size(), 0);
}



// Test peak
TEST_F(Stack, peak) {
  STACK <int> testStack;
  int testValue = 5;
  int testValue2 = 55;

  // add first test item
  testStack.push(testValue);

  int stackSize = testStack.size();

  // invoke peak()
  int peakValue = testStack.peak();

  // Test that top has correct value
  EXPECT_EQ(peakValue, testValue);

  //Test that size not changed after call peak()
  EXPECT_EQ(testStack.size(), stackSize);


  // add second item
  testStack.push(testValue2);

  // update peakValue and size
  stackSize = testStack.size();
  peakValue = testStack.peak();

  // Test that top has correct value
  EXPECT_EQ(peakValue, testValue2);

  // Test that size not changed after invoke peak()
  EXPECT_EQ(testStack.size(), stackSize);

  // exclude all elements
  int pop1 = testStack.pop();
  int pop2 = testStack.pop();

  // update peakValue
  peakValue = testStack.peak();

  // should return default 0 for empty stack
  EXPECT_EQ(peakValue, 0);
}
