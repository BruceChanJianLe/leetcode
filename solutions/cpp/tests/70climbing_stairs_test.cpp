#include "70climbing_stairs.hpp"

#include "gtest/gtest.h"

struct States
{
  int n;
  int result;
};

class ClimbStairsTest : public ::testing::TestWithParam<States>
{
protected:
  DPSolution dps;
  OSolution os;
};

TEST_P(ClimbStairsTest, OptimalClimbStairsCase) {
  auto state = GetParam();
  EXPECT_EQ(dps.climbStairs(state.n), state.result);
}

TEST_P(ClimbStairsTest, DPClimbStairsCase) {
  auto state = GetParam();
  EXPECT_EQ(os.climbStairs(state.n), state.result);
}

INSTANTIATE_TEST_SUITE_P(
    ClimbStairsTests,
    ClimbStairsTest,
    ::testing::Values(
      States{1, 1},
      States{2, 2},
      States{3, 3},
      States{4, 5},
      States{5, 8},
      States{10, 89},
      States{20, 10946}
      )
    );
