#pragma once

#include <vector>
#include <span>
#include <numeric>

// Span, create nums to select in advance
// 38ms
class SpanSolution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);
    decisionTree(nums, k, result, results);
    return results;
  }

private:
  void decisionTree(std::span<const int> nums,
      const int k,
      std::vector<int>& result,
      std::vector<std::vector<int>>& results
      ) {
    // Base cases
    if (result.size() == k /* k == 0*/) {
      results.push_back(result);
      return;
    }

    // When there is nothing left to choose from
    if (nums.empty()) return;

    // Select current number
    result.push_back(nums.front());
    decisionTree(nums.subspan(1), k /*k - 1*/, result, results);
    // Unselect current number
    result.pop_back();
    // Try the next number
    decisionTree(nums.subspan(1), k /*k - 1*/, result, results);
  }
};

// Span, create nums on the go
// Seems to be slower... 88ms
class SpanCreateSolution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    decisionTree(1, k, n, result, results);
    return results;
  }

private:
  void decisionTree(const int start,
      const int k,
      const int n,
      std::vector<int>& result,
      std::vector<std::vector<int>>& results) {
    // Base case
    if (k == 0) {
      results.push_back(result);
      return;
    }

    // Do not exceed n
    if (start > n) return;

    result.push_back(start);
    decisionTree(start + 1, k - 1, n, result, results);
    result.pop_back();
    decisionTree(start + 1, k, n, result, results);
  }
};
