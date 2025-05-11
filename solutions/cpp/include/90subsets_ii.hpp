#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>
#include <set>
#include <unordered_set>

// Decision Tree (Recursive)
class RSolution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    // Always remember to sort
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<int> subset;
    decisionTree(nums, subset, 0, result);
    return result;
  }

private:
  void decisionTree(const std::vector<int>& nums,
      std::vector<int>& subset,
      std::size_t index,
      std::vector<std::vector<int>>& result) {
    // Base case
    if (index == nums.size()) {
      result.emplace_back(subset);
      return;
    }

    auto num = nums[index];
    subset.emplace_back(num);
    decisionTree(nums, subset, index + 1, result);
    subset.pop_back();

    // To avoid duplicate, do not include the same candidate
    while (index + 1 < nums.size() && num == nums[index + 1]) {
      ++index;
    }
    decisionTree(nums, subset, index + 1, result);
  }
};

// Masking With Checks
class MCSolution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    // Important notice: please sort your input array aka nums
    std::sort(nums.begin(), nums.end());

    auto n = nums.size();
    // The total number of subsets 2^n (including duplicate)
    auto total_subsets = 1uz << n;

    for (auto mask = 0uz; mask < total_subsets; ++mask) {
      std::vector<int> subset;
      bool valid{true};

      for (auto i = 0uz; i < n; ++i) {
        // If current i-th bit is set
        if (mask & 1uz << i) {
          // Check if current number is a duplicate but its previous occurrence wasn't chosen
          if (i > 0 && nums[i] == nums[i - 1] && !(mask & (1uz << (i - 1uz)))) {
            valid = false;
            break;
          }
          subset.emplace_back(nums[i]);
        }
      }

      if (valid) result.emplace_back(subset);
    }
    return result;
  }
};

// Masking With Unordered Set (need custom hash function)
class MUSSolution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::unordered_set<std::vector<int>, VectorHash> result;

    auto n = nums.size();
    // The total number of subsets 2^n
    auto total_subsets = 1uz << n;

    for (auto mask = 0uz; mask < total_subsets; ++mask) {
      std::vector<int> subset;
      for (auto i = 0uz; i < n; ++i) {
        if (mask & 1uz << i) {
          subset.emplace_back(nums[i]);
        }
      }
      result.insert(subset);
    }

    return {result.begin(), result.end()};
  }

private:
  // Custom hash function for vector<int>
  struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
      size_t hash = v.size();
      for (auto i : v) {
        // Combine the hash with each element
        hash ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
      }
      return hash;
    }
  };
};

// Masking With Set (need not custom hash function)
class MSSolution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::set<std::vector<int>> result;

    auto n = nums.size();
    // The total number of subsets 2^n
    auto total_subsets = 1uz << n;

    for (auto mask = 0uz; mask < total_subsets; ++mask) {
      std::vector<int> subset;
      for (auto i = 0uz; i < n; ++i) {
        if (mask & 1uz << i) {
          subset.emplace_back(nums[i]);
        }
      }
      result.insert(subset);
    }

    return {result.begin(), result.end()};
  }
};
