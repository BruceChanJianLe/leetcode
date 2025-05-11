#include "46permutations.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  std::vector<std::vector<int>> result;
};

class PermutationsTest : public ::testing::TestWithParam<States>
{
protected:
  SSolution ss; // optimal
  BRSolution brs;
  RSolution rs;

  static void normalize(std::vector<std::vector<int>>& vec) {
    for (auto& v : vec) std::sort(v.begin(), v.end());
    std::sort(vec.begin(), vec.end());
  }
};

TEST_P(PermutationsTest, RPermutationsCase) {
  auto state = GetParam();
  auto result = brs.permute(state.nums);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(PermutationsTest, BRPermutationsCase) {
  auto state = GetParam();
  auto result = brs.permute(state.nums);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

TEST_P(PermutationsTest, SPermutationsCase) {
  auto state = GetParam();
  auto result = ss.permute(state.nums);
  normalize(result);
  auto expected = state.result;
  normalize(expected);
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Default, PermutationsTest,
  ::testing::Values(
    States{{1}, {{1}}},
    States{{0, 1}, {{0, 1}, {1, 0}}},
    States{{1, 2, 3}, {
    {1, 2, 3}, {1, 3, 2}, {2, 1, 3},
    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
    }}
  )
);
