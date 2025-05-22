#include "91decode_ways.hpp"

#include "gtest/gtest.h"

struct States {
  std::string input;
  int result;
};

class DecodeWaysTest : public ::testing::TestWithParam<States>
{
  protected:
    DPSolution dps;
};

TEST_P(DecodeWaysTest, HandlesNumDecodings) {
  const auto& as = GetParam();
  auto result = dps.numDecodings(as.input);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, DecodeWaysTest,
  ::testing::Values(
    States{"12", 2},           // "AB", "L"
    States{"226", 3},          // "BZ", "VF", "BBF"
    States{"06", 0},           // invalid due to leading 0
    States{"0", 0},            // invalid
    States{"10", 1},           // "J"
    States{"101", 1},          // "JA"
    States{"27", 1},           // "BG" (27 is invalid for 2-digit mapping)
    States{"2611055971756562", 4}, // large input, known answer
    States{"11106", 2}         // "AAJF", "KJF"
  )
);
