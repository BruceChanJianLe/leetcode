#include "51n_queens.hpp"

#include "gtest/gtest.h"

struct States
{
  int n;
  std::vector<std::vector<std::string>> result;
};

class NQueensTest : public ::testing::TestWithParam<States>
{
protected:
  HDTSolution hdts;
  VDTSolution vdts;
};

bool compareBoardsUnordered(std::vector<std::vector<std::string>> a,
    std::vector<std::vector<std::string>> b) {
  auto normalize = [](const std::vector<std::vector<std::string>>& boards) {
    std::set<std::vector<std::string>> s(boards.begin(), boards.end());
    return s;
  };
  return normalize(a) == normalize(b);
}

TEST_P(NQueensTest, VectorDecisionTreeNQueensCase)
{
  auto as = GetParam();
  auto result = vdts.solveNQueens(as.n);
  EXPECT_TRUE(compareBoardsUnordered(result, as.result));
}

TEST_P(NQueensTest, HashDecisionTreeNQueensCase)
{
  auto as = GetParam();
  auto result = hdts.solveNQueens(as.n);
  EXPECT_TRUE(compareBoardsUnordered(result, as.result));
}

INSTANTIATE_TEST_SUITE_P(Default, NQueensTest,
  ::testing::Values(
    States{1, {{"Q"}}},
    States{4, {
    {".Q..", "...Q", "Q...", "..Q."},
    {"..Q.", "Q...", "...Q", ".Q.."}
    }}
  )
);
