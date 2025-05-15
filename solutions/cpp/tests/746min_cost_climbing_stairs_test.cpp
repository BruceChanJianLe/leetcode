#include "746min_cost_climbing_stairs.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> cost;
  int result;
};

class MinCostClimbingStairsTest : public ::testing::TestWithParam<States>
{
protected:
  DPBottomUpSolution s;
  DPRecursiveSolution rs;
};

TEST_P(MinCostClimbingStairsTest, DPBottomUpMinCostClimbingStairsCase) {
  auto as = GetParam();
  auto result = s.minCostClimbingStairs(as.cost);
  EXPECT_EQ(result, as.result);
}

TEST_P(MinCostClimbingStairsTest, DPRecursiveMinCostClimbingStairsCase) {
  auto as = GetParam();
  auto result = rs.minCostClimbingStairs(as.cost);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MinCostClimbingStairsTest,
  ::testing::Values(
    States{{10,15,20}, 15},
    States{{1,100,1,1,1,100,1,1,100,1}, 6},
    States{{0,0,1,1}, 1},
    States{{0,2,2,1}, 2},
    States{{1,1,0,0}, 1}
  )
);
