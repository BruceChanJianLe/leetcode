#include "22generate_parentheses.hpp"

#include "gtest/gtest.h"

struct States {
  int n;
  std::vector<std::string> result;
};

struct GenerateParenthesesTest : public testing::Test, testing::WithParamInterface<States> {
  Solution s;
  AnotherSolution ss;
};

TEST_P(GenerateParenthesesTest, GenerateParenthesesCase) {
  auto as = GetParam();
  auto result = s.generateParenthesis(as.n);
  EXPECT_EQ(result, as.result);
}

TEST_P(GenerateParenthesesTest, SpanGenerateParenthesesCase) {
  auto as = GetParam();
  auto result = ss.generateParenthesis(as.n);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, GenerateParenthesesTest,
    testing::Values(
      States{1, {"()"}},
      States{3, {"((()))","(()())","(())()","()(())","()()()"}}
    ));
