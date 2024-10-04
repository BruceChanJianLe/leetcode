#pragma once

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry{0};
    ListNode head(0);
    ListNode* result;
    result = &head;

    while (nullptr != l1 || nullptr != l2 || carry) {
      carry += l1 ? l1->val : 0;
      carry += l2 ? l2->val : 0;

      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;

      result->next = new ListNode(carry > 9 ? carry - 10 : carry);
      result = result->next;
      carry = carry > 9 ? 1 : 0;
    }
    return head.next;
  }
};
