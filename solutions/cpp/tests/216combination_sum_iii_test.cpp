#include "216combination_sum_iii.hpp"

#include "gtest/gtest.h"

struct States
{
  int k;
  int n;
  std::vector<std::vector<int>> result;
};

class CombinationSumIIITest : public ::testing::TestWithParam<States>
{
protected:
  RSpanSolution r_span_s;
  CRSpanSolution cr_span_s;

  static void normalize(std::vector<std::vector<int>>& vec) {
    for (auto& v : vec) std::sort(v.begin(), v.end());
    std::sort(vec.begin(), vec.end());
  }
};

TEST_P(CombinationSumIIITest, RSpanSolution) {
  auto as = GetParam();
  auto result = r_span_s.combinationSum3(as.k, as.n);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationSumIIITest, CRSpanSolution) {
  auto as = GetParam();
  auto result = cr_span_s.combinationSum3(as.k, as.n);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Default, CombinationSumIIITest,
  ::testing::Values(
    States{3, 9, { {1, 2, 6}, {1, 3, 5}, {2, 3, 4} }},
    States{4, 1, {}},
    States{2, 17, {{8, 9}}},
    States{9, 45, {{1, 2, 3, 4, 5, 6, 7, 8, 9}}},
    States{9, 10, {}}
  )
);
