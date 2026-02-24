#include "198house_robber.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int result;
};

class HouseRobberTest : public ::testing::TestWithParam<States> 
{
protected:
  FirstSolution fs;
  DPSolution dps;
  ODPSolution odps;
  ADPSolution adps;
};

TEST_P(HouseRobberTest, FirstHourseRobberCase) {
  auto as = GetParam();
  auto result = fs.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(HouseRobberTest, DPHourseRobberCase) {
  auto as = GetParam();
  auto result = dps.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(HouseRobberTest, ODPHourseRobberCase) {
  auto as = GetParam();
  auto result = odps.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(HouseRobberTest, ADPHourseRobberCase) {
  auto as = GetParam();
  auto result = adps.rob(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, HouseRobberTest,
  ::testing::Values(
    States{{1,2,3,1}, 4},
    States{{2,7,9,3,1}, 12},
    States{{2,1,1,2}, 4},
    States{{1}, 1},
    States{{5,5,10,100,10,5}, 110},
    States{{0,0,0}, 0},
    States{{10,1,1,10}, 20},
    States{{4,2,1,100}, 104},
    States{{2,1,1,2}, 4}
  )
);
