#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> records;
    records.reserve(k + 1);

    for (auto i = 0; i < nums.size(); ++i) {
      // insert to set, if failed means it exist, hence, return true
      if (!records.insert(nums[i]).second) {
        return true;
      }

      // pop the first element if reached window size
      // because at this point, we already checked all elements in the window
      // hence, pop it before moving forward, otherwise, we will exceed window
      if (records.size() > k) {
        records.erase(nums[i - k]);
      }
    }

    return false;
  }
};
