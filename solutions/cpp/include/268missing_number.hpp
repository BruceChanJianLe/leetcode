#pragma once

#include <vector>
#include <unordered_set>
#include <ranges>
#include <numeric>
#include <algorithm>

class Solution {
public:
  int missingNumber(std::vector<int>& nums) {
    int max = std::ssize(nums) + 1;
    int result{0};
    for (const auto num : nums) {
      result ^= num;
    }

    for (auto i = 0; i < max; ++i) {
      result ^= i;
    }

    return result;
  }
};

class ModernSolution {
public:
  int missingNumber(std::vector<int>& nums) {
    auto ranges = std::views::iota(0, static_cast<int>(nums.size()) + 1);
    int acc = std::accumulate(ranges.begin(), ranges.end(), 0, std::bit_xor<>{});
    return std::accumulate(nums.begin(), nums.end(), acc, std::bit_xor<>{});
  }
};

class MoreModernSolution {
public:
  int missingNumber(std::vector<int>& nums) {
    int acc = std::ranges::fold_left(std::views::iota(0, static_cast<int>(nums.size()) + 1), 0, std::bit_xor<>{});
    return std::ranges::fold_left(nums, acc, std::bit_xor<>{});
  }
};

class SumSolution {
public:
  int missingNumber(std::vector<int>& nums) {
    int sum{0};
    for (const auto num : nums) {
      sum += num;
    }

    return ((std::ssize(nums) + 1) * (std::ssize(nums))) / 2 - sum;
  }
};

class HashSolution {
public:
  int missingNumber(std::vector<int>& nums) {
    std::unordered_set<int> records;
    records.reserve(nums.size());

    for (const auto num : nums) {
      records.insert(num);
    }

    for (auto i = 0; i < records.size() + 1; ++i) {
      if (!records.count(i)) return i;
    }

    return 0;
  }
};
