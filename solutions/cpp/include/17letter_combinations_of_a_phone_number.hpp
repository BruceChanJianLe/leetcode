#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <array>
#include <span>

// Decision tree with span
class DTSpanSolution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> results{};
    std::string result{};
    decisionTree(digits, result, results);
    return results;
  }

private:
  const std::array<std::string, 9> buttons {
    std::string{'a', 'b', 'c'}, {'d', 'e', 'f'},
      {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
  };

  void decisionTree(std::span<char> digits,
      std::string& result,
      std::vector<std::string>& results) {
    // Base case
    if (digits.empty()) {
      results.push_back(result);
      return;
    }

    for (const auto &button : buttons[digits.front() - '2']) {
      result.push_back(button);
      decisionTree(digits.subspan(1), result, results);
      result.pop_back();
    }
  }
};

// DT Recursion 
// Pass in new string in every call
class DTSolution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    // Sanity check
    if (digits.empty()) return {};

    std::vector<std::string> result;
    std::string str;
    decisionTree(digits, str, result);

    return result;
  }

private:
  const std::vector<std::string> lookup
  {
    {'a', 'b', 'c'}, {'d', 'e', 'f'},
      {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
  };

  void decisionTree(const std::string& digits, std::string& str,
      std::vector<std::string>& result) {
    // Base case
    if (digits.empty()) {
      result.emplace_back(str);
      return;
    }

    for (const auto &c : lookup[digits.front() - '2']) {
      str.push_back(c);
      decisionTree(digits.substr(1), str, result);
      str.pop_back(); // backtracking
    }
  }
};

// DT Recursion 
// Same string pass around, only new index pass in
class DT2Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    // Sanity check
    if (digits.empty()) return {};

    std::vector<std::string> result;
    std::string str;
    decisionTree(digits, 0, str, result);

    return result;
  }

private:
  const std::vector<std::string> lookup
  {
    {'a', 'b', 'c'}, {'d', 'e', 'f'},
      {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
  };

  void decisionTree(const std::string& digits,
      std::size_t index, std::string& str,
      std::vector<std::string>& result) {
    // Base case
    if (index == digits.size()) {
      result.emplace_back(str);
      return;
    }

    for (const auto &c : lookup[digits[index] - '2']) {
      str.push_back(c);
      decisionTree(digits, index + 1, str, result);
      str.pop_back(); // backtracking
    }
  }
};
