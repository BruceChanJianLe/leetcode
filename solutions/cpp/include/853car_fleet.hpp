#pragma once

#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>

// More modern approach
class ModernSolution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    auto zips = std::views::zip(position, speed);
    std::vector<std::pair<int, int>> cars(zips.begin(), zips.end());
    std::sort(cars.begin(), cars.end());
    int fleet{}; float eta{};

    for (const auto [pose, vel] : cars | std::views::reverse) {
      auto curr_eta = static_cast<double>(target - pose) / vel;
      if (curr_eta > eta) {
        ++fleet;
        eta = curr_eta;
      }
      std::cout << "[" << pose << "," << vel << "]"<< "eta: "
        << eta << ", fleet: " << fleet << std::endl;
    }

    return fleet;
  }
};

class Solution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, float>> cars(position.size());

    std::transform(position.begin(), position.end(), speed.begin(), cars.begin(), 
        [&target](auto p, auto s) { return std::make_pair(p, static_cast<float>(target - p) / s); });

    std::sort(cars.begin(), cars.end());

    int fleet{1};
    float prev_time{cars.back().second};
    for (auto const& car : std::views::reverse(cars))
    {
      if (prev_time >= car.second)
        continue;
      ++fleet;
      prev_time = car.second;
    }
    return fleet;
  }
};

class FirstSolution {
public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<float> fleet;
    std::vector<std::pair<int, int>> info(position.size());
    std::transform(position.begin(), position.end(), speed.begin(), info.begin(), 
        [](auto p, auto s) { return std::make_pair(p, s); });

    std::sort(info.begin(), info.end());

    for (auto it = info.rbegin(); it != info.rend(); ++it)
    {
      float curr_dest_speed = (target - it->first) / (float) it->second;
      if (!fleet.empty() && fleet.back() >= curr_dest_speed)
        continue;
      fleet.push_back(curr_dest_speed);
    }
    return fleet.size();
  }
};
