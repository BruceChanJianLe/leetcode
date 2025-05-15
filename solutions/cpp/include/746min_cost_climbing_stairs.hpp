#pragma once

#include <vector>

// DP bottom up
class DPBottomUpSolution {
public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    // Sanity check (please read the constraints)
    if (cost.empty()) return 0;

    // Require a place holder for the last step
    cost.emplace_back(0);

    for (auto i = 2uz; i < cost.size(); ++i) {
      // cost[i] = std::min(cost[i] + cost[i -1], cost[i] + cost[i - 2]);
      cost[i] += std::min(cost[i -1], cost[i - 2]);
    }

    return cost.back();
  }
};

// DP recursive
// Too slow...
class DPRecursiveSolution {
public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    // Sanity check (please read the constraints)
    if (cost.empty()) return 0;

    return std::min(walk(cost, 0), walk(cost, 1));
  }

private:
  int walk(std::vector<int>& cost, const std::size_t index) {
    if (index >= cost.size()) return 0;

    return cost[index] + std::min(walk(cost, index + 1), walk(cost, index + 2));
  }
};
