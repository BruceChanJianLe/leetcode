#pragma once

#include <array>
#include <vector>
#include <span>

// Recursive span
class RSpanSolution {
public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    std::array<int, 9> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    decisionTree(nums, k, n, result, results);
    return results;
  }

private:
  void decisionTree(std::span<int> nums,
      const int k,
      const int target,
      std::vector<int>& result,
      std::vector<std::vector<int>>& results
      ) {
    // Base cases
    if (result.size() == k && target == 0) {
      results.push_back(result);
      return;
    }

    // Early return if we choose more that what is allowed
    // if our target is already less than zero
    // if we have nothing else to choose from
    if (result.size() > k || 0 > target || nums.empty()) {
      return;
    }

    // Select current number
    result.push_back(nums.front());
    decisionTree(nums.subspan(1), k, target - nums.front(), result, results);
    // Unselect this number
    result.pop_back();
    decisionTree(nums.subspan(1), k, target, result, results);
  }
};

// A more common recursive span
class CRSpanSolution {
public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    std::array<int, 9> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    decisionTree(nums, k, n, result, results);
    return results;
  }

private:
  void decisionTree(std::span<int> nums,
      const int k,
      const int target,
      std::vector<int>& result,
      std::vector<std::vector<int>>& results) {
    // Base cases
    if (result.size() == k && target == 0) {
      results.push_back(result);
      return;
    }

    if (result.size() > k || 0 > target || nums.empty()) {
      return;
    }

    for (auto it = nums.begin(); it != nums.end(); ++it) {
      // Select current number
      result.push_back(*it);
      decisionTree({it + 1, nums.end()}, k, target - *it, result, results);
      // Unselect current number
      result.pop_back();
    }
  }
};
