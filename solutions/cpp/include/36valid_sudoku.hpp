#pragma once

#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    // Generic appoarch, however, we do know that sudoku is always
    // 9x9, for a faster version please refer to NonLazySolution
    std::vector<std::unordered_set<char>> record_rows(board.size()),
        record_cols(board.size()), record_boxes(board.size());

    for (const auto &[row, col] : std::views::cartesian_product(
             std::views::iota(0u, board.size()),
             std::views::iota(0u, board.front().size()))) {
      // Obtain element
      if (const auto &e = board[row][col]; '.' != e) {
        // Verify the element has not appear before
        if (!record_rows[row].insert(e).second ||
            !record_cols[col].insert(e).second ||
            !record_boxes[(row / 3) * 3 + col / 3].insert(e).second)
          return false;
      }
    }
    return true;
  }
};

class NonLazySolution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    // Since we know sudoku is always 9x9, let generate the index first
    // We do this to avoid lazy evaluation
    std::array<std::pair<int, int>, 81> indexes;
    std::ranges::copy(
        std::views::cartesian_product(
          std::views::iota(0, 9), std::views::iota(0, 9)),
        indexes.begin());

    std::vector<std::unordered_set<char>> record_rows(board.size()),
        record_cols(board.size()), record_boxes(board.size());

    for (const auto &[row, col] : indexes) {
      // Obtain element
      if (const auto &e = board[row][col]; '.' != e) {
        // Verify the element has not appear before
        if (!record_rows[row].insert(e).second ||
            !record_cols[col].insert(e).second ||
            !record_boxes[(row / 3) * 3 + col / 3].insert(e).second)
          return false;
      }
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
