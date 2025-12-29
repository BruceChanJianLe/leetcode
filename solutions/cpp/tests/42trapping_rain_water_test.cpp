#include "42trapping_rain_water.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> height;
  int result;
};

struct TrappingRainWaterTest : public testing::Test, testing::WithParamInterface<States>
{
  ClassicSolution cs;
  IteratorSolution is;
  StackSolution ss;
};

TEST_P(TrappingRainWaterTest, ClassicTrappingRainWaterCase)
{
  auto as = GetParam();
  auto result = cs.trap(as.height);
  EXPECT_EQ(result, as.result);
}

TEST_P(TrappingRainWaterTest, IteratorTrappingRainWaterCase)
{
  auto as = GetParam();
  auto result = is.trap(as.height);
  EXPECT_EQ(result, as.result);
}

TEST_P(TrappingRainWaterTest, StackTrappingRainWaterCase)
{
  auto as = GetParam();
  auto result = ss.trap(as.height);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, TrappingRainWaterTest,
    testing::Values(
      States{{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
      States{{4,2,0,3,2,5}, 9},
      States{{0,2,0,3,1,0,1,3,2,1}, 9}
    ));
