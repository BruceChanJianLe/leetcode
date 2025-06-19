#include "53maximum_subarray.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int result;
};

class MaximumSubarrayTest : public ::testing::TestWithParam<States> {
protected:
  Solution s;
  FirstSolution fs;
};

TEST_P(MaximumSubarrayTest, FirstMaximumSubarrayCase) {
  auto as = GetParam();
  auto result = fs.maxSubArray(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MaximumSubarrayTest, MaximumSubarrayCase) {
  auto as = GetParam();
  auto result = s.maxSubArray(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MaximumSubarrayTest,
  ::testing::Values(
    States{{-2,1,-3,4,-1,2,1,-5,4}, 6},    // [4,-1,2,1]
    States{{1}, 1},                        // single element
    States{{5,4,-1,7,8}, 23},              // full array
    States{{-1,-2,-3,-4}, -1},             // all negative
    States{{1,2,3,4,5}, 15},               // all positive
    States{{-2,-3,4,-1,-2,1,5,-3}, 7},     // [4,-1,-2,1,5]
    States{{8,-19,5,-4,20}, 21}            // [5,-4,20]
  )
);
