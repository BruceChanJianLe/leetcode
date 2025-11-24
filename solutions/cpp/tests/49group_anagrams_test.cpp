#include "49group_anagrams.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::string> strs;
  std::vector<std::vector<std::string>> result;
};

struct GroupAnagramsTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s;
  HashKeySolution hks;
};

TEST_P(GroupAnagramsTest, GroupAnagramsCases)
{
  auto as = GetParam();
  auto result = s.groupAnagrams(as.strs);
  EXPECT_EQ(result, as.result);
}

TEST_P(GroupAnagramsTest, HashKeyGroupAnagramsCases)
{
  auto as = GetParam();
  auto result = hks.groupAnagrams(as.strs);
  std::sort(result.begin(), result.end());
  std::sort(as.result.begin(), as.result.end());
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Defaul, GroupAnagramsTest,
    testing::Values(
      States{{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}},
      States{{""}, {{""}}},
      States{{"a"}, {{"a"}}},
      States{{"ac", "d"}, {{"d"}, {"ac"}}},
      States{{"cab","tin","pew","duh","may","ill","buy","bar","max","doc"}, {{"max"},{"buy"},{"doc"},{"may"},{"ill"},{"duh"},{"tin"},{"bar"},{"pew"},{"cab"}}}
    ));
