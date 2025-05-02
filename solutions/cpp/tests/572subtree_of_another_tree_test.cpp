#include "572subtree_of_another_tree.hpp"

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
  std::vector<std::optional<int>> root_values;
  std::vector<std::optional<int>> subroot_values;
  bool result;
};

struct SubtreeOfAnotherTreeTest : public ::testing::TestWithParam<States>
{
  FirstSolution s;
};

TEST_P(SubtreeOfAnotherTreeTest, DetectsSubtreeCorrectly) {
  auto [rootVals, subRootVals, expected] = GetParam();
  TreeNode* root = buildTree(rootVals);
  TreeNode* subRoot = buildTree(subRootVals);
  EXPECT_EQ(s.isSubtree(root, subRoot), expected);
  freeTree(root);
  freeTree(subRoot);
}

INSTANTIATE_TEST_SUITE_P(Default, SubtreeOfAnotherTreeTest,
  ::testing::Values(
    States{{3, 4, 5, 1, 2}, {4, 1, 2}, true},
    States{{3, 4, 5, 1, 2, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 0}, {4, 1, 2}, false},
    States{{1}, {1}, true},
    States{{1, 2, 3}, {4}, false},
    States{{}, {1}, false}
  )
);
