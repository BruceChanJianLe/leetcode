#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> leftRightDifference(const std::vector<int> &nums) {
    std::vector<int> left(nums.size()), right(nums.size()), result(nums.size());

    std::exclusive_scan(nums.begin(), nums.end(), left.begin(), 0);
    std::exclusive_scan(nums.rbegin(), nums.rend(), right.rbegin(), 0);
    std::transform(left.begin(), left.end(), right.begin(), result.begin(),
                   [](const auto left, const auto right) {
                     return std::abs(left - right);
                   });

    return result;
  }
};
