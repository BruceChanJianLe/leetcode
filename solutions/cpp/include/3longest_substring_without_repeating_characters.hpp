#pragma once

#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_set>
#include <deque>

// 26ms
class SetSolution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> lookup;
    int max_seen{}, ptr{}; 

    for (int i = 0; i < s.size(); ++i) {
      while (!lookup.insert(s[i]).second) {
        lookup.erase(s[ptr]);
        ++ptr;
      }

      max_seen = std::max<int>(max_seen, lookup.size());
    }

    return max_seen;
  }
};

// int method (18ms)
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
      auto left{0}, max_seen{0};
    std::unordered_set<char> records;

    for (auto right = 0; right < s.size(); ++right) {
      while (records.count(s[right])) {
        records.erase(s[left++]);
      }
      records.insert(s[right]);
      max_seen = std::max(max_seen, right - left + 1); // off by one error, when both pointers is pointing as the same element, size is 1;
    }
    return max_seen;
}
};

// iterator method (7ms)
class SecondSolution {
public:
  int lengthOfLongestSubstring(std::string s) {
    auto left{s.begin()}, right{s.begin()};
    std::unordered_set<char> records;
    auto max_seen{0l};

    while (right != s.end()) {
      // if (!records.insert(*right).second) {
      if (!records.emplace(*right).second) {
        bool is_found = false;
        while (!is_found) {
          if (*left == *right) {
            is_found = true;
          } else {
            records.erase(*left);
          }
          ++left;
        }
      }
      max_seen = std::max(max_seen, std::distance(left, right) + 1);
      ++right;
    }
    return max_seen;
  }
};

// 9ms
class FirstSolution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> records;
    auto max_seen{0uz};
    std::deque<char> collection;

    for (const auto& e : s) {
      if(!records.insert(e).second) {
        auto is_found = false;
        while (!is_found) {
          if (collection.front() == e) {
            is_found = true;
          } else {
            records.erase(collection.front());
          }
          collection.pop_front();
        }
      }
      collection.push_back(e);
      max_seen = std::max(max_seen, collection.size());
    }
    return max_seen;
  }
};
