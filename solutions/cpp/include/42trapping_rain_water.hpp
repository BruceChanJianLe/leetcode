#pragma once

#include <stack>
#include <vector>
#include <iostream>

// Iterator solution
class Solution {
public:
  int trap(std::vector<int> &height) {
    int result{0};
    auto lp{height.begin()}, rp{height.end() - 1};
    int max_left{*lp}, max_right{*rp};
    while (lp < rp) {
      if (*lp < *rp) {
        ++lp;
        max_left = (*lp > max_left) ? *lp : max_left;
        result += max_left - *lp;
      } else {
        --rp;
        max_right = (*rp > max_right) ? *rp : max_right;
        result += max_right - *rp;
      }
    }
    return result;
  }
};

// Monotonic decreasing stack solution
// More about monotonic stack: https://medium.com/@hanxuyang0826/mastering-monotonic-stacks-optimizing-algorithmic-efficiency-in-array-and-sequence-problems-28d2a16eeccc
class SecondSolution {
public:
  int trap(std::vector<int> &height) {
    std::stack<int> stack;
    int water{0};

    for (int i = 0; i < height.size(); ++i)
    {
      auto curr_height = height[i];
      while (!stack.empty() && curr_height >= height[stack.top()])
      {
        auto mid_height = height[stack.top()];
        stack.pop();

        if (!stack.empty())
        {
          auto left_height = height[stack.top()];
          auto width = i - stack.top() - 1;
          water += width * (std::min(left_height, curr_height) - mid_height);
        }
      }
      stack.push(i);
    }

    return water;
  }
};
