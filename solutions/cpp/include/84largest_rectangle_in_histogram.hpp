#pragma once

#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    std::stack<int> records;
    int max_area{0};

    // Note that this loop until size of heights
    // No the convention loop less than
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
