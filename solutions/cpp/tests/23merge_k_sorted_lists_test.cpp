#include "23merge_k_sorted_lists.hpp"

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
  std::vector<std::vector<int>> values;
  std::vector<int> result;
};

struct MergeKSortedListsTest : public testing::TestWithParam<States>
{
  FirstSolution fs;
  MinHeapSolution ms;
};

// O(n * k)
TEST_P(MergeKSortedListsTest, FirstSolutionMergeKSortedListsTest)
{
  auto as = GetParam();
  std::vector<ListNode*> lists;

  for (const auto& value : as.values) {
    lists.emplace_back(createLinkedList(value));
  }

  auto result = fs.mergeKLists(lists);

  if (!result) {
    EXPECT_EQ(result, nullptr);
  } else {
    for (const auto& val : as.result) {
      EXPECT_EQ(result->val, val);
      result = result->next;
    }
  }
}

// O(n log k)
TEST_P(MergeKSortedListsTest, MinHeapSolutionMergeKSortedListsTest)
{
  auto as = GetParam();
  std::vector<ListNode*> lists;

  for (const auto& value : as.values) {
    lists.emplace_back(createLinkedList(value));
  }

  auto result = ms.mergeKLists(lists);

  if (!result) {
    EXPECT_EQ(result, nullptr);
  } else {
    for (const auto& val : as.result) {
      EXPECT_EQ(result->val, val);
      result = result->next;
    }
  }
}

INSTANTIATE_TEST_SUITE_P(Default, MergeKSortedListsTest,
    testing::Values(
      States{{{1,4,5},{1,3,4},{2,6}}, {1,1,2,3,4,4,5,6}},
      States{{},{}},
      States{{{1}, {}},{1}},
      States{{{}},{}}
  ));
