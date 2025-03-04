#pragma once

#include <vector>

class Solution
{
public:
  int search(const std::vector<int>& haystack, const int needle)
  {
    auto lo {0uz}, hi{haystack.size()};
    while (lo < hi)
    {
      auto mid = lo + (hi - lo) / 2;
      if (needle == haystack[mid])
        return mid;
      else if (needle > haystack[mid] )
        lo = mid + 1;
      else
        hi = mid;
    }
    return -1;
  }
};
