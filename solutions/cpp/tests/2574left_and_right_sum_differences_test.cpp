#include "2574left_and_right_sum_differences.hpp"

#include <gtest/gtest.h>

struct States {
  std::vector<int> nums;
  std::vector<int> result;
};

struct LeftAndRightSumDifferencesTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(LeftAndRightSumDifferencesTest, ComputesDifference)
{
  auto as = GetParam();
  auto result = s.leftRightDifference(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, LeftAndRightSumDifferencesTest,
  ::testing::Values(
    States{ {10, 4, 8, 3}, {15, 1, 11, 22} },
    States{ {1}, {0} },
    States{ {1, 2}, {2, 1} },
    States{ {5, 5, 5, 5}, {15, 5, 5, 15} },
    States{ {100000, 1, 1, 1}, {3, 99998, 99999, 100002} }
  )
);

