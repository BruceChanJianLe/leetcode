#include "876middle_of_the_linked_list.hpp"

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
  std::vector<int> list;
  std::vector<int> result;
};

struct MiddleOfTheLinkedListTest : public testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(MiddleOfTheLinkedListTest, MiddleOfTheLinkedListCase)
{
  auto as = GetParam();
  auto list = createLinkedList(as.list);
  auto result = s.middleNode(list);

  for (const auto& val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

INSTANTIATE_TEST_SUITE_P(Default, MiddleOfTheLinkedListTest,
    testing::Values(
      States{{1,2,3,4,5}, {3,4,5}},
      States{{1,2,3,4,5,6}, {4,5,6}}
    ));
