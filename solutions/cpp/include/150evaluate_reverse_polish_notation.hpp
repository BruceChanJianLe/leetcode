#pragma once

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stack;
    int left{0}, right{0};
    for (const auto &s : tokens)
    {
      if (s.compare("+") == 0) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();
        stack.push(left + right);
      }
      else if (s.compare("-") == 0) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();
        stack.push(left - right);
      }
      else if (s.compare("*") == 0) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();
        stack.push(left * right);
      }
      else if (s.compare("/") == 0) {
        right = stack.top();
        stack.pop();
        left = stack.top();
        stack.pop();
        stack.push(left / right);
      }
      else {
        stack.push(std::stoi(s));
      }
    }
    return stack.top();
  }
};

