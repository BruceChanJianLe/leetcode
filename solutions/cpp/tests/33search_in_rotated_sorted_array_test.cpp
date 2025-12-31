#include "33search_in_rotated_sorted_array.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  int target;
  int result;
};

struct SearchInRotatedSortedArrayTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(SearchInRotatedSortedArrayTest, FirstSearchInRotatedArrayTest)
{
  auto as = GetParam();
  auto result = s.search(as.nums, as.target);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SearchInRotatedSortedArrayTest,
    testing::Values(
      States{{1}, 0, -1},
      States{{4,5,6,7,0,1,2}, 0, 4},
      States{{5,1,3}, 3, 2},
      States{{3,1}, 1, 1},
      States{{4,5,6,7,0,1,2}, 3, -1}
    ));
