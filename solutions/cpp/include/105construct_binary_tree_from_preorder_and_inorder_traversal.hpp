#pragma once

#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    // Create a hash map storing the inorder value and index
    std::unordered_map<int, int> lookup;

    for (auto i = 0; i < inorder.size(); ++i) {
      lookup.emplace_hint(lookup.end(), inorder[i], i);
    }

    return buildTreeHelper(
        preorder, 0, preorder.size() - 1,
        inorder, 0, inorder.size() - 1,
        lookup
      );
  }

private:
  TreeNode* buildTreeHelper(
      std::vector<int>& preorder, int pre_start, int pre_end,
      std::vector<int>& inorder, int in_start, int in_end,
      std::unordered_map<int, int>& lookup
    ) {
    if (pre_start > pre_end || in_start > in_end) return nullptr;

    auto curr_val = preorder[pre_start];
    auto node = new TreeNode(curr_val);
    auto curr_pose = lookup[curr_val];
    auto left_subtree_size = curr_pose - in_start;

    node->left = buildTreeHelper(
        preorder, pre_start + 1, pre_start + left_subtree_size, 
        inorder, in_start, curr_pose, 
        lookup);

    node->right = buildTreeHelper(
        preorder, pre_start + left_subtree_size + 1, pre_end, 
        inorder, curr_pose + 1, in_end,
        lookup);

    return node;
  }
};
