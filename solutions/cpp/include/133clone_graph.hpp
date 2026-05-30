#pragma once

#include <queue>
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

// Use a queue for unseen nodes
// doesn't require function call
class QueueSolution {

public:
  Node* cloneGraph(Node* node) {
    // Base cases
    if (!node) return nullptr;

    std::unordered_map<Node*, Node*> clones;

    clones[node] = new Node(node->val);

    std::queue<Node*> queue;
    queue.push(node);

    while (!queue.empty()) {
      auto curr = queue.front();
      queue.pop();

      for (const auto& neighbor : curr->neighbors) {
        if (auto [it, is_success] = clones.try_emplace(neighbor, nullptr);
            is_success) {
          it->second = new Node(neighbor->val);
          queue.push(neighbor);
        }
        clones[curr]->neighbors.push_back(clones[neighbor]);
      }
    }

    return clones[node];
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

