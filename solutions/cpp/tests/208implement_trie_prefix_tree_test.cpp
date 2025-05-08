#include "208implement_trie_prefix_tree.hpp"

#include <gtest/gtest.h>

struct ImplementTriePrefixTreeTest : public ::testing::Test
{
  Trie t;
};

TEST_F(ImplementTriePrefixTreeTest, BasicOperations)
{
  t.insert("apple");
  EXPECT_TRUE(t.search("apple"));     // inserted word
  EXPECT_FALSE(t.search("app"));      // prefix only, not inserted yet
  EXPECT_TRUE(t.startsWith("app"));   // prefix exists

  t.insert("app");
  EXPECT_TRUE(t.search("app"));       // now inserted
}

TEST_F(ImplementTriePrefixTreeTest, StartsWithVariousPrefixes)
{
  t.insert("banana");
  t.insert("band");
  t.insert("bandana");

  EXPECT_TRUE(t.startsWith("ban"));
  EXPECT_TRUE(t.startsWith("band"));
  EXPECT_FALSE(t.startsWith("bang"));
}

TEST_F(ImplementTriePrefixTreeTest, SearchNonInsertedWords)
{
  t.insert("cat");
  t.insert("cater");

  EXPECT_FALSE(t.search("car"));
  EXPECT_FALSE(t.search("catering"));
  EXPECT_TRUE(t.search("cat"));
  EXPECT_TRUE(t.search("cater"));
}

TEST_F(ImplementTriePrefixTreeTest, EmptyInsertAndPrefix)
{
  t.insert("");  // Edge case: insert empty string
  EXPECT_TRUE(t.search(""));
  EXPECT_TRUE(t.startsWith(""));
}

struct ImplementTriePrefixTreeTest2 : public ::testing::Test
{
  SlightlyFasterTrie t;
};

TEST_F(ImplementTriePrefixTreeTest2, BasicOperations)
{
  t.insert("apple");
  EXPECT_TRUE(t.search("apple"));     // inserted word
  EXPECT_FALSE(t.search("app"));      // prefix only, not inserted yet
  EXPECT_TRUE(t.startsWith("app"));   // prefix exists

  t.insert("app");
  EXPECT_TRUE(t.search("app"));       // now inserted
}

TEST_F(ImplementTriePrefixTreeTest2, StartsWithVariousPrefixes)
{
  t.insert("banana");
  t.insert("band");
  t.insert("bandana");

  EXPECT_TRUE(t.startsWith("ban"));
  EXPECT_TRUE(t.startsWith("band"));
  EXPECT_FALSE(t.startsWith("bang"));
}

TEST_F(ImplementTriePrefixTreeTest2, SearchNonInsertedWords)
{
  t.insert("cat");
  t.insert("cater");

  EXPECT_FALSE(t.search("car"));
  EXPECT_FALSE(t.search("catering"));
  EXPECT_TRUE(t.search("cat"));
  EXPECT_TRUE(t.search("cater"));
}

TEST_F(ImplementTriePrefixTreeTest2, EmptyInsertAndPrefix)
{
  t.insert("");  // Edge case: insert empty string
  EXPECT_TRUE(t.search(""));
  EXPECT_TRUE(t.startsWith(""));
}
