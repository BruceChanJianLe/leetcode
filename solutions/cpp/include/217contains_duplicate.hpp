#pragma once

#include <vector>
#include <unordered_set>

class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> record;
    for (auto& num : nums)
    {
      if (!record.insert(num).second) return true;
    }
    return false;
  }
};

