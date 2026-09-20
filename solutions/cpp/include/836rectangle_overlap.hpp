#pragma once

#include <vector>

class Solution {
  enum pos {
    bot_x = 0,
    bot_y,
    top_x,
    top_y
  };

  public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
      return rec2[top_x] > rec1[bot_x] && rec2[top_y] > rec1[bot_y]
        && rec1[top_x] > rec2[bot_x] && rec1[top_y] > rec2[bot_y];
    }
};
