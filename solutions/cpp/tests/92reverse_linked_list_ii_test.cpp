#include "92reverse_linked_list_ii.hpp"

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
  int left;
  int right;
  std::vector<int> result;
};

struct ReverseLinkedListIITest : public ::testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(ReverseLinkedListIITest, ReverseLinkedListIICase)
{
  auto as = GetParam();
  ListNode* head = createLinkedList(as.input);
  ListNode* result = s.reverseBetween(head, as.left, as.right);
  for (const auto& val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

// Define test cases
INSTANTIATE_TEST_SUITE_P(Default, ReverseLinkedListIITest,
  testing::Values(
    States{{1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5}},
    States{{5}, 1, 1, {5}},
    States{{1, 2, 3}, 1, 2, {2, 1, 3}},
    States{{1, 2, 3, 4}, 2, 3, {1, 3, 2, 4}},
    States{{1, 2, 3}, 1, 3, {3, 2, 1}}
  ));
