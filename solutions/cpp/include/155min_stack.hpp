#pragma once

#include <stdexcept>
#include <vector>
#include <stack>

// Stack solution
class MinStack {
public:
  MinStack()
  {
  }

  void push(int val) {
    min_stack.push(min_stack.empty() ? val : std::min(val, min_stack.top()));
    stack.push(val);
  }

  void pop() {
    stack.pop();
    min_stack.pop();
  }

  int top() {
    return stack.empty() ? throw std::underflow_error("Stack is empty!") : stack.top();
  }

  int getMin() {
    return stack.empty() ? throw std::underflow_error("Stack is empty!") : min_stack.top();
  }

private:
  std::stack<int> stack;
  std::stack<int> min_stack;
};

// Vector solution
class MinStackVector {
public:
  MinStackVector()
  {
  }

  void push(int val) {
    min_stack.emplace_back(min_stack.empty() ? val : std::min(val, min_stack.back()));
    stack.push_back(val);
  }

  void pop() {
    stack.pop_back();
    min_stack.pop_back();
  }

  int top() {
    return stack.empty() ? throw std::underflow_error("Stack is empty!") : stack.back();
  }

  int getMin() {
    return stack.empty() ? throw std::underflow_error("Stack is empty!") : min_stack.back();
  }

private:
  std::vector<int> stack;
  std::vector<int> min_stack;
};
