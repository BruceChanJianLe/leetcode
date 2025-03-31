#pragma once
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 0ms!
// However, the if statement are too complicated
class FirstSolution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    std::vector<ListNode*> records;
    records.reserve(30);

    while (head) {
      records.push_back(head);
      head = head->next;
    }

    // This part is too complicated
    if (auto curr = records.rbegin() + n - 1, prev = curr + 1; curr != records.rend()) {
      if (prev != records.rend()) {
        if ((*curr)->next)
          (*prev)->next = (*curr)->next;
        else
          (*prev)->next = nullptr;
        return records.front();
      }
      return (*curr)->next;
    }
    return nullptr;
  }
};

class SecondSolution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode record{0, head}, *slow{head}, *fast{head};

    // move to n-th position
    for (auto i = 0; i < n; ++i) {
      fast = fast->next;
    }

    // move both fast and slow pointers
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* to_be_deleted = slow->next;
    slow->next = slow->next->next;
    delete to_be_deleted;

    return record.next;
  }
};
