#pragma once

#include <utility>

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

// A more simple but brute force solution
// Break the whole thing into pre_list, mid_list, post_list
// Hence you will need to introduce a "sentinel" to watch over your head
// This is so that if you need to reverse the entire list you can still point
// to the correct "head" once you are done
class BruteForceSolution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode sentinel{0, head};

    // Find pre_list
    auto* pre_list{&sentinel};
    for (auto i = 1; i < left; ++i) {
      pre_list = pre_list->next;
    }

    // mid_list begins at the next of pre_list
    auto* mid_list = pre_list->next;
    auto *post_list = pre_list->next;

    // Continue to look for post list
    for (auto i = left; i < right; ++i) {
      post_list = post_list->next;
    }

    // Detach post_list from reverse region
    {
      auto* region_end = post_list;
      post_list = post_list->next; // this has to happen first
      region_end->next = nullptr;
    }

    auto [mid_head, mid_tail] = ReverseListNode(mid_list);

    pre_list->next = mid_head;
    mid_tail->next = post_list;

    return sentinel.next;
  }

  std::pair<ListNode*, ListNode*> ReverseListNode(ListNode* head) {
    ListNode *tail{head}, *prev{nullptr}, *next{nullptr};

    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return {prev, tail};
  }
};
