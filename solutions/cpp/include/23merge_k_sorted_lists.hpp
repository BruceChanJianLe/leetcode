#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n * k)
// n - total number of nodes
// k - total number of lists
class FirstSolution {
public:

  ListNode* mergeKLists(std::vector<ListNode*> lists) {
    if (lists.empty()) return nullptr;

    ListNode* temp_list{nullptr};

    for (auto& list : lists) {
      if (list) {
        temp_list = mergeTwoLists(temp_list, list);
      }
    }

    return temp_list;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head{0};
    ListNode* tail = &head;

    while(list1 && list2) {
      if (list1->val > list2->val) {
        tail->next = list2;
        list2 = list2->next;
      } else {
        tail->next = list1;
        list1 = list1->next;
      }
      tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return head.next;
  }
};
