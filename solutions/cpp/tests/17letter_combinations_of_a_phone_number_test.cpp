#include "17letter_combinations_of_a_phone_number.hpp"

#include "gtest/gtest.h"

struct States {
  std::string digits;
  std::vector<std::string> result;
};

class LetterCombinationsOfAPhoneNumberTest : public ::testing::TestWithParam<States> {
protected:
  DTSolution dts;
  DT2Solution dt2s;
  DTSpanSolution dtss;
};

bool compareUnordered(const std::vector<std::string>& a, const std::vector<std::string>& b) {
  std::multiset<std::string> setA(a.begin(), a.end());
  std::multiset<std::string> setB(b.begin(), b.end());
  return setA == setB;
}

TEST_P(LetterCombinationsOfAPhoneNumberTest, DTSpanLetterCombinationsOfAPhoneNumberTest) {
  auto as = GetParam();
  auto result = dtss.letterCombinations(as.digits);
  EXPECT_TRUE(compareUnordered(result, as.result));
}

TEST_P(LetterCombinationsOfAPhoneNumberTest, DT2LetterCombinationsOfAPhoneNumberTest) {
  auto as = GetParam();
  auto result = dt2s.letterCombinations(as.digits);
  EXPECT_TRUE(compareUnordered(result, as.result));
}

TEST_P(LetterCombinationsOfAPhoneNumberTest, DTLetterCombinationsOfAPhoneNumberTest) {
  auto as = GetParam();
  auto result = dts.letterCombinations(as.digits);
  EXPECT_TRUE(compareUnordered(result, as.result));
}

INSTANTIATE_TEST_SUITE_P(Default, LetterCombinationsOfAPhoneNumberTest,
  ::testing::Values(
    States{"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"}},
    States{"7", {"p", "q", "r", "s"}},
    States{"2", {"a", "b", "c"}},
    States{"9", {"w", "x", "y", "z"}}
  )
);
