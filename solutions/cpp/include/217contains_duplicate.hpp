#pragma once

#include <vector>
#include <unordered_set>

class Solution
{
public:
  bool containsDuplicate(std::vector<int> &nums)
  {
    std::unordered_set<int> record;
    for (auto& e : nums)
    {
      if (!record.insert(e).second) return true;
    }
    return false;
  }
};

