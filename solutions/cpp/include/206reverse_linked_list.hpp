#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val{0}, next{nullptr} {}
  ListNode(int x) : val{x}, next{nullptr} {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {}
};

class IterativeSolution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev_node{nullptr}, *next_node{nullptr};
    while (head) {
      next_node = head->next;
      head->next = prev_node;
      prev_node = head;
      head = next_node;
    }
    return prev_node;
  }
};


class RecursiveSolution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* new_head = reverseList(head->next);
    head->next->next = head; // point back to myself
    head->next = nullptr; // the next reverseList() call will handle
    return new_head;
  }
};
