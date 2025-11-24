#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <ranges>
#include <algorithm>
#include <array>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> records;
    // Sort and store in records
    for (const auto& str : strs)
    {
      std::string sorted_str{str};
      std::sort(sorted_str.begin(), sorted_str.end());
      records[sorted_str].push_back(str);
    }

    // Create result
    std::vector<std::vector<std::string>> result;
    for (const auto& [_, v] : records)
    {
      result.push_back(v);
    }

    return result;
  }
};

// Took too long to resolve
class FirstSolution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::vector<std::unordered_map<char, int>> stores;
    for (auto str : strs)
    {
      std::unordered_map<char, int> store;
      for (auto s : str)
      {
        ++store[s];
      }
      stores.push_back(store);
    }

    std::unordered_map<int, int> record;
    std::vector<std::vector<std::string>> results;
    std::unordered_map<char, int> s1, s2;
    // for (std::size_t i = 0; i < strs.size(); ++i)
    for (const int i : std::ranges::iota_view(0u, strs.size()))
    {
      std::vector<std::string> result {};
      if (auto curr_record = record.find(i); curr_record == record.end())
      {
        record[i] = 1; s1 = stores[i];
        result.push_back(strs[i]);
        for (std::size_t j = i + 1; j < strs.size(); ++j)
        {
          if (auto next_record = record.find(j); next_record == record.end())
          {
            s2 = stores[j];
            if (s1 == s2)
            {
              result.push_back(strs[j]);
              // Update record
              record[j] = 1;
            }
          }
        }
        results.push_back(result);
      }
    }
    return results;
  }
};

// Create a hash key from the string
class HashKeySolution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> records;

    for (const auto& str : strs) {
      std::array<int, 26> tokens{};
      for (const auto& c : str) {
        ++tokens[c - 'a'];
      }

      // Create key
      std::string key;
      for (const auto& token : tokens) {
        key += '#' + std::to_string(token);
      }

      records[key].emplace_back(str);
    }

    std::vector<std::vector<std::string>> result;

    for (const auto& [_, record] : records) {
      result.emplace_back(record);
    }

    return result;
  }
};
