#pragma once

#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> nextGreaterElement(std::vector<int> &nums1,
                                      std::vector<int> &nums2) {
      std::vector<int> res;
    std::unordered_map<int, int> records(nums2.size());
    std::stack<int> stack;

    for (auto rit = nums2.rbegin(); rit != nums2.rend(); ++rit)
    {
      while (!stack.empty() && *rit > stack.top())
      {
        stack.pop();
      }
      records[*rit] = !stack.empty() ? stack.top() : -1;
      stack.push(*rit);
    }

    for (const auto& num : nums1)
    {
      res.push_back(records[num]);
    }

    return res;
}
};
