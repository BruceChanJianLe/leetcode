#pragma once

#include <vector>
#include <unordered_set>

class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    // Sanity check (based on contraints)
    if (nums.size() == 1) return false;

    std::unordered_set<int> record;
    record.reserve(nums.size() / 2);

    for (auto& num : nums)
    {
      if (!record.insert(num).second) return true;
    }
    return false;
  }
};

