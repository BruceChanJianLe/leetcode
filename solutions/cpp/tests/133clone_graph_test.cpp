#include "133clone_graph.hpp"
#include "gtest/gtest.h"

#include <queue>
#include <unordered_map>
#include <vector>

static Node *buildGraph(const std::vector<std::vector<int>> &adjList) {
  if (adjList.empty()) return nullptr;

  std::vector<Node *> nodes;
  for (int i = 0; i < (int)adjList.size(); ++i)
    nodes.push_back(new Node(i + 1));

  for (int i = 0; i < (int)adjList.size(); ++i)
    for (int neighbor : adjList[i])
      nodes[i]->neighbors.push_back(nodes[neighbor - 1]);

  return nodes[0];
}

static std::vector<std::vector<int>> graphToAdjList(Node *node) {
  if (!node) return {};

  std::unordered_map<Node *, int> indexMap;
  std::vector<Node *> nodes;
  std::queue<Node *> q;

  q.push(node);
  indexMap[node] = 0;

  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    nodes.push_back(curr);

    for (Node *neighbor : curr->neighbors) {
      if (!indexMap.count(neighbor)) {
        indexMap[neighbor] = (int)indexMap.size();
        q.push(neighbor);
      }
    }
  }

  std::vector<std::vector<int>> adjList(nodes.size());
  for (Node *curr : nodes) {
    for (Node *neighbor : curr->neighbors)
      adjList[curr->val - 1].push_back(neighbor->val);
  }

  return adjList;
}

struct States {
  std::vector<std::vector<int>> adjList;
};

struct CloneGraphTest : public ::testing::TestWithParam<States> {
  DFSSolution rs;
};

TEST_P(CloneGraphTest, DFSSolutionClonesCorrectly) {
  auto as = GetParam();
  Node *original = buildGraph(as.adjList);
  Node *cloned = rs.cloneGraph(original);
  EXPECT_EQ(graphToAdjList(cloned), as.adjList);
  if (original && cloned)
    EXPECT_NE(original, cloned);
}

INSTANTIATE_TEST_SUITE_P(
    CloneGraphParameterizedTests, CloneGraphTest,
    ::testing::Values(
        States{{{2, 4}, {1, 3}, {2, 4}, {1, 3}}}, // 4-node cycle
        States{{{}}},                              // single node, no neighbors
        States{{}},                                // null graph
        States{{{2}, {1}}},                        // two-node graph
        States{{{2, 3, 4}, {1}, {1}, {1}}}         // star graph
    ));
