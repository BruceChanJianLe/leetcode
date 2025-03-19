#include "141linked_list_cycle.hpp"

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

// Helper function to create a cycle for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* cycleNode = nullptr;
    ListNode* tail = head;
    int index = 0;
    
    while (tail->next) {
        if (index == pos) cycleNode = tail;
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create the cycle
}

struct States
{
  std::vector<int> list;
  int pos;
  bool result;
};

struct LinkedListCycleTest : public testing::TestWithParam<States>
{
  FirstSolution fs;
};

TEST_P(LinkedListCycleTest, LinkedListCycleCase)
{
  auto as = GetParam();
  auto list = createLinkedList(as.list);
  createCycle(list, as.pos);

  auto result = fs.hasCycle(list);
  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_SUITE_P(Default, LinkedListCycleTest,
    testing::Values(
      States{{3,2,0,-4}, 1, true},
      States{{1,2}, 0, true},
      States{{1}, -1, false}
    ));
