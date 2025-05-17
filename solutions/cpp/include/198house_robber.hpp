#pragma once

#include <algorithm>
#include <vector>

// Optimal
class ODPSolution {
public:
  int rob(std::vector<int>& nums) {
    auto n = nums.size();

    // Sanity check
    if (n == 1) return nums.front();

    auto twoHouseBack = nums.front();
    auto oneHouseBack = std::max(nums[0], nums[1]);
    // Important to set max_seen, because size == 2 would not run the loop
    auto max_seen{oneHouseBack};

    for (auto index = 2uz; index < n; ++index) {
      max_seen = std::max(oneHouseBack, twoHouseBack + nums[index]);
      twoHouseBack = oneHouseBack;
      oneHouseBack = max_seen;
    }

    return max_seen;
  }
};

// Classic DP
class DPSolution {
public:
  int rob(std::vector<int>& nums) {
    auto n = nums.size();

    // Sanity check
    if (n == 1) return nums.front();

    std::vector<int> memo(n, 0);
    memo.front() = nums.front();
    memo[1] = std::max(nums[0], nums[1]);

    for (auto index = 2uz; index < n; ++index) {
      memo[index] = std::max(nums[index] + memo[index - 2], memo[index - 1]);
    }

    return memo.back();
  }
};

class FirstSolution {
public:
  int rob(std::vector<int>& nums) {
    // Sanity check
    if (nums.size() == 1) return nums.front();
    if (nums.size() == 2) return std::max(nums.front(), nums.back());

    auto max_seen{0};
    nums[1] = std::max(nums[0], nums[1]);

    for (auto index = 2uz; index < nums.size(); ++index) {
      nums[index] = std::max(nums[index] + nums[index - 2], nums[index - 1]);
      max_seen = std::max(max_seen, nums[index]);
    }

    return max_seen;
  }
};
