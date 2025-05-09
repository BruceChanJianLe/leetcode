#include "1804implement_trie_ii_prefix_tree.hpp"

#include <gtest/gtest.h>

// Test fixture for Trie tests
class TrieTest : public ::testing::Test {
  protected:
    Trie* trie;

    void SetUp() override {
      // This is called before each test
      trie = new Trie();
    }

    void TearDown() override {
      // This is called after each test
      delete trie;
    }
};

// Test basic insert and count
TEST_F(TrieTest, BasicInsertAndCount) {
  trie->insert("apple");

  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsEqualTo("app"));
  EXPECT_EQ(1, trie->countWordsStartingWith("app"));
  EXPECT_EQ(0, trie->countWordsStartingWith("orange"));
}

// Test multiple inserts of the same word
TEST_F(TrieTest, MultipleInserts) {
  trie->insert("apple");
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(3, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(3, trie->countWordsStartingWith("app"));
}

// Test erase functionality
TEST_F(TrieTest, Erase) {
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(2, trie->countWordsEqualTo("apple"));

  trie->erase("apple");
  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));

  trie->erase("apple");
  EXPECT_EQ(0, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsStartingWith("app"));
}

// Test with multiple words
TEST_F(TrieTest, MultipleWords) {
  trie->insert("apple");
  trie->insert("app");
  trie->insert("application");

  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(1, trie->countWordsEqualTo("app"));
  EXPECT_EQ(1, trie->countWordsEqualTo("application"));
  EXPECT_EQ(3, trie->countWordsStartingWith("app"));

  trie->erase("app");
  EXPECT_EQ(0, trie->countWordsEqualTo("app"));
  EXPECT_EQ(2, trie->countWordsStartingWith("app"));
}

// Test example from problem statement
TEST_F(TrieTest, ExampleFromProblem) {
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(2, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(2, trie->countWordsStartingWith("app"));

  trie->erase("apple");
  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(1, trie->countWordsStartingWith("app"));

  trie->erase("apple");
  EXPECT_EQ(0, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsStartingWith("app"));
}

// Test with empty string
TEST_F(TrieTest, EmptyString) {
  trie->insert("");
  EXPECT_EQ(1, trie->countWordsEqualTo(""));
  EXPECT_EQ(0, trie->countWordsStartingWith("a"));

  trie->erase("");
  EXPECT_EQ(0, trie->countWordsEqualTo(""));
}

// Test with long strings
TEST_F(TrieTest, LongStrings) {
  std::string longWord(2000, 'a'); // 2000 'a' characters
  trie->insert(longWord);

  EXPECT_EQ(1, trie->countWordsEqualTo(longWord));
  EXPECT_EQ(1, trie->countWordsStartingWith(longWord.substr(0, 1000)));

  trie->erase(longWord);
  EXPECT_EQ(0, trie->countWordsEqualTo(longWord));
}

// Test with strings containing all lowercase letters
TEST_F(TrieTest, AllLetters) {
  std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
  trie->insert(allLetters);

  EXPECT_EQ(1, trie->countWordsEqualTo(allLetters));
  EXPECT_EQ(1, trie->countWordsStartingWith("abc"));
  EXPECT_EQ(0, trie->countWordsStartingWith("abd"));

  trie->erase(allLetters);
  EXPECT_EQ(0, trie->countWordsEqualTo(allLetters));
}

// Repeat same test for SlightlyFasterTrie
// Test fixture for Trie tests
class SlightlyFasterTrieTest : public ::testing::Test {
  protected:
    SlightlyFasterTrie* trie;

    void SetUp() override {
      // This is called before each test
      trie = new SlightlyFasterTrie();
    }

    void TearDown() override {
      // This is called after each test
      delete trie;
    }
};

// Test basic insert and count
TEST_F(SlightlyFasterTrieTest, BasicInsertAndCount) {
  trie->insert("apple");

  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsEqualTo("app"));
  EXPECT_EQ(1, trie->countWordsStartingWith("app"));
  EXPECT_EQ(0, trie->countWordsStartingWith("orange"));
}

// Test multiple inserts of the same word
TEST_F(SlightlyFasterTrieTest, MultipleInserts) {
  trie->insert("apple");
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(3, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(3, trie->countWordsStartingWith("app"));
}

// Test erase functionality
TEST_F(SlightlyFasterTrieTest, Erase) {
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(2, trie->countWordsEqualTo("apple"));

  trie->erase("apple");
  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));

  trie->erase("apple");
  EXPECT_EQ(0, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsStartingWith("app"));
}

// Test with multiple words
TEST_F(SlightlyFasterTrieTest, MultipleWords) {
  trie->insert("apple");
  trie->insert("app");
  trie->insert("application");

  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(1, trie->countWordsEqualTo("app"));
  EXPECT_EQ(1, trie->countWordsEqualTo("application"));
  EXPECT_EQ(3, trie->countWordsStartingWith("app"));

  trie->erase("app");
  EXPECT_EQ(0, trie->countWordsEqualTo("app"));
  EXPECT_EQ(2, trie->countWordsStartingWith("app"));
}

// Test example from problem statement
TEST_F(SlightlyFasterTrieTest, ExampleFromProblem) {
  trie->insert("apple");
  trie->insert("apple");

  EXPECT_EQ(2, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(2, trie->countWordsStartingWith("app"));

  trie->erase("apple");
  EXPECT_EQ(1, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(1, trie->countWordsStartingWith("app"));

  trie->erase("apple");
  EXPECT_EQ(0, trie->countWordsEqualTo("apple"));
  EXPECT_EQ(0, trie->countWordsStartingWith("app"));
}

// Test with empty string
TEST_F(SlightlyFasterTrieTest, EmptyString) {
  trie->insert("");
  EXPECT_EQ(1, trie->countWordsEqualTo(""));
  EXPECT_EQ(0, trie->countWordsStartingWith("a"));

  trie->erase("");
  EXPECT_EQ(0, trie->countWordsEqualTo(""));
}

// Test with long strings
TEST_F(SlightlyFasterTrieTest, LongStrings) {
  std::string longWord(2000, 'a'); // 2000 'a' characters
  trie->insert(longWord);

  EXPECT_EQ(1, trie->countWordsEqualTo(longWord));
  EXPECT_EQ(1, trie->countWordsStartingWith(longWord.substr(0, 1000)));

  trie->erase(longWord);
  EXPECT_EQ(0, trie->countWordsEqualTo(longWord));
}

// Test with strings containing all lowercase letters
TEST_F(SlightlyFasterTrieTest, AllLetters) {
  std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
  trie->insert(allLetters);

  EXPECT_EQ(1, trie->countWordsEqualTo(allLetters));
  EXPECT_EQ(1, trie->countWordsStartingWith("abc"));
  EXPECT_EQ(0, trie->countWordsStartingWith("abd"));

  trie->erase(allLetters);
  EXPECT_EQ(0, trie->countWordsEqualTo(allLetters));
}
