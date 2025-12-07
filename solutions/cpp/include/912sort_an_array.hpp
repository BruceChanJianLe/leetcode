#pragma once

#include <utility>
#include <vector>

// This chose the last element as the pivot point
class RecursiveQuickSortLastSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      quickSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

private:
  void quickSort(std::vector<int>& nums, int lo, int hi) {
    // Base cases
    if (lo >= hi)  return;

    const auto pivot_index = partition(nums, lo, hi);
    quickSort(nums, lo, pivot_index - 1);
    quickSort(nums, pivot_index + 1, hi);
  }

  int partition(std::vector<int>& nums, int lo, int hi) {
    const auto pivot_value = nums[hi];
    auto pivot_index = lo - 1;

    for (auto index = lo; index < hi; ++index) {
      if (nums[index] <= pivot_value) {
        ++pivot_index;
        std::swap(nums[index], nums[pivot_index]);
      }
    }
    // move the pivot to the pivot index
    ++pivot_index;
    std::swap(nums[pivot_index], nums[hi]);

    return pivot_index;
  }
};

// This chose the first element as the pivot point
class RecursiveQuickSortFirstSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      quickSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

private:
  void quickSort(std::vector<int>& nums, int lo, int hi) {
    // Base cases
    if (lo >= hi)  return;

    const auto pivot_index = partition(nums, lo, hi);
    quickSort(nums, lo, pivot_index - 1);
    quickSort(nums, pivot_index + 1, hi);
  }

  int partition(std::vector<int>& nums, int lo, int hi) {
    const auto pivot_value = nums[lo];
    auto pivot_index = lo;

    for (auto index = lo + 1; index <= hi; ++index) {
      if (nums[index] <= pivot_value) {
        ++pivot_index;
        std::swap(nums[index], nums[pivot_index]);
      }
    }
    // move the pivot to the pivot index
    std::swap(nums[pivot_index], nums[lo]);

    return pivot_index;
  }
};

// This chose the middle element as the pivot point
// This is sort median-of-three pivots (lo, mid, hi) for better performance
// This can avoid reverse sorted array
class RecursiveQuickSortMidSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      quickSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

private:
  void quickSort(std::vector<int>& nums, int lo, int hi) {
    // Base cases
    if (lo >= hi)  return;

    const auto pivot_index = partition(nums, lo, hi);
    quickSort(nums, lo, pivot_index - 1);
    quickSort(nums, pivot_index + 1, hi);
  }

  int partition(std::vector<int>& nums, int lo, int hi) {
    int mid = lo + (hi - lo) / 2;

    // Find median between lo, mid, hi
    if (nums[mid] < nums[lo]) std::swap(nums[mid], nums[lo]);
    if (nums[hi] < nums[lo]) std::swap(nums[hi], nums[lo]);
    if (nums[hi] < nums[mid]) std::swap(nums[hi], nums[mid]);

    // Sort to lo, mid, hi to find median
    const auto pivot_value = nums[mid];
    std::swap(nums[mid], nums[hi]);
    auto pivot_index = lo;

    for (auto index = lo; index < hi; ++index) {
      if (nums[index] <= pivot_value) {
        std::swap(nums[index], nums[pivot_index]);
        ++pivot_index;
      }
    }

    // move the pivot to the pivot index
    std::swap(nums[pivot_index], nums[hi]);

    return pivot_index;
  }
};
