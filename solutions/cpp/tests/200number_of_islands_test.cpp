#include "200number_of_islands.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<std::vector<char>> grid;
  int result;
};

struct NumberOfIslandsTest : public ::testing::TestWithParam<States> {
  FirstSolution fs;
};

TEST_P(NumberOfIslandsTest, HandlesCases) {
  auto as = GetParam();
  auto result = fs.numIslands(as.grid);

  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(
  NumberOfIslandsParameterizedTests,
  NumberOfIslandsTest,
  ::testing::Values(
    States{
      {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
      },
      1
    }, // example 1

    States{
      {
          {'1','1','0','0','0'},
          {'1','1','0','0','0'},
          {'0','0','1','0','0'},
          {'0','0','0','1','1'}
      },
      3
    }, // example 2

    States{
      {
          {'0','0','0'},
          {'0','0','0'},
          {'0','0','0'}
      },
      0
    }, // all water

    States{
      {
          {'1','1','1'},
          {'1','1','1'},
          {'1','1','1'}
      },
      1
    }, // all land

    States{
      {
          {'1','0','1','0'},
          {'0','1','0','1'},
          {'1','0','1','0'}
      },
      6
    }, // isolated islands

    States{
      {
          {'1'}
      },
      1
    }, // single land cell

    States{
      {
          {'0'}
      },
      0
    } // single water cell
  )
);
