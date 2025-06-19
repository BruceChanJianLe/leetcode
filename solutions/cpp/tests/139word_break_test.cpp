#include "139word_break.hpp"

#include "gtest/gtest.h"

struct States {
  std::string s;
  std::vector<std::string> wordDict;
  bool result;
};

class WordBreakTest : public ::testing::TestWithParam<States>
{
protected:
  Solution s;
};

TEST_P(WordBreakTest, HandlesWordBreak) {
  const auto& as = GetParam();
  auto result = s.wordBreak(as.s, as.wordDict);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, WordBreakTest,
  ::testing::Values(
    States{"leetcode", {"leet", "code"}, true},
    States{"applepenapple", {"apple", "pen"}, true},
    States{"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
    States{"", {"a", "b"}, true},                      // empty string
    States{"aaaaaaa", {"aaaa", "aaa"}, true},         // multiple overlapping
    States{"aaaaaaa", {"aa", "aaa"}, true},
    States{"abcd", {"a", "abc", "b", "cd"}, true},
    States{"abcd", {"ab", "c"}, false}
  )
);
