#include "84largest_rectangle_in_histogram.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> heights;
  int result;
};

struct LargestRectangleInHistogramTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
};

TEST_P(LargestRectangleInHistogramTest, LargestRectangleInHistograCase)
{
  auto as = GetParam();
  auto result = s.largestRectangleArea(as.heights);
  EXPECT_EQ(result, as.result);
}

// TEST_P(LargestRectangleInHistogramTest, FisrtLargestRectangleInHistograCase)
// {
//   auto as = GetParam();
//   auto result = fs.largestRectangleArea(as.heights);
//   EXPECT_EQ(result, as.result);
// }

INSTANTIATE_TEST_SUITE_P(Default, LargestRectangleInHistogramTest,
    testing::Values(
      States{{1}, 1},
      States{{}, 0},
      States{{1,1}, 2},
      States{{0,9}, 9},
      States{{2,0,2}, 2},
      States{{4, 2}, 4},
      States{{4,2,0,3,2,5}, 6},
      States{{2,1,5,6,2,3}, 10},
      States{{2,4}, 4}
    ));
