#pragma once

#include <ranges>
#include <vector>
#include <unordered_set>

class Solution
{
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> records(nums.begin(), nums.end());
    int length{0};

    for (const auto record : records)
    {
      if (records.find(record - 1) == records.end())
      {
        int curr_length{0};
        do {
          ++curr_length;
          if (records.find(record + curr_length) == records.end())
            break;
        }while (true);
        // length = std::max(length, curr_length);
        length = (length > curr_length) ? length : curr_length;
      }
    }
    return length;
  }
};


class FirstSolution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> records(nums.size());

    for (const auto e : nums)
    {
      records.insert(e);
    }

    int length{0};
    for (const auto record : records)
    {
      int curr_length = 0;
      if (auto search = records.find(record - 1); search != records.end())
      {
        continue;
      }
      else
      {
        do
        {
          ++curr_length;
          if (auto search = records.find(record + curr_length); search == records.end())
            break;
        }
        while (true);
      }
      if (curr_length > length) length = curr_length;
    }

    return length;
  }
};