#include "509fibonacci_number.hpp"

#include "gtest/gtest.h"

struct States {
  int n;
  int result;
};

class FibonacciTest : public ::testing::TestWithParam<States>
{
protected:
  NaiveSolution ns;
  DPTopDownSolution dp_tp_s;
  DPBottomUpSolution dp_bu_s;
  DPBottomUpOptimizedSolution dp_buo_s;
};

TEST_P(FibonacciTest, NaiveFibonacciTestCases) {
  auto as = GetParam();
  auto result = ns.fib(as.n);
  EXPECT_EQ(result, as.result);
}

TEST_P(FibonacciTest, DPTopDownFibonacciTestCases) {
  auto as = GetParam();
  auto result = dp_tp_s.fib(as.n);
  EXPECT_EQ(result, as.result);
}

TEST_P(FibonacciTest, DPBottomUpFibonacciTestCases) {
  auto as = GetParam();
  auto result = dp_bu_s.fib(as.n);
  EXPECT_EQ(result, as.result);
}

TEST_P(FibonacciTest, DPBottomUpOptimizedFibonacciTestCases) {
  auto as = GetParam();
  auto result = dp_buo_s.fib(as.n);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, FibonacciTest,
  ::testing::Values(
    States{0, 0},
    States{1, 1},
    States{2, 1},
    States{3, 2},
    States{4, 3},
    States{5, 5},
    States{10, 55},
    States{20, 6765},
    States{30, 832040}
  )
);
