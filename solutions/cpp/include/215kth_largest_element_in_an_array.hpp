#pragma once

#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

// 1. QuickSelect (Recommended):
//    - Time: O(n) average, O(n²) worst case
//    - Space: O(1) if iterative, O(log n) for recursion
//    - Best for: Most scenarios, especially large arrays
class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
  }
};

// 2. STL nth_element:
//    - Time: O(n) average
//    - Space: O(1)
//    - Best for: Quick implementation

class STDNthSolution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::nth_element(nums.begin(), nums.end() - k, nums.end());
    return *std::prev(nums.end(), k);
  }
};

// 3. Full Sort:
//    - Time: O(n log n)
//    - Space: O(1) or O(log n) depending on sort
//    - Best for: When you need sorted array anyway

class STDFullSortSolution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

// 4. Min Heap of size k:
//    - Time: O(n log k)
//    - Space: O(k)
//    - Best for: When k is small

class MinHeapSolution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<>>
      min_heap(nums.begin(), nums.end());

    while (min_heap.size() != k) {
      min_heap.pop();
    }
    return min_heap.top();
  }
};

// 5. Max Heap:
//    - Time: O(n + k log n)
//    - Space: O(n)
//    - Best for: When k is close to n

class MaxHeapSolution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    // std::priority_queue<int, std::vector<int>, std::greater<>>
    std::priority_queue<int> max_heap(nums.begin(), nums.end());

    int result;
    while (k > 0) {
      result = max_heap.top();
      max_heap.pop();
      --k;
    }

    return result;
  }
};
