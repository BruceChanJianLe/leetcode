#pragma once

#include <vector>
#include <string>

class Solution {
public:
  void backtrack(const size_t open_cout, const size_t close_count,
                 const size_t max_pair, std::string curr_str,
                 std::vector<std::string> &result) {
    if (open_cout == max_pair && close_count == max_pair) {
      result.push_back(curr_str);
      return;
    }

    if (open_cout < max_pair) {
      curr_str += "(";
      backtrack(open_cout + 1, close_count, max_pair, curr_str, result);
      curr_str.pop_back();
    }

    if (close_count < open_cout) {
      curr_str += ")";
      backtrack(open_cout, close_count + 1, max_pair, curr_str, result);
    }
  }
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    backtrack(0, 0, n, "", result);
    return result;
  }
};
