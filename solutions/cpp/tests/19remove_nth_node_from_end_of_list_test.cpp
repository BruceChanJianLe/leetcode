#include "19remove_nth_node_from_end_of_list.hpp"

#include "gtest/gtest.h"
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
  std::vector<int> values;
  int n;
  std::vector<int> result;
};

struct RemoveNthNodeFromEndOfListTest : public testing::TestWithParam<States>
{
  FirstSolution fs;
};

TEST_P(RemoveNthNodeFromEndOfListTest, RemoveNthNodeFromEndOfListCase)
{
  auto as = GetParam();
  auto list = createLinkedList(as.values);
  auto result = fs.removeNthFromEnd(list, as.n);
  for (const auto &val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

INSTANTIATE_TEST_SUITE_P(Default, RemoveNthNodeFromEndOfListTest,
    testing::Values(
      States{{1,2,3,4,5}, 2, {1,2,3,5}},
      States{{1}, 1, {}},
      States{{1,2}, 1, {1}}
    ));
