#pragma once

#include <vector>
#include <unordered_map>

// 0ms
class HashSolution {
public:
    int majorityElement(std::vector<int>& nums) {
      std::unordered_map<int, int> records;
      int half_size = nums.size() / 2;

      for (const auto num : nums) {
        if (++records[num] > half_size) return num;
      }

      return -1;
    }
};

class FirstSolution {
public:
    int majorityElement(std::vector<int>& nums) {
      std::unordered_map<int, int> records;
      int curr_candy{};
      int max_count{};

      for (const auto num : nums) {
        ++records[num];
        if (auto it = records.find(num); it != records.end()) {
          auto [candy, count] = *it;
          if (count > max_count) {
            curr_candy = candy;
            max_count = count;
          }
        }
      }

      return curr_candy;
    }
};

// Boyer-Moore Vote
class BoyerMooreolution {
public:
    int majorityElement(std::vector<int>& nums) {
      auto candy{nums.front()};
      auto count{0};

      for (const auto num : nums) {
        if (candy == num) {
          ++count;
        } else if (--count == 0) {
          count = 1;
          candy = num;
        }
      }

      return candy;
    }
};
