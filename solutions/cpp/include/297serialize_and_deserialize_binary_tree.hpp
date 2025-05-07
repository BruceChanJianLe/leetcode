#pragma once

#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    if (!root) return {"N"};
    std::string result{};

    preOrderWalk(root, result);

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    if (data.compare("N") == 0) return nullptr;

    std::stringstream ss{data};
    std::queue<std::string> queuey;
    std::string token;

    while (std::getline(ss, token, ',')) {
      queuey.emplace(token);
    }

    return buildTree(queuey);
  }

private:
  void preOrderWalk(TreeNode* root, std::string& result) {
    if (!root) {
      result += "N,";
      return;
    };

    result += std::to_string(root->val) + ",";
    preOrderWalk(root->left, result);
    preOrderWalk(root->right, result);
  }

  TreeNode* buildTree(std::queue<std::string>& queuey) {
    if (queuey.empty()) return nullptr;
    auto curr = queuey.front();

    if (curr == "N")
    {
      queuey.pop();
      return nullptr;
    }

    auto root = new TreeNode(std::stoi(queuey.front()));
    queuey.pop();

    root->left = buildTree(queuey);
    root->right = buildTree(queuey);

    return root;
  }
};

