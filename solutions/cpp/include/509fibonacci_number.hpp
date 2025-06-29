#pragma once

#include <array>
#include <utility>
#include <vector>

// Naive solution with recursion
// Time complexity: O(2^n)
class NaiveSolution {
public:
  int fib(const int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
  }
};

// DP: Top-down (memoization)
// Time complexity: O(n) + recursion stack (which can be worse)
// Space complexity: O(n)
class DPTopDownSolution {
public:
  DPTopDownSolution() : memo{} { memo[1] = 1; }

  int fib(const int n) {
    if (memo[n] || n == 0) return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
  }

private:
  // Based on question's constrait
  std::array<int, 31> memo;
};

// DP: Bottom-up (tabulation)
// Time complexity: O(n)
// Space complexity: O(n)
class DPBottomUpSolution {
public:
  int fib(const int n) {
    // Sanity check
    if (n <= 1) return n;

    std::vector<int> lookup(n + 1, 0);
    lookup[1] = 1;

    for (auto i = 2; i < n + 1; ++i) {
      lookup[i] = lookup[i - 1] + lookup[i - 2];
    }

    return lookup.back();
  }
};

// DP: Bottom-up (tabulation)
// Time complexity: O(n)
// Space complexity: O(1)
class DPBottomUpOptimizedSolution {
public:
  int fib(const int n) {
    // Sanity check
    if (n <= 1) return n;

    auto fib_curr{0}, fib_prev1{1}, fib_prev2{0};

    for (auto i = 2; i < n + 1; ++i) {
      fib_curr = fib_prev1 + fib_prev2;
      fib_prev2 = std::exchange(fib_prev1, fib_curr);
    }

    return fib_prev1;
  }
};
