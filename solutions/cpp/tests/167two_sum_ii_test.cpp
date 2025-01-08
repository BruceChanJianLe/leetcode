#include "167two_sum_ii.hpp"

#include "gtest/gtest.h"

// 167. Two Sum II Test

struct States
{
  std::vector<int> nums;
  int target;
  std::vector<int> result;
};

struct TwoSumIITest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
  SecondSolution ss;
};

TEST_P(TwoSumIITest, TwoSumIICase)
{
  auto as = GetParam();
  auto result = s.twoSum(as.nums, as.target);
  EXPECT_EQ(result, as.result);
}

TEST_P(TwoSumIITest, FirstTwoSumIICase)
{
  auto as = GetParam();
  auto result = fs.twoSum(as.nums, as.target);
  EXPECT_EQ(result, as.result);
}

TEST_P(TwoSumIITest, SecondTwoSumIICase)
{
  auto as = GetParam();
  auto result = ss.twoSum(as.nums, as.target);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, TwoSumIITest,
    testing::Values(
      States{{2,7,11,15}, 9, {1, 2}},
      States{{2, 3, 4}, 6, {1, 3}},
      States{{-1, 0}, -1, {1, 2}}
    ));
