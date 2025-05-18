#pragma once

#include <vector>
#include <algorithm>

// Time complexity: O(n) linear
// Space complexity: O(n) linear
class DPSolution {
public:
  int rob(std::vector<int>& nums) {
    return std::max({
        nums.front(),
        robHelper({nums.begin(), nums.end() - 1}),
        robHelper({nums.begin() + 1, nums.end()})
      });
  }

private:
  int robHelper(std::vector<int> nums) {
    // Sanity check
    auto n = nums.size();

    if (n == 0) return 0;
    if (n == 1) return nums.front();

    nums[1] = std::max(nums[0], nums[1]);

    for (auto index = 2uz; index < n; ++index) {
      nums[index] = std::max(nums[index] + nums[index - 2], nums[index - 1]);
    }

    return nums.back();
  }
};

// Time complexity: O(n) linear
// Space complexity: O(1) constant
class ODPSolution {
public:
  int rob(std::vector<int>& nums) {
    return std::max({
        nums.front(),
        robHelper({nums.begin(), nums.end() - 1}),
        robHelper({nums.begin() + 1, nums.end()})
      });
  }

private:
  int robHelper(const std::vector<int>& nums) {
    // Rob first left house, Rob second left house
    // [second left house], [first left house], [curr_house]
    auto rob1{0}, rob2{0}, max_rob{0};

    for (const auto &curr_house : nums) {
      max_rob = std::max(curr_house + rob2, rob1);
      rob2 = rob1;
      rob1 = max_rob;
    }

    return max_rob;
  }
};
