#include "211design_add_and_search_words_data_structure.hpp"

#include <gtest/gtest.h>

TEST(DesignAddAndSearchWordsDataStructureTest, BasicSearch) {
  WordDictionary wd;
  wd.addWord("bad");
  wd.addWord("dad");
  wd.addWord("mad");

  EXPECT_FALSE(wd.search("pad"));
  EXPECT_TRUE(wd.search("bad"));
  EXPECT_TRUE(wd.search(".ad"));
  EXPECT_TRUE(wd.search("b.."));
}

TEST(DesignAddAndSearchWordsDataStructureTest, EdgeCases) {
  WordDictionary wd;
  wd.addWord("a");

  EXPECT_TRUE(wd.search("a"));
  EXPECT_TRUE(wd.search("."));
  EXPECT_FALSE(wd.search("b"));
}

TEST(DesignAddAndSearchWordsDataStructureTest, MultipleDots) {
  WordDictionary wd;
  wd.addWord("abc");
  wd.addWord("xyz");
  wd.addWord("xaz");

  EXPECT_TRUE(wd.search("...")); // matches any 3-letter word
  EXPECT_TRUE(wd.search("x.z")); // matches "xaz"
  EXPECT_FALSE(wd.search("..")); // too short
  EXPECT_FALSE(wd.search("....")); // too long
}

TEST(DesignAddAndSearchWordsDataStructureTest, RepeatedAdds) {
  WordDictionary wd;
  wd.addWord("test");
  wd.addWord("test");

  EXPECT_TRUE(wd.search("test"));
  EXPECT_TRUE(wd.search("t.st"));
  EXPECT_TRUE(wd.search("te.t"));
  EXPECT_FALSE(wd.search("t..t."));
}
