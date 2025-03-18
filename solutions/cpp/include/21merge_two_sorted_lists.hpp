#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class IterativeSolution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode head{0};
      ListNode *tail = &head;

      while (list1 && list2) {
        if (list1->val > list2->val) {
          tail->next = list2;
          list2 = list2->next;
        } else {
          tail->next = list1;
          list1 = list1->next;
        }
        // Move tail forward by 1
        tail = tail->next;
      }

      // Append the remaining list
      tail->next = list1 ? list1 : list2;

      return head.next;
    }
};

class RecursiveSolution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      // Base cases
      if (!list1) return list2;
      if (!list2) return list1;

      if (list1->val > list2->val) {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      } else {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      }
    }
};
