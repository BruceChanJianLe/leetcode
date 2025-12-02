#pragma once

#include <cctype>
#include <stdexcept>
#include <vector>
#include <string>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stack;
    for (const auto &s : tokens) {
      if (!std::isdigit(s.front()) && s.size() == 1) {
        auto right = stack.top();
        stack.pop();
        auto left = stack.top();
        stack.pop();
        stack.push(executeOperator(left, right, s.c_str()));
      } else {
        stack.push(std::stoi(s));
      }
    }
    return stack.top();
  }

  int executeOperator(const int left, const int right, const char* op)
  {
    switch (*op) {
      case '+':
        return left + right;

      case '-':
        return left - right;

      case '*':
        return left * right;

      case '/':
        return left / right;

      default:
        throw std::invalid_argument("Executed invalid opertor!");
    }
  }
};

class FirstSolution {
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

// A solution after revisiting this question
class RevisitSolution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::vector<int> stack; stack.reserve(tokens.size());

    for (const auto& token : tokens) {
      switch (token.front()) {
        case '+':
          {
            auto right = stack.back();
            stack.pop_back();
            auto left = stack.back();
            stack.pop_back();
            stack.push_back(left + right);
          }
          break;

        case '*':
          {
            auto right = stack.back();
            stack.pop_back();
            auto left = stack.back();
            stack.pop_back();
            stack.push_back(left * right);
          }
          break;

        case '/':
          {
            auto right = stack.back();
            stack.pop_back();
            auto left = stack.back();
            stack.pop_back();
            stack.push_back(left / right);
          }
          break;

        case '-':
          if (token.size() == 1)
          {
            auto right = stack.back();
            stack.pop_back();
            auto left = stack.back();
            stack.pop_back();
            stack.push_back(left - right);
            break;
          }

        default:
          stack.push_back(std::stoi(token));
      }
    }

    return stack.back();
  }
};
