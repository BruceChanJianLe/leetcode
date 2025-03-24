#pragma once
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    void reorderList(ListNode* head) {
      ListNode *slow{head}, *fast{head};

      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }

      // Find second-half and break it
      auto head2 = slow->next;
      slow->next = nullptr;

      // reverse second half
      ListNode* prev{nullptr}, *next{nullptr};
      while (head2) {
        next = head2->next;
        head2->next = prev;
        prev = head2;
        head2 = next;
      }

      head2 = prev;

      ListNode store{0};
      ListNode *new_head{&store};
      while (head && head2) {
        new_head->next = head;
        head = head->next;

        new_head->next->next = head2;
        head2 = head2->next;

        new_head = new_head->next->next;
      }

      new_head->next = head ? head : head2;

      head = store.next;
    }
};
