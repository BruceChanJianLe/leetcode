#include "4median_of_two_sorted_arrays.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums1;
  std::vector<int> nums2;
  double result;
};

struct MedianOfTwoSortedArraysTest : public testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(MedianOfTwoSortedArraysTest, MedianOfTwoSortedArraysCase)
{
  auto as = GetParam();
  auto result = s.findMedianSortedArrays(as.nums1, as.nums2);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MedianOfTwoSortedArraysTest,
    testing::Values(
      States{{1,3}, {2}, 2.0},
      States{{1,2}, {3, 4}, 2.5}
    ));
