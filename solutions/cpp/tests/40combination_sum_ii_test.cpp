#include "40combination_sum_ii.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> candidates;
  int target;
  std::vector<std::vector<int>> result;
};

class CombinationSum2Test : public ::testing::TestWithParam<States>
{
protected:
  RSolution rs;
  IRSolution irs;
  IRSpanSolution ir_span_s;

  static void normalize(std::vector<std::vector<int>>& v) {
    for (auto& comb : v) std::sort(comb.begin(), comb.end());
    std::sort(v.begin(), v.end());
  }
};

TEST_P(CombinationSum2Test, IRSpanCombinationSum2Case) {
  auto as = GetParam();
  auto result = ir_span_s.combinationSum2(as.candidates, as.target);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSum2Test, IRCombinationSum2Case) {
  auto as = GetParam();
  auto result = irs.combinationSum2(as.candidates, as.target);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSum2Test, RCombinationSum2Case) {
  auto as = GetParam();
  auto result = rs.combinationSum2(as.candidates, as.target);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Default, CombinationSum2Test,
  ::testing::Values(
    States{ {10, 1, 2, 7, 6, 1, 5}, 8, {{1,1,6}, {1,2,5}, {1,7}, {2,6}} },
    States{ {2, 5, 2, 1, 2}, 5, {{1,2,2}, {5}} },
    States{ {1, 1, 1, 1}, 2, {{1,1}} },
    States{ {3, 1, 3, 5, 1, 1}, 8, {{1,1,1,5}, {1,1,3,3}, {3,5}} }
  )
);
