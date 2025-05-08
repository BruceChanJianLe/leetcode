#pragma once

#include <string>
#include <array>

class Trie {
public:
  Trie() : root {new Node} {}

  void insert(std::string word) {
    auto node = root;

    for (const auto &c : word) {
      if (!node->children[c - 'a']) {
        node->children[c - 'a'] = new Node;
      }
      node = node->children[c - 'a'];
    }

    node->is_word = true;
  }

  bool search(std::string word) {
    auto node = root;

    for (const auto &c : word) {
      if (!node->children[c - 'a']) {
        return false;
      }
      node = node->children[c - 'a'];
    }

    return node->is_word;
  }

  bool startsWith(std::string prefix) {
    auto node = root;

    for (const auto &c : prefix) {
      if (!node->children[c - 'a']) {
        return false;
      }
      node = node->children[c - 'a'];
    }

    return node;
  }

private:
  struct Node {
    std::array<Node*, 26> children{};
    bool is_word{false};
  };

  Node* root;
};

class SlightlyFasterTrie {
public:
  SlightlyFasterTrie() : root {new Node} {}

  void insert(std::string word) {
    auto node = root;

    for (const auto &c : word) {
      auto index = c - 'a';
      if (auto lookup = node->children[index]; !lookup) {
        auto new_node = new Node;
        node->children[index] = new_node;
        node = new_node;
      } else {
        node = lookup;
      }
    }

    node->is_word = true;
  }

  bool search(std::string word) {
    auto node = root;

    for (const auto &c : word) {
      auto index = c - 'a';
      if (auto lookup = node->children[index]; !lookup) {
        return false;
      } else {
        node = lookup;
      }
    }

    return node->is_word;
  }

  bool startsWith(std::string prefix) {
    auto node = root;

    for (const auto &c : prefix) {
      auto index = c - 'a';
      if (auto lookup = node->children[c - 'a']; !lookup) {
        return false;
      } else {
        node = lookup;
      }
    }

    return node;
  }

private:
  struct Node {
    std::array<Node*, 26> children{};
    bool is_word{false};
  };

  Node* root;
};
