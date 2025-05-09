#pragma once

#include <array>
#include <string>

class WordDictionary {
public:
  WordDictionary() : root{new Node{}} {}

  void addWord(std::string word) {
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

    node->is_word = true;
  }

  bool search(std::string word) {
    return searchHelper(word, 0, root);
  }

private:
  struct Node {
    std::array<Node*, 26> children{};
    bool is_word{};
  };

  Node* root;

  bool searchHelper(const std::string& word, std::size_t index, Node* node) {
    // Base case
    if (index == word.size()) {
      return node->is_word;
    }

    if (word[index] == '.') {
      // Is a wildcard
      for (const auto child : node->children) {
        if (child && searchHelper(word, index + 1, child)) {
          return true;
        }
      }
      return false;
    } else {
      // Is a normal character
      if (auto lookup = node->children[word[index] - 'a']; !lookup) {
        return false;
      } else {
        return searchHelper(word, index + 1, lookup);
      }
    }
  }
};
