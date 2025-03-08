#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

class TimeMap {
public:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> records;
  TimeMap() {
  }

  void set(std::string key, std::string value, int timestamp) {
    records[key].emplace_back(timestamp, value);
  }

  std::string get(std::string key, int timestamp) {
    if (auto history = records.find(key); history != records.end())
    {
      std::string best_match{""};
      auto left{0uz}, right{history->second.size()};

      while (left < right) {
        auto mid = (left + right) / 2;

        if (auto entry = history->second[mid]; timestamp >= entry.first) {
          best_match = entry.second;
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      return best_match;
    }
    return "";
  }
};

class FirstTimeMap {
public:
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> records;
  FirstTimeMap() {
  }

  void set(std::string key, std::string value, int timestamp) {
    records[key].push_back(std::make_pair(timestamp, value));
    // std::cout << "key: " << key << ", timestamp: " << timestamp << ", value: " << value << std::endl;
  }

  std::string get(std::string key, int timestamp) {
    // std::cout << "asking for key: " << key << ", timestamp: " << timestamp << std::endl;

    auto history = records[key];
    auto left{0uz}, right{history.size()};
    auto mid{0uz};

    while (left < right) {
      mid = (left + right) / 2;
      auto val = history[mid];
      if (timestamp == val.first) {
        return val.second;
      } else if (timestamp < val.first) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    // std::cout << "obtained key: " << mid << ", timestamp: " << history[mid].first
    //   << ", value: " << history[mid].second << std::endl;

    if (left >= history.size()) return history.back().second;
    if (timestamp > (history.rbegin() + 1 )->first) return (history.rbegin() + 1 )->second;
    return "";
  }
};
