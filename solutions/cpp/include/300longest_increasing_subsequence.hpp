#pragma once

#include <vector>
#include <algorithm>

// DP
class DPSolution {
public:
  int lengthOfLIS(const std::vector<int>& nums) {
    // Sanity check (notice nums.size() in constraints)
    if (nums.empty()) return 0;

    auto n = nums.size();
    std::vector<int> memo(n, 1);
    auto lis{1};

    for (auto i = 0uz; i < n; ++i) {
      for (auto j = 0uz; j < i; ++j) {
        if (nums[i] > nums[j]) {
          memo[i] = std::max(memo[i], 1 + memo[j]);
          lis = std::max(lis, memo[i]);
        }
      }
    }

    return lis;
  }
};

// DP + Greedy + std (binary search)
class STDSolution {
public:
  int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> memo;
    memo.reserve(nums.size());

    for (const auto num : nums) {
      // Find index to insert
      auto itr = std::lower_bound(memo.begin(), memo.end(), num);

      if (itr == memo.end()) {
        memo.emplace_back(num);
      } else {
        *itr = num;
      }
    }

    return memo.size();
  }
};

// DP + Greedy + Binary Search (self implemented)
class DPGreedySolution {
public:
  int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> memo;
    memo.reserve(nums.size());

    for (const auto num : nums) {
      int left = 0, right = memo.size();

      while (left < right) {
        auto mid = left + (right - left) / 2;
        if (num > memo[mid]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (left == memo.size()) {
        memo.emplace_back(num);
      } else {
        memo[left] = num;
      }
    }

    return memo.size();
  }
};
