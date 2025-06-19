#pragma once

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
  bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> lookup(wordDict.begin(), wordDict.end());
    auto n = s.size() + 1;
    std::vector<bool> memo(n, false);
    // Always true to form zero words
    memo.front() = true;

    for (auto i = 1uz; i < n; ++i) {
      for (auto j = 0uz; j < i; ++j) {
        if (memo[j] && lookup.count(s.substr(j, i - j))) {
          memo[i] = true;
          break;
        }
      }
    }

    return memo.back();
  }
};
