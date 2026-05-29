#pragma once

#include <vector>
#include <unordered_map>

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// Recursive DFS, as the depth is 100
// we are safe from stack overflow
class DFSSolution {
  std::unordered_map<Node*, Node*> clones;

public:
  Node* cloneGraph(Node* node) {
    // Base cases
    if (!node) return nullptr;

    // Return if node already exist
    if (auto it = clones.find(node); it != clones.end()) return it->second;

    auto* clone = new Node(node->val);
    clones[node] = clone;

    for (const auto& neighbor : node->neighbors) {
      clone->neighbors.push_back(cloneGraph(neighbor));
    }

    return clones[node];
  }
};

