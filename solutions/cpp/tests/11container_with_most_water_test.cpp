#include "11container_with_most_water.hpp"

#include "gtest/gtest.h"

// 11. Container with Most Water Test

struct States
{
  std::vector<int> height;
  int result;
};

struct ContainerWithMostWaterTest : public testing::Test, testing::WithParamInterface<States>
{
  ClassicSolution cs;
  IteratorSolution is;
  FirstSolution fs;
};

TEST_P(ContainerWithMostWaterTest, IteratorContainerWithMostWaterCase)
{
  auto as = GetParam();
  auto result = is.maxArea(as.height);
  EXPECT_EQ(result, as.result);
}

TEST_P(ContainerWithMostWaterTest, FirstContainerWithMostWaterCase)
{
  auto as = GetParam();
  auto result = fs.maxArea(as.height);
  EXPECT_EQ(result, as.result);
}

TEST_P(ContainerWithMostWaterTest, ClassicContainerWithMostWaterCase)
{
  auto as = GetParam();
  auto result = cs.maxArea(as.height);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, ContainerWithMostWaterTest,
    testing::Values(
      States{{1,8,6,2,5,4,8,3,7}, 49},
      States{{1,1}, 1}
    ));
