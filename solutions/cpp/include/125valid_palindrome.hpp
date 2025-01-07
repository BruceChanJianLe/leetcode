#pragma once

#include <cctype>
#include <iostream>
#include <string>

class Solution {
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
