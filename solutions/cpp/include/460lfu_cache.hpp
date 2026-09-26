#pragma once

#include <unordered_map>
#include <list>

class LFUCache {
public:
  LFUCache(int capacity) {

  }

  int get(int key) {
    // If does not exist return -1
    // If key exist in key_to_val
    // get the current frequency of the key from key_to_freq
    // remove the key from the list at freq_to_keys[curr_freq]
    // increment frequency: curr_freq = 1
    // add key to new list at freq_to_keys[new_freq] (push_front)
    // update min_freq, if old frequency list is empty
  }

  void put(int key, int value) {
    // case1: key exist
    // update the value in key_to_val
    // trigger the same logic as GET to increase frequency

    // case2: new key & full
    // find the list at min_freq
    // remove the least recently used item from that list (pop_back)
    // delete from all maps

    // case3: inserting new key
    // add to key_to_val
    // set frequency to 1
    // add freq_to_keys[1] (push_front)
    // reset min_freq -> 1
  }
};

