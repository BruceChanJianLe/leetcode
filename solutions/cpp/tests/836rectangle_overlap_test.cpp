#include "836rectangle_overlap.hpp"

#include "gtest/gtest.h"
#include <vector>

// 836 Rectangle Overlap

struct States {
  std::vector<int> rec1;
  std::vector<int> rec2;
  bool result;
};

struct RectangleOverlapTest : public ::testing::Test, ::testing::WithParamInterface<States> {
  Solution s;
};

TEST_P(RectangleOverlapTest, RectangleOverlapCases) {
  auto as = GetParam();
  auto result = s.isRectangleOverlap(as.rec1, as.rec2);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, RectangleOverlapTest,
    testing::Values(
      // Example 1: Overlapping rectangles
      States{{0, 0, 2, 2}, {1, 1, 3, 3}, true},

      // Example 2: Touching at the edges (No overlap)
      States{{0, 0, 1, 1}, {1, 0, 2, 1}, false},

      // Example 3: Completely separate
      States{{0, 0, 1, 1}, {2, 2, 3, 3}, false},

      // Additional Case: One rectangle entirely inside another
      States{{0, 0, 4, 4}, {1, 1, 2, 2}, true},

      // Additional Case: Touching only at a single corner (No overlap)
      States{{0, 0, 1, 1}, {1, 1, 2, 2}, false}
  ));
