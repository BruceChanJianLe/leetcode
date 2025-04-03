#include "138copy_list_with_random_pointer.hpp"

#include "gtest/gtest.h"

// Utility function to create linked lists
Node* createLinkedList(const std::vector<std::pair<int, int>>& values) {
  std::vector<Node*> nodes;
  // Create nodes
  for (const auto& [val, _] : values) {
    nodes.push_back(new Node(val));
  }

  // Link nodes
  for (auto i = 0uz; i < values.size(); ++i) {
    if (i + 1 < values.size()) nodes[i]->next = nodes[i + 1];
    if (values[i].second != -1) nodes[i]->random = nodes[values[i].second];
  }

  // Return final list
  return nodes.empty() ? nullptr : nodes.front();
}

// Utility function to verify deep copy correctness
void verifyDeepCopy(Node* ori_list, Node* copy_list) {
  while (ori_list && copy_list) {
    ASSERT_NE(ori_list, copy_list); // Address must not be the same
    ASSERT_EQ(ori_list->val, copy_list->val); // Values must be the same
    if (ori_list->random) {
      ASSERT_NE(ori_list->random, copy_list->random); // Address must not be the same
      ASSERT_EQ(ori_list->random->val, copy_list->random->val); // Values must be the same
    }
    // Walk the list
    ori_list = ori_list->next;
    copy_list = copy_list->next;
  }
  ASSERT_EQ(nullptr, ori_list);
  ASSERT_EQ(nullptr, copy_list);
}

struct CopyListWithRandomPointerTest :
  public testing::TestWithParam<std::vector<std::pair<int, int>>>
{
  StandardSolution ss;
  PMRSolution ps;
};

TEST_P(CopyListWithRandomPointerTest, StandardCopyListWithRandomPointerCase) {
    Node* original = createLinkedList(GetParam());
    Node* copy = ss.copyRandomList(original);
    verifyDeepCopy(original, copy);
}

TEST_P(CopyListWithRandomPointerTest, PMRCopyListWithRandomPointerCase) {
    Node* original = createLinkedList(GetParam());
    Node* copy = ps.copyRandomList(original);
    verifyDeepCopy(original, copy);
}

// Parameterized test cases
INSTANTIATE_TEST_SUITE_P(
    CopyRandomListTests,
    CopyListWithRandomPointerTest,
    ::testing::Values(
        std::vector<std::pair<int, int>>{{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
        std::vector<std::pair<int, int>>{{1, 1}, {2, 1}},
        std::vector<std::pair<int, int>>{{3, -1}, {3, 0}, {3, -1}},
        std::vector<std::pair<int, int>>{}
    )
);;
