#pragma once

#include <vector>

// Optimal solution
// This is like a fibonacci solution
class OSolution {
public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    auto one_step_before = 1;
    auto two_step_before = 2;
    auto curr_steps = 0;

    for (auto i = 3; i < n + 1; ++i) {
      curr_steps = one_step_before + two_step_before;
      two_step_before = one_step_before;
      one_step_before = curr_steps;
    }

    return one_step_before;
  }
};

// Dynamic programming
// Memoization with vector
class DPSolution {
public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    // 0 is not counted
    // n is the target, hence, size if n + 1
    std::vector<int> lookup(n + 1);
    lookup[0] = 0;
    lookup[1] = 1;
    lookup[2] = 2;

    for (auto i = 3; i < lookup.size(); ++i) {
      lookup[i] = lookup[i - 1] + lookup[i - 2];
    }

    return lookup[n];
  }
};
