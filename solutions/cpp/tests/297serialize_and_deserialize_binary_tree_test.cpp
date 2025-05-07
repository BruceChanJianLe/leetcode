#include "297serialize_and_deserialize_binary_tree.hpp"

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

bool isSameTree(TreeNode* tree_p, TreeNode* tree_q) {
  if (!tree_p && !tree_q) return true;
  if (!tree_p || !tree_q) return false;

  return tree_p->val == tree_q->val
    && isSameTree(tree_p->left, tree_q->left)
    && isSameTree(tree_p->right, tree_q->right);
}

struct States
{
  std::vector<std::optional<int>> tree;
};

struct SerializeAndDeserializeBinaryTreeTest : public ::testing::TestWithParam<States>
{
  Codec codec;
};

TEST_P(SerializeAndDeserializeBinaryTreeTest, SerializeAndDeserializeBinaryTreeCase)
{
  auto as = GetParam();
  TreeNode* root = buildTree(as.tree);
  std::string encoded = codec.serialize(root);
  TreeNode* decoded_tree = codec.deserialize(encoded);
  EXPECT_TRUE(isSameTree(root, decoded_tree));
}

INSTANTIATE_TEST_SUITE_P(Default, SerializeAndDeserializeBinaryTreeTest,
  ::testing::Values(
    States{{1, 2, 3, std::nullopt, std::nullopt, 4, 5}},
    States{{std::nullopt}},
    States{{42}},
    States{{1, 2, std::nullopt, 3, std::nullopt, 4}}
  )
);
