#pragma once

#include <cstddef>
#include <utility>
#include <vector>

// Recursion
class RSolution {
public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    if (nums.size() == 0) return {{}};

    auto permutes = permute({nums.begin() + 1, nums.end()});
    std::vector<std::vector<int>> result;

    for (auto &permute : permutes) {
      // The condition allow to insert at the end of permutation
      for (auto i = 0uz; i < permute.size() + 1; ++i) {
        auto lpermute = permute;
        lpermute.insert(lpermute.begin() + i, nums.front());
        result.emplace_back(lpermute);
      }
    }

    return result;
  }
};

// Booking + Recursion
class BRSolution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> set;
    std::vector<bool> visited(nums.size(), false);
    permuteHelper(nums, set, visited, result);
    return result;
  }

private:
  void permuteHelper(std::vector<int>& nums,
      std::vector<int>& set, std::vector<bool>& visited,
      std::vector<std::vector<int>>& result
      ) {
    if (set.size() == nums.size()) {
      result.emplace_back(set);
      return;
    }

    for (auto i = 0uz; i < nums.size(); ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      set.emplace_back(nums[i]);
      permuteHelper(nums, set, visited, result);
      set.pop_back();
      visited[i] = false;
    }
  }
};

// Swapping positions (optimal)
class SSolution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> set;
    permuteHelper(nums, 0, result);
    return result;
  }

private:
  void permuteHelper(std::vector<int>& nums, std::size_t start,
      std::vector<std::vector<int>>& result
      ) {
    if (start == nums.size()) {
      result.emplace_back(nums);
      return;
    }

    for (auto i = start; i < nums.size(); ++i) {
      std::swap(nums[start], nums[i]);
      permuteHelper(nums, start + 1, result);
      std::swap(nums[start], nums[i]);
    }
  }
};
