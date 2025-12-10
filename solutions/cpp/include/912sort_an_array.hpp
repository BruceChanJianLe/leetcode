#pragma once

#include <algorithm>
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


class RecursiveMergeSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      mergeSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }

private:
  void mergeSort(std::vector<int>& nums, int lo, int hi) {
    // Base case
    if (lo >= hi) return;

    // Calculate mid point
    const auto mid = lo + (hi - lo) / 2;
    // Sort two halves
    mergeSort(nums, lo, mid);
    mergeSort(nums, mid + 1, hi);

    // Merge two halves
    merge(nums, lo, mid, hi);
  }

  void merge(std::vector<int>& nums, int lo, int mid, int hi) {
    // const auto left_size = mid - lo + 1;
    // const auto right_size = hi - mid;

    std::vector<int> left_vec(nums.begin() + lo, nums.begin() + mid + 1);
    std::vector<int> right_vec(nums.begin() + mid + 1, nums.begin() + hi + 1);

    int left{}, right{}, index{lo};
    while (left < left_vec.size() && right < right_vec.size()) {
      if (left_vec[left] <= right_vec[right]) {
        nums[index] = left_vec[left];
        ++left;
      } else {
        nums[index] = right_vec[right];
        ++right;
      }
      ++index;
    }

    // Copy remaining elements of left_vec
    while (left < left_vec.size()) {
      nums[index] = left_vec[left];
      ++left;
      ++index;
    }

    // Copy remaining elements of right_vec
    while (right < right_vec.size()) {
      nums[index] = right_vec[right];
      ++right;
      ++index;
    }
  }
};

// Use iterators with bubble sort
class ItrBubbleSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    bubbleSort(nums.begin(), nums.end());
    return nums;
  }

private:
  template<typename Iterator>
    void bubbleSort(Iterator begin, Iterator end) {
      // Sanity check
      if (begin == end) return;

      bool swapped{false};
      auto last = end;

      do {
        swapped = false;
        // Two pointers
        auto curr = begin;
        auto next = begin;
        ++next;

        while (next !=  last) {
          if (*curr > *next) {
            std::iter_swap(curr, next);
            swapped = true;
          }
          ++curr;
          ++next;
        }
        --last;
      } while (swapped && last != end);
    }
};

// Use iterators with bubble sort
class ItrInsertionSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    InsertionSort(nums.begin(), nums.end());
    return nums;
  }

private:
  template<typename Iterator>
    void InsertionSort(Iterator begin, Iterator end) {
      // Sanity check
      if (begin == end) return;

      for (auto curr = begin; curr != end; ++curr) {
        auto curr_val = *curr;
        auto insert_pose = curr;
        while (insert_pose != begin) {
          auto prev = insert_pose;
          --prev;

          if (*prev <= curr_val) {
            break;
          }

          // Shift to the right
          *insert_pose = *prev;
          insert_pose = prev;
        }

        *insert_pose = curr_val;
      }
    }
};
