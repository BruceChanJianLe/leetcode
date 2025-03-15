#pragma once

#include <string>
#include <array>
#include <ranges>

// Fastest 0ms
class Solution
{
public:
  bool checkInclusion(std::string s1, std::string s2) {
    // Sanity check
    if (s1.size() > s2.size()) return false;

    std::array<int, 26> s1_record{}, s2_record{};

    for (const auto& s : s1) {
      ++s1_record[s - 'a'];
    }

    bool first_time = true;
    for (const auto& window : std::ranges::slide_view(s2, s1.size())) {
      if (!first_time) {
        ++s2_record[window.back() - 'a'];
      } else {
        for (const auto& e : window) {
          ++s2_record[e - 'a'];
        }
        first_time = false;
      }

      if (s1_record == s2_record) return true;
      --s2_record[window.front() - 'a'];
    }

    return false;}
};

// zip_view is cool but takes longer execution time
class FirstSolution
{
public:
  bool checkInclusion(std::string s1, std::string s2) {
    // Sanity check
    if (s1.size() > s2.size()) return false;

    std::array<int, 26> s1_record{}, s2_record{};

    for (const auto& [e1, e2] : std::ranges::zip_view(s1, s2)) {
      ++s1_record[e1 - 'a'];
      ++s2_record[e2 - 'a'];
    }

    if (s1_record == s2_record) return true;
    --s2_record[s2.front() - 'a'];

    // Start from the second
    for (const auto& window : std::ranges::slide_view(s2.substr(1), s1.size())) {
      ++s2_record[window.back() - 'a'];
      if (s1_record == s2_record) return true;
      --s2_record[window.front() - 'a'];
    }

    return false;
  }
};

class RawPointerSolution
{
public:
  bool checkInclusion(std::string s1, std::string s2) {
    // Sanity check
    if (s1.size() > s2.size()) return false;

    std::array<int, 26> s1_record{}, s2_record{};
    auto s1_length{s1.size()}, s2_length{s2.size()};

    for (auto i = 0uz; i < s1_length; ++i ) {
      ++s1_record[s1[i] - 'a'];
    }

    for (auto left{0uz}, right{0uz}; right < s2_length; ++right) {
      ++s2_record[s2[right] - 'a'];
      if (right >= s1_length) {
        --s2_record[s2[left++] - 'a'];
      }
      if (s1_record == s2_record) return true;
    }

    return false;
  }
};
