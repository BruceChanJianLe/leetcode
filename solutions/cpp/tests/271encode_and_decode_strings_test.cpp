#include "271encode_and_decode_strings.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::string> strs;
};

struct EncodeAndDecodeStringTest : public testing::Test, testing::WithParamInterface<States>
{
  Solution s;
  PracticeSolution ps;
};

TEST_P(EncodeAndDecodeStringTest, EncodeAndDecodeStringCases)
{
  auto as = GetParam();
  auto result = s.decode(s.encode(as.strs));
  EXPECT_EQ(result, as.strs);
}

TEST_P(EncodeAndDecodeStringTest, PracticeEncodeAndDecodeStringCases)
{
  auto as = GetParam();
  auto result = ps.decode(ps.encode(as.strs));
  EXPECT_EQ(result, as.strs);
}

INSTANTIATE_TEST_CASE_P(Default, EncodeAndDecodeStringTest,
    testing::Values(
      States{{"leet", "code", "love", "you"}},
      States{{"we", "say", ":", "yes"}}
    ));
