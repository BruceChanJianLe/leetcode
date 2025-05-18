#include "213house_robber_ii.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int result;
};

class HouseRobberIITest : public ::testing::TestWithParam<States> {
protected:
  DPSolution dps;
  ODPSolution odps;
};

TEST_P(HouseRobberIITest, DPHouseRobberIICase) {
  auto as = GetParam();
  auto result = dps.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(HouseRobberIITest, OptimizeDPHouseRobberIICase) {
  auto as = GetParam();
  auto result = odps.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, HouseRobberIITest,
  ::testing::Values(
    States{{2,3,2}, 3},
    States{{1,2,3,1}, 4},
    States{{1,2,3}, 3},
    States{{5,1,1,5}, 6},
    States{{1}, 1},
    States{{1,2,1,1}, 3},
    States{{1,7,9,2}, 10},
    States{{10,1,1,10}, 11}
  )
);
