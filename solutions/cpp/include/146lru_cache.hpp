#pragma once

#include <cstdint>
#include <iostream>
#include <list>
#include <memory_resource>
#include <unordered_map>

class PMR_LRUCache {
public:
  explicit PMR_LRUCache(const int _capacity)
    : capacity(_capacity)
    , memory_buffer(capacity * 3)
    , memory_upstream(memory_buffer.data(), memory_buffer.size())
    , memory_resource(&memory_upstream)
    , cache(&memory_resource)
    , cache_map(&memory_resource)
  {}

  int get(const int key) {
    if (auto it = cache_map.find(key); it != cache_map.end()) {
      auto& [key, node] = *it;
      cache.splice(cache.begin(), cache, node);
      return node->value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (auto it = cache_map.find(key); it != cache_map.end()) {
      auto& [key, node] = *it;
      node->value = value;
      cache.splice(cache.begin(), cache, node);
    } else {
      cache.emplace_front(key, value);
      cache_map.emplace(key, cache.begin());

      // evict LRU if over capacity
      if (cache.size() > capacity) {
        cache_map.erase(cache.back().key);
        cache.pop_back();
      }
    }
  }

private:
  struct Node {
    int key;
    int value;
  };

  int capacity;
  // Buffer storage
  std::vector<Node> memory_buffer;

  // Memory resources
  std::pmr::monotonic_buffer_resource memory_upstream;
  std::pmr::synchronized_pool_resource memory_resource;

  std::pmr::list<Node> cache;
  std::pmr::unordered_map<int, std::pmr::list<Node>::iterator> cache_map;
};

class LRUCache {
public:
  LRUCache(const int _capacity)
    : head{nullptr}
    , tail{nullptr}
    , length{0}
    , capacity{_capacity}
  {}

  int get(int key) {
    // if exist return value and update head
    // Otherwise return -1
    if (auto lookup = records.find(key); lookup != records.end()) {
      auto& node = lookup->second;
      detach(node);
      append(node);
      return node->value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    // if key exist, update value and head
    // Otherwise, create and update head
    if (auto lookup = records.find(key); lookup != records.end()) {
      auto& node = lookup->second;
      node->value = value;
      detach(node);
      append(node);
    }
    else {
      auto node = new Node{key, value};
      records.insert({key, node});
      append(node);

      ++length;
    }

    if (length > capacity) {
      auto lru = tail;
      detach(lru);
      records.erase(lru->key);
      delete lru;
      --length;
    }
  }

private:
  struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
  };

  Node* head;
  Node* tail;
  std::unordered_map<int, Node*> records;
  uint_fast16_t length;
  int capacity;

  void detach(Node* node) {
    if (node->next) {
      node->next->prev = node->prev;
    }

    if (node->prev) {
      node->prev->next = node->next;
    }

    if (head == node) {
      head = head->next;
    }

    if (tail == node) {
      tail = tail->prev;
    }

    node->next = node->prev = nullptr;
  }

  void append(Node* node) {
    if (!head) {
      head = tail = node;
    } else {
      node->next = head;
      head->prev = node;
      head = node;
    }
  }
};

class STD_LRUCache {
public:
  STD_LRUCache(const int _capacity) : capacity(_capacity) {}

  int get(const int key) {
    // Return stored value if key exist
    if (auto itr = cache_map.find(key); itr != cache_map.end()) {
      auto& [_, node] = *itr;
      cache.splice(cache.begin(), cache, node);
      return node->second;
    } else {
      return -1;
    }
  }

  void put(const int key, const int value) {
    // If exist, update value and move to front
    if (auto it = cache_map.find(key); it != cache_map.end()) {
      auto [_, node] = *it;
      node->second = value;
      cache.splice(cache.begin(), cache, node);
    } else {
      // If not, create new node, and check if capacity has reached
      cache.emplace_front(key, value);
      cache_map.emplace(key, cache.begin());

      if (cache.size() > capacity) {
        cache_map.erase(cache.back().first);
        cache.pop_back();
      }
    }
  }

private:
  // Doubly linked-list (key, value)
  std::list<std::pair<int, int>> cache;

  // Instant lookup (key, {key, value})
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map;
  // Referring to the description, only 3000 insert max
  std::uint_fast16_t capacity;
};

class LRUCache2 {
public:
  LRUCache2(const int _capacity)
    : capacity{_capacity}
    , head{nullptr}
    , tail{nullptr}
  {}

  int get(int key) {
    // if key exist
    if (auto it = lookup.find(key); it != lookup.end()) {
      auto [_, node] = *it;
      // move to front
      move_to_front(node);
      // return value
      return node->value;
    }
    // Otherwise return -1
    return -1;
  }

  void put(int key, int value) {
    // if key exist
    if (auto it = lookup.find(key); it != lookup.end()) {
      auto [_, node] = *it;
      // update value
      node->value = value;
      // move to front
      move_to_front(node);
    } else {
      // Otherwise, create new key
      push_front(key, value);
      // check if capcity is reached
      if (lookup.size() > capacity) {
        auto lru = tail;
        detach(tail);
        lookup.erase(lru->key);
        // evit if so
        delete lru;
      }
    }
  }

private:
  struct Node {
    int key, value;
    Node *next, *prev;

    Node(const int _key, const int _value)
      : key{_key}, value{_value}, next{nullptr}, prev{nullptr} {}
  };

  int capacity;
  Node *head, *tail;
  std::unordered_map<int, Node*> lookup;

  void detach(Node* node) {
    if (node->next) {
      node->next->prev = node->prev;
    }

    if (node->prev) {
      node->prev->next = node->next;
    }

    if (head == node) {
      head = head->next;
    }

    if (tail == node) {
      tail = tail->prev;
    }

    node->next = node->prev = nullptr;
  }

  void push_front(const int key, const int value) {
    auto node = new Node(key, value);
    lookup.emplace(key, node);
    push_front(node);
  }

  void push_front(Node* node) {
    if (!head) {
      head = tail = node;
    } else {
      node->next = head;
      head->prev = node;
      head = node;
    }
  }

  void move_to_front(Node* node) {
    detach(node);
    push_front(node);
  }
};
