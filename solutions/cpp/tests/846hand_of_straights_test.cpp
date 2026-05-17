#include "846hand_of_straights.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> hand;
  int groupSize;
  bool result;
};

class HandOfStraightsTest : public ::testing::TestWithParam<States> {
protected:
  FirstSolution fs;
};

TEST_P(HandOfStraightsTest, FirstSolutionHandlesCases) {
  auto as = GetParam();
  auto result = fs.isNStraightHand(as.hand, as.groupSize);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(HandOfStraightsParameterizedTests, HandOfStraightsTest,
  ::testing::Values(
    States{
    {1,2,3,6,2,3,4,7,8},
    3,
    true
    }, // example 1

    States{
    {1,2,3,4,5},
    4,
    false
    }, // example 2

    States{
    {1,2,3,4},
    1,
    true
    }, // groupSize = 1

    States{
    {1,1,2,2,3,3},
    3,
    true
    }, // duplicates valid

    States{
      {1,1,2,2,3,4},
      3,
      false
    }, // missing consecutive

    States{
      {8,10,12},
      3,
      false
    }, // non-consecutive

    States{
      {1,2,3,4,5,6},
      2,
      true
    }, // multiple groups

    States{
      {1,2,3,4,5,6},
      4,
      false
    } // size not divisible
  )
);
