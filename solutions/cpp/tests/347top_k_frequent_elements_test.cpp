#include "347top_k_frequent_elements.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  int k;
  std::vector<int> result;
};

struct TopKfrequentElementsTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  FirstSolution fs;
};

TEST_P(TopKfrequentElementsTest, TopKfrequentElementsCases)
{
  auto as = GetParam();
  auto result = s.topKFrequent(as.nums, as.k);
  EXPECT_EQ(result, as.result);
}

TEST_P(TopKfrequentElementsTest, TopKfrequentElementsFirstSolutionCases)
{
  auto as = GetParam();
  auto result = fs.topKFrequent(as.nums, as.k);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, TopKfrequentElementsTest,
    testing::Values(
      States{{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
      States{{1}, 1, {1}}
    ));
