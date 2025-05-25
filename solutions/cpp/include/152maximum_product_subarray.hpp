#pragma once

#include <algorithm>
#include <vector>

// Kadane's algorithm (slightly modified)
class KSSolution {
public:
  int maxProduct(const std::vector<int>& nums) {
    // Using 1 as initial value so I can start from the first element
    auto curr_max{1}, curr_min{1};
    // Using the first element, as size is guarantee to be at least 1
    auto global_max{nums.front()};

    for (const auto &num : nums) {
      auto [min, max] = std::minmax({num, num * curr_min, num * curr_max});
      curr_min = min;
      curr_max = max;
      global_max = std::max(global_max, curr_max);
    }

    return global_max;
  }
};

// Kadane's algorithm (with std::swap)
// A more general approach is to swap the min and max
// when num value is negative
class GKSSolution {
public:
  int maxProduct(const std::vector<int>& nums) {
    // Using 1 as initial value so I can start from the first element
    auto curr_max{1}, curr_min{1};
    // Using the first element, as size is guarantee to be at least 1
    auto global_max{nums.front()};

    for (const auto &num : nums) {
      if (num < 0) {
        std::swap(curr_min, curr_max);
      }

      curr_min = std::min(num, num * curr_min);
      curr_max = std::max(num, num * curr_max);
      global_max = std::max(global_max, curr_max);
    }

    return global_max;
  }
};
