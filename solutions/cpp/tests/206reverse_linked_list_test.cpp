#include "206reverse_linked_list.hpp"

#include "gtest/gtest.h"

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

// Helper function to convert a linked list to a vector
std::vector<int> linkedListToVector(ListNode* head) {
  std::vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

struct States
{
  std::vector<int> values;
  std::vector<int> result;
};

struct ReverseLinkedListTest : public testing::TestWithParam<States>
{
  IterativeSolution is;
  RecursiveSolution rs;
};

TEST_P(ReverseLinkedListTest, IterativeReverseLinkedListCase)
{
  auto as = GetParam();
  ListNode* head = createLinkedList(as.values);
  auto result = is.reverseList(head);
  for (const auto& val : as.result) {
    EXPECT_EQ(val, result->val);
    result = result->next;
  }
}

TEST_P(ReverseLinkedListTest, RecursiveReverseLinkedListCase)
{
  auto as = GetParam();
  ListNode* head = createLinkedList(as.values);
  auto result = rs.reverseList(head);
  for (const auto& val : as.result) {
    EXPECT_EQ(val, result->val);
    result = result->next;
  }
}

INSTANTIATE_TEST_SUITE_P(Default, ReverseLinkedListTest,
    testing::Values(
      States{{1,2,3,4,5}, {5,4,3,2,1}},
      States{{1,2}, {2,1}}
    ));
