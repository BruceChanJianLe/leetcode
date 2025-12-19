#pragma once

#include <algorithm>
#include <utility>
#include <vector>
#include <span>
#include <random>

// Optimized by Gemini, randomize the pivot selection
// and skip all elements that are the same as pivot
class OptimizedRecursiveQuickSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      quickSort(std::span<int>(nums));
    }
    return nums;
  }

private:
  void quickSort(std::span<int> nums) {
    if (nums.size() <= 1) return;

    // 1. Choose a truly random pivot to avoid worst-case test cases
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, nums.size() - 1);
    int pivot = nums[dist(rng)];

    // 2. Three-Way Partitioning (Dutch National Flag)
    size_t lt = 0;           // Elements < pivot
    size_t i = 0;            // Current element
    size_t gt = nums.size(); // Elements > pivot (using size for unsigned bounds)

    while (i < gt) {
      if (nums[i] < pivot) {
        std::swap(nums[i++], nums[lt++]);
      } else if (nums[i] > pivot) {
        std::swap(nums[i], nums[--gt]);
      } else {
        i++;
      }
    }

    // 3. Recurse ONLY on the < and > parts (skip all == pivot elements)
    quickSort(nums.subspan(0, lt));
    quickSort(nums.subspan(gt));
  }
};

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

// Optimized by Gemini
// create a buffer to be reused, merge sort's hiccup comes from extra space
class OptimizedRecursiveMergeSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() <= 1) return nums;

    // 1. Allocate a single temporary buffer to reuse across all merges
    std::vector<int> buffer(nums.size());

    // 2. Start the recursive merge sort
    // We pass the data (nums) and the workspace (buffer) as spans
    mergeSort(std::span<int>(nums), std::span<int>(buffer));

    return nums;
  }

private:
  void mergeSort(std::span<int> nums, std::span<int> buffer) {
    if (nums.size() <= 1) return;

    const size_t mid = nums.size() / 2;

    // Use subspan to split the views without copying any data
    auto left_nums = nums.subspan(0, mid);
    auto right_nums = nums.subspan(mid);
    auto left_buf = buffer.subspan(0, mid);
    auto right_buf = buffer.subspan(mid);

    // Recursive calls
    mergeSort(left_nums, left_buf);
    mergeSort(right_nums, right_buf);

    // Merge the results using the pre-allocated buffer
    merge(nums, left_nums, right_nums, buffer);
  }

  void merge(std::span<int> target, std::span<int> left, std::span<int> right, std::span<int> buffer) {
    // Copy the current sorted halves into our temporary buffer workspace
    // This is the ONLY copy per merge level
    std::copy(left.begin(), left.end(), buffer.begin());
    std::copy(right.begin(), right.end(), buffer.begin() + left.size());

    // Re-view the buffer as two distinct sorted parts to merge back into target
    auto b_left = buffer.subspan(0, left.size());
    auto b_right = buffer.subspan(left.size());

    size_t lp = 0, rp = 0, idx = 0;
    while (lp < b_left.size() && rp < b_right.size()) {
      if (b_left[lp] <= b_right[rp]) {
        target[idx++] = b_left[lp++];
      } else {
        target[idx++] = b_right[rp++];
      }
    }

    // Copy remaining elements
    while (lp < b_left.size()) target[idx++] = b_left[lp++];
    while (rp < b_right.size()) target[idx++] = b_right[rp++];
  }
};

// Merge Sort using std::span
class RecursiveSpanMergeSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    if (nums.size() > 1) {
      mergeSort(nums);
    }
    return nums;
  }

private:
  void mergeSort(std::span<int> nums) {
    // Base case
    if (nums.size() <= 1) return;

    // Calculate mid point
    const auto mid = nums.size() / 2;
    // A view into the two halves
    auto left_num = nums.subspan(0, mid);
    auto right_num = nums.subspan(mid);

    // Sort two halves
    mergeSort(left_num);
    mergeSort(right_num);

    // Merge two halves
    merge(nums, left_num, right_num);
  }

  void merge(std::span<int> nums, std::span<int> left_num, std::span<int> right_num) {
    std::vector<int> left_vec(left_num.begin(), left_num.end());
    std::vector<int> right_vec(right_num.begin(), right_num.end());

    int left{}, right{}, index{};
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

// Using standard library to implement heap sort
class STDHeapSortSolution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    std::make_heap(nums.begin(), nums.end());
    std::sort_heap(nums.begin(), nums.end());

    return nums;
  }
};
