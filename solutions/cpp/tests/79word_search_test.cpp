#include "79word_search.hpp"

#include "gtest/gtest.h"

struct States
{
  std::vector<std::vector<char>> board;
  std::string word;
  bool result;
};

class WordSearchTest : public ::testing::TestWithParam<States>
{
protected:
  FirstSolution fs;
  SecondSolution ss;
};

TEST_P(WordSearchTest, FindsWordCorrectly) {
  auto as = GetParam();
  auto result = fs.exist(as.board, as.word);
  EXPECT_EQ(result, as.result);
}

TEST_P(WordSearchTest, SecondFindsWordCorrectly) {
  auto as = GetParam();
  auto result = ss.exist(as.board, as.word);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, WordSearchTest,
  ::testing::Values(
    States{
      {{'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}},
      "ABCCED", true
    },
    States{
      {{'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}},
      "SEE", true
    },
    States{
      {{'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'}},
      "ABCB", false
    },
    States{
      {{'C','A','A'},
      {'A','A','A'},
      {'B','C','D'}},
      "AAB", true
    },
    States{
      {{'A'}},
      "A", true
    },
    States{
      {{'A'}},
      "B", false
    }
  )
);
