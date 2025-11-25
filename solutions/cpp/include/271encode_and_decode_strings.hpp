#pragma once

#include <string>
#include <vector>

class Solution {
public:
  std::string encode(std::vector<std::string> &strs) {
    std::string s {""};
    for (const auto& str : strs) {
      s += std::to_string(str.size()) + '^' + str;
      // s = s + std::to_string(str.size()) + str;
    }
    return s;
  }

  std::vector<std::string> decode(std::string str) {
    std::vector<std::string> result;
    for (auto itr = str.begin(); itr != str.end();) {
      std::string walk_str;
      while(*itr != '^') {
        walk_str += *itr;
        ++itr;
      }

      auto walk = std::stoi(walk_str);
      std::string s;

      // move to start of string
      ++itr;

      while(walk > 0)
      {
        s += *itr;
        ++itr;
        --walk;
      }
      result.push_back(s);
    }
    return result;
  }
};


class PracticeSolution {
public:
  std::string encode(std::vector<std::string> &strs) {
    std::string result;
    for (const auto& str : strs) {
      result += std::to_string(str.size()) + '^' + str;
    }
    return result;
  }

  std::vector<std::string> decode(std::string str) {
    std::vector<std::string> result;
    int i{0};

    while (i < str.size()) {
      // Find the delimiter position '^'
      int delim_pose = str.find('^', i);

      // Extract length
      int length = std::stoi(str.substr(i, delim_pose - i));

      // Extract the string of that length
      result.emplace_back(str.substr(delim_pose + 1, length));

      // Move to next encoded string position
      i = delim_pose + 1 + length;
    }

    return result;
  }
};
