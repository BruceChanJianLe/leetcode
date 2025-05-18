#pragma once

#include <cstddef>
#include <string>

// Two pointer solution
// Time complexity: O(n)
// Second attempt slightly more efficient
class SecondSolution {
public:
  std::string longestPalindrome(std::string s) {
    std::string result;

    for (auto index = 0uz; index < s.size(); ++index) {
      // odd
      if (auto [l, len] = longestPalindromeHelper(index, index, s); len > result.size()) {
        result = s.substr(l, len);
      }
      // even
      if (auto [l, len] = longestPalindromeHelper(index, index + 1, s); len > result.size()) {
        result = s.substr(l, len);
      }
    }

    return result;
  }

private:
  std::pair<std::size_t, std::size_t> longestPalindromeHelper(
      int left, int right, const std::string& s
      ) {

    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }

    return {left + 1, right - left - 1};
  }
};

// Two pointer solution
// Time complexity: O(n)
class FirstSolution {
public:
  std::string longestPalindrome(std::string s) {
    std::string result;

    for (auto index = 0uz; index < s.size(); ++index) {
      // odd
      if (auto pal = longestPalindromeHelper(index, index, s); pal.size() > result.size()) {
        result = pal;
      }
      // even
      if (auto pal = longestPalindromeHelper(index, index + 1, s); pal.size() > result.size()) {
        result = pal;
      }
    }

    return result;
  }

private:
  std::string longestPalindromeHelper(int left, int right, const std::string& s) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    return s.substr(left + 1, right - left - 1);
  }
};
