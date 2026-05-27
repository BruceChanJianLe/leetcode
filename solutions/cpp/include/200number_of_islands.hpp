#pragma once

#include <vector>
#include <array>
#include <utility>

// This does not use additional seen_list
// replace the grid directly
class InplaceSolution {
  const std::array<std::pair<int, int>, 4> walks {{
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
  }};

  void walk(const int row, const int col, std::vector<std::vector<char>>& grid) {
    // update the cell to '0'
    grid[row][col] = '0';

    for (const auto& [r, c] : walks) {
      if (auto nxt_row{row + r}, nxt_col{col + c};
          nxt_row < 0 || nxt_row >= grid.size() ||
          nxt_col < 0 || nxt_col >= grid.front().size() ||
          grid[nxt_row][nxt_col] == '0'
          ) {
        continue;
      } else {
        walk(nxt_row, nxt_col, grid);
      }
    }
  }

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int count{};

    for (auto row{0}; row < grid.size(); ++row) {
      for (auto col{0}; col < grid.front().size(); ++col) {
        if (grid[row][col] == '0') continue;

        ++count;
        walk(row, col, grid);
      }
    }

    return count;
  }
};

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
