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
  SecondSolution ss;
  OtherSolution os;
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

TEST_P(TopKfrequentElementsTest, TopKfrequentElementsSecondSolutionCases)
{
  auto as = GetParam();
  auto result = ss.topKFrequent(as.nums, as.k);
  EXPECT_EQ(result, as.result);
}

TEST_P(TopKfrequentElementsTest, TopKfrequentElementsOtherSolutionCases)
{
  auto as = GetParam();
  auto result = os.topKFrequent(as.nums, as.k);
  std::sort(result.begin(), result.end());
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, TopKfrequentElementsTest,
    testing::Values(
      States{{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
      States{{1}, 1, {1}}
    ));
