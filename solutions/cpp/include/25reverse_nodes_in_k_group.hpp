#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    // Edge cases
    if (!head || k == 1) return head;

    ListNode root{0, head};
    ListNode *group_prev{&root}, *group_next{nullptr};

    while (true) {
      auto kth_node = getKthNode(group_prev, k);

      // Break out condition
      if (!kth_node) break;

      group_next = kth_node->next;
      auto prev = group_next;

      while (head != group_next) {
        auto next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }

      auto next_start_node = group_prev->next;
      group_prev->next = kth_node;
      group_prev = next_start_node;
    }

    return root.next;
  }

  ListNode* getKthNode(ListNode* curr, int k) {
    while (k > 0 && curr) {
      curr = curr->next;
      --k;
    }
    return curr;
  }
};
