#include "74search_a_2d_matrix.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::vector<int>> matrix;
  int target;
  bool result;
};

struct SearchA2DMatrixTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  SecondSolution ss;
};

TEST_P(SearchA2DMatrixTest, SearchA2DMatrixCase)
{
  auto as = GetParam();
  auto result = s.searchMatrix(as.matrix, as.target);
  EXPECT_EQ(result, as.result);
}

TEST_P(SearchA2DMatrixTest, SecondSearchA2DMatrixCase)
{
  auto as = GetParam();
  auto result = ss.searchMatrix(as.matrix, as.target);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SearchA2DMatrixTest,
    testing::Values(
      States{{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 3, true},
      States{{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 13, false},
      States{{{1}}, 2, false}
    ));
