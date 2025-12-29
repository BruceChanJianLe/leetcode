#pragma once

#include <vector>

class ClassicSolution {
public:
  int maxArea(std::vector<int> &height) {
    int max_seen{}, lp{}, rp = height.size() - 1;

    while (lp < rp) {
      max_seen = std::max(std::min(height[lp], height[rp]) * (rp - lp), max_seen);
      if (height[lp] > height[rp]) {
        --rp;
      } else {
        ++lp;
      }
    }

    return max_seen;
  }
};

class IteratorSolution {
public:
  int maxArea(std::vector<int> &height) {
    int max {0};
    auto fp = height.begin();
    auto lp = height.end() - 1;
    while (fp < lp)
    {
      max = std::max<int>(max, std::min(*fp, *lp) * std::distance(fp, lp));
      if (*fp > *lp)
      {
        --lp;
      }
      else
      {
        ++fp;
      }
    }
    return max;
  }
};

// Brute force solution O(n^2)
class FirstSolution {
public:
  int maxArea(std::vector<int> &height) {
    int max {0};
    for (auto it1 = height.begin(); it1 != height.end(); ++it1)
    {
      for (auto it2 = it1 + 1; it2 != height.end(); ++it2)
      {
        max = std::max<int>(max, std::min(*it1, *it2) * std::distance(it1, it2));
      }
    }
    return max;
  }
};

