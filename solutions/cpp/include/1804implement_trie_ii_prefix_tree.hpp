#pragma once

#include <string>
#include <array>

// C++17
class SlightlyFasterTrie {
  public:
    SlightlyFasterTrie() : root{new Node{}} {}

    /**
     * @param word: The string to be inserted into the Trie.
     * @return: nothing
     */
    void insert(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';
        if (auto lookup = node->children[index]; !lookup) {
          auto new_node = new Node{};
          ++new_node->prefix_count;
          node->children[index] = new_node;
          node = new_node;
        } else {
          ++lookup->prefix_count;
          node = lookup;
        }
      }

      ++node->word_count;
    }

    /**
     * @param word: The word to be searched for.
     * @return: The number of words in the Trie that are equal to the given word.
     */
    int countWordsEqualTo(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';
        if (auto lookup = node->children[index]; !lookup) {
          return 0;
        } else {
          node = lookup;
        }
      }

      return node->word_count;
    }

    /**
     * @param prefix: The prefix to be searched for.
     * @return: The words in the Trie that have the same prefix as the given word.
     */
    int countWordsStartingWith(const std::string &prefix) {
      auto node = root;

      for (const auto &c : prefix) {
        auto index = c - 'a';
        if (auto lookup = node->children[index]; !lookup) {
          return 0;
        } else {
          node = lookup;
        }
      }

      return node->prefix_count;
    }

    /**
     * @param word: The word to be removed.
     * @return: nothing
     */
    void erase(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';
        if (auto lookup = node->children[index]; !lookup) {
          return;
        } else {
          node = lookup;
          --node->prefix_count;
        }
      }

      node->word_count = std::max(0, --node->word_count);
    }

  private:
    struct Node {
      std::array<Node*, 26> children{};
      int prefix_count;
      int word_count;
    };

    Node* root;
};

// C++ 11
class Trie {
  public:
    Trie() : root{new Node{}} {}

    /**
     * @param word: The string to be inserted into the Trie.
     * @return: nothing
     */
    void insert(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';

        if (!node->children[index]) {
          node->children[index] = new Node{};
        }

          node = node->children[index];
          ++node->prefix_count;
      }

      ++node->word_count;
    }

    /**
     * @param word: The word to be searched for.
     * @return: The number of words in the Trie that are equal to the given word.
     */
    int countWordsEqualTo(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';

        if (!node->children[index]) return 0;


        node = node->children[index];
      }

      return node->word_count;
    }

    /**
     * @param prefix: The prefix to be searched for.
     * @return: The words in the Trie that have the same prefix as the given word.
     */
    int countWordsStartingWith(const std::string &prefix) {
      auto node = root;

      for (const auto &c : prefix) {
        auto index = c - 'a';

        if (!node->children[index]) return 0;

        node = node->children[index];
      }

      return node->prefix_count;
    }

    /**
     * @param word: The word to be removed.
     * @return: nothing
     */
    void erase(const std::string &word) {
      auto node = root;

      for (const auto &c : word) {
        auto index = c - 'a';

        if (!node->children[index]) return;

          node = node->children[index];
          --node->prefix_count;
      }

      node->word_count = std::max(0, --node->word_count);
    }

  private:
    struct Node {
      std::array<Node*, 26> children{};
      int prefix_count{};
      int word_count{};
    };

    Node* root;
};
