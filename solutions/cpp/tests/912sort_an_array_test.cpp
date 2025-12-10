#include "912sort_an_array.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> nums;
  std::vector<int> result;
};

struct SortArrayTest : public ::testing::TestWithParam<States>{
  RecursiveQuickSortLastSolution rqsls;
  RecursiveQuickSortFirstSolution rqsfs;
  RecursiveQuickSortMidSolution rqsms;
  RecursiveMergeSortSolution rmss;
  ItrBubbleSortSolution ibss;
};

TEST_P(SortArrayTest, RecursiveQuickSortLastSolutionTests) {
    auto as = GetParam();
    std::vector<int> temp = as.nums;
    EXPECT_EQ(rqsls.sortArray(temp), as.result);
}

TEST_P(SortArrayTest, RecursiveQuickSortFirstSolutionTests) {
    auto as = GetParam();
    std::vector<int> temp = as.nums;
    EXPECT_EQ(rqsfs.sortArray(temp), as.result);
}

TEST_P(SortArrayTest, RecursiveQuickSortMidSolutionTests) {
    auto as = GetParam();
    std::vector<int> temp = as.nums;
    EXPECT_EQ(rqsms.sortArray(temp), as.result);
}

TEST_P(SortArrayTest, RecursiveMergeSortSolutionTests) {
    auto as = GetParam();
    std::vector<int> temp = as.nums;
    EXPECT_EQ(rmss.sortArray(temp), as.result);
}

TEST_P(SortArrayTest, ItrBubbleSortSolutionTests) {
    auto as = GetParam();
    std::vector<int> temp = as.nums;
    EXPECT_EQ(ibss.sortArray(temp), as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, SortArrayTest,
    ::testing::Values(
        States{{5,2,3,1}, {1,2,3,5}},                 // example 1
        States{{5,1,1,2,0,0}, {0,0,1,1,2,5}},         // example 2
        States{{1}, {1}},                             // single element
        States{{3,3,3}, {3,3,3}},                     // all equal
        States{{-1,-3,-2}, {-3,-2,-1}},               // negatives
        States{{-1,2,-8,-10}, {-10,-8,-1,2}},         // negatives
        States{{10,9,8,7,6,5}, {5,6,7,8,9,10}},       // reverse order
        States{{2,1,3,1,2}, {1,1,2,2,3}}              // duplicates mixed
    )
);
