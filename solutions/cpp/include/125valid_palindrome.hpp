#pragma once

#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    // Using while loop is faster by 1ms on leetcode submission
    for (int lp = 0, rp = s.size() - 1; lp < rp; ++lp, --rp) {
      while (lp < rp && !std::isalnum(s[lp])) {
        ++lp;
      }

      while (lp < rp && !std::isalnum(s[rp])) {
        --rp;
      }

      if (std::tolower(s[lp]) != std::tolower(s[rp])) {
        return false;
      }
    }

    return true;
  }
};

// Iterator Solution
class ItrSolution {
public:
  bool isPalindrome(std::string s) {
    for (auto [first, second] = std::make_tuple(s.begin(), s.rbegin());
         first != s.end() && second != s.rend();
         ++first, ++second) {

      while(!std::isalnum(*first) && std::next(first) != s.end())
      {
        ++first;
      }

      while(!std::isalnum(*second) && std::next(second) != s.rend())
      {
        ++second;
      }

      // If iterator crossed, it is a PALINDROME
      if (std::distance(first, second.base() - 1) < 0) return true;

      if (std::tolower(*first) != std::tolower(*second)) return false;
    }
    return true;
  }
};
