#include "226invert_binary_tree.hpp"

#include <gtest/gtest.h>

#include <vector>
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

// Helper: Compare two trees
bool TreeEqual(TreeNode* root1, TreeNode* root2) {
  // Base cases
  if (!root1 && !root2) return true; // both are valid
  if (!root1 || !root2) return false; // both are same
  if (root1->val != root2->val) return false; // both values are same

  return TreeEqual(root1->left, root2->left) && TreeEqual(root1->right, root2->right);
}

struct States
{
  std::vector<std::optional<int>> input;
  std::vector<std::optional<int>> result;
};

struct InvertTreeTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(InvertTreeTest, InvertTreeTestCase) {
  auto as = GetParam();
  TreeNode* root = buildTree(as.input);
  TreeNode* result = s.invertTree(root);
  EXPECT_TRUE(TreeEqual(result, buildTree(as.result)));
}

// Test cases
INSTANTIATE_TEST_SUITE_P(Default, InvertTreeTest,
    testing::Values(
      States{{4, 2, 7, 1, 3, 6, 9}, {4, 7, 2, 9, 6, 3, 1}},
      States{{2, 1, 3}, {2, 3, 1}},
      States{{}, {}},
      States{{1}, {1}},
      States{{1, 2, std::nullopt, 3}, {1, std::nullopt, 2, std::nullopt, 3}}  // skewed tree
      )
    );
