#pragma once

#include <climits>
#include <vector>

class Solution {
public:
  int change(const int amount, const std::vector<int>& coins) {
    std::vector<int> lookup(amount + 1, 0);
    // Base case (1 way to build amount 0)
    lookup[0] = 1;

    for (const auto &coin : coins) {
      for (auto i = coin; i < amount + 1; ++i) {
        // This is need if UndefinedBehaviorSanitizer is enabled
        // if (lookup[i] <= INT_MAX - lookup[i - coin]) {
        lookup[i] += lookup[i - coin];
        // }

      }
    }

    return lookup.back();
  }
};
