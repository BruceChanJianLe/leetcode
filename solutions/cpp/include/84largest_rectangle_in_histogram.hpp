#pragma once

#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    std::stack<int> records;
    int max_area{0};

    // Note that this loop until size of heights
    // Not the convention loop
    for (int i = 0; i <= heights.size(); ++i)
    {
      auto curr_height = (i == heights.size()) ? 0 : heights[i];
      while(!records.empty() && curr_height < heights[records.top()])
      {
        // Calculate area
        auto height = heights[records.top()];
        records.pop();
        auto width = records.empty() ? i : (i - (records.top() + 1));
        // Off by one
        max_area = std::max(max_area, width * height);

      }
      records.push(i);
    }

    return max_area;
  }
};

class FirstSolution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    // Sanity check
    if (heights.empty())
      return 0;

    std::stack<std::pair<int, int>> records;
    int max_area = 0;

    int i = 1;
    records.push({0, heights[0]});
    while (i < heights.size()) {
      auto curr_height = heights[i];
      while (!records.empty() && curr_height >= records.top().second) {
        auto [top_index, top_height] = records.top();
        records.pop();
        max_area = std::max(max_area, top_height * (1 + i - top_index));
      }
      records.push({i, curr_height});
      ++i;
    }

    while (!records.empty()) {
      auto [top_index, top_height] = records.top();
      records.pop();
      max_area = std::max(max_area, top_height);
    }

    return max_area;
  }
};

class AnotherSolution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    std::vector<std::pair<int, int>> stack;
    int max_seen{};

    for (auto i = 0ul; i < heights.size(); ++i) {
      auto start = i;
      while (!stack.empty() && stack.back().first > heights[i]) {
        auto [height, idx] = stack.back();
        stack.pop_back();
        max_seen = std::max<int>(max_seen, height * (i - idx));
        // Extend backward to calculate the area of the smaller height
        start = idx;
      }
      stack.emplace_back(heights[i], start);
    }

    // Calculate the left over in stack
    while (!stack.empty()) {
      auto [height, idx] = stack.back();
      stack.pop_back();
      max_seen = std::max<int>(max_seen, height * (heights.size() - idx));
    }

    return max_seen;
  }
};
