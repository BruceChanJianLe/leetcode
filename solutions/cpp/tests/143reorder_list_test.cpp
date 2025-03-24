#include "143reorder_list.hpp"

#include "gtest/gtest.h"
#include <vector>


// Helper function to convert a vector to a linked list
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

struct States
{
  std::vector<int> values;
  std::vector<int> result;
};

struct ReorderListTest : public testing::TestWithParam<States>
{
  Solution s;
};

TEST_P(ReorderListTest, ReorderListCase)
{
  auto as = GetParam();
  auto result = createLinkedList(as.values);
  s.reorderList(result);
  for (const auto& val : as.result) {
    EXPECT_EQ(result->val, val);
    result = result->next;
  }
}

INSTANTIATE_TEST_SUITE_P(Default, ReorderListTest,
    testing::Values(
      States{{1,2,3,4}, {1,4,2,3}},
      States{{1,2,3,4,5}, {1,5,2,4,3}}
    ));
