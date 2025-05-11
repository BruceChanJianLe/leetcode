#pragma once

#include <array>
#include <cstddef>
#include <utility>
#include <vector>
#include <string>

class FirstSolution {
public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    auto rows{board.size()}, cols{board.front().size()};
    std::vector<std::vector<bool>>
      visited(rows, std::vector(cols, false));

    for (auto row = 0uz; row < rows; ++row) {
      for (auto col = 0uz; col < cols; ++col) {
        if (walk(board, visited, row, col, word, 0uz))
          return true;
      }
    }

    return false;
  }

private:
  static constexpr std::array<std::pair<int, int>, 4> walks{{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};

  bool walk(const std::vector<std::vector<char>>& board,
      std::vector<std::vector<bool>>& visited,
      int row, int col, const std::string& word, std::size_t index
      ) {
    // Base case
    if (index == word.size()) return true;

    if ( row < 0 || col < 0
        || row == board.size() || col == board.front().size()
        || visited[row][col] || board[row][col] != word[index]
       ) return false;

    visited[row][col] = true;
    for (const auto &[row_walk, col_walk] : walks) {
      auto curr_row = row + row_walk;
      auto curr_col = col + col_walk;

      if (walk(board, visited, curr_row, curr_col, word, index + 1))
        return true;
    }
    visited[row][col] = false;

    return false;
  }
};
