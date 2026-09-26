#pragma once

#include <array>
#include <cstddef>
#include <vector>
#include <set>
#include <algorithm>

// Time Complexity: O(n)
// Memory Complexity: O(n)
class Solution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::vector<int> records(nums.size());
    for (auto i = 0; i < records.size(); ++i) {
      records[i] = i + 1;
    }

    for (const auto& num : nums) {
      records[num - 1] = 0;
    }

    std::vector<int> result;
    for (const auto& record : records) {
      result.push_back(record);
    }

    return result;
  }
};

// Time Complexity: O(n)
// Memory Complexity: O(1)
class NoExtraMemorySolution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    for (auto num : nums) {
      auto i = std::abs(num) - 1;
      nums[i] = -std::abs(nums[i]);
    }

    std::vector<int> result;
    for (auto i = 0uz; i < std::ssize(nums); ++i) {
      if (nums[i] > 0) result.push_back(i + 1);
    }

    return result;
  }
};

// 84ms (SLOW)
class FristTrySolution {
public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::set<int> records;
    for (const auto& num : nums) records.insert(num);

    auto i = 1;
    std::vector<int> result;
    while (i <= nums.size()) {
      if (auto it = records.find(i); it == records.end()) {
        result.push_back(i);
      }
      ++i;
    }

    return result;
  }
};
