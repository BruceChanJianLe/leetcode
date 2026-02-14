#pragma once

#include <vector>
#include <span>
#include <algorithm>

// Backtracking with SPAN!
class BTSpanSolution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> results;
    std::vector<int> result;

    backtrack(nums, target, result, results);

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

    // Early termination
    if (candies.empty() || candies.front() > target) {
      return;
    }

    for (auto it = candies.begin(); it != candies.end(); ++it) {
      auto candy = *it;
      result.push_back(candy);
      backtrack({it, candies.end()}, target - candy, result, results);
      result.pop_back();
    }
  }
};


// Another Backtracking Solution WITHOUT Iteration
// key diff: this uses minus to target
//           this uses span which faster since it's only a view
// Note that input must be sorted

class BTNSolution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
    std::vector<int> result{};
    std::vector<std::vector<int>> results{};
    std::sort(nums.begin(), nums.end());
    backtrack(nums, target, result, results);
    return results;
  }

private:
  void backtrack(std::span<int> nums, int target, std::vector<int>& result, std::vector<std::vector<int>>& results) {
    // Base case 1: perfect match
    if (target == 0) {
      results.push_back(result);
      return;
    }

    // Base case 2: not more candidates, and early termination check
    if (nums.size() == 0 || nums.front() > target) {
      return;
    }

    // // Base case 3: Early termination
    // if (nums.front() > target) {
    //   return;
    // }

    // Choose the curr candidate
    result.emplace_back(nums.front());
    backtrack(nums, target - nums.front(), result, results);
    // Don't choose the curr candidate
    result.pop_back();
    backtrack({nums.begin() + 1, nums.end()}, target, result, results);
  }
};

// Another Backtracking Solution WITH Iteration
// key diff: this uses minus to target
//           this uses span which faster since it's only a view
// Note that input must be sorted
class BTSolution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> results{};
    std::vector<int> result{};
    std::sort(nums.begin(), nums.end());
    backtrack(nums, target, 0, result, results);
    return results;
  }

private:
  void backtrack(std::span<int> nums, int target, int start,
      std::vector<int>& result, std::vector<std::vector<int>>& results) {
    // Base case 1: perfect match
    if (target == 0) {
      results.push_back(result);
      return;
    }

    // Base case 2: Overshoot
    if (target < 0) {
      return;
    }

    for (auto index = start; index < nums.size(); ++index) {
      // Early termination condition since this is an sorted arrary
      if (nums[index] > target) break;
      result.emplace_back(nums[index]);
      backtrack(nums, target - nums[index], index, result, results);
      // Remove this choice
      result.pop_back();
    }
  }
};

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
