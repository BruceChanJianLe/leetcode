#pragma once

#include <array>
#include <memory_resource>
#include <unordered_map>

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class PMRSolution {
public:
  Node* copyRandomList(Node* head) {
    std::array<uint8_t, 32768> buffer{};
    std::pmr::monotonic_buffer_resource memory_resource{buffer.data(), buffer.size()};
    std::pmr::unordered_map<Node*, Node*> records{&memory_resource};
    std::pmr::polymorphic_allocator<Node> alloc{&memory_resource};

    // Create records
    auto walk = head;
    while (walk) {
      records[walk] = alloc.new_object<Node>(walk->val);
      walk = walk->next;
    }

    // Link the list
    walk = head;
    while (walk) {
      records[walk]->next = records[walk->next];
      records[walk]->random = records[walk->random];
      walk = walk->next;
    }

    return records[head];
  }
};

class StandardSolution {
public:
  Node* copyRandomList(Node* head) {
    std::unordered_map<Node*, Node*> records;

    // Create records
    auto walk = head;
    while (walk) {
      records[walk] = new Node(walk->val);
      walk = walk->next;
    }

    // Link the list
    walk = head;
    while (walk) {
      records[walk]->next = records[walk->next];
      records[walk]->random = records[walk->random];
      walk = walk->next;
    }

    return records[head];
  }
};
