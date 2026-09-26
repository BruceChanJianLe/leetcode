#include "460lfu_cache.hpp"

#include "gtest/gtest.h"

// 460 LFU Cache
// Design problem: drive the object through an operation sequence rather than
// checking a single return value. Replace the stubs with the problem examples.

TEST(LFUCacheTest, BasicOperations)
{
  LFUCache obj{0 /* capacity */};

  // EXPECT_EQ(obj.get(key), expected);
  // obj.put(key, value);
}

TEST(LFUCacheTest, EdgeCases)
{
  LFUCache obj{0 /* capacity */};

  // TODO: empty state, capacity limits, overwriting an existing key, ...
}
