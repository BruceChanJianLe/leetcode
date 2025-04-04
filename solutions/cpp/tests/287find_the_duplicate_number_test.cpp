#include "287find_the_duplicate_number.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  int result;
};

struct FindTheDuplicateNumberTest : public ::testing::TestWithParam<States>
{
  Solution s;
  StandardSolution ss;
  PMRSolution ps;
};

TEST_P(FindTheDuplicateNumberTest, FindTheDuplicateNumberCase)
{
  auto as = GetParam();
  auto result = s.findDuplicate(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(FindTheDuplicateNumberTest, StandardFindTheDuplicateNumberCase)
{
  auto as = GetParam();
  auto result = ss.findDuplicate(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(FindTheDuplicateNumberTest, PMRFindTheDuplicateNumberCase)
{
  auto as = GetParam();
  auto result = ps.findDuplicate(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, FindTheDuplicateNumberTest,
    ::testing::Values(
      States{{1,3,4,2,2},2},
      States{{3,1,3,4,2},3},
      States{{3,3,3,3,3},3}
    ));
