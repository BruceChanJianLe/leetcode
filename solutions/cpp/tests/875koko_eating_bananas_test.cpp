#include "875koko_eating_bananas.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> piles;
  int h;
  int result;
};

struct KokoEatingBananasTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(KokoEatingBananasTest, KokoEatingBananasCase)
{
  auto as = GetParam();
  auto result = s.minEatingSpeed(as.piles, as.h);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, KokoEatingBananasTest,
    testing::Values(
      States{{3,6,7,11}, 8, 4},
      States{{30,11,23,4,20}, 5, 30},
      States{{30,11,23,4,20}, 6, 23},
      States{{1000000000}, 2, 500000000}
    ));
