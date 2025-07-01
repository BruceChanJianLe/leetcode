#pragma once

#include <algorithm>
#include <limits>
#include <vector>

// Pure recursion, without memoization - for education purpose
class DFSSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    return dfsWalk(coins, amount);
  }

private:
  int dfsWalk(const std::vector<int>& coins, const int amount) {
    if (amount == 0) return 0;

    auto min_coin{std::numeric_limits<int>::max()};

    // Try each coin
    for (const auto coin : coins) {
      if (auto sub_amount = amount - coin; sub_amount >= 0) {
        if (auto result = dfsWalk(coins, sub_amount); result != -1) {
          min_coin = std::min(min_coin, result + 1);
        }
      }
    }

    return (min_coin == std::numeric_limits<int>::max()) ? -1 : min_coin;
  }
};

// DP Top Down - Memoization
class DPTopDownSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    memo.assign(amount + 1, -2);
    return coinChangeHelper(coins, amount);
  }

private:
  int coinChangeHelper(const std::vector<int>& coins, const int amount) {
    if (amount == 0) return 0;
    if (memo[amount] != -2) return memo[amount];

    auto min_coin{std::numeric_limits<int>::max()};

    // Try each coin
    for (const auto coin : coins) {
      if (auto sub_amount = amount - coin; sub_amount >= 0) {
        if (auto result = coinChangeHelper(coins, sub_amount); result != -1) {
          min_coin = std::min(min_coin, result + 1);
        }
      }
    }

    memo[amount] =
      (min_coin == std::numeric_limits<int>::max()) ? -1 : min_coin;

    return memo[amount];
  }

  std::vector<int> memo;
};

// DP Bottom Up - Tabulation
class DPBottomUpSolution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    std::vector<int> lookup(amount + 1, amount + 1); // amount + 1 is impossible
    // Always true to make zero amount with 0 coin
    lookup.front() = 0;

    for (auto curr_amount = 1; curr_amount < amount + 1; ++curr_amount) {
      for (const auto coin : coins) {
        if (coin <= curr_amount) {
          lookup[curr_amount] =
            std::min(lookup[curr_amount], lookup[curr_amount - coin] + 1);
        }
      }
    }

    return (lookup.back() == amount + 1) ? -1 : lookup.back();
  }
};

// Old solutions
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
