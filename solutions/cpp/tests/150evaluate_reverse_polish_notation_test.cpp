#include "150evaluate_reverse_polish_notation.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::string> tokens;
  int result;
};

struct EvaluateReversePolishNotationTest
  : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(EvaluateReversePolishNotationTest, EvaluateReversePolishNotationCase)
{
  auto as = GetParam();
  auto result = s.evalRPN(as.tokens);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, EvaluateReversePolishNotationTest,
    testing::Values(
      States{{"2","1","+","3","*"}, 9},
      States{{"4","13","5","/","+"}, 6},
      States{{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}, 22}
    ));
