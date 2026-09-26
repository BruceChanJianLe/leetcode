#include "448find_all_numbers_disappeared_in_an_array.hpp"

#include "gtest/gtest.h"

// 448 Find All Numbers Disappeared in an Array

struct States {
  std::vector<int> nums;
  std::vector<int> result;
};

struct FindAllNumbersDisappearedInAnArrayTest : public ::testing::Test, ::testing::WithParamInterface<States> {
  Solution s;
  NoExtraMemorySolution nes;
  FristTrySolution fts;
};

TEST_P(FindAllNumbersDisappearedInAnArrayTest, Solution) {
  auto as = GetParam();
  auto result = s.findDisappearedNumbers(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(FindAllNumbersDisappearedInAnArrayTest, NoExtraMemorySolution) {
  auto as = GetParam();
  auto result = nes.findDisappearedNumbers(as.nums);
  EXPECT_EQ(result, as.result);
}

TEST_P(FindAllNumbersDisappearedInAnArrayTest, FristTrySolution) {
  auto as = GetParam();
  auto result = fts.findDisappearedNumbers(as.nums);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, FindAllNumbersDisappearedInAnArrayTest,
    testing::Values(
      // TODO: fill in cases as States{ nums, expected }
      States{}
    ));
