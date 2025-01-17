#pragma once

#include <string>
#include <vector>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;

    for (const auto &c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else {
        if (stack.empty())
          return false;

        auto top = stack.top();
        if (('(' != top && ')' == c) || ('[' != top && ']' == c) ||
            ('{' != top && '}' == c))
          return false;
        stack.pop();
      }
    }
    return stack.empty();
  }
};

class FirstSolution {
public:
  bool isValid(std::string s) {
    std::vector<char> stack;
    for (const auto &brace : s) {
      switch (brace) {
      case ')':
        if (stack.empty() || stack.back() != '(') {
          return false;
        } else {
          stack.pop_back();
        }
        break;

      case ']':
        if (stack.empty() || stack.back() != '[') {
          return false;
        } else {
          stack.pop_back();
        }
        break;

      case '}':
        if (stack.empty() || stack.back() != '{') {
          return false;
        } else {
          stack.pop_back();
        }
        break;

      default:
        stack.emplace_back(brace);
        break;
      }
    }

    if (stack.empty()) {
      return true;
    } else {
      return false;
    }
  }
};
