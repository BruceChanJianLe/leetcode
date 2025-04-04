#pragma once

#include <vector>
#include <array>
#include <memory_resource>
#include <unordered_set>

class Solution {
public:
  int findDuplicate(const std::vector<int>& nums) {
    auto slow{nums[0]}, fast{nums[nums[0]]};
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return fast;
  }
};

// This solution uses extra memory
class PMRSolution {
public:
  int findDuplicate(const std::vector<int>& nums) {
    std::array<int, 100001> buffer{};
    std::pmr::monotonic_buffer_resource mr{buffer.data(), buffer.size()};
    std::pmr::unordered_set<int> records{&mr};

    for (const auto& num : nums) {
      if (!records.insert(num).second)
        return num;
    }

    return -1;
  }
};

// This solution also uses extra memory
class StandardSolution {
public:
  int findDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> records;

    for (const auto& num : nums) {
      if (!records.insert(num).second)
        return num;
    }

    return -1;
  }
};

