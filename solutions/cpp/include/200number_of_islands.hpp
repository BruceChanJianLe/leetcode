#pragma once

#include <vector>
#include <array>
#include <utility>
#include <stack>

// This solution should be faster as it does not
// incur function calling causing stack overflow
class StackSolution {
  static constexpr std::array<std::pair<int, int>, 4> walks{{
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
  }};

  void walk(const int row, const int col,
      std::vector<std::vector<char>>& grid) {
    std::stack<std::pair<int, int>> stack{{{row, col}}};
    while (!stack.empty()) {
      auto [top_row, top_col] = stack.top();
      grid[top_row][top_col] = '0';
      stack.pop();

      for (const auto& [r, c] : walks) {
        if (auto curr_row{top_row + r}, curr_col{top_col + c};
            curr_row < 0 || curr_row >= grid.size() ||
            curr_col < 0 || curr_col >= grid.front().size() ||
            grid[curr_row][curr_col] == '0'){
          continue;
        } else {
          stack.emplace(curr_row, curr_col);
        }
      }
    }
  }

public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int count{};
    for (auto row{0}; row < std::ssize(grid); ++row) {
      for (auto col{0}; col < std::ssize(grid.front()); ++col) {
        if (grid[row][col] == '0') continue;
        ++count;
        walk(row, col, grid);
      }
    }
    return count;
  }
};

// This does not use additional seen_list
// replace the grid directly
// but this will be risky to stack overflow if the grid is huge
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
