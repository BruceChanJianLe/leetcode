#include "20valid_parentheses.hpp"

#include "gtest/gtest.h"
#include <string>

// 20. Valid Parentheses Test

struct States
{
  std::string s;
  bool result;
};

struct ValidParenthesesTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
};

TEST_P(ValidParenthesesTest, ValidParenthesesCases)
{
  auto as = GetParam();
  auto result = s.isValid(as.s);
  EXPECT_EQ(result, as.result);
}

TEST_P(ValidParenthesesTest, FirstValidParenthesesCases)
{
  auto as = GetParam();
  auto result = fs.isValid(as.s);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, ValidParenthesesTest,
    testing::Values(
      States{"()", true},
      States{"()[]{}", true},
      States{"(]", false},
      States{"{[]}", true},
      States{"([)]", false}
    ));
