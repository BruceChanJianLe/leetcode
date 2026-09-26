#include "169majority_element.hpp"

#include "gtest/gtest.h"

// 169 Majority Element

struct States {
  std::vector<int> nums;
  int result;
};

struct MajorityElementTest : public ::testing::Test, ::testing::WithParamInterface<States> {
  HashSolution hs;
  FirstSolution fs;
  BoyerMooreolution bms;
};

TEST_P(MajorityElementTest, FirstSolution) {
  auto as = GetParam();
  auto result = fs.majorityElement(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MajorityElementTest, HashSolution) {
  auto as = GetParam();
  auto result = hs.majorityElement(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MajorityElementTest, BoyerMooreolution) {
  auto as = GetParam();
  auto result = bms.majorityElement(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MajorityElementTest,
    testing::Values(
      // LeetCode examples
      States{ {3, 2, 3}, 3 },
      States{ {2, 2, 1, 1, 1, 2, 2}, 2 },

      // Smallest inputs
      States{ {1}, 1 },
      States{ {5, 5}, 5 },

      // All elements identical
      States{ {4, 4, 4, 4}, 4 },

      // Majority clustered at the start
      States{ {7, 7, 7, 7, 1, 2, 3}, 7 },

      // Majority clustered at the end (candidate switches late)
      States{ {1, 2, 3, 3, 3}, 3 },
      States{ {6, 5, 5}, 5 },

      // Majority interleaved with other values
      States{ {1, 2, 1, 2, 1}, 1 },
      States{ {1, 7, 2, 7, 3, 7, 7}, 7 },

      // Barely a majority (n/2 + 1 occurrences)
      States{ {8, 9, 8, 9, 8, 9, 8}, 8 },

      // Negative values and constraint extremes
      States{ {-1, -1, 2}, -1 },
      States{ {-1000000000, 1000000000, -1000000000}, -1000000000 }
      ));
