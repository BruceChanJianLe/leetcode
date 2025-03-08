#include "981time_based_key_value_store.hpp"

#include "gtest/gtest.h"

#include <tuple>
#include <vector>

struct States {
  std::vector<std::tuple<std::string, std::string, int>>
      set_operations; // (key, value, timestamp)
  std::vector<std::tuple<std::string, int, std::string>>
      get_operations; // (key, timestamp, exapected_value)
};

struct TimeBasedKeyValueStoreTest : public testing::TestWithParam<States> {
  FirstTimeMap ft;
  TimeMap tm;
};

TEST_P(TimeBasedKeyValueStoreTest, TimeBasedKeyValueStoreCase) {
  auto as = GetParam();

  // Perform set operations
  for (const auto &[key, value, timestamp] : as.set_operations) {
    tm.set(key, value, timestamp);
  }

  // Perform get operations
  for (const auto &[key, timestamp, expected_value] : as.get_operations) {
    EXPECT_EQ(tm.get(key, timestamp), expected_value);
  }
}

TEST_P(TimeBasedKeyValueStoreTest, FirstTimeBasedKeyValueStoreCase) {
  auto as = GetParam();

  // Perform set operations
  for (const auto &[key, value, timestamp] : as.set_operations) {
    ft.set(key, value, timestamp);
  }

  // Perform get operations
  for (const auto &[key, timestamp, expected_value] : as.get_operations) {
    EXPECT_EQ(ft.get(key, timestamp), expected_value);
  }
}

INSTANTIATE_TEST_SUITE_P(Default, TimeBasedKeyValueStoreTest,
    testing::Values(
      States{
      // Set operations
      { {"foo", "bar", 1}, {"foo", "bar2", 4} },
      // Get operations
      { {"foo", 1, "bar"}, {"foo", 3, "bar"}, {"foo", 4, "bar2"}, {"foo", 5, "bar2"} }
      },
      States{
      // Set operations
      { {"apple", "red", 10}, {"apple", "green", 20} },
      // Get operations
      { {"apple", 5, ""}, {"apple", 10, "red"}, {"apple", 15, "red"}, {"apple", 20, "green"}, {"apple", 25, "green"} }
      },
      States{
      // Set operations
      { {"key1", "val1", 5}, {"key1", "val2", 10}, {"key1", "val3", 15} }, 
      // Get operations
      { {"key1", 4, ""}, {"key1", 5, "val1"}, {"key1", 10, "val2"}, {"key1", 14, "val2"}, {"key1", 15, "val3"}, {"key1", 20, "val3"} } 
      },
      States{
      // Set operations
      { {"love","high",10}, {"love","low",20} }, 
      // Get operations
      { {"love",5, ""}, {"love",10, "high"}, {"love",15, "high"}, {"love",20, "low"}, {"love",25, "low"} } 
      },
      States{
      // Set operations
      { {"foo","bar",1}, {"foo", "toilet", 5}, {"foo", "bucket", 10}, {"foo","bar2",20} }, 
      // Get operations
      { {"foo",15,"bucket"} } 
      }
      )
    );
