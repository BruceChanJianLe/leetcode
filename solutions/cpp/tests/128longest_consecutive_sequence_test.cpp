#include "128longest_consecutive_sequence.hpp"

#include "gtest/gtest.h"

// 128. Longest Consecutive Sequence Test

struct States
{
  std::vector<int> nums;
  int result;
};

struct LongestConsecutiveSequenceTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(LongestConsecutiveSequenceTest, LongestConsecutiveSequenceCases)
{
  auto as = GetParam();
  auto result = s.longestConsecutive(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, LongestConsecutiveSequenceTest,
    testing::Values(
      States{{100,4,200,1,3,2}, 4},
      States{{0,3,7,2,5,8,4,6,0,1}, 9}
    ));
