#include "36valid_sudoku.hpp"

#include "gtest/gtest.h"

// 36. Valid Sudoku Test

struct States {
  std::vector<std::vector<char>> board;
  bool result;
};

struct ValidSudokuTest : public ::testing::Test,
                         ::testing::WithParamInterface<States> {
  Solution s;
};

TEST_P(ValidSudokuTest, ValidSudokuCases) {
  auto as = GetParam();
  auto result = s.isValidSudoku(as.board);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(
    Default, ValidSudokuTest,
    testing::Values(States{{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
                           true},
                    States{{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}},
                           false}
     ));
