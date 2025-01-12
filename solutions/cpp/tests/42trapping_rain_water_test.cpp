#include "42trapping_rain_water.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> height;
  int result;
};

struct TrappingRainWaterTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(TrappingRainWaterTest, TrappingRainWaterCase)
{
  auto as = GetParam();
  auto result = s.trap(as.height);
}

INSTANTIATE_TEST_SUITE_P(Default, TrappingRainWaterTest,
    testing::Values(
      States{{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
      States{{4,2,0,3,2,5}, 9},
      States{{0,2,0,3,1,0,1,3,2,1}, 9}
    ));
