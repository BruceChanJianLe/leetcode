#pragma once

#include <unordered_set>
#include <vector>

// Backtracking and early cutoffs
// Solution is exactly the same as n-queen
// just without the board generation
class Solution {
public:
  int totalNQueens(int n) {
    int result{};
    std::vector<int> rows;
    cols.clear(); neg_d.clear(); pos_d.clear();
    decisionTree(n, rows, result);
    return result;
  }

private:
  std::unordered_set<int> cols, neg_d, pos_d;
  void decisionTree(const int n,
      std::vector<int>& rows,
      int& result) {
    if (rows.size() == n) {
      ++result;
      return;
    }

    const auto row = rows.size() + 1;
    for (auto i = 0; i < n; ++i) {
      // Check if it's out of bounds (early cutoffs)
      if (cols.count(i) ||
          neg_d.count(row - i) ||
          pos_d.count(row + i)) continue;

      // Update constraints
      cols.insert(i);
      neg_d.insert(row - i);
      pos_d.insert(row + i);
      // Insert current position
      rows.push_back(i);
      decisionTree(n, rows, result);
      // Remove current position
      rows.pop_back();
      // Remove constraints
      // (in reverse order, just being fancy, not hard requirement)
      pos_d.erase(row + i);
      neg_d.erase(row - i);
      cols.erase(i);
    }
  }
};
