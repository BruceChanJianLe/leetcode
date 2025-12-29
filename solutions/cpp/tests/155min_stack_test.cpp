#include "155min_stack.hpp"

#include "gtest/gtest.h"

// Stack solution
// Test Case: Push and Minimum
TEST(MinStackTest, PushAndMinimum) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    EXPECT_EQ(minStack.getMin(), -3);  // Minimum should be -3
}

// Test Case: Pop and Minimum
TEST(MinStackTest, PopAndMinimum) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), -2);  // After popping, minimum should be -2
}

// Test Case: Top Element
TEST(MinStackTest, TopElement) {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.top(), 0);  // Top should be 0
}

// Test Case: Empty Stack Operations
TEST(MinStackTest, EmptyStackOperations) {
    MinStack minStack;
    EXPECT_THROW(minStack.top(), std::exception);     // Accessing top of an empty stack should throw
    EXPECT_THROW(minStack.getMin(), std::exception);  // Accessing minimum of an empty stack should throw
}

// Test Case: Push Duplicate Minimums
TEST(MinStackTest, PushDuplicateMinimums) {
    MinStack minStack;
    minStack.push(2);
    minStack.push(2);
    minStack.push(2);
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should be 2
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after popping one element
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after another pop
}

// Test Case: Single Element Stack
TEST(MinStackTest, SingleElementStack) {
    MinStack minStack;
    minStack.push(42);
    EXPECT_EQ(minStack.top(), 42);    // Top should be 42
    EXPECT_EQ(minStack.getMin(), 42); // Minimum should also be 42
    minStack.pop();
    EXPECT_THROW(minStack.getMin(), std::exception);  // Accessing minimum of an empty stack should throw
}

// Test Case: Push and Minimum
TEST(MinStackVectorTest, PushAndMinimum) {
    MinStackVector minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    EXPECT_EQ(minStack.getMin(), -3);  // Minimum should be -3
}

// Test Case: Pop and Minimum
TEST(MinStackVectorTest, PopAndMinimum) {
    MinStackVector minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), -2);  // After popping, minimum should be -2
}

// Test Case: Top Element
TEST(MinStackVectorTest, TopElement) {
    MinStackVector minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.top(), 0);  // Top should be 0
}

// Test Case: Empty Stack Operations
TEST(MinStackVectorTest, EmptyStackOperations) {
    MinStackVector minStack;
    EXPECT_THROW(minStack.top(), std::exception);     // Accessing top of an empty stack should throw
    EXPECT_THROW(minStack.getMin(), std::exception);  // Accessing minimum of an empty stack should throw
}

// Test Case: Push Duplicate Minimums
TEST(MinStackVectorTest, PushDuplicateMinimums) {
    MinStackVector minStack;
    minStack.push(2);
    minStack.push(2);
    minStack.push(2);
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should be 2
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after popping one element
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after another pop
}

// Test Case: Single Element Stack
TEST(MinStackVectorTest, SingleElementStack) {
    MinStackVector minStack;
    minStack.push(42);
    EXPECT_EQ(minStack.top(), 42);    // Top should be 42
    EXPECT_EQ(minStack.getMin(), 42); // Minimum should also be 42
    minStack.pop();
    EXPECT_THROW(minStack.getMin(), std::exception);  // Accessing minimum of an empty stack should throw
}

// Test Case: Push and Minimum
TEST(PairMinStack, PushAndMinimum) {
    PairMinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    EXPECT_EQ(minStack.getMin(), -3);  // Minimum should be -3
}

// Test Case: Pop and Minimum
TEST(PairMinStack, PopAndMinimum) {
    PairMinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), -2);  // After popping, minimum should be -2
}

// Test Case: Top Element
TEST(PairMinStack, TopElement) {
    PairMinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.pop();
    EXPECT_EQ(minStack.top(), 0);  // Top should be 0
}

// Test Case: Push Duplicate Minimums
TEST(PairMinStack, PushDuplicateMinimums) {
    PairMinStack minStack;
    minStack.push(2);
    minStack.push(2);
    minStack.push(2);
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should be 2
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after popping one element
    minStack.pop();
    EXPECT_EQ(minStack.getMin(), 2);  // Minimum should still be 2 after another pop
}
