#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

// DP
class DPSolution {
public:
  std::string longestPalindrome(std::string s) {
    auto n = s.size();

    // Sanity check
    if (n == 1) return s;

    // A lookup table to store panlindrome matching result
    std::vector<std::vector<bool>> lookup(n, std::vector(n, false));

    // Fill the single alphabet, the diagonals, size == 1
    for (auto index = 0uz; index < n; ++index) {
      lookup[index][index] = true;
    }

    // Book keeping (start index and length)
    auto start{0}, max_seen{1};

    // Fill double alphabets, size == 2
    for (auto index = 1uz; index < n; ++index) {
      if (s[index - 1] == s[index]) {
        lookup[index - 1][index] = true;
        start = index - 1;
        max_seen = 2;
      }
    }

    // Fill three alphabets and above size >= 3
    // inclusive of the entire string
    for (auto len = 3uz; len < n + 1; ++len) {
      for (auto index = len - 1uz; index < n; ++ index) {
        // Check if both ends are same and the inner ends are palindrome
        if (s[index - len + 1] == s[index] && lookup[index - len + 2][index - 1]) {
          lookup[index - len + 1][index] = true;

          if (len > max_seen) {
            start = index - len + 1;
            max_seen = len;
          }
        }
      }
    }
    std::cout << "start: " << start << ", len: " << max_seen << std::endl;

    return s.substr(start, max_seen);
  }
};

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
