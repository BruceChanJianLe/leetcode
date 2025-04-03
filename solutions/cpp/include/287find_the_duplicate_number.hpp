#pragma once

#include <vector>
#include <array>
#include <memory_resource>
#include <unordered_set>

class PMRSolution {
public:
  int findDuplicate(std::vector<int>& nums) {
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

class StandardSolution {
public:
  int findDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> records;

    for (const auto& num : nums) {
      if (!records.insert(num).second)
        return num;
    }

    return -1;
  }
};

