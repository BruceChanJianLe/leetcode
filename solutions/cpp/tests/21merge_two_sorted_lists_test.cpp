#include "21merge_two_sorted_lists.hpp"

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
  std::vector<int> list1;
  std::vector<int> list2;
  std::vector<int> result;
};

struct MergeTwoSortedListsTest : public testing::TestWithParam<States>
{
  IterativeSolution is;
  RecursiveSolution rs;
};

TEST_P(MergeTwoSortedListsTest, IterativeMergeTwoSortedListsCase)
{
  auto as = GetParam();
  ListNode* list1 = createLinkedList(as.list1);
  ListNode* list2 = createLinkedList(as.list2);

  auto result = is.mergeTwoLists(list1, list2);
  for (const auto& val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

TEST_P(MergeTwoSortedListsTest, RecursiveMergeTwoSortedListsCase)
{
  auto as = GetParam();
  ListNode* list1 = createLinkedList(as.list1);
  ListNode* list2 = createLinkedList(as.list2);

  auto result = rs.mergeTwoLists(list1, list2);
  for (const auto& val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

INSTANTIATE_TEST_SUITE_P(Default, MergeTwoSortedListsTest,
    testing::Values(
      States{{1,2,4},{1,3,4},{1,1,2,3,4,4}},
      States{{},{},{}},
      States{{},{0},{0}}
    ));
