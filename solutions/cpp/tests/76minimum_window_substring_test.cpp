#include "76minimum_window_substring.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string s;
  std::string t;
  std::string result;
};

struct MinimumWindowSubstringTest : public testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(MinimumWindowSubstringTest, MinimumWindowSubstringCase)
{
  auto as = GetParam();
  auto result = s.minWindow(as.s, as.t);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MinimumWindowSubstringTest,
    testing::Values(
      States{"ADOBECODEBANC", "ABC", "BANC"},
      States{"a", "a", "a"},
      States{"a", "aa", ""},
      States{"aa", "aa", "aa"},
      States{"a", "b", ""}
    ));
