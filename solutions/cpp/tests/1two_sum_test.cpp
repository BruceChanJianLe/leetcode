#include "1two_sum.hpp"

#include "gtest/gtest.h"
#include <vector>
#include <algorithm>

// 1. Two Sum Test

struct States
{
  std::vector<int> nums;
  int target;
  std::vector<int> result;
};

struct TwoSumTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(TwoSumTest, TwoSumCases)
{
  auto as = GetParam();
  auto result = s.twoSum(as.nums, as.target);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, TwoSumTest,
    testing::Values(
      States{{2, 7, 11, 15}, 9, {0, 1}},
      States{{3, 2, 4}, 6, {1, 2}},
      States{{3, 3}, 6, {0, 1}}
    ));
