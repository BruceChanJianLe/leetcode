#include "39combination_sum.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> candidates;
  int target;
  std::vector<std::vector<int>> result;
};

class CombinationSumTest : public ::testing::TestWithParam<States> {
protected:
  IRSolution is;
  RSolution rs;
  BTSolution bts;
  BTNSolution btns;

  static void normalize(std::vector<std::vector<int>>& v) {
    for (auto& comb : v) std::sort(comb.begin(), comb.end());
    std::sort(v.begin(), v.end());
  }
};

TEST_P(CombinationSumTest, RCombinationSumCase) {
  States state = GetParam();
  auto result = rs.combinationSum(state.candidates, state.target);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumTest, IRCombinationSumCase) {
  States state = GetParam();
  auto result = is.combinationSum(state.candidates, state.target);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumTest, BTCombinationSumCase) {
  States state = GetParam();
  auto result = bts.combinationSum(state.candidates, state.target);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumTest, BTNCombinationSumCase) {
  States state = GetParam();
  auto result = btns.combinationSum(state.candidates, state.target);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Default, CombinationSumTest,
  ::testing::Values(
    States{ {2, 3, 6, 7}, 7, {{2, 2, 3}, {7}} },
    States{ {2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}} },
    States{ {2}, 1, {} },
    States{ {1}, 2, {{1, 1}} }
  )
);
