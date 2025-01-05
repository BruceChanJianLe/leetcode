#include "238product_of_array_except_self.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  std::vector<int> result;
};

struct ProductOfArrayExceptSelfTest : public testing::Test, testing::WithParamInterface<States>
{
  FirstSolution fs;
  SecondSolution ss;
  ThirdSolution ts;
  FourthSolution s;
};

TEST_P(ProductOfArrayExceptSelfTest, FirstProductOfArrayExceptSelfCases)
{
  auto as = GetParam();
  auto result = fs.productExceptSelf(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(ProductOfArrayExceptSelfTest, SecondProductOfArrayExceptSelfCases)
{
  auto as = GetParam();
  auto result = ss.productExceptSelf(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(ProductOfArrayExceptSelfTest, ThirdProductOfArrayExceptSelfCases)
{
  auto as = GetParam();
  auto result = ts.productExceptSelf(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(ProductOfArrayExceptSelfTest, FourthProductOfArrayExceptSelfCases)
{
  auto as = GetParam();
  auto result = s.productExceptSelf(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, ProductOfArrayExceptSelfTest,
    testing::Values(
      States{{1,2,3,4}, {24,12,8,6}},
      States{{-1,1,0,-3,3}, {0,0,9,0,0}}
    ));
