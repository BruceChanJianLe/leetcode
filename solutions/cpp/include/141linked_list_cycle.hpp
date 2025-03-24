#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Floyd's tortise and hare (cycle detection)
// 6ms
class Solution {
public:
  bool hasCycle(ListNode *head) {
    // Sanity check
    if (!head || !head->next) return false;

    ListNode* slow{head->next}, *fast{head->next->next};

    while (fast && fast->next) {
      if (slow == fast)  return true;

      slow = slow->next;
      fast = fast->next->next;
    }

    return false;
  }
};

class FirstSolution {
public:
  bool hasCycle(ListNode *head) {
    while (head) {
      if (head->val != 100009) {
        head->val = 100009;
      } else {
        return true;
      }
      head = head->next;
    }
    return false;
  }
};
