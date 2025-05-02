#include "100same_tree.hpp"

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
  std::vector<std::optional<int>> p_tree;
  std::vector<std::optional<int>> q_tree;
  bool result;
};

struct SameTreeTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(SameTreeTest, ComparesStructureAndValuesCorrectly) {
  auto as = GetParam();
  TreeNode* p = buildTree(as.p_tree);
  TreeNode* q = buildTree(as.q_tree);
  auto result = s.isSameTree(p, q);
  EXPECT_EQ(result, result);
}

INSTANTIATE_TEST_SUITE_P(Default, SameTreeTest,
  ::testing::Values(
    States{{1, 2, 3}, {1, 2, 3}, true},
    States{{1, 2}, {1, std::nullopt, 2}, false},
    States{{1, 2, 1}, {1, 1, 2}, false},
    States{{}, {}, true},
    States{{1}, {}, false},
    States{{}, {1}, false}
  )
);
