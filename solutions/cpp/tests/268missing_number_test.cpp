#include "268missing_number.hpp"

#include "gtest/gtest.h"

// 268 Missing Number

struct States {
  std::vector<int> nums;
  int result;
};

struct MissingNumberTest : public ::testing::Test, ::testing::WithParamInterface<States> {
  Solution s;
  ModernSolution ms;
  MoreModernSolution mms;
  SumSolution ss;
  HashSolution hs;
};

TEST_P(MissingNumberTest, Solution) {
  auto as = GetParam();
  auto result = s.missingNumber(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MissingNumberTest, ModernSolution) {
  auto as = GetParam();
  auto result = ms.missingNumber(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MissingNumberTest, MoreModernSolution) {
  auto as = GetParam();
  auto result = mms.missingNumber(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MissingNumberTest, SumSolution) {
  auto as = GetParam();
  auto result = ss.missingNumber(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MissingNumberTest, HashSolution) {
  auto as = GetParam();
  auto result = hs.missingNumber(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MissingNumberTest,
    testing::Values(
      // LeetCode examples
      States{ {3, 0, 1}, 2 },
      States{ {0, 1}, 2 },
      States{ {9, 6, 4, 2, 3, 5, 7, 0, 1}, 8 },

      // Smallest inputs
      States{ {0}, 1 },
      States{ {1}, 0 },

      // Missing zero
      States{ {1, 2, 3}, 0 },

      // Missing n (all of 0..n-1 present)
      States{ {0, 1, 2, 3}, 4 },
      States{ {5, 4, 3, 2, 1, 0}, 6 },

      // Missing in the middle, unsorted
      States{ {2, 0}, 1 },
      States{ {4, 3, 1, 0}, 2 }
    ));
