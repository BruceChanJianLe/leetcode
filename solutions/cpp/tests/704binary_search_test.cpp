#include "704binary_search.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> haystack;
  int needle;
  int result;
};

struct BinarySearchTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
};

TEST_P(BinarySearchTest, BinarySearchCase)
{
  auto as = GetParam();
  auto result = s.search(as.haystack, as.needle);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, BinarySearchTest,
    testing::Values(
      States{{-1,0,3,5,9,12}, 9, 4},
      States{{-1,0,3,5,9,12}, 2, -1}
    ));
