#pragma once

#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::vector<std::unordered_set<char>> record_rows(board.size()),
        record_cols(board.size()), record_boxes(board.size());

    for (auto [row, col] : std::ranges::views::cartesian_product(
             std::views::iota(0u, board.size()),
             std::views::iota(0u, board.front().size()))) {
      // Obtain element
      auto e = board[row][col];
      if ('.' == e)
        continue;

      // Verify the element has not appear before
      if (!record_rows[row].insert(e).second ||
          !record_cols[col].insert(e).second ||
          !record_boxes[(row / 3) * 3 + col / 3].insert(e).second)
        return false;
    }
    return true;
  }
};

class FirstSolution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    // Row
    for (const auto &row : board) {
      std::unordered_set<char> record{};
      for (const auto &e : row) {
        if (e == '.') {
          continue;
        } else if (!record.insert(e).second) {
          return false;
        }
      }
    }

    // Column
    std::vector<std::unordered_set<char>> records(board.size());
    for (const auto &row : board) {
      for (std::size_t i = 0; i < row.size(); ++i) {
        if ('.' == row[i]) {
          continue;
        } else if (!records[i].insert(row[i]).second) {
          return false;
        }
      }
    }

    // Grid
    records.clear();
    std::size_t index = 0;
    for (std::size_t g = 0; g < board.size(); g += 3) {
      for (std::size_t h = 0; h < board.size(); h += 3) {
        records.emplace_back(std::unordered_set<char>{});
        for (std::size_t i = 0; i < 3; ++i) {
          for (std::size_t j = 0; j < 3; ++j) {
            // std::cout << "(" << g + i << ", " << h + j << ")\n";
            if ('.' == board[g + i][j + h]) {
              continue;
            } else if (!records[index].insert(board[g + i][h + j]).second) {
              return false;
            }
          }
        }
        ++index;
      }
    }

    return true;
  }
};
