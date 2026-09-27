#pragma once

#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    std::size_t write{0};
    for (std::size_t read{0}; read < nums.size(); ++read) {
      if (nums[read] != 0) {
        if (read != write) std::swap(nums[read], nums[write]);
        ++write;
      }
    }
  }
};

class FirstSolution {
public:
  void moveZeroes(std::vector<int>& nums) {
    // Sanity check
    if (nums.size() == 1) return;
    int l{0}, r{1};
    while(r < nums.size()) {
      if (nums[l] != 0) {
        ++l;
      } else if (nums[r] != 0) {
        std::swap(nums[l], nums[r]);
        ++l;
      }
      ++r;
    }
  }
};
