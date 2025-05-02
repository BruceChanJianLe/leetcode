#pragma once

#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n * log k)
// n - total number of nodes
// k - total number of lists
class MinHeapSolution {
public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    // custom comparator
    auto compare_node = [](ListNode* first, ListNode* second) {
      return first->val > second->val;
    };

    // Pass custom comparator during construction as lambda are not default constructible
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare_node)> min_heap;
    // also, you can remove the custom comparator and do the below
    /*
    std::priority_queue<
      ListNode*,
      std::vector<ListNode*>,
      decltype([](ListNode* first, ListNode* second)
          { return first->val > second->val; }
      )> min_heap;
    */

    // Place first nodes of each list to the heap (valid ones)
    for (auto& list : lists) {
      if (list) {
        min_heap.emplace(list);
        list  = list->next;
      }
    }

    ListNode head{0};
    ListNode* tail = &head;
    // Process node until heap is empty
    while (!min_heap.empty()) {
      // Obtain smallest value
      auto curr_smallest = min_heap.top();
      min_heap.pop();

      // Add to our list
      tail->next = curr_smallest;
      tail = tail->next;

      // Add the next node to the list from the obtain node (if exist)
      if (curr_smallest->next) {
        min_heap.emplace(curr_smallest->next);
      }
    }

    return head.next;
  }
};

// O(n * k)
// n - total number of nodes
// k - total number of lists
class FirstSolution {
public:

  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
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
