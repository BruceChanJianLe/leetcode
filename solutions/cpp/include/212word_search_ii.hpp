#pragma once

#include <array>
#include <vector>
#include <string>

class Solution {
public:
  Solution()
    : root{new Node{}}
    , walks{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}}
  {}

  ~Solution() { if (root) freeTrie(root); }

  std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
    std::vector<std::string> result;

    for (const auto& word : words) {
      insert(word);
    }

    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board.front().size(), false));
    auto rows{board.size()}, cols{board.front().size()};

    for (auto row = 0uz; row < rows; ++row) {
      for (auto col = 0uz; col < cols; ++col) {
        findWordsHelper(board, row, col, root, visited, result);
      }
    }

    return result;
  }

private:
  struct Node {
    std::array<Node*, 26> children{};
    std::string word;
  };

  Node* root;
  std::array<std::pair<int, int>, 4> walks;

  void insert(const std::string& word) {
    auto node = root;

    for (const auto &c : word) {
      auto index = c - 'a';

      if (auto lookup = node->children[index]; !lookup) {
        auto new_node = new Node{};
        node->children[index] = new_node;
        node = new_node;
      } else {
        node = lookup;
      }
    }

    node->word = word; // mark as end of word
  }

  void findWordsHelper(std::vector<std::vector<char>>& board,
      int row, int col,
      Node* trie, std::vector<std::vector<bool>>& visited,
      std::vector<std::string>& result) {
    // Base cases
    if (row >= board.size()
        || col >= board.front().size()
        || !trie
        || visited[row][col]
        ) return;

    auto index = board[row][col] - 'a';
    visited[row][col] = true;

    if (auto lookup = trie->children[index]; lookup) {

      if (auto& word = lookup->word; !word.empty()) {
        result.emplace_back(word);
        word.clear(); // avoid duplicate
      }

      for (const auto &walk : walks) {
        findWordsHelper(board, row + walk.first, col + walk.second, lookup, visited, result);
      }
    }

    // Backtrack
    visited[row][col] = false;
  }

  // Free memory of the trie
  void freeTrie(Node* node) {
    if (!node) return;

    for (int i = 0; i < 26; i++) {
      if (node->children[i]) {
        freeTrie(node->children[i]);
      }
    }

    delete node;
  }
};
