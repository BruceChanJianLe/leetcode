#include "152maximum_product_subarray.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  int result;
};

class MaximumProductSubarrayTest : public ::testing::TestWithParam<States>
{
protected:
 KSSolution kss;
 GKSSolution gkss;
};

TEST_P(MaximumProductSubarrayTest, KSMaximumProductSubarrayCase) {
  const auto& as = GetParam();
  auto result = kss.maxProduct(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(MaximumProductSubarrayTest, GKSMaximumProductSubarrayCase) {
  const auto& as = GetParam();
  auto result = gkss.maxProduct(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, MaximumProductSubarrayTest,
  ::testing::Values(
    States{{2, 3, -2, 4}, 6},            // [2,3]
    States{{-2, 0, -1}, 0},              // 0 is max
    States{{-2}, -2},                    // single negative
    States{{0, 2}, 2},                   // max is 2
    States{{-2, 3, -4}, 24},             // [-2,3,-4]
    States{{-1, -3, -10, 0, 60}, 60},    // [60]
    States{{6, -3, -10, 0, 2}, 180},     // [6, -3, -10]
    States{{2, -5, -2, -4, 3}, 24}       // [2, -5, -2, -4, 3]
  )
);
