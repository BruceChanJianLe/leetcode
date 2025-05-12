#pragma once

#include <unordered_set>
#include <vector>
#include <string>

// Decision Tree recursive
// Using vectors
class VDTSolution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(n, std::string(n, '.'));

    /// Visited column
    std::vector<bool> vcol(n, false);
    /// Visited positive diagonal
    std::vector<bool> vpos_diag(2 * n - 1, false);
    /// Visited negative diagonal
    std::vector<bool> vneg_diag(2 * n - 1, false);

    decisionTree(0, n, board, result, vcol, vpos_diag, vneg_diag);

    return result;
  }

private:
  void decisionTree(const int row, const int n,
      std::vector<std::string>& board,
      std::vector<std::vector<std::string>>& result,
      std::vector<bool>& vcol, std::vector<bool>& vpos_diag,
      std::vector<bool>& vneg_diag
      ) {
    // Base case
    if (row == n) {
      result.emplace_back(board);
      return;
    }

    for (auto col = 0uz; col < n; ++col) {
      // Validate it position has been taken
      if (vcol[col]
          || vpos_diag[row + col]
          || vneg_diag[row - col + n - 1]) {
        continue;
      }

      board[row][col] = 'Q';
      vcol[col] = true;
      vpos_diag[row + col] = true;
      vneg_diag[row - col + n - 1] = true;

      decisionTree(row + 1, n, board, result, vcol, vpos_diag, vneg_diag);

      vneg_diag[row - col + n - 1] = false;
      vpos_diag[row + col] = false;
      vcol[col] = false;
      board[row][col] = '.';
    }
  }
};

// Decision Tree recursive
// Using hash sets
class HDTSolution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(n, std::string(n, '.'));
    decisionTree(0, n, board, result);

    return result;
  }

private:
  /// Visited column
  std::unordered_set<int> vcol;
  /// Visited positive diagonal
  std::unordered_set<int> vpos_diag;
  /// Visited negative diagonal
  std::unordered_set<int> vneg_diag;

  void decisionTree(const int row, const int n,
      std::vector<std::string>& board,
      std::vector<std::vector<std::string>>& result) {
    // Base case
    if (row == n) {
      result.emplace_back(board);
      return;
    }

    for (auto col = 0uz; col < n; ++col) {
      // Validate it position has been taken
      if (vcol.contains(col)
          || vpos_diag.contains(row + col)
          || vneg_diag.contains(row - col)) {
        continue;
      }

      board[row][col] = 'Q';
      vcol.insert(col);
      vpos_diag.insert(row + col);
      vneg_diag.insert(row - col);

      decisionTree(row + 1, n, board, result);

      vneg_diag.erase(row - col);
      vpos_diag.erase(row + col);
      vcol.erase(col);
      board[row][col] = '.';
    }
  }
};
