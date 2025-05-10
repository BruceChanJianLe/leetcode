#include "78subsets.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> input;
  std::vector<std::vector<int>> result;
};

class SubsetsTest : public ::testing::TestWithParam<States> {
  protected:
    RBTSolution rbts;
    IRBTSolution irbts;
    BMSolution bms;
    ISolution is;

    static void sortSubsets(std::vector<std::vector<int>>& subsets) {
      for (auto& v : subsets) sort(v.begin(), v.end());
      sort(subsets.begin(), subsets.end());
    }
};

TEST_P(SubsetsTest, ISubsetsCase) {
  auto as = GetParam();
  auto result = is.subsets(as.input);
  sortSubsets(result);
  sortSubsets(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsTest, BMSubsetsCase) {
  auto as = GetParam();
  auto result = bms.subsets(as.input);
  sortSubsets(result);
  sortSubsets(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsTest, RBTSubsetsCase) {
  auto as = GetParam();
  auto result = rbts.subsets(as.input);
  sortSubsets(result);
  sortSubsets(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsTest, IRBTSubsetsCase) {
  auto as = GetParam();
  auto result = irbts.subsets(as.input);
  sortSubsets(result);
  sortSubsets(as.result);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SubsetsTest,
  ::testing::Values(
    States{
      {1, 2, 3},
      {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
    },
    States{
      {0},
      {{}, {0} }
    },
    States{
      {},
      {{}}
    }
  )
);
