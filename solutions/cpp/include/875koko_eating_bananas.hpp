#pragma once 

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
  int minEatingSpeed(std::vector<int>& piles, const int h) {
    auto min_eating_speed = std::ranges::max(piles);
    auto lo{1}, hi{min_eating_speed + 1}; // avoid off by one error

    while (lo < hi) {
      auto mid = (lo + hi) / 2;
      int needed_hour{0};
      for (const auto& p : piles) {
        if (needed_hour > h) break; // this may help to speed things up (Early Exit)
        needed_hour += (p + mid - 1) / mid;
      }

      if (needed_hour > h) {
        lo = mid + 1;
      }
      else {
        min_eating_speed = std::min(min_eating_speed, mid);
        hi = mid;
      }
    }

    return min_eating_speed;
  }
};

// Failed for case: States{{1000000000}, 2, 500000000}
class FirstSolution {
public:
  int minEatingSpeed(std::vector<int>& piles, const int h) {
    auto eating_speed = std::ranges::max(piles);
    auto lo{1}, hi{eating_speed + 1}; // avoid off by one error

    while (lo < hi)
    {
      auto mid = (lo + hi) / 2;

      // calculate eating speed
      int hours_needed = 0;
      for (const auto& p : piles)
      {
        hours_needed += (int)std::ceil(p / (float)mid);
      }

      if (hours_needed > h)
      {
        lo = mid + 1;
      }
      else
      {
        eating_speed = std::min(mid, eating_speed);
        hi = mid;
      }
    }

    return eating_speed;
  }
};
