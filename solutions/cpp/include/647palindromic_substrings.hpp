#pragma once

#include <string>
#include <vector>
#include <span>

// Decision tree solution
// this option is quite slow since it can also
// return all possible palindromic substrings
class DTSolution {
public:
  int countSubstrings(std::string s) {
    int count{};
    counts(s, count);
    return count;
  }

private:
  void counts(std::span<char> words, int& count) {
    if (words.empty()) {
      return;
    }

    for (auto i = 0uz; i < std::ssize(words); ++i) {
      auto word = words.subspan(0uz, i + 1uz);
      if (isPalindrome(word)) {
        ++count;
      }
    }

    // Start without head
    counts(words.subspan(1uz), count);
  }

  bool isPalindrome(std::span<char> word) {
    int left{}, right= std::ssize(word) - 1;
    while (left < right) {
      if (word[left++] != word[right--]) {
        return false;
      }
    }
    return true;
  }
};

// DP
class DPSolution {
public:
  int countSubstrings(std::string s) {
    auto n = s.size();

    // Sanity check
    if (n == 1) return 1;

    // Lookup table to store palindrome matching results
    std::vector<std::vector<bool>> lookup(n, std::vector(n, false));
    // Store the numbers of palindrome seen thus far
    auto count{0};

    // Every single alphabet is always a palindrome
    for (auto i = 0uz; i < n; ++i) {
      lookup[i][i] = true;
      ++count;
    }

    // Manually check for every size 2 word
    for (auto i = 1uz; i < n; ++i) {
      if (s[i - 1] == s[i]) {
        lookup[i - 1][i] = true;
        ++count;
      }
    }

    // Check all size 3 and above, including the entire word
    for (auto len = 3uz; len < n + 1; ++len) {
      for (auto i = len - 1; i < n; ++i) {
        if (s[i - len + 1] == s[i] && lookup[i - len + 2][i -1]) {
          lookup[i - len + 1][i] = true;
          ++count;
        }
      }
    }

    return count;
  }
};

// Two pointer solution
// Generally faster
class TwoPointerSolution {
public:
  int countSubstrings(std::string s) {
    auto n{s.size()};
    auto count{0};

    for (auto i = 0uz; i < n; ++i) {
      // odd
      count += countSubstringsHelper(i, i, s);
      // even
      count += countSubstringsHelper(i, i + 1, s);
    }

    return count;
  }

private:
  int countSubstringsHelper(int l, int r, const std::string& s) {
    auto n{s.size()};
    auto count{0};

    while (l >= 0 && r < n && s[l] == s[r]) {
      ++count;
      --l;
      ++r;
    }

    return count;
  }
};
