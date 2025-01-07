#include "125valid_palindrome.hpp"

#include "gtest/gtest.h"

// 125. Valid Palindrome Test

struct States
{
  std::string input_string;
  bool result;
};

struct ValidPalindromeTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(ValidPalindromeTest, ValidPalindromeCase)
{
  auto as = GetParam();
  auto result = s.isPalindrome(as.input_string);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, ValidPalindromeTest,
    testing::Values(
      States{{"A man, a plan, a canal: Panama"}, true},
      States{{"race a car"}, false},
      States{{" "}, true},
      States{{"."}, true},
      States{{".,"}, true},
      States{{"0P"}, false},
      States{{".,"}, true}
    ));
