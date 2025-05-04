#include "230kth_smallest_element_in_a_bst.hpp"

#include <cstdlib>
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
  int k;
  int result;
};

struct KthSmallestElementInABSTTest : public ::testing::TestWithParam<States>
{
  OptimalRDSFSolution or_dsf;
  RDSFSolution r_dsf;
  IDSFSolution i_dsf;
};

TEST_P(KthSmallestElementInABSTTest, OptimalRecursiveDSFKthSmallestElementInABSTCase)
{
  const auto& [tree, k, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(or_dsf.kthSmallest(root, k), result);
  free(root);
}

TEST_P(KthSmallestElementInABSTTest, RecursiveDSFKthSmallestElementInABSTCase)
{
  const auto& [tree, k, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(r_dsf.kthSmallest(root, k), result);
  free(root);
}

TEST_P(KthSmallestElementInABSTTest, IterativeDSFKthSmallestElementInABSTCase)
{
  const auto& [tree, k, result] = GetParam();
  TreeNode* root = buildTree(tree);
  EXPECT_EQ(i_dsf.kthSmallest(root, k), result);
  free(root);
}

INSTANTIATE_TEST_SUITE_P(Default, KthSmallestElementInABSTTest,
  ::testing::Values(
    States{{3, 1, 4, std::nullopt, 2}, 1, 1},
    States{{5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1}, 3, 3},
    States{{41,37,44,24,39,42,48,1,35,38,40,std::nullopt,43,46,49,0,2,30,36,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,45,47,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,4,29,32,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,3,9,26,std::nullopt,31,34,std::nullopt,std::nullopt,7,11,25,27,std::nullopt,std::nullopt,33,std::nullopt,6,8,10,16,std::nullopt,std::nullopt,std::nullopt,28,std::nullopt,std::nullopt,5,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,15,19,std::nullopt,std::nullopt,std::nullopt,std::nullopt,12,std::nullopt,18,20,std::nullopt,13,17,std::nullopt,std::nullopt,22,std::nullopt,14,std::nullopt,std::nullopt,21,23}, 25, 24},
    States{{1}, 1, 1},
    States{{1,std::nullopt,2}, 2, 2},
    States{{5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1}, 6, 6}
  )
);
