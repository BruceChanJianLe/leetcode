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

      if (std::tolower(*first) != std::tolower(*second)
          && std::next(first) != s.end() && std::next(second) != s.rend()
          ) return false;
    }
    return true;
  }
};

// Failed...
// class FirstSolution {
// public:
//   bool isPalindrome(std::string s) {
//     if (s.empty())
//       return true;
//
//     for (auto [first, second] = std::make_tuple(s.begin(), s.rbegin());
//          first != s.end() && second != s.rend(); ++first, ++second) {
//       while (!std::isalnum(*first) && std::next(first) != s.end()) {
//         ++first;
//       }
//       while (!std::isalnum(*first) && std::next(second) != s.rend()) {
//         ++second;
//       }
//       std::cout << "first:" << *first << ", second: " << *second << '\n';
//       if (std::tolower(*first) != std::tolower(*second) ||
//           first == (second.base() - 1))
//         return false;
//     }
//     return true;
//   }
// };