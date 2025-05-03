#include "1448count_good_nodes_in_binary_tree.hpp"

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

// Cleanup utility
void freeTree(TreeNode* root) {
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

struct States
{
  std::vector<std::optional<int>> tree;
  int result;
};

struct CountGoodNodesInBinaryTreeTest : public ::testing::TestWithParam<States>
{
  BFSSolution bs;
  DFSSolution1 ds1;
  DFSSolution2 ds2;
};

TEST_P(CountGoodNodesInBinaryTreeTest, BFSCountGoodNodesInBinaryTreeCase) {
  const auto& [tree, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(bs.goodNodes(root), result);
  freeTree(root);
}

TEST_P(CountGoodNodesInBinaryTreeTest, DFS1CountGoodNodesInBinaryTreeCase) {
  const auto& [tree, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(ds1.goodNodes(root), result);
  freeTree(root);
}

TEST_P(CountGoodNodesInBinaryTreeTest, DFS2CountGoodNodesInBinaryTreeCase) {
  const auto& [tree, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(ds2.goodNodes(root), result);
  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(Default,
  CountGoodNodesInBinaryTreeTest,
  ::testing::Values(
    States{{3,1,4,3,std::nullopt,1,5}, 4},
    States{{3,3,std::nullopt,4,2}, 3},
    States{{1}, 1},
    States{{5,4,6,3,5,std::nullopt,7}, 4},
    States{{9,std::nullopt,3,6}, 1},
    States{{0,-1,std::nullopt,-2,-3}, 1}             // Edge case: negatives
  )
);
