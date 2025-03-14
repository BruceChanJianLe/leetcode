#include "424longest_repeating_character_replacement.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string s;
  int k;
  int result;
};

struct LongestRepeatingCharacterReplacementTest : public testing::TestWithParam<States>
{
  Solution s;
  AnotherSolution anos;
};

TEST_P(LongestRepeatingCharacterReplacementTest, LongestRepeatingCharacterReplacementCase)
{
  auto as = GetParam();
  auto result = s.characterReplacement(as.s, as.k);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestRepeatingCharacterReplacementTest, AnotherLongestRepeatingCharacterReplacementCase)
{
  auto as = GetParam();
  auto result = s.characterReplacement(as.s, as.k);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, LongestRepeatingCharacterReplacementTest,
    testing::Values(
      States{"ABAB", 2, 4},
      States{"AABABBA", 1, 4}
    ));
