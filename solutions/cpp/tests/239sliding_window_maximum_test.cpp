#include "239sliding_window_maximum.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  int k;
  std::vector<int> result;
};

struct SlidingWindowMaximumTest : public testing::TestWithParam<States>
{
  Solution s;
  NaiveSolution ns;
};

TEST_P(SlidingWindowMaximumTest, SlidingWindowMaximumCase)
{
  auto as = GetParam();
  auto result = s.maxSlidingWindow(as.nums, as.k);
  EXPECT_EQ(result, as.result);
}

TEST_P(SlidingWindowMaximumTest, NaiveSlidingWindowMaximumCase)
{
  auto as = GetParam();
  auto result = ns.maxSlidingWindow(as.nums, as.k);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SlidingWindowMaximumTest,
  testing::Values(
    States{{1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}}
  )
);
