#pragma once

#include "518coin_change_ii.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>
#include <span>

class IRSpanSolution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    std::sort(candidates.begin(), candidates.end());
    backtrack(candidates, target, result, results);

    return results;
  }

private:
  void backtrack(std::span<int> candies,
      const int target,
      std::vector<int>& result,
      std::vector<std::vector<int>>& results) {
    // Base case
    if (target == 0) {
      results.push_back(result);
      return;
    }

    // No more options or options are too large to make target
    if (candies.empty() || candies.front() > target) {
      return;
    }

    for (auto i = 0uz; i < candies.size(); ++i) {
      // Skip the same option
      if (i > 0uz && candies[i] == candies[i - 1]) continue;
      result.push_back(candies[i]);
      backtrack({candies.begin() + i + 1, candies.end()}, target - candies[i], result, results);
      result.pop_back();
    }
  }
};

// Iterative + Recursive
class IRSolution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> set;
    std::sort(candidates.begin(), candidates.end());
    decisionTree(candidates, set, target, 0, result);
    return result;
  }
private:
  void decisionTree(std::vector<int>& candidates, std::vector<int>& set,
      int target, std::size_t start, std::vector<std::vector<int>>& result) {
    if (target == 0) {
      result.emplace_back(set);
      return;
    }

    for (auto i = start; i < candidates.size(); ++i) {
      auto candidate = candidates[i];
      if (target - candidate < 0) return;

      set.emplace_back(candidate);
      decisionTree(candidates, set, target - candidate, i + 1, result);
      set.pop_back();

      // Shift to next different candidate
      while (i + 1 < candidates.size() && candidates[i + 1] == candidate) {
        ++i;
      }
    }
  }
};

// Recursive
class RSolution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> set;
    std::sort(candidates.begin(), candidates.end());
    decisionTree(candidates, set, target, 0, result);
    return result;
  }
private:
  void decisionTree(std::vector<int>& candidates, std::vector<int>& set,
      int target, std::size_t index, std::vector<std::vector<int>>& result) {
    // Base case
    if (target == 0) {
      result.emplace_back(set);
      return;
    }

    if (index >= candidates.size()) return;

    auto candidate = candidates[index];
    if (target - candidate < 0) return;

    set.emplace_back(candidate);
    decisionTree(candidates, set, target - candidate, index + 1, result);
    set.pop_back();

    while (index + 1 < candidates.size() && candidates[index + 1] == candidate) {
      ++index;
    }
    decisionTree(candidates, set, target, index + 1, result);
  }
};
