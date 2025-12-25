#include "219contains_duplicate_ii.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int k;
  bool expected;
};

struct ContainsDuplicateTest : public ::testing::TestWithParam<States> {
  Solution s;
};

TEST_P(ContainsDuplicateTest, ContainsDuplicateSolutionTests) {
   auto as = GetParam();
   auto expected = s.containsNearbyDuplicate(as.nums, as.k);
   EXPECT_EQ(expected, as.expected);
}

INSTANTIATE_TEST_SUITE_P(Default, ContainsDuplicateTest,
    ::testing::Values(
        States{{1,2,3,1}, 3, true},        // example 1
        States{{1,0,1,1}, 1, true},        // example 2
        States{{1,2,3,1,2,3}, 2, false},   // example 3
        States{{1,2,3,4,5}, 0, false},     // k = 0
        States{{1,1}, 1, true},            // adjacent duplicate
        States{{1,2,1}, 1, false},         // distance too large
        States{{-1,-1}, 1, true}           // negatives
    )
);
