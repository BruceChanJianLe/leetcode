#include "153find_minimum_in_rotated_sorted_array.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  int result;
};

struct FindMinimumInRotatedSortedArrayTest : public testing::Test, testing::WithParamInterface<States>
{
  FirstSolution fs;
  Solution s;
};

TEST_P(FindMinimumInRotatedSortedArrayTest, FirstFindMinimumInRotatedSortedArrayCase)
{
  auto as = GetParam();
  auto result = fs.findMin(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(FindMinimumInRotatedSortedArrayTest, FindMinimumInRotatedSortedArrayCase)
{
  auto as = GetParam();
  auto result = s.findMin(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Defalt, FindMinimumInRotatedSortedArrayTest,
    testing::Values(
      States{{3,4,5,1,2}, 1},
      States{{4,5,6,7,0,1,2}, 0},
      States{{11,13,15,17}, 11}
    ));
