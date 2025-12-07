#include "215kth_largest_element_in_an_array.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int k;
  int expected;
};

// Test fixture
struct KthLargestTest : public ::testing::TestWithParam<States> {
  Solution s;
  STDNthSolution sns;
  STDFullSortSolution sfss;
  MinHeapSolution minhs;
  MaxHeapSolution maxhs;
};

TEST_P(KthLargestTest, SolutionTests) {
  auto as = GetParam();
  // Note that solution mutates the input vector
  auto temp = as.nums;
  EXPECT_EQ(s.findKthLargest(temp, as.k), as.expected);
}

TEST_P(KthLargestTest, STDNthSolutionTests) {
  auto as = GetParam();
  // Note that solution mutates the input vector
  auto temp = as.nums;
  EXPECT_EQ(sns.findKthLargest(temp, as.k), as.expected);
}

TEST_P(KthLargestTest, STDFullSortSolutionTests) {
  auto as = GetParam();
  // Note that solution mutates the input vector
  auto temp = as.nums;
  EXPECT_EQ(sfss.findKthLargest(temp, as.k), as.expected);
}

TEST_P(KthLargestTest, MinHeapSolutionTests) {
  auto as = GetParam();
  // Note that solution mutates the input vector
  auto temp = as.nums;
  EXPECT_EQ(minhs.findKthLargest(temp, as.k), as.expected);
}

TEST_P(KthLargestTest, MaxHeapSolutionTests) {
  auto as = GetParam();
  // Note that solution mutates the input vector
  auto temp = as.nums;
  EXPECT_EQ(maxhs.findKthLargest(temp, as.k), as.expected);
}

INSTANTIATE_TEST_SUITE_P(Default, KthLargestTest,
    ::testing::Values(
      States{{3,2,1,5,6,4}, 2, 5},         // example 1
      States{{3,2,3,1,2,4,5,5,6}, 4, 4},   // example 2
      States{{10}, 1, 10},                 // single element
      States{{5,5,5,5,5}, 3, 5},           // all equal
      States{{-3,-1,-2,-5,-4}, 1, -1},     // negatives
      States{{7,10,4,3,20,15}, 3, 10}      // random example
      )
    );
