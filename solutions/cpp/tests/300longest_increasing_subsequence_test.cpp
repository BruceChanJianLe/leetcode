#include "300longest_increasing_subsequence.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int result;
};

class LongestIncreasingSubsequenceTest : public ::testing::TestWithParam<States> {
protected:
  DPSolution dps;
  STDSolution stds;
  DPGreedySolution dpgs;
};

TEST_P(LongestIncreasingSubsequenceTest, DPLongestIncreasingSubsequenceCase) {
  const auto& as = GetParam();
  auto result = dps.lengthOfLIS(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestIncreasingSubsequenceTest, STDLongestIncreasingSubsequenceCase) {
  const auto& as = GetParam();
  auto result = stds.lengthOfLIS(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(LongestIncreasingSubsequenceTest, DPGreedyLongestIncreasingSubsequenceCase) {
  const auto& as = GetParam();
  auto result = dpgs.lengthOfLIS(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(
    LIS_Tests,
    LongestIncreasingSubsequenceTest,
    ::testing::Values(
      States{{10,9,2,5,3,7,101,18}, 4},
      States{{0,1,0,3,2,3}, 4},
      States{{7,7,7,7,7,7,7}, 1},
      States{{1,3,6,7,9,4,10,5,6}, 6}, // more complex
      States{{}, 0}, // empty input
      States{{1}, 1}, // single element
      States{{4,10,4,3,8,9}, 3}
      )
    );
