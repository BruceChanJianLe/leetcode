#include "121best_time_to_buy_and_sell_stock.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<int> prices;
  int result;
};

struct BestTimeToBuyAndSellStockTest : public testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(BestTimeToBuyAndSellStockTest, BestTimeToBuyAndSellStockCase)
{
  auto as = GetParam();
  auto result = s.maxProfit(as.prices);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, BestTimeToBuyAndSellStockTest,
    testing::Values(
      States{{7,1,5,3,6,4}, 5},
      States{{7,6,4,3,1}, 0}
    ));
