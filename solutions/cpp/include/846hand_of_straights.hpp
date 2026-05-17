#pragma once

#include <vector>
#include <map>

class FirstSolution {
public:
  bool isNStraightHand(std::vector<int>& hand, int groupSize) {
    // Sanity check
    if (hand.size() % groupSize != 0) return false;

    // Insert all in a red-black tree (which is std::map)
    std::map<int, int> records;
    for (const auto& key : hand) {
      ++records[key];
    }

    for (auto &[key, count] : records) {
      while (count != 0){
        for (auto i{0}; i < groupSize; ++i) {
          if (auto& curr_count = records[key + i]; curr_count > 0) {
            --curr_count;
          } else {
            return false;
          }
        }
      }
    }
    return true;
  }
};
