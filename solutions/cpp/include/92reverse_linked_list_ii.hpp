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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode holder{0, head};

    auto pre_list = &holder;
    // Find the node just before reversal
    for (auto i = 1; i < left; ++i) {
      pre_list = pre_list->next;
    }

    auto curr = pre_list->next;

    // Need to reverse right - left + 1 times
    for (auto i = 0; i < right - left; ++i) {
      auto temp = curr->next; // Node to be moved
      curr->next = temp->next; // Skip over the temp node
      temp->next = pre_list->next; // Insert at begining of reverse list
      pre_list->next = temp; // Update pre_list to point to new begin of reverse list
    }

    return holder.next;
  }
};
