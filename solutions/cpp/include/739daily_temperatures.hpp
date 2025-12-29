#pragma once

#include <iostream>
#include <vector>
#include <stack>

// traditional index method
class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
      std::vector<std::pair<int, int>> records;
    std::vector<int> result(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); ++i) {
      while (!records.empty() && records.back().first < temperatures[i]) {
        auto [_, index] =
            records.back(); // Does make things faster if stored locally
        result[index] = i - index;
        records.pop_back();
      }
      records.emplace_back(temperatures[i], i);
    }
    return result;
}
};

// Iterator solution, slower due to index computation
class SecondSolution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    std::vector<std::vector<int>::iterator> records;
    std::vector<int> result(temperatures.size(), 0);

    for (auto it = temperatures.begin(); it != temperatures.end(); ++it) {
      while (!records.empty() && *records.back() < *it) {
        auto record =
            records.back(); // Does make things faster if stored locally
        result[std::distance(std::begin(temperatures), record)] = std::distance(record, it);
        records.pop_back();
      }
      records.emplace_back(it);
    }
    return result;
  }
};

