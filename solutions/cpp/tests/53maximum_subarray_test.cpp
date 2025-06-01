#include "53maximum_subarray.hpp"

#include "gtest/gtest.h"

struct TestCase {
  std::vector<int> nums;
  int result;
};

class MaximumSubarrayTest : public ::testing::TestWithParam<TestCase> {
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
    TestCase{{-2,1,-3,4,-1,2,1,-5,4}, 6},    // [4,-1,2,1]
    TestCase{{1}, 1},                        // single element
    TestCase{{5,4,-1,7,8}, 23},              // full array
    TestCase{{-1,-2,-3,-4}, -1},             // all negative
    TestCase{{1,2,3,4,5}, 15},               // all positive
    TestCase{{-2,-3,4,-1,-2,1,5,-3}, 7},     // [4,-1,-2,1,5]
    TestCase{{8,-19,5,-4,20}, 21}            // [5,-4,20]
  )
);
