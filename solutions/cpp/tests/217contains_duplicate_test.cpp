#include "217contains_duplicate.hpp"

#include "gtest/gtest.h"

// 217 Contains Duplicate

struct States
{
  std::vector<int> nums;
  bool result;
};

struct ContainsDuplicateTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(ContainsDuplicateTest, ContainDuplicateCases)
{
  auto as = GetParam();
  auto result = s.containsDuplicate(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, ContainsDuplicateTest,
    testing::Values(
      States{{1,2,3,1}, true},
      States{{1,2,3,4}, false},
      States{{1,1,1,3,3,4,3,2,4,2}, true}
    ));
