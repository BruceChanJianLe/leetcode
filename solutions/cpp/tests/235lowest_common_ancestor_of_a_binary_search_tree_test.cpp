#include "235lowest_common_ancestor_of_a_binary_search_tree.hpp"

#include <gtest/gtest.h>

#include <optional>
#include <queue>

// Helper: Build tree from level-order vector (using `std::optional`)
TreeNode* buildTreeWithMap(
    const std::vector<std::optional<int>>& vals,
    std::unordered_map<int, TreeNode*>& nodeMap)
{
  if (vals.empty() || !vals.front()) return nullptr;
  TreeNode* root = new TreeNode(*vals.front());
  nodeMap[root->val] = root;
  std::queue<TreeNode*> q;
  q.push(root);
  size_t i = 1;
  while (!q.empty() && i < vals.size()) {
    TreeNode* curr = q.front(); q.pop();
    if (i < vals.size() && vals[i]) {
      curr->left = new TreeNode(*vals[i]);
      nodeMap[curr->left->val] = curr->left;
      q.push(curr->left);
    }
    ++i;
    if (i < vals.size() && vals[i]) {
      curr->right = new TreeNode(*vals[i]);
      nodeMap[curr->right->val] = curr->right;
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
    int p_val;
    int q_val;
    int result;
};

struct LCABinarySearchTreeTest : public ::testing::TestWithParam<States>
{
  FirstSolution fs;
};

TEST_P(LCABinarySearchTreeTest, FindsCorrectLCA) {
  const auto& [treeData, p_val, q_val, expected] = GetParam();
  std::unordered_map<int, TreeNode*> nodeMap;
  TreeNode* root = buildTreeWithMap(treeData, nodeMap);

  ASSERT_TRUE(nodeMap.count(p_val));
  ASSERT_TRUE(nodeMap.count(q_val));

  TreeNode* lca = fs.lowestCommonAncestor(root, nodeMap[p_val], nodeMap[q_val]);
  ASSERT_NE(lca, nullptr);
  EXPECT_EQ(lca->val, expected);

  freeTree(root);
}

INSTANTIATE_TEST_SUITE_P(Default, LCABinarySearchTreeTest,
  ::testing::Values(
    States{{6,2,8,0,4,7,9,std::nullopt,std::nullopt,3,5}, 2, 8, 6},
    States{{6,2,8,0,4,7,9,std::nullopt,std::nullopt,3,5}, 2, 4, 2},
    States{{2,1}, 2, 1, 2},
    States{{10,5,15,2,7,12,20}, 2, 7, 5},
    States{{10,5,15,2,7,12,20}, 7, 12, 10}
  )
);
