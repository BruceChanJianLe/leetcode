#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    // Collect record of num and freq
    std::unordered_map<int, int> records;
    for (const auto& num : nums) {
      ++records[num];
    }

    // Create bucket sort container
    std::vector<std::vector<int>> bucket(nums.size() + 1);
    for (const auto& [num, freq] : records) {
      bucket[freq].emplace_back(num);
    }

    // Get k element from the bucket
    std::vector<int> result{};
    for (auto ritr = bucket.rbegin(); ritr != bucket.rend() && result.size() < k; ++ritr) {
      if (ritr->size() > 0)
      {
        for (const auto& e : *ritr)
        {
          result.emplace_back(e);
        }
      }
    }

    return result;
  }
};


class FirstSolution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> records;
    for (const auto& num : nums) {
      ++records[num];
    }

    std::vector<std::pair<int, int>> sorted_records;
    for (const auto& [num, freq] : records) {
      sorted_records.emplace_back(freq, num);
    }

    // Sort the record
    std::partial_sort(sorted_records.begin(), sorted_records.begin() + k, sorted_records.end(), std::greater<std::pair<int, int>>{});

    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
      result.emplace_back(sorted_records[i].second);
    }

    return result;
  }
};
