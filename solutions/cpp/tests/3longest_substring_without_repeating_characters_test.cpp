#include "3longest_substring_without_repeating_characters.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string s;
  int result;
};

struct LongestSubstringWithoutRepeatingCharactersTest : public testing::TestWithParam<States>
{
  Solution s;
  SecondSolution ss; // fastest with iterator and while loop
  FirstSolution fs;
  SetSolution sets;
};

TEST_P(LongestSubstringWithoutRepeatingCharactersTest, LongestSubstringWithoutRepeatingCharactersCase)
{
  auto as = GetParam();
  auto result = s.lengthOfLongestSubstring(as.s);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestSubstringWithoutRepeatingCharactersTest, SecondLongestSubstringWithoutRepeatingCharactersCase)
{
  auto as = GetParam();
  auto result = ss.lengthOfLongestSubstring(as.s);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestSubstringWithoutRepeatingCharactersTest, FirstLongestSubstringWithoutRepeatingCharactersCase)
{
  auto as = GetParam();
  auto result = fs.lengthOfLongestSubstring(as.s);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestSubstringWithoutRepeatingCharactersTest, SetLongestSubstringWithoutRepeatingCharactersCase)
{
  auto as = GetParam();
  auto result = sets.lengthOfLongestSubstring(as.s);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, LongestSubstringWithoutRepeatingCharactersTest,
    testing::Values(
      States{"abcabcbb", 3},
      States{"bbbbb", 1},
      States{"pwwkew", 3},
      States{"abba", 2},
      States{"aab", 2},
      States{"dvdf", 3},
      States{" ", 1}
    ));
