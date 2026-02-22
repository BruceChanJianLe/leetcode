#include "52n_queens_ii.hpp"

#include <gtest/gtest.h>

struct States {
    int n;
    int result;
};

class NQueensII : public ::testing::TestWithParam<States> {
protected:
  Solution s;
};

TEST_P(NQueensII, Solution) {
    const auto& as = GetParam();
    auto result = s.totalNQueens(as.n);
    EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, NQueensII,
  ::testing::Values(
    States{1, 1},
    States{2, 0},
    States{3, 0},
    States{4, 2},
    States{5, 10},
    States{6, 4},
    States{7, 40},
    States{8, 92},
    States{9, 352}
  )
);
