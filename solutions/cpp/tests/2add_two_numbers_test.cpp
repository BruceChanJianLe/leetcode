#include "2add_two_numbers.hpp"

#include "gtest/gtest.h"
#include <vector>

// 2. Add Two Numbers Test

struct States
{
  std::vector<int> l1; 
  std::vector<int> l2; 
  std::vector<int> result; 
};

struct AddTwoNumbersTest : public ::testing::Test, ::testing::WithParamInterface<States>
{
  Solution s; 
};

TEST_P(AddTwoNumbersTest, AddTwoNumbersCases)
{
  auto as = GetParam();
  ListNode* _l1, _l1_head(0);
  ListNode* _l2, _l2_head(0);
  _l1 = &_l1_head;
  _l2 = &_l2_head;

  for (auto& e : as.l1)
  {
    _l1->next = new ListNode(e);
    _l1 = _l1->next;
  }

  for (auto& e : as.l2)
  {
    _l2->next = new ListNode(e);
    _l2 = _l2->next;
  }

  auto result_ptr = s.addTwoNumbers(_l1_head.next, _l2_head.next);

  std::vector<int> result;
  while (result_ptr) {
    result.emplace_back(result_ptr->val);
    result_ptr = result_ptr->next;
  }

  EXPECT_EQ(result, as.result);
}

INSTANTIATE_TEST_CASE_P(Default, AddTwoNumbersTest,
    testing::Values(
      States{{2,4,3}, {5,6,4}, {7,0,8}},
      States{{0}, {0}, {0}},
      States{{9,9,9,9,9,9,9}, {9,9,9,9}, {8,9,9,9,0,0,0,1}}
      ));
