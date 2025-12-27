#pragma once

#include <vector>

// Less branches, less prediction, faster execution
// Second solution
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int lp = 0, rp = numbers.size() - 1;
    int sum = numbers.front() + numbers.back();
    while (sum != target) {
      if (sum > target) {
        --rp;
      } else if (sum < target) {
        ++lp;
      }
      sum = numbers[lp] + numbers[rp];
    }
    return {lp + 1, rp + 1};
  }
};

class FirstSolution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int lp{0}, rp = numbers.size() - 1;
    while (lp != rp)
    {
      auto sum = numbers[lp] + numbers[rp];
      if (sum > target)
        --rp;
      else if (sum < target)
        ++lp;
      else
        return {lp + 1, rp + 1};
    }
    return {};
  }
};

// Using iterator
class SecondSolution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    auto sp = numbers.begin();
    auto lp = numbers.end() - 1;
    auto sum = *sp + *lp;
    while (sum != target)
    {
      if (sum > target) {
        --lp;
      }
      else if (sum < target) {
        ++sp;
      }
      sum = *sp + *lp;
    }
    return {
      (int) std::distance(numbers.begin(), sp) + 1,
      (int) std::distance(numbers.begin(), lp) + 1
    };
  }
};
