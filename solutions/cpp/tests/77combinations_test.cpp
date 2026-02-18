#include "77combinations.hpp"

#include "gtest/gtest.h"

struct States {
  int n;
  int k;
  std::vector<std::vector<int>> result;
};

class CombinationsTest : public ::testing::TestWithParam<States>
{
protected:
  SpanSolution ss;
  SpanCreateSolution scs;

  static void normalize(std::vector<std::vector<int>>& vec) {
    for (auto& v : vec) std::sort(v.begin(), v.end());
    std::sort(vec.begin(), vec.end());
  }
};

TEST_P(CombinationsTest, SpanSolution) {
  auto as = GetParam();
  auto result = ss.combine(as.n, as.k);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(CombinationsTest, SpanCreateSolution) {
  auto as = GetParam();
  auto result = scs.combine(as.n, as.k);
  normalize(result);
  auto expected = as.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Default, CombinationsTest,
  ::testing::Values(
    States{4, 2, {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
    States{1, 1, {{1}}},
    States{5, 5, {{1,2,3,4,5}}},
    States{5, 1, {{1},{2},{3},{4},{5}}}
  )
);
