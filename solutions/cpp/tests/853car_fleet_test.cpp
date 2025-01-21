#include "853car_fleet.hpp"

#include "gtest/gtest.h"

struct States
{
  int target;
  std::vector<int> position;
  std::vector<int> speed;
  int result;
};

struct CarFleetTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
};

TEST_P(CarFleetTest, CarFleetCase)
{
  auto as = GetParam();
  auto result = s.carFleet(as.target, as.position, as.speed);
  EXPECT_EQ(result, as.result);
}

TEST_P(CarFleetTest, FirstCarFleetCase)
{
  auto as = GetParam();
  auto result = fs.carFleet(as.target, as.position, as.speed);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, CarFleetTest,
    testing::Values(
      States{12, {10,8,0,5,3}, {2,4,1,1,3}, 3},
      States{10, {3}, {3}, 1},
      States{100, {0,2,4}, {4,2,1}, 1}
    ));
