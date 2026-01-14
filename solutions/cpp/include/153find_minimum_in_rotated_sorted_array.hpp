#pragma once

#include <vector>
#include <algorithm>

// Easy to understand
class EasySolution {
public:
  int findMin(const std::vector<int>& nums) {
    // Sanity check
    if (nums.size() == 1) return nums.front();

    // Declare the pointers
    int lo{}, hi = nums.size() - 1;

    while (lo < hi) {
      const auto mid = lo + (hi - lo) / 2;

      // No way in a sorted array left is greater than curr
      if (mid > 0 && nums[mid - 1] > nums[mid]) {
        return nums[mid];
      } else if (nums[mid] > nums[hi]) {
        // Search the unsorted side
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return nums[lo];
  }
};

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

