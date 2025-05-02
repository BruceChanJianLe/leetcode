#include "25reverse_nodes_in_k_group.hpp"

#include <gtest/gtest.h>
#include <vector>

// Helper function to convert a vector to a linked list
ListNode* createLinkedList(const std::vector<int>& values) {
  if (values.empty()) return nullptr;
  ListNode head{0};
  ListNode* tail = &head;
  for (int value : values) {
    tail->next = new ListNode(value);
    tail = tail->next;
  }
  return head.next;
}

struct States
{
  std::vector<int> input;
  int k;
  std::vector<int> result;
};

struct ReverseKGroupTest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(ReverseKGroupTest, ReverseKGroupCase)
{
  auto as = GetParam();
  ListNode* head = createLinkedList(as.input);
  ListNode* result = s.reverseKGroup(head, as.k);

  if (result) {
    for (const auto & val : as.result) {
      EXPECT_EQ(result->val, val);
      result = result->next;
    }
  } else {
    EXPECT_EQ(result, nullptr);
  }
}

INSTANTIATE_TEST_SUITE_P(Default, ReverseKGroupTest,
  testing::Values(
    States{{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
    States{{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
    States{{1}, 1, {1}},
    States{{1, 2}, 2, {2, 1}},
    States{{1, 2, 3, 4, 5, 6}, 3, {3, 2, 1, 6, 5, 4}}
  )
);
