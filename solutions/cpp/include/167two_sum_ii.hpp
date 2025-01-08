#pragma once

#include <vector>

// Less branches, less prediction, faster execution
// Second solution
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int lp = numbers.size() - 1;
    std::vector<int> index{0, lp};
    int sum = numbers[index[0]] + numbers[index[1]];
    while (sum != target)
    {
      if (sum > target)
        --index[1];
      else if (sum < target)
        ++index[0];
      sum = numbers[index[0]] + numbers[index[1]];
    }
    return {index[0] + 1, index[1] + 1};
  }
};

class FirstSolution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int sp{0}, lp;
    lp = numbers.size() - 1;
    while (sp != lp)
    {
      auto sum = numbers[sp] + numbers[lp];
      if (sum > target)
        --lp;
      else if (sum < target)
        ++sp;
      else
        return {sp + 1, lp + 1};
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
