#pragma once

#include <cstddef>
#include <vector>
#include <string>

// Decision Tree Recursive
class DTSolution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> parts;
    decisionTree(s, parts, result);

    return result;
  }

private:
  void decisionTree(const std::string& word,
      std::vector<std::string>& parts,
      std::vector<std::vector<std::string>>& result
      ) {
    if (word.empty()) {
      result.emplace_back(parts);
      return;
    }

    // Ensure first and last character is included
    // This is specially related to how std::string
    // does their substr
    for (auto i = 1uz; i <= word.size(); ++i) {
      auto sub_word = word.substr(0, i);
      if (isPalindrome(sub_word)) {
        parts.emplace_back(sub_word);
        decisionTree(word.substr(i), parts, result);
        parts.pop_back();
      }
    }
  }

  bool isPalindrome(const std::string& word) {
    // Single character is always a palindrome
    if (word.size() == 1) return true;

    auto l{0uz}, r{word.size() - 1};
    while (l < r) {
      if (word[l] != word[r]) return false;
      ++l;
      --r;
    }

    return true;
  }
};

// Decision Tree Recursive II
class DT2Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> parts;
    decisionTree(s, 0, parts, result);

    return result;
  }

private:
  void decisionTree(const std::string& word,
      std::size_t start, std::vector<std::string>& parts,
      std::vector<std::vector<std::string>>& result) {
    // Base case
    if (start >= word.size()) {
      result.emplace_back(parts);
      return;
    }

    for (auto end = start; end < word.size(); ++end) {
      if (isPalindrome(word, start, end)) {
        parts.emplace_back(word.substr(start, end - start + 1));
        decisionTree(word, end + 1, parts, result);
        parts.pop_back();
      }
    }
  }

  bool isPalindrome(const std::string& word,
      std::size_t left, std::size_t right) {
    while (left < right) {
      if (word[left] != word[right]) return false;
      ++left;
      --right;
    }
    return true;
  }
};
