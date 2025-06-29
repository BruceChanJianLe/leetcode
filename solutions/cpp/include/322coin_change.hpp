#pragma once

#include <algorithm>
#include <limits>
#include <vector>

// DP First Solution
class FirstSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    std::vector<int> lookup(amount + 1, std::numeric_limits<int>::max());
    // Base cases
    lookup[0] = 0;

    for (auto i = 1; i < amount + 1; ++i) {
      for (const auto &coin : coins) {
        if (auto subproblem = i - coin;
            subproblem >= 0 && lookup[subproblem] != std::numeric_limits<int>::max()) {
          lookup[i] = std::min(lookup[i], 1 + lookup[subproblem]);
        }
      }
    }

    return lookup.back() == std::numeric_limits<int>::max() ? -1 : lookup.back();
  }
};

// DP Second Solution
class SecondSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    std::vector<int> lookup(amount + 1, amount + 1);
    // Base cases
    lookup[0] = 0;

    for (auto i = 1; i < amount + 1; ++i) {
      for (const auto &coin : coins) {
        if (i >= coin) {
          lookup[i] = std::min(lookup[i], 1 + lookup[i - coin]);
        }
      }
    }

    return lookup.back() == amount + 1 ? -1 : lookup.back();
  }
};

// Naive Recursive Backtracking
class NRBSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    auto result{amount + 1};

    coinChangeHelper(coins, amount, 0, result);

    return result == amount + 1 ? -1 : result;
  }
private:
  void coinChangeHelper(const std::vector<int>& coins, int curr_amount, int curr_coins, int& result) {
    // Base cases
    if (curr_amount == 0) {
      result = std::min(curr_coins, result);
    }

    for (const auto &coin : coins) {
      if (auto amount = curr_amount - coin; amount >= 0) {
        coinChangeHelper(coins, amount, curr_coins + 1, result);
      }
    }
  }
};

class Solution {
public:
  int coinChange(const std::vector<int>& coins, int amount) {
    // std::vector<int> memo(amount + 1, amount + 1);
    // return coinChangeHelper(coins, amount, memo);
    // return walk(coins, amount);
    memo.assign(amount + 1, -2); // -2 mean uncomputed
    return memoWalk(coins, amount);
  }

private:
  std::vector<int> memo;

  int coinChangeHelper(const std::vector<int>& coins, const int amount, std::vector<int>& memo) {
    if (memo[amount] != amount + 1) return memo[amount];
    if (amount == 0) return 0;

    for (const auto coin : coins) {
      // Create subproblem
      if (auto sub_amount = amount - coin; sub_amount >= 0) {
        memo[amount] = std::min(memo[amount],
            coinChangeHelper(coins, sub_amount, memo) + 1);
      }
    }

    return (memo[amount] == amount + 1) ? -1 : memo[amount];
  }

  int walk(const std::vector<int>& coins, const int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    auto curr_count{std::numeric_limits<int>::max()};

    // Try each coin
    for (const auto coin : coins) {
      auto result = walk(coins, amount - coin);
      if (result != -1) { // only if valid result exist
        curr_count = std::min(curr_count, result + 1);
      }
    }

    return (curr_count == std::numeric_limits<int>::max()) ? -1 : curr_count;
  }

  int memoWalk(const std::vector<int>& coins, const int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;

    if (memo[amount] != -2) return memo[amount];

    auto min_coin{std::numeric_limits<int>::max()};

    // Try each coin
    for (const auto coin : coins) {
      auto result = memoWalk(coins, amount - coin);
      if (result != -1) {
        min_coin = std::min(min_coin, result + 1);
      }
    }

    // Store result in memo
    memo[amount] = (min_coin == std::numeric_limits<int>::max()) ? -1 : min_coin;

    return memo[amount];
  }
};
