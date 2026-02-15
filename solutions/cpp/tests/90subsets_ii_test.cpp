#include "90subsets_ii.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> nums;
  std::vector<std::vector<int>> result;
};

class SubsetsIITest : public ::testing::TestWithParam<States> {
protected:
  MSSolution ss;
  MUSSolution uss;
  MCSolution mcs;
  RSolution rs;
  RSpanSolution r_span_s;

  static void normalize(std::vector<std::vector<int>>& vec) {
    for (auto& v : vec) std::sort(v.begin(), v.end());
    std::sort(vec.begin(), vec.end());
  }
};

TEST_P(SubsetsIITest, DecisionTreeRecursiveSubsetsIICase) {
  auto as = GetParam();
  auto result = rs.subsetsWithDup(as.nums);
  normalize(result);
  normalize(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsIITest, MaskCheckSubsetsIICase) {
  auto as = GetParam();
  auto result = mcs.subsetsWithDup(as.nums);
  normalize(result);
  normalize(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsIITest, MaskUnorderedSetSubsetsIICase) {
  auto as = GetParam();
  auto result = uss.subsetsWithDup(as.nums);
  normalize(result);
  normalize(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsIITest, MaskSetSubsetsIICase) {
  auto as = GetParam();
  auto result = ss.subsetsWithDup(as.nums);
  normalize(result);
  normalize(as.result);
  EXPECT_EQ(result, as.result);
}

TEST_P(SubsetsIITest, RecursiveSpanSubsetsIICase) {
  auto as = GetParam();
  auto result = r_span_s.subsetsWithDup(as.nums);
  normalize(result);
  normalize(as.result);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SubsetsIITest,
  ::testing::Values(
    States{{1,2,2}, {
    {}, {1}, {2}, {1,2}, {2,2}, {1,2,2}
    }},
    States{
      {4,4,4,1,4},
      {{},{1},{1,4},{1,4,4},{1,4,4,4},{1,4,4,4,4},{4},{4,4},{4,4,4},{4,4,4,4}}
    },
    States{{0}, {
    {}, {0}
    }}
  )
);
