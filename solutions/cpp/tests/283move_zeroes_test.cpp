#include "283move_zeroes.hpp"

#include "gtest/gtest.h"

// 283 Move Zeroes

struct States {
  std::vector<int> nums;
  std::vector<int> result;;
};

struct MoveZeroesTest : public ::testing::Test, ::testing::WithParamInterface<States> {
  FirstSolution fs;
  Solution s;
};

TEST_P(MoveZeroesTest, FirstSolution) {
  auto as = GetParam();
  fs.moveZeroes(as.nums);
  EXPECT_EQ(as.nums, as.result);
}

TEST_P(MoveZeroesTest, Solution) {
  auto as = GetParam();
  s.moveZeroes(as.nums);
  EXPECT_EQ(as.nums, as.result);
}

constexpr int kMin = std::numeric_limits<int>::min();
constexpr int kMax = std::numeric_limits<int>::max();

INSTANTIATE_TEST_SUITE_P(Default, MoveZeroesTest,
    testing::Values(
      // LeetCode examples
      States{ {0, 1, 0, 3, 12}, {1, 3, 12, 0, 0} },
      States{ {0}, {0} },

      // Single non-zero
      States{ {1}, {1} },

      // All zeros / no zeros
      States{ {0, 0, 0}, {0, 0, 0} },
      States{ {1, 2, 3}, {1, 2, 3} },

      // Zeros already at the end (no work needed)
      States{ {1, 2, 0, 0}, {1, 2, 0, 0} },

      // Zeros at the start
      States{ {0, 0, 1}, {1, 0, 0} },
      States{ {0, 0, 0, 5, 6}, {5, 6, 0, 0, 0} },

      // Alternating zeros
      States{ {1, 0, 2, 0, 3}, {1, 2, 3, 0, 0} },

      // Relative order preserved, including duplicates and negatives
      States{ {0, -1, 0, -1, 2}, {-1, -1, 2, 0, 0} },
      States{ {4, 0, 2, 0, 4, 2}, {4, 2, 4, 2, 0, 0} },

      // Constraint extremes
      States{ {kMin, 0, kMax}, {kMin, kMax, 0} }
      ));
