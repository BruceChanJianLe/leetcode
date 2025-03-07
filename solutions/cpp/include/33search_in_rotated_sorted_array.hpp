#pragma once

#include <vector>

class Solution
{
public:
  int search(const std::vector<int>& nums, const int target) {
    auto left{0uz}, right{nums.size() - 1};

    while (left <= right) {
      auto mid = (left + right) / 2;

      if (target == nums[mid]) return mid;

      // Left portion
      if (nums[left] <= nums[mid]){
        // Is target between the left portion?
        if (nums[left] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      // Right portion
      else {
        // Is target between the right portion?
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};

