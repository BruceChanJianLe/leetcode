#pragma once

#include <vector>

// Kadane's algorithm
// Refer also to maximum subarray product
class Solution {
public:
  int maxSubArray(const std::vector<int>& nums) {
    // global sum as first element as size is guarantee to be at least 1
    auto curr_sum{0}, global_sum{nums.front()};

    for (const auto &num : nums) {
      // Decide whether to restart
      curr_sum = std::max(num, num + curr_sum);
      // Update global sum if current one is largest seen
      global_sum = std::max(global_sum, curr_sum);
    }

    return global_sum;
  }
};
// Kadane's algorithm version 1
class FirstSolution {
public:
  int maxSubArray(const std::vector<int>& nums) {
    // global sum as first element as size is guarantee to be at least 1
    auto curr_sum{0}, global_sum{nums.front()};

    for (const auto &num : nums) {
      if (curr_sum > 0) {
        // Extend the subarray
        curr_sum += num;
      } else {
        // Restart the subarray
        curr_sum = num;
      }

      // Update global sum if current one is largest seen
      global_sum = std::max(global_sum, curr_sum);
    }

    return global_sum;
  }
};
