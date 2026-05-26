#pragma once

#include <vector>
#include <array>
#include <utility>

class FirstSolution {
int searchIsland(const int row, const int col,
    const std::vector<std::vector<char>>& grid,
    std::vector<std::vector<bool>>& seen_list
    ) {
  // Skip if we have seen this cell before
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid.front().size()
      || seen_list[row][col] || grid[row][col] == '0') {
    return 0;
  } else {
    seen_list[row][col] = true;
    for (const auto& [r, c] : walks) {
      searchIsland(row + r, col + c, grid, seen_list);
    }
    return 1;
  }
}

const std::array<std::pair<int, int>, 4> walks{{
  {-1, 0}, {0, -1}, {1, 0}, {0, 1}
}};

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    std::vector<std::vector<bool>> has_visited(
        grid.size(), std::vector(grid.front().size(), false));

    int island_count{};

    for (auto row = 0; row < grid.size(); ++row) {
      for (auto col = 0; col < grid.front().size(); ++col) {
        island_count += searchIsland(row, col, grid, has_visited);
      }
    }

    return island_count;
  }
};
