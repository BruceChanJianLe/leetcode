#include "739daily_temperatures.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> temperatures;
  std::vector<int> result;
};

struct DailyTemperaturesTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  SecondSolution ss;
};

TEST_P(DailyTemperaturesTest, DailyTemperaturesCase)
{
  auto as = GetParam();
  auto result = s.dailyTemperatures(as.temperatures);
  EXPECT_EQ(result, as.result);
}

TEST_P(DailyTemperaturesTest, SecondDailyTemperaturesCase)
{
  auto as = GetParam();
  auto result = ss.dailyTemperatures(as.temperatures);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, DailyTemperaturesTest,
    testing::Values(
      States{{73,74,75,71,69,72,76,73},{1,1,4,2,1,1,0,0}},
      States{{30,40,50,60},{1,1,1,0}},
      States{{30,60,90},{1,1,0}}
    ));
