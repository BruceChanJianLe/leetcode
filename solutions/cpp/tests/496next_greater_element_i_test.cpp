#include "496next_greater_element_i.hpp"

#include "gtest/gtest.h"

// 496. Next Greater Elelment I

struct States {
  std::vector<int> nums1;
  std::vector<int> nums2;
  std::vector<int> result;
};

struct NextGreaterElementITest : public ::testing::Test,
                         ::testing::WithParamInterface<States> {
  Solution s;
};

TEST_P(NextGreaterElementITest, NextGreaterElementICase) {
  auto as = GetParam();
  auto result = s.nextGreaterElement(as.nums1, as.nums2);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(
    Default, NextGreaterElementITest,
    testing::Values(
      States{{4,1,2}, {1,3,4,2}, {-1,3,-1}},
      States{{2,4},{1,2,3,4},{3,-1}},
      States{{1,3,5,2,4},{6,5,4,3,2,1,7},{7,7,7,7,7}}
   ));
