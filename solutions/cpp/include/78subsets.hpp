#pragma once

#include <cstddef>
#include <vector>

// Iterative Solution (quite smart eh?)
class ISolution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    // Init with an empty set
    std::vector<std::vector<int>> result {{}};

    for (const auto &num : nums) {
      auto n = result.size();
      for (auto i = 0; i < n; ++i) {
        auto subset = result[i];
        subset.emplace_back(num);
        result.emplace_back(subset);
      }
    }

    return result;
  }
};

// Bit Mask
class BMSolution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    auto n = nums.size();
    std::vector<std::vector<int>> result;

    // Total number of subsets is 2^n
    std::size_t total_subsets = 1uz << n;

    for (auto mask = 0uz; mask < total_subsets; ++mask) {
      std::vector<int> subset;
      for (auto i = 0uz; i < nums.size(); ++i) {
        if (mask & (1uz << i)) {
          subset.emplace_back(nums[i]);
        }
      }
      result.emplace_back(subset);
    }

    return result;
  }
};

// Recursive backtracking
class RBTSolution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> subset;

    buildSubsets(nums, 0, subset, result);

    return result;
  }

private:
  void buildSubsets(std::vector<int> &nums, std::size_t index,
                    std::vector<int> &subset,
                    std::vector<std::vector<int>> &result) {
    // Base case
    if (index >= nums.size()) {
      result.emplace_back(subset);
      return;
    }

    subset.emplace_back(nums[index]);
    buildSubsets(nums, index + 1, subset, result);

    subset.pop_back();
    buildSubsets(nums, index + 1, subset, result);
  }
};

// Iterative + Recursive backtracking
class IRBTSolution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> subset;

    buildSubsets(nums, 0, subset, result);

    return result;
  }

private:
  void buildSubsets(std::vector<int> &nums, std::size_t start,
                    std::vector<int> &subset,
                    std::vector<std::vector<int>> &result) {
    result.emplace_back(subset);

    for (auto i = start; i < nums.size(); ++i) {
      subset.emplace_back(nums[i]);
      buildSubsets(nums, i + 1, subset, result);
      subset.pop_back();
    }
  }
};
