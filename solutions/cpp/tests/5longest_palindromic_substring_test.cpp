#include "5longest_palindromic_substring.hpp"

#include "gtest/gtest.h"

#include <unordered_set>

struct States {
  std::string input;
  std::unordered_set<std::string> result;  // Use a set to allow multiple valid answers
};

class LongestPalindromicSubstringTest : public ::testing::TestWithParam<States> {
protected:
  FirstSolution fs;
  SecondSolution ss;
};

TEST_P(LongestPalindromicSubstringTest, FirstLongestPalindromicSubstringCase) {
  const auto& as = GetParam();
  std::string result = fs.longestPalindrome(as.input);
  EXPECT_TRUE(as.result.count(result));
}

TEST_P(LongestPalindromicSubstringTest, SecondLongestPalindromicSubstringCase) {
  const auto& as = GetParam();
  std::string result = ss.longestPalindrome(as.input);
  EXPECT_TRUE(as.result.count(result));
}

INSTANTIATE_TEST_SUITE_P(Default, LongestPalindromicSubstringTest,
  ::testing::Values(
    States{"babad", {"bab", "aba"}},
    States{"cbbd", {"bb"}},
    States{"a", {"a"}},
    States{"bb", {"bb"}},
    States{"ac", {"a", "c"}},
    States{"racecar", {"racecar"}},
    States{"abcda", {"a", "b", "c", "d"}},
    States{"aacabdkacaa", {"aca"}}
  )
);
