#include <algorithm>
#include <fmt/core.h>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>

class Solution {
public:
  // Attempt 4, seems like changing the control order matters
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> index_map;
    index_map.reserve(nums.size());
    for (const int index : std::ranges::iota_view(0u, nums.size())) {
      if (auto itr = index_map.find(target - nums[index]);
          itr != index_map.end()) {
        return {index, itr->second};
      } else {
        index_map[nums[index]] = index;
      }
    }
    return {};
  }

  // Attempt 3
  std::vector<int> twoSumAttempt3(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> index_map;
    index_map.reserve(nums.size());
    for (const int index : std::ranges::iota_view(0u, nums.size())) {
      // target - nums[index] = b
      // If b does not exist, store nums[index] as seen for future
      if (auto itr = index_map.find(target - nums[index]);
          itr == index_map.end()) {
        index_map[nums[index]] = index;
      } else {
        return {index, itr->second};
      }
    }

    // Attempt 4 (only if the nums are sorted)
    // int index_small{0}, index_large{(int)nums.size() - 1};
    // while(index_small != index_large)
    // {
    //     if (nums[index_small] + nums[index_large] == target)
    //         return {index_small, index_large};
    //     else if (nums[index_small] + nums[index_large] < target)
    //         ++index_small;
    //     else
    //         --index_large;
    // }
    return {};
  }

  // Attempt 4, with xing yu, jia min and elizabeth
  std::vector<int> twoSumAttempt4(std::vector<int> &nums, int target) {
    std::vector<std::pair<int, int>> records;

    for (auto index = 0; index < nums.size(); ++index) {
      records.emplace_back(nums[index], index);
    }

    std::sort(records.begin(), records.end());

    int left{0}, right{static_cast<int>(nums.size()) - 1};

    while (left < right) {
      if (auto sum = records[left].first + records[right].first; sum == target) {
        break;
      } else if (sum > target) {
        --right;
      } else {
        ++left;
      }
    }

    return {records[left].second, records[right].second};
  }

// How to use iota_view to generate index (ascending)
// Run time
// #include <iostream>
// #include <ranges>
// #include <vector>

  void printIndex() {
    constexpr int start = 42;
    constexpr int end = 0;

    // Create an iota_view and reverse it to get values from 42 down to 0
    auto sequence1 = std::ranges::iota_view{end, start + 1};
    auto sequence2 =
        std::ranges::iota_view{end, start + 1} | std::views::reverse;

    // Construct the vector from the iota_view
    std::vector<int> ascending(sequence1.begin(), sequence1.end());
    std::vector<int> descending(sequence2.begin(), sequence2.end());

    // Output the ascending result
    for (const auto &num : ascending) {
      std::cout << num << " ";
    }

    // Output the descending result
    for (const auto &num : descending) {
      std::cout << num << " ";
    }
  }

  constexpr std::array<int, 43> generateDescending() {
    std::array<int, 43> arr{};
    for (int i = 0; i < arr.size(); ++i) {
      arr[i] = 42 - i;
    }
    return arr;
  }

  void constPrintIndex() {
    /* constexpr */ auto arr = generateDescending();

    // Output the descending result
    for (const auto &num : arr) {
      std::cout << num << " ";
    }
  }
};
