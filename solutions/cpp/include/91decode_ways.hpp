#pragma once

#include <string>
#include <vector>

// DP Bottom up
class DPSolution {
public:
  int numDecodings(const std::string& s) {
    // Sanity check
    if (s.front() == '0') return 0;

    // Vector to store result, note that there is a off by one
    auto n = s.size();
    std::vector<int> lookup(n + 1, 0);
    // Empty string has one way to decode?
    lookup[0] = 1;
    // First character is valid since we check it is not '0'
    lookup[1] = 1;

    for (auto i = 2uz; i < n + 1uz; ++i) {
      // Consider as single digit
      // string index i - 1
      // lookup index i
      if (s[i - 1] != '0') {
        lookup[i] += lookup[i - 1];
      }

      // Consider as double digit
      // number must be within 10 <= number <= 26
      if (auto two_digits = std::stoi(s.substr(i - 2, 2));
          two_digits >= 10 && two_digits <= 26) {
        lookup[i] += lookup[i - 2];
      }
    }

    return lookup.back();
  }
};
