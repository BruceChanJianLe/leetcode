#pragma once

#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    auto lo_col{0uz}, hi_col{matrix.size()};
    // log(m)
    while (lo_col < hi_col)
    {
      auto mid = (hi_col + lo_col) / 2;
      auto val = matrix[mid].back();
      if (target == val)
      {
        return true;
      }
      else if (target > val)
      {
        lo_col = mid + 1;
      }
      else
      {
        hi_col = mid;
      }
    }

    if (lo_col == matrix.size()) return false;

    // log(n)
    auto lo_row{0uz}, hi_row{matrix[lo_col].size()};
    while (lo_row < hi_row)
    {
      auto mid = (lo_row + hi_row) / 2;
      auto val = matrix[lo_col][mid];
      if (target == val)
      {
        return true;
      }
      else if (target > val )
      {
        lo_row = mid + 1;
      }
      else
      {
        hi_row = mid;
      }
    }

    return false;
  }
};


class SecondSolution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    auto rol_size = matrix.front().size();
    auto lo{0uz}, hi{matrix.size() * rol_size};

    while (lo < hi)
    {
      auto mid = (lo + hi) / 2;
      auto val = matrix[mid / rol_size][mid % rol_size];

      if (target == val)
      {
        return true;
      }
      else if (target > val)
      {
        lo = mid + 1;
      }
      else
      {
        hi = mid;
      }
    }
    return false;
  }
};
