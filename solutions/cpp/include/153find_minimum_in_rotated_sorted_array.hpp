#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
  int findMin(const std::vector<int>& nums) {
    auto left{0uz}, right{nums.size() - 1};

    while (left < right) {
      const auto mid = left + (right - left) / 2;

      // search the right portion
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      }
      else {
        right = mid;
      }
    }

    return nums[left]; // left and right will converge at the same spot
  }
};

class FirstSolution {
public:
  int findMin(const std::vector<int>& nums) {
    auto left{0uz}, right{nums.size()};
    auto min = nums.front();

    while (left < right) {
      const auto mid = left + (right - left) / 2;
      const auto val = nums[mid];

      // search my left portion
      min = std::min({nums[left], min, val});
      if (nums[left] > val) {
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }

    return min;
  }
};

