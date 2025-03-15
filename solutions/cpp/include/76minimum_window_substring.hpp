#pragma once

#include <limits>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::string minWindow(const std::string& s, const std::string& t) {
    // Sanity check
    if (s.empty() || t.empty()) return "";

    std::unordered_map<char, int> t_record, curr_record;

    // O(n)
    for (const auto& e : t) {
      ++t_record[e];
    }

    auto curr_match{0uz}, expected_match{t_record.size()};
    auto min_left{0uz}; auto min_length{std::numeric_limits<int>::max()};
    // O(m)
    for (auto left{0uz}, right{0uz}; right < s.size(); ++right) {
      if (t_record[s[right]] == ++curr_record[s[right]]) {
        ++curr_match;
      }

      while (curr_match == expected_match) {
        if (right - left + 1 < min_length) {
          min_length = right - left + 1;
          min_left = left;
        }

        if (--curr_record[s[left]] < t_record[s[left]]) {
          --curr_match;
        }
        ++left;
      }
    }
    return (min_length == std::numeric_limits<int>::max()) ? "" : s.substr(min_left, min_length);
  }
};
