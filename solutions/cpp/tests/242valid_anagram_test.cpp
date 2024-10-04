#include "242valid_anagram.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string str1;
  std::string str2;
  bool result;
};

struct ValidAnagramTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(ValidAnagramTest, ValidAnagramCases)
{
  auto as = GetParam();
  auto result = s.isAnagram(as.str1, as.str2);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, ValidAnagramTest,
    testing::Values(
      States{{"anagram"}, {"nagaram"}, true},
      States{{"cat"}, {"car"}, false}
    ));
