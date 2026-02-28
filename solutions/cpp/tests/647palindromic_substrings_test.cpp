#include "647palindromic_substrings.hpp"

#include "gtest/gtest.h"

struct States {
  std::string s;
  int result;
};

class PalindromicSubstringsTest : public ::testing::TestWithParam<States>
{
protected:
  DTSolution dts;
  DPSolution dps;
  TwoPointerSolution tps;
};

TEST_P(PalindromicSubstringsTest, DTPalindromicSubstringsCase) {
  const auto& param = GetParam();
  auto result = dts.countSubstrings(param.s);
  EXPECT_EQ(result, param.result);
}

TEST_P(PalindromicSubstringsTest, PDPalindromicSubstringsCase) {
  const auto& param = GetParam();
  auto result = dps.countSubstrings(param.s);
  EXPECT_EQ(result, param.result);
}

TEST_P(PalindromicSubstringsTest, TwoPointerPalindromicSubstringsCase) {
  const auto& as = GetParam();
  auto result = tps.countSubstrings(as.s);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, PalindromicSubstringsTest,
  ::testing::Values(
    States{"abc", 3},
    States{"aaa", 6},
    States{"a", 1},
    States{"abccba", 9},      // a,b,c,c,b,a + cc + bcb + abccba
    States{"racecar", 10},    // 7 single chars + aceca + cec + racecar
    States{"abcd", 4},        // each char only
    States{"abba", 6}         // a, b, b, a, bb, abba
  )
);
