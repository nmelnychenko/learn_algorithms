#include <gmock/gmock.h>
#include <stdexcept>
#include "hashTable.h"

using namespace testing;

struct HashTableTest : public Test {};

// Test put 1 element
TEST_F(HashTableTest, putSingle) {
  HashTable<string> testTable;
  string testValue = "testValue";
  string testKey = "testKey";

  testTable.put(testKey, testValue);

  // Test that table has only 1 elements
  EXPECT_TRUE(testTable.Count() == 1);

  // Test item value by key
  EXPECT_EQ(testTable.valueAt(testKey), testValue);
}

// Test put element to full Table
TEST_F(HashTableTest, putFull) {
  HashTable<string> testTable1;
  string testValue = "testValue";
  string testKey = "testKey";

  for (int i = 0; i < 1000; i++) {
    testTable1.put(to_string(i), to_string(rand()));
  }

  // Test that table has exactly 1000 elements (full)
  EXPECT_TRUE(testTable1.Count() == 1000);

  // Should not put to full table
  EXPECT_THROW(testTable1.put(testKey, testValue), std::length_error);
}

// Test erase element
TEST_F(HashTableTest, eraseSingle) {
  HashTable<string> testTable2;
  string testValue = "testValue";
  string testKey = "testKey";

  testTable2.put(testKey, testValue);

  // Test that table has only 1 elements
  EXPECT_TRUE(testTable2.Count() == 1);

  testTable2.erase(testKey);

  // Test that table has not any elements
  EXPECT_TRUE(testTable2.Count() == 0);

  // Test that table has not values by testKey
  EXPECT_THROW(testTable2.valueAt(testKey), std::invalid_argument);
}
