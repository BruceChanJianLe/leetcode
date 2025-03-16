#pragma once

#include <algorithm>
#include <deque>
#include <ranges>
#include <vector>

class Solution
{
public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, const int k) {
    std::vector<int> result;
    std::deque<int> records;

    for (auto i = 0; i < nums.size(); ++i) {
      // Remove out-of-bound elements
      if (!records.empty() && records.back() == i - k) {
        records.pop_front();
      }

      // Mantain monotonic decreasing deque
      while (!records.empty() && nums[i] > nums[records.back()]) {
        records.pop_back();
      }

      records.emplace_back(i);

      // Obtain current sliding window maximum value
      if (i >= k - 1) {
        result.emplace_back(nums[records.front()]);
      }
    }

    return result;
  }
};

class PointerSolution
{
public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, const int k) {
    std::vector<int> result;

    for (auto left{0uz}, right{0uz}; right < nums.size(); ++right) {
      ;
    }

    return result;
  }
};

class NaiveSolution
{
public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, const int k) {
    std::vector<int> result;

    for (const auto& window : std::ranges::slide_view(nums, k)) {
      result.emplace_back(*std::ranges::max_element(window));
    }

    return result;
  }
};

