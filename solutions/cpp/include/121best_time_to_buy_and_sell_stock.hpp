#pragma once

#include <vector>

class Solution
{
public:
  int maxProfit(const std::vector<int>& prices) {
    auto max_profit{0}, lowest_record{prices.front()};
    for (const auto& price : prices) {
      lowest_record = std::min(lowest_record, price);
      max_profit = std::max(max_profit, price - lowest_record);
    }
    return max_profit;
  }
};

