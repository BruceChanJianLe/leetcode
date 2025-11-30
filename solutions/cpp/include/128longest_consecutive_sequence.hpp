#pragma once

#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> records(nums.size());
    records.insert(nums.begin(), nums.end());
    int max{0};

    for (const auto& num : nums) {
      // For c++17
      // if (records.find(record - 1) == records.end()) {
      // For c++20
      if (!records.contains(num - 1)) {
        auto length = 1;
        // For c++17
        // while (records.find(suffix) != records.end()) {
        // For c++20
        while (records.contains(num + length)) {
          ++length;
        }
        max = std::max(max, length);
      }
    }
    return max;
  }
};

// Hash map solution
class HashMapSolution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_map<int, int> records(nums.size());
    int max_size = 0;
    for (const auto &num : nums) {
      if (!records[num]) {
        //             left_val + curr_val + right_val
        records[num] = records[num - 1] + 1 + records[num + 1];
        // Update leftmost
        records[num - records[num - 1]] = records[num];
        // Update rightmost
        records[num + records[num + 1]] = records[num];
        max_size = std::max(max_size, records[num]);
      }
    }
    return max_size;
  }
};

class SecondSolution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> records(nums.size());
    records.insert(nums.begin(), nums.end());
    int length{0};

    for (const auto record : records) {
      if (records.find(record - 1) == records.end()) {
        int curr_length{0};
        do {
          ++curr_length;
          if (records.find(record + curr_length) == records.end())
            break;
        } while (true);
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

    for (const auto e : nums) {
      records.insert(e);
    }

    int length{0};
    for (const auto record : records) {
      int curr_length = 0;
      if (auto search = records.find(record - 1); search != records.end()) {
        continue;
      } else {
        do {
          ++curr_length;
          if (auto search = records.find(record + curr_length);
              search == records.end())
            break;
        } while (true);
      }
      if (curr_length > length)
        length = curr_length;
    }

    return length;
  }
};
