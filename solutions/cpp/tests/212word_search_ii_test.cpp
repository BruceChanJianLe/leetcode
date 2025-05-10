#include "212word_search_ii.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::vector<char>> board;
  std::vector<std::string> words;
  std::vector<std::string> result;
};

struct WordSearchIITest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(WordSearchIITest, WordSearchIICase)
{
  auto as = GetParam();
  auto result = s.findWords(as.board, as.words);

  std::sort(result.begin(), result.end());
  std::sort(as.result.begin(), as.result.end());

  EXPECT_EQ(result, as.result);
}

TEST(FindWordsTest, SingleLetterBoardAndWord) {
  Solution sol;
  std::vector<std::vector<char>> board = {{'a'}};
  std::vector<std::string> words = {"a", "b"};
  std::vector<std::string> expected = {"a"};

  EXPECT_EQ(sol.findWords(board, words), expected);
}

INSTANTIATE_TEST_SUITE_P(Default, WordSearchIITest,
  ::testing::Values(
    States{{
      {'o','a','a','n'},
      {'e','t','a','e'},
      {'i','h','k','r'},
      {'i','f','l','v'}
    },{"oath", "pea", "eat", "rain"},{"oath", "eat"}},
    States{{
      {'a','b'},
      {'c','d'}
    },{"abcb"},{}},
    States{{
      {'a'},
    },{"a", "b"},{"a"}},
    States{{
      {'a'},
    },{"a"},{"a"}}
  )
);
