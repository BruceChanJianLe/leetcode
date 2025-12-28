#include "15three_sum.hpp"

#include "gtest/gtest.h"

// 15. Three Sum Test


struct States
{
  std::vector<int> nums;
  std::vector<std::vector<int>> result;
};

struct ThreeSumTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
  RecursiveSolution rs;
};

TEST_P(ThreeSumTest, ThreeSumCase)
{
  auto as = GetParam();
  auto result = s.threeSum(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(ThreeSumTest, FirstThreeSumCase)
{
  auto as = GetParam();
  auto result = fs.threeSum(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(ThreeSumTest, RecursiveThreeSumCase)
{
  auto as = GetParam();
  auto result = rs.threeSum(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, ThreeSumTest,
    testing::Values(
      States{{-1,0,1,2,-1,-4},{{-1,-1,2}, {-1,0,1}}},
      States{{0,1,1},{}},
      States{{0,0,0},{{0, 0, 0}}},
      States{{-2,0,1,1,2},{{-2,0,2},{-2,1,1}}},
      States{{-1,0,1,2,-1,-4},{{-1,-1,2},{-1,0,1}}}
    ));
