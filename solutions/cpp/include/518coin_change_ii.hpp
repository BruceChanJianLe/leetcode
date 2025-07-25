#pragma once

#include <vector>

// A more modern approach - without memoization
class backtrackSolution {
public:
  int change(const int amount, const std::vector<int>& coins) {
    // return backtrack(amount, 0uz, coins);
    // Base cases
    if (amount == 0) return 1;
    if (amount < 0 || coins.empty()) return 0;

    int total_ways{0};

    // Decision 1: Stay with current coin
    if (auto sub_amount = amount - coins.front(); sub_amount >= 0) {
      total_ways += change(sub_amount, coins);
    }

    // Decision 2: Move to next coin
    total_ways += change(amount, {coins.begin() + 1, coins.end()});

    return total_ways;
  }

private:
  int backtrack(const int amount, const std::size_t index, const std::vector<int>& coins) {
    if (amount == 0) return 1;
    if (amount < 0 || index >= coins.size()) return 0;

    int total_ways{0};

    // Decision 1: Stay with current coin
    if (auto sub_amount = amount - coins[index]; sub_amount >= 0) {
      total_ways += backtrack(sub_amount, index, coins);
    }

    // Decision 2: Move to next coin
    total_ways += backtrack(amount, index + 1uz, coins);

    return total_ways;
  }
};

// DP Top Down - Memoization
class DPTopDownSolution {
public:
  int change(const int amount, const std::vector<int>& coins) {
    memo.assign(coins.size(), std::vector<int>(amount + 1, -1));
    return changeHelper(amount, 0uz, coins);
  }

private:
  std::vector<std::vector<int>> memo;
  int changeHelper(const int amount, const std::size_t index, const std::vector<int>& coins) {
    // Base cases
    if (amount == 0) return 1;
    if (amount < 0 || index >= coins.size()) return 0;

    if (memo[index][amount] != -1) return memo[index][amount];

    auto total_ways{0};

    // Decision 1: Stay with current coin
    if (auto sub_amount = amount - coins[index]; sub_amount >= 0) {
      total_ways += changeHelper(sub_amount, index, coins);
    }

    // Decision 2: Move to next coin
    total_ways += changeHelper(amount, index + 1uz, coins);

    memo[index][amount] = total_ways;

    return memo[index][amount];
  }
};

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
