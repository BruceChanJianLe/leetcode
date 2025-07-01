#include "322coin_change.hpp"

#include "gtest/gtest.h"

struct States {
  std::vector<int> coins;
  int amount;
  int result;
};

class CoinChangeTest : public ::testing::TestWithParam<States>
{
protected:
  FirstSolution fs;
  SecondSolution ss;
  NRBSolution nrbs; // This will take a super long time to pass the stress test case
  DFSSolution dfss; // This will take a super long time to pass the stress test case
  DPTopDownSolution dp_td_s;
  DPBottomUpSolution dp_bu_s;
};

TEST_P(CoinChangeTest, FirstDPCoinChangeCase) {
  auto as = GetParam();
  auto result = fs.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

TEST_P(CoinChangeTest, SecondDPCoinChangeCase) {
  auto as = GetParam();
  auto result = ss.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

TEST_P(CoinChangeTest, RBCoinChangeCase) {
  auto as = GetParam();
  auto result = nrbs.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

// Depth first search (pure recursion)
TEST_P(CoinChangeTest, DFSCoinChangeCase) {
  auto as = GetParam();
  auto result = dfss.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

// DP Top Down - Memoization
TEST_P(CoinChangeTest, DPTopDownCoinChangeCase) {
  auto as = GetParam();
  auto result = dp_td_s.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

// DP Bottom Up - Tabulation
TEST_P(CoinChangeTest, DPBottomUpCoinChangeCase) {
  auto as = GetParam();
  auto result = dp_bu_s.coinChange(as.coins, as.amount);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, CoinChangeTest,
  ::testing::Values(
    States{{1, 2, 5}, 11, 3},        // 5+5+1
    States{{2}, 5, -1},              // not possible
    States{{1}, 0, 0},               // 0 coins
    States{{1}, 2, 2},               // 1+1
    // States{{186, 419, 83, 408}, 6249, 20}, // stress test case from LeetCode
    States{{2, 5, 10, 1}, 27, 4}     // 10+10+5+2
  )
);
