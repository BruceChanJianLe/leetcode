#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (auto ap = nums.begin(); ap != nums.end(); ++ap) {
      if (ap != nums.begin() && *std::prev(ap) == *ap)
        continue;

      auto fp = ap + 1;
      auto lp = nums.end() - 1;
      while (fp < lp) {
        auto sum = *ap + *fp + *lp;
        if (sum == 0) {
          result.emplace_back(std::vector<int>{*ap, *fp, *lp});
          do { ++fp; } while (fp < lp && *fp == *std::prev(fp));
          do { --lp; } while (fp < lp && *lp == *std::next(lp));
        } else if (sum > 0) {
          --lp;
        } else {
          ++fp;
        }
      }
    }
    return result;
  }
};

class FirstSolution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int f = i + 1;
      int l = nums.size() - 1;
      while (f < l) {
        auto sum = nums[i] + nums[f] + nums[l];
        if (sum < 0) {
          ++f;
        } else if (sum > 0) {
          --l;
        } else {
          result.push_back({nums[i], nums[f], nums[l]});
          ++f;
          while (nums[f] == nums[f - 1] && f < l) {
            ++f;
          }
        }
      }
    }
    return result;
  }
};
