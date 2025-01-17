#pragma once

#include <vector>

// Iterator solution
class Solution {
public:
  int trap(std::vector<int> &height) {
    int result{0};
    auto lp{height.begin()}, rp{height.end() - 1};
    int max_left{*lp}, max_right{*rp};
    while (lp < rp) {
      if (*lp < *rp) {
        ++lp;
        max_left = (*lp > max_left) ? *lp : max_left;
        result += max_left - *lp;
      } else {
        --rp;
        max_right = (*rp > max_right) ? *rp : max_right;
        result += max_right - *rp;
      }
    }
    return result;
  }
};
