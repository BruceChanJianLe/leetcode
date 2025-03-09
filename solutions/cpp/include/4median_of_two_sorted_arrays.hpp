#pragma once

#include <limits>
#include <span>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    // Obtain the smaller range
    auto [larger_range, smaller_range] = (nums1.size() > nums2.size())
      ? std::pair{std::span{nums1}, std::span{nums2}}
      : std::pair{std::span{nums2}, std::span{nums1}};

      auto total_size = larger_range.size() + smaller_range.size();
      auto half_size = (total_size + 1) / 2; // take note
      auto lo{0uz}, hi{smaller_range.size()}; // take note

      while (lo <= hi) {
        // Calculate left portion size (smaller_size + larger_size = half_size)
        auto smaller_size = (lo + hi) / 2;
        auto larger_size = half_size - smaller_size;

        // Calculate left portion values
        auto smaller_left_val = (smaller_size == 0) ?
          std::numeric_limits<int>::min() : smaller_range[smaller_size - 1];
        auto larger_left_val = (larger_size == 0) ?
          std::numeric_limits<int>::min() : larger_range[larger_size - 1];

        // Calculate right portion values
        auto smaller_right_val = (smaller_size == smaller_range.size()) ?
          std::numeric_limits<int>::max() : smaller_range[smaller_size];
        auto larger_right_val = (larger_size == larger_range.size()) ?
          std::numeric_limits<int>::max() : larger_range[larger_size];

        // Calculate median
        if (smaller_left_val <= larger_right_val && larger_left_val <= smaller_right_val)
        {
          // if even
          if (total_size % 2 == 0) {
            return (std::max(smaller_left_val, larger_left_val) +
                std::min(smaller_right_val, larger_right_val)) / 2.0;
          } // if odd
          else {
            return std::max(smaller_left_val, larger_left_val);
          }
        } else if (smaller_left_val > larger_right_val) {
          hi = smaller_size;
        } else {
          lo = smaller_size + 1;
        }
      }
      // Should never reach here
      return -1;
  }
};
