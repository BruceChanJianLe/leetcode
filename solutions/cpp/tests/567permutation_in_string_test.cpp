#include "567permutation_in_string.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string s1;
  std::string s2;
  bool result;
};

struct PermutationInStringTest : public testing::TestWithParam<States>
{
  Solution s;
  FirstSolution fs;
  RawPointerSolution rps;
};

TEST_P(PermutationInStringTest, PermutationInStringCase)
{
  auto as = GetParam();
  auto result = s.checkInclusion(as.s1, as.s2);
  EXPECT_EQ(result, as.result);
}

TEST_P(PermutationInStringTest, FisrtPermutationInStringCase)
{
  auto as = GetParam();
  auto result = fs.checkInclusion(as.s1, as.s2);
  EXPECT_EQ(result, as.result);
}

TEST_P(PermutationInStringTest, RawPointerPermutationInStringCase)
{
  auto as = GetParam();
  auto result = rps.checkInclusion(as.s1, as.s2);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, PermutationInStringTest,
    testing::Values(
      States{"ab", "eidbaooo", true},
      States{"ab", "eidboaoo", false},
      States{"ab", "a", false}
    ));
