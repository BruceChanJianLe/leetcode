#include "110balanced_binary_tree.hpp"

#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include <optional>
#include <queue>

// Helper: Build tree from level-order vector (using `std::optional`)
TreeNode* buildTree(const std::vector<std::optional<int>>& data) {
  if (data.empty() || !data.front()) return nullptr;

  TreeNode* root = new TreeNode(*data.front());
  std::queue<TreeNode*> q;
  q.push(root);
  std::size_t i = 1;

  while (i < data.size()) {
    TreeNode* curr = q.front(); q.pop();
    if (i < data.size() && data[i]) {
      curr->left = new TreeNode(*data[i]);
      q.push(curr->left);
    }
    ++i;
    if (i < data.size() && data[i]) {
      curr->right = new TreeNode(*data[i]);
      q.push(curr->right);
    }
    ++i;
  }

  return root;
}

struct States
{
  std::vector<std::optional<int>> input;
  bool result;
};

struct BalancedBinaryTreeTest : public ::testing::TestWithParam<States>
{
  FirstSolution fs;
  SecondSolution ss;
};

TEST_P(BalancedBinaryTreeTest, FirstBalancedBinaryTreeCase)
{
  auto as = GetParam();
  auto root = buildTree(as.input);
  auto result = fs.isBalanced(root);
  EXPECT_EQ(result, as.result);
}

TEST_P(BalancedBinaryTreeTest, SecondBalancedBinaryTreeCase)
{
  auto as = GetParam();
  auto root = buildTree(as.input);
  auto result = ss.isBalanced(root);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, BalancedBinaryTreeTest,
  ::testing::Values(
    States{{3, 9, 20, std::nullopt, std::nullopt, 15, 7}, true},
    States{{1, 2, 2, 3, 3, std::nullopt, std::nullopt, 4, 4}, false},
    States{{}, true},
    States{{1, 2, std::nullopt, 3}, false}, // Deep left
    States{{1, std::nullopt, 2, std::nullopt, 3}, false}, // Deep right
    States{{1, 2, 2, 3, std::nullopt, std::nullopt, 3, 4, std::nullopt, std::nullopt, 4}, false},
    States{{1}, true}
  )
);
