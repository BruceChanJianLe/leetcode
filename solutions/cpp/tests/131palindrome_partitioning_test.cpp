#include "131palindrome_partitioning.hpp"

#include "gtest/gtest.h"

struct States
{
  std::string input;
  std::vector<std::vector<std::string>> result;
};

class PalindromePartitioningTest : public ::testing::TestWithParam<States>
{
protected:
  DTSolution dts;
  DT2Solution dt2s;
};

bool compareResult(std::vector<std::vector<std::string>> a,
    std::vector<std::vector<std::string>> b) {
  auto sort_inner = [](std::vector<std::string>& vec) {
    std::sort(vec.begin(), vec.end());
  };
  for (auto& v : a) sort_inner(v);
  for (auto& v : b) sort_inner(v);
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  return a == b;
}

TEST_P(PalindromePartitioningTest, DTPalindromePartitioningCase) {
  auto as = GetParam();
  auto output = dts.partition(as.input);
  EXPECT_TRUE(compareResult(output, as.result));
}

TEST_P(PalindromePartitioningTest, DT2PalindromePartitioningCase) {
  auto as = GetParam();
  auto output = dt2s.partition(as.input);
  EXPECT_TRUE(compareResult(output, as.result));
}

INSTANTIATE_TEST_SUITE_P(Default, PalindromePartitioningTest,
  ::testing::Values(
    States{"aab", {{"a", "a", "b"}, {"aa", "b"}}},
    States{"a", {{"a"}}},
    States{"aaa", {{"a", "a", "a"}, {"aa", "a"}, {"a", "aa"}, {"aaa"}}},
    States{"aabb", {{"a","a","b","b"},{"a","a","bb"},{"aa","b","b"},{"aa","bb"}} }
  )
);
