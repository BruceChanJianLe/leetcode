#pragma once

#include <vector>
#include <algorithm>

// Recursive
class RSolution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr_candidates;
    std::sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, curr_candidates,
        0, target, 0,
        result);

    return result;
  }

private:
  // A decision tree (backtracking) function
  void combinationSumHelper(
      std::vector<int>& candidates, std::vector<int>& curr_candidates,
      std::size_t start, const int target, const int curr_target,
      std::vector<std::vector<int>>& result
      ) {
    // Base case
    // if (start >= candidates.size() || curr_target > target) return;
    if (start >= candidates.size()) return;

    if (curr_target == target) {
      result.emplace_back(curr_candidates);
      return;
    }

    // Use this statemetn only when the input is sorted
    // Otherwise, move the checking to the base case
    if (auto candidate = candidates[start]; candidate + curr_target <= target) {
      // Decision with current candidate
      curr_candidates.emplace_back(candidate);
      combinationSumHelper(candidates, curr_candidates,
          start, target, curr_target + candidate,
          result);

      // Decision without current candidate
      curr_candidates.pop_back();
      combinationSumHelper(candidates, curr_candidates,
          start + 1, target, curr_target,
          result);
    }
  }
};

// Iterative + Recursive
class IRSolution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr_candidates;
    std::sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, curr_candidates,
        0, target, 0,
        result);

    return result;
  }

private:
  // A decision tree (backtracking) function
  void combinationSumHelper(
      std::vector<int>& candidates, std::vector<int>& curr_candidates,
      std::size_t start, const int target, const int curr_target,
      std::vector<std::vector<int>>& result
      ) {
    // Base case
    // Refer to the break statement below
    // if (start >= candidates.size() || curr_target > target) return;
    if (curr_target > target) return;

    if (curr_target == target) {
      result.emplace_back(curr_candidates);
      return;
    }

    for (auto i = start; i < candidates.size(); ++i) {
      // Only do this if candidates are sorted
      // All up coming candidates since they are sorted
      // This check also eliminate the checking in base case
      if (curr_target + candidates[i] > target) break;

      curr_candidates.emplace_back(candidates[i]);
      combinationSumHelper(candidates, curr_candidates,
          i, target, curr_target + candidates[i],
          result);
      curr_candidates.pop_back();
    }
  }
};
