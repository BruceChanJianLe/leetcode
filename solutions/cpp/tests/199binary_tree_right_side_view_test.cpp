#include "199binary_tree_right_side_view.hpp"

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
  std::vector<int> result;
};

struct BinaryTreeRightSideViewTest : public ::testing::TestWithParam<States>
{
  FirstSolution fs;
  SecondSolution ss;
  DFSSolution ds;
};

TEST_P(BinaryTreeRightSideViewTest, DFSBinaryTreeRightSideViewCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  auto result = ds.rightSideView(root);
  EXPECT_EQ(result, as.result);
  freeTree(root);
}

TEST_P(BinaryTreeRightSideViewTest, SecondBinaryTreeRightSideViewCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  auto result = ss.rightSideView(root);
  EXPECT_EQ(result, as.result);
  freeTree(root);
}

TEST_P(BinaryTreeRightSideViewTest, FirstBinaryTreeRightSideViewCase) {
  const auto& as = GetParam();
  TreeNode* root = buildTree(as.tree);
  auto result = fs.rightSideView(root);
  EXPECT_EQ(result, as.result);
  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(Default, BinaryTreeRightSideViewTest,
  ::testing::Values(
    States{{1,2,3,std::nullopt,5,std::nullopt,4}, {1,3,4}},
    States{{1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5}, {1,3,4,5}},
    States{{1,std::nullopt,3}, {1,3}},
    States{{}, {}},
    States{{1,2,3,std::nullopt,5,6}, {1,3,6}},
    States{{1,2,std::nullopt,3,std::nullopt,4}, {1,2,3,4}}
  )
);
